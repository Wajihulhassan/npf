/*
 * app_ipc.c
 * Application IPC implementation
 * NOTE: we are using Unix domain socket with datagram without connection and Non-blocking!
 * and this implementation is NOT thread-safe!
 * Feb 18, 2015
 * root@davejingtian.org
 * http://davejingtian.org
 */
#include "app_ipc.h"
#include <provmon_proto.h>

#include <sys/ioctl.h>
#include <asm-generic/ioctls.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "slog.h"

/* Global vars */
static int sfd;
static struct sockaddr_un addr;
static struct sockaddr_un client_addr;

static struct provmsg * data;
static struct provmsg * ack;
static int max_provmsg_len = 2048;

static char app_proc_path[APP_PATH_LEN_MAX];
static char app_bin_name[APP_PATH_LEN_MAX];

static int app_ipc_start;
static int app_debug = 1;

/* APIs */
struct provmsg * app_ipc_process(int stop)
{
	int ret, pid, sfd2, t;
	struct sockaddr_un remote;
	char *log;
	size_t nw;
	ssize_t nr = 0;

	if (stop) {
		printf("Warning: app_ipc_process is stopped\n");
		return 0;
	}

	if (!app_ipc_start) {
		printf("Warning: app ipc is NOT started\n");
		return 0;
	}

	t = sizeof(remote);
        if ((sfd2 = accept(sfd, (struct sockaddr *)&remote, (socklen_t*)&t)) == -1) {
		// We have set the socket to be nonblicking, so it is not surprising
		// when there is an error code here.
		return NULL;
        }

	slog(SLOG_LIVE,SLOG_LIVE,"%s: Accepted connect",__func__);

	/* Try to recv the provenance record */
	nr = recv(sfd2, data, max_provmsg_len, 0);
	if (nr <= 0) {
		perror("recv");
		goto out_err;
	}
	
	slog(SLOG_LIVE,SLOG_LIVE,"%s: Received %d bytes",__func__,nr);

	if(send(sfd2, ack, sizeof(*ack),  0) < 0) {
		perror("send");
		goto out_err;
	}

	slog(SLOG_LIVE,SLOG_LIVE,"%s: Sent %d bytes",__func__,sizeof(*ack));

	close(sfd2);
	return data;

 out_err:
	close(sfd2);
	return NULL;

}

int setNonblocking(int fd)
{
	int flags;

	/* Fixme: O_NONBLOCK is defined but broken on SunOS 4.1.x and AIX 3.2.5. */
	if (-1 == (flags = fcntl(fd, F_GETFL, 0)))
		flags = 0;
	return fcntl(fd, F_SETFL, flags | O_NONBLOCK);

}     


int app_ipc_init(void)
{
	int optval, len;

	if ((sfd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
		perror("socket");
		exit(1);
	}

	memset(&addr, 0, sizeof(struct sockaddr_un));
	addr.sun_family = AF_UNIX;
	strcpy(addr.sun_path, APP_SOCK_PATH);
	unlink(addr.sun_path);
	len = strlen(addr.sun_path) + sizeof(addr.sun_family);
	if (bind(sfd, (struct sockaddr *)&addr, len) == -1) {
		perror("bind");
		exit(1);
	}

	setNonblocking(sfd);
	chmod(addr.sun_path, 0777);

	if (listen(sfd, 10) == -1) {
		perror("listen");
		exit(1);
	}

	/* Init the ACK msg which will be used soon */
	ack = (struct provmsg *) malloc(sizeof(*ack));
	ack->type = NUM_PROVMSG_TYPES;
	msg_initlen(ack, sizeof(*ack));

	data = (struct provmsg *)malloc(max_provmsg_len);

	/* Mark the flag and return */
	app_ipc_start = 1;

	return 0;
}

void app_ipc_exit(void)
{
	if (app_debug)
		printf("app_ipc: into [%s]\n", __func__);

	if (app_ipc_start)
		close(sfd);
}
