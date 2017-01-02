/*
 * Provenance collector daemon.  Simply funnels the relay file to port 16152 on
 * the given host.
 *
 * Unlike uprovd.c, this function records uncompressed provenance to the log
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>

#include <sys/stat.h>
#include <fcntl.h>

#include "slog.h"
#include "plog.hpp"
#include <provmon_proto.h>

int stopping;

void handle(int signo)
{
	stopping = 1;
}

int main(int argc, char *argv[])
{
	int rv = 0;
	int kernel_provenance = 1;
	const char *inpath;
	int infd;

	ProvenanceGraph graph;

	/* Parse arguments - should be two or three */
	if (argc < 2)
		goto err_usage;
	inpath = argv[1];

	/* Initalize slog */
	init_slog("snap_provd", "slog.cfg", 3);

	if (inpath[0] != '/') {
		slog(SLOG_ERROR,SLOG_ERROR, "Input file must be given as absolute path\n");
		return 1;
	}

	/* Try to open provenance relay */
	infd = open(inpath, O_RDONLY);
	if (infd < 0) {
		slog(SLOG_ERROR,SLOG_ERROR,"Failed to open LPM relay. Continuing.");
		kernel_provenance = 0;
	}

	/* Shut down gracefully when given the chance */
	signal(SIGHUP, handle);
	signal(SIGINT, handle);
	signal(SIGQUIT, handle);
	signal(SIGTERM, handle);

	/* daveti: init the app ipc */
	rv = app_ipc_init();
	if (rv) {
		slog(SLOG_ERROR,SLOG_ERROR,"app_ipc_init");
		/* We should NOT impact the kernel relay */
	}	
	
	/* Start doing real work */
	for (;;) {
		/* DAVETI: Add something here to check for new app prov */
		// Check for new message
		// Recover PID of proc that sent the message
		// Use PID to get binary name
		// Check IMA to see if digest for that binary is valid
		// If so...
		//   Pipe message into zip file like funnel_data
		// Either way, send ACK
		struct provmsg * ipc_msg = app_ipc_process(stopping);
		if (ipc_msg != NULL) {
			rv = plog_process_provmsg(ipc_msg,&graph);
		}


		/* Sleep some small amount of time before checking again*/
		usleep(1000);

		/* Exit condition */
		if (stopping)
			break;

		/* Write everything currently in relay to log */
	        if(kernel_provenance){
			rv = plog_process_raw(infd, graph);
			if (rv)
				goto out_close_relay;

			if (TEMP_FAILURE_RETRY(close(infd))) {
				perror("close");
				rv = 1;
				goto out_close_log;
			}
			
			infd = TEMP_FAILURE_RETRY(open(inpath, O_RDONLY));
			if (infd < 0) {
				perror("open temp failure retry");
				rv = 1;
				goto out_close_log;
			}
		}


	}

out_close_relay:
	/* Close relay */
	if (TEMP_FAILURE_RETRY(close(infd))) {
		perror("close");
		rv = 1;
	}
out_close_log:

	/* Close log file */
	return rv;

err_usage:
	fprintf(stderr, "usage: uprovd <infile>\n");
	return 1;
}
