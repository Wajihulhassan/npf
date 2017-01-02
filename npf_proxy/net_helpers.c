#include "net_helpers.h"

// get port, IPv4 or IPv6:
in_port_t get_in_port(struct sockaddr *sa)
{
  if (sa->sa_family == AF_INET) {
    return (((struct sockaddr_in*)sa)->sin_port);
  }

  return (((struct sockaddr_in6*)sa)->sin6_port);
}

void tokenize(char * text, int len, char delimiter, int max_tokens){

  int i=0;

  while(i<len){

    if(text[i] == delimiter){

      if(max_tokens == 0)
	return;
      else
	max_tokens--;

      text[i] = '\0';
    }
      
    i++;
  }

}

char * get_token(char * text, int len, int pos){

  int i=0;
  int in_word = 0;

  while( i < len ){

    if(!in_word && text[i] != '\0'){

      in_word = 1;

      if(pos == 0)
	return text + i;

      pos--;
    }
    else if(text[i] == '\0'){
      in_word = 0;
    }

    i++;
  }

  return NULL; 
}

int msghdr_to_pid(struct msghdr * msgh){

  struct cmsghdr *cmhp;
  struct ucred *ucredp;

  /* Extract credentials information from received ancillary data */
  cmhp = CMSG_FIRSTHDR(msgh);

  if (cmhp == NULL || cmhp->cmsg_len != CMSG_LEN(sizeof(struct ucred))) {
    slog(SLOG_DEBUG, SLOG_DEBUG,"%s: bad cmsg header... we likely proxied a non-local TCP connection",__func__);
    return -1;
  }

  if (cmhp->cmsg_level != SOL_SOCKET) {
    slog(SLOG_ERROR, SLOG_ERROR,"%s: cmsg_level != SOL_SOCKET\n",__func__);
    return -1;
  }

  if (cmhp->cmsg_type != SCM_CREDENTIALS) {
    slog(SLOG_ERROR, SLOG_ERROR,"%s: cmsg_type != SCM_CREDENTIALS\n",__func__);
    return -1;
  }

  ucredp = (struct ucred *) CMSG_DATA(cmhp);

  slog(SLOG_INFO,SLOG_INFO,"%s: Received credentials pid=[%ld], uid=[%ld], gid=[%ld]\n",
       __func__,(long) ucredp->pid, (long) ucredp->uid, (long) ucredp->gid);

  return (int)ucredp->pid;


}

int sock_to_pid(struct sockaddr_in * client) {

  int rv = -1;

  /* BATES -- Short Circuit */
  return rv;

  //The target
  char src_ip[INET_ADDRSTRLEN];
  int src_port;

  //For executing netstat command
  int buf_len = 100;
  char * buffer = malloc(buf_len);

  //For reading netstat output
  FILE * fp;
  char * line = NULL;
  size_t len = 0;
  ssize_t read;
  
  //For parsing netstat output
  char * client_addr;
  char * client_proc;
  char * client_ip;
  int client_port, client_pid;

  /* Convert sockaddr_in struct to target fields */
  const char* result = inet_ntop(AF_INET,&client->sin_addr, src_ip, sizeof(src_ip));

  src_port = ntohs(get_in_port((struct sockaddr *)client));

  slog(0, SLOG_INFO,"Looking up pid for client socket with ip %s and port %d",src_ip,src_port);

  /* Execute netstat command */
  snprintf(buffer,buf_len,"netstat -tnap | grep -Ri \"\\:%d\" > /tmp/.proxy%d",src_port,src_port);

  slog(0, SLOG_LIVE,"%s",buffer);
  system(buffer);

  snprintf(buffer,buf_len,"/tmp/.proxy%d",src_port);

  fp = fopen(buffer, "r");
  if (fp == NULL)
    goto out;

  while ((read = getline(&line, &len, fp)) != -1) {
    slog(0, SLOG_LIVE, "Recovered netstat entry of length %zu", read);

    /* Split netstat line into tokens */
    tokenize(line,read,' ',-1);

    /* Token 3 is source IP/Port */
    /* Token 4 is dest IP/Port */
    /* Token 6 is source process/pid */
    client_addr = get_token(line,read,3);
    client_proc = get_token(line,read,6);

    slog(0,SLOG_LIVE,"Source address is %s, Proc ID is %s.",client_addr,client_proc);

    /* Further tokenize the address and process information */
    tokenize(client_addr,16,':',1);
    tokenize(client_proc,16,'/',1);

    client_ip = get_token(client_addr,16,0);
    client_port = atoi(get_token(client_addr,16,1));
    client_pid = atoi(get_token(client_proc,16,0));

    //slog(0, SLOG_LIVE,"Recovered ip = (%s), port = (%d)",get_token(client_addr,16,0),client_port);
    //slog(0, SLOG_LIVE,"Recovered cmd = (%s), pid = (%d)",get_token(client_proc,8,1),client_pid);

    /* Compare to provided client address and port */
    if(strcmp(src_ip,client_ip) == 0 &&  src_port == client_port) {
      slog(0, SLOG_INFO,"%s: Matched client socket to process %s <PID=%d>, returning PID",
	   __func__,get_token(client_proc,8,1),client_pid);

      rv = client_pid;
    }
    else
      slog(0, SLOG_WARN,"%s: Client socket does not match process %s <PID=%d>, keep looking",
	   __func__,get_token(client_proc,8,1),client_pid);

  }

  fclose(fp);


  if (line)
    free(line);

  snprintf(buffer,buf_len,"rm /tmp/.proxy%d",src_port);
  system(buffer);

 out:
  free(buffer);
  return rv;

}


