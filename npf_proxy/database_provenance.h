//#ifndef DATABASE_PROVENANCE_H
//#define DATABASE_PROVENANCE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <provmon_proto.h>
#include <sys/time.h>

#include "liblpm.h"
#include "slog.h"

//void extract_provenance(int client_pid, char * query, int len);
//void provenance_disclose_read(unsigned long prov_id, char * table, char * column);

double time_to_parse, time_to_prov;

static double get_time() {
  struct timeval t;
  struct timezone tzp;
  gettimeofday(&t, &tzp);
  return t.tv_sec + t.tv_usec*1e-6;
}


int extract_provenance(int client_pid, char * query, int len) {

  //For executing system command
  int buf_len = 2048;
  char * buffer = malloc(buf_len);
  int i, rv = -1;

  //For writing query to file
  FILE * fp;

  // Write query to file
  snprintf(buffer,buf_len,"/tmp/proxy%d.sql",client_pid);
  
  fp = fopen(buffer, "w");
  if (fp == NULL)
    return;

  fwrite(query, sizeof(char), len, fp);

  fclose(fp);

  /*
  fp = fopen(buffer,"r");
  fread(buffer,1,buf_len,fp);
  printf("File says [%s]\n",buffer);
  fclose(fp);
  */

  // Write query to file 
  snprintf(buffer,buf_len,"./sqlprov /tmp/proxy%d.sql %d 2>&1",client_pid,client_pid); 
  int ret = system(buffer);
  if (WIFEXITED(ret)) {
    rv = WEXITSTATUS(ret);
    /* printf("exited, status=%d\n", rv);*/
  }  

  //printf("%s\n",buffer);
  snprintf(buffer,buf_len,"rm /tmp/proxy%d.sql",client_pid);
  system(buffer);

  return rv;
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


//#endif
