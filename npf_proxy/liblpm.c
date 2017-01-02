#include "liblpm.h"

/* x86 */
//#define _CURR_PROV_ 249
//#define _PID_TO_PROV_ 250
/* x86_64 */
#define _CURR_PROV_ 312
#define _PID_TO_PROV_ 313

#define PROVD_SOCK_PATH                 "/tmp/app_ipc_sock"
#define PROVD_SERVER_SOCK_PATH          "/tmp/provd_ipc_sock"

#define PROVD_PATH_LEN_MAX		1024
#define PROVD_INPUT_FILE		0
#define PROVD_OUTPUT_FILE		1
#define IMAGEMAGICK_FILE_NAME_LEN_MAX	512

static int provd_debug = 1;
long unsigned current_provenance(){
  return syscall(_CURR_PROV_);
}

long unsigned pid_to_provenance(int pid){
  return syscall(_CURR_PROV_,pid);
}

unsigned long  lpm_get_time()
{
	struct timeval t;
	gettimeofday(&t, NULL);
	return 1000000 * t.tv_sec + t.tv_usec;
}

static int provd_ipc_process(struct provmsg * msg)
{
	ssize_t ns, nr;
	int t, len;
	char str[100];

	if ((sfd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}

	addr.sun_family = AF_UNIX;
	strcpy(addr.sun_path, PROVD_SOCK_PATH);
	len = strlen(addr.sun_path) + sizeof(addr.sun_family);

	if (connect(sfd, (struct sockaddr *)&addr, len) == -1) {
		perror("connect");
		printf("%s: Failed to connect to %s!\n",__func__,addr.sun_path);
		exit(1);
	}

	// Send the msg
	ns = send(sfd, msg, msg_getlen(msg), 0);
	if (ns == -1) {
		fprintf(stderr,"Error: sendmsg failed [%s]\n", strerror(errno));
		return -1;
	}

	// Wait for the ACK from the server
	// NOTE: this is a blocking recv!
	// TODO: timeout this recv
	nr = recv(sfd, &ack, sizeof(ack), MSG_WAITALL);
	if (nr < 0) {
		fprintf(stderr,"Error: recvmsg failed [%s]\n", strerror(errno));
		return -1;
	}
	else if (nr == 0) {
		fprintf(stderr,"Server closed connection\n");
		return -1;
	}

	close(sfd);

	return 0;
}

unsigned char * lpm_unit_start(const char * id){
	    struct provmsg_unit_start * msg;
	    unsigned long time_to_unit_start_begin, time_to_unit_start_finish;
	    char benchmark_cmd[100];

    	    time_to_unit_start_begin = lpm_get_time();

	    // typedef unsigned char uuid_t[16];
	    unsigned char * uuid = (unsigned char *) malloc(16);

	    msg = (struct provmsg_unit_start *) malloc(sizeof(*msg));
	    if(!msg)
		    printf("%s: Attempt to allocate provenance failed\n",__func__);

	    msg_initlen(&msg->msg, sizeof(*msg));
	    msg->msg.type = PROVMSG_UNIT_START;

	    /* Resolve cred_id using process id */
	    msg->msg.cred_id = pid_to_provenance(getpid());
	    if(msg->msg.cred_id == -1){
		    /* printf("%s: failed to recover cred id. Falling back to proc id\n",__func__); */
		    msg->msg.cred_id = getpid();
	    }

	    /* Access Network Context */
	    /* ( printf("%s: Start of unit of work for id %lu\n",__func__,msg->msg.cred_id); */

	    /* Copy in User Identifier */
	    memcpy(msg->id,id,strlen(id));

	    /* Copy in UUID */
	    uuid_generate_time_safe(uuid);
	    memcpy(msg->uuid.b,uuid,16);

	    provd_ipc_process((struct provmsg *)msg);

	    free(msg);

    	    time_to_unit_start_finish=lpm_get_time();

	    snprintf(benchmark_cmd,100,"echo %lu >> /tmp/lpm_benchmark_unit_start_musec.txt",
		     time_to_unit_start_finish-time_to_unit_start_begin);
	    system(benchmark_cmd);	    

	    return uuid;
}

void lpm_unit_end(uuid_t uuid){

	    struct provmsg_unit_end * msg;
	    unsigned long time_to_unit_end_begin, time_to_unit_end_finish;
	    char benchmark_cmd[100];

    	    time_to_unit_end_begin = lpm_get_time();

	    msg = (struct provmsg_unit_end *) malloc(sizeof(*msg));
	    if(!msg)
		    printf("%s: Attempt to allocate provenance failed\n",__func__);

	    msg_initlen(&msg->msg, sizeof(*msg));
	    msg->msg.type = PROVMSG_UNIT_END;	

	    /* Resolve cred_id using process id */
	    msg->msg.cred_id = pid_to_provenance(getpid());
	    if(msg->msg.cred_id == -1){
		    /* printf("%s: failed to recover cred id. Falling back to proc id\n",__func__); */
		    msg->msg.cred_id = getpid();
	    }

	    /* Copy in UUID */
	    memcpy(msg->uuid.b,uuid,16);

	    provd_ipc_process((struct provmsg *)msg);

	    free(msg);

    	    time_to_unit_end_finish = lpm_get_time();

	    snprintf(benchmark_cmd,100,"echo %lu >> /tmp/lpm_benchmark_unit_end_musec.txt",
		     time_to_unit_end_finish - time_to_unit_end_begin);
	    system(benchmark_cmd);	    

}
void provenance_disclose_access(int provmsg_type, int proc_id, char * data, int data_len) {

  struct provmsg_sql_read * msg;
  unsigned long prov_id;

  msg = malloc(sizeof(struct provmsg_sql_read) + data_len);
  if(!msg)
    printf("Provenance Disclosure: Attempt to allocate provenance failed\n");

  msg->msg.type = provmsg_type;

  msg->data_len = data_len;

  // Resolve cred_id using process id 
  msg->msg.cred_id = pid_to_provenance(proc_id);
  if(msg->msg.cred_id == 0){
	  msg->msg.cred_id = proc_id;
  }

  // New way (isn't that simpler?)
  memcpy(msg->data,data,data_len);

  msg_initlen(&msg->msg, sizeof(*msg) + data_len);
 
  // Old way follows
  /*
  if(table) {
	  msg->table_len = strlen(table);
	  snprintf(msg->table_name,SQL_FIELD_NAME_MAX,"%s",table);
  }
  else
	  msg->table_len = 0;

  if(column){
	  msg->column_len = strlen(column);
	  snprintf(msg->column_name,SQL_FIELD_NAME_MAX,"%s",column);
  }
  else
	  msg->column_len = 0;

  //printf("%s: [%d] read %s.%s (%d.%d)\n", __func__,msg->msg.cred_id,msg->table_name,msg->column_name,msg->table_len,msg->column_len);
  */

  provd_ipc_process((struct provmsg *)msg);

  free(msg);

  return;
}

void provenance_disclose_read(int proc_id, char * data, int data_len){
	
  provenance_disclose_access(PROVMSG_SQL_READ, proc_id, data, data_len);

}

void provenance_disclose_used(int proc_id, char * data, int data_len){
	
  provenance_disclose_access(PROVMSG_SQL_USED, proc_id, data, data_len);

}


