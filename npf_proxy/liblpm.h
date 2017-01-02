#ifndef LIBLPM_H
#define LIBLPM_H

#include <errno.h>      /* Declares errno and defines error constants */
#include <linux/unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/syscall.h> 
#include <sys/un.h>
#include <unistd.h>

#include <uuid/uuid.h>

#include <provmon_proto.h>

#include <time.h>
#include <uuid/uuid.h>
/* x86 */
//#define _CURR_PROV_ 249
//#define _PID_TO_PROV_ 250
/* x86_64 */
#define _CURR_PROV_ 312
#define _PID_TO_PROV_ 313

long unsigned current_provenance(){
  return syscall(_CURR_PROV_);
}

long unsigned pid_to_provenance(int pid){
  return syscall(_CURR_PROV_,pid);
}

//#define PROVD_SOCK_PATH                 "/tmp/provd_ipc_sock"
//#define PROVD_SERVER_SOCK_PATH          "/tmp/app_ipc_sock"

#define PROVD_SOCK_PATH                 "/tmp/app_ipc_sock"
#define PROVD_SERVER_SOCK_PATH          "/tmp/provd_ipc_sock"

#define PROVD_PATH_LEN_MAX		1024
#define PROVD_INPUT_FILE		0
#define PROVD_OUTPUT_FILE		1
#define IMAGEMAGICK_FILE_NAME_LEN_MAX	512

/*
 * mogrify-provd-ipc.c
 * The implementation of IPC between mogrify and provd.
 * NOTE: we are using Unix domain socket without connection and blocking recving.
 * This implementation is NOT thread-safe!
 * Feb 19, 2015
 * root@davejingtian.org
 * http://davejingtian.org
 */
/* Global vars */
static int sfd;
static struct sockaddr_un addr;
static struct sockaddr_un server_addr;
static struct provmsg ack;

static int provd_data_input_ready;
static int provd_data_output_ready;
static int provd_ipc_start;
static int provd_debug = 1;

/* Internal routines */


/* APIs */
/*
static int provd_ipc_data(char *name, int len, int input)
{
	if (provd_debug)
		printf("provd_ipc: into [%s], name [%p], len [%d], input [%d]\n",
			__func__, name, len, input);

	if (!provd_ipc_start) {
		printf("Error: provd IPC is NOT started - abort\n");
		return -1;
	}

	if (len >= IMAGEMAGICK_FILE_NAME_LEN_MAX) {
		printf("Error: len [%d] exceeds the max [%d] - abort\n",
			len, IMAGEMAGICK_FILE_NAME_LEN_MAX);
		provd_data_input_ready = 0;
		provd_data_output_ready = 0;
		return -1;
	}

	switch (input) {

	case PROVD_INPUT_FILE:
		data.input_len = len;
		memset(data.input, 0x0, IMAGEMAGICK_FILE_NAME_LEN_MAX);
		memcpy(data.input, name, len);
		provd_data_input_ready = 1;
		provd_data_output_ready = 0;
		return 0;

	case PROVD_OUTPUT_FILE:
		data.output_len = len;
		memset(data.output, 0x0, IMAGEMAGICK_FILE_NAME_LEN_MAX);
		memcpy(data.output, name, len);
		provd_data_output_ready = 1;
		return 0;
	
	default:
		printf("Error: unsupported input flag [%d]\n", input);
		provd_data_input_ready = 0;
		provd_data_output_ready = 0;
		break;
	}

	return -1;	
}
*/

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

#endif

