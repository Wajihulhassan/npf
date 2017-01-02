#ifndef NET_HELPERS_H
#define NET_HELPERS_H

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/un.h>

#include "slog.h"

in_port_t get_in_port(struct sockaddr *sa);
void tokenize(char * text, int len, char delimiter, int max_tokens);
char * get_token(char * text, int len, int pos);
int msghdr_to_pid(struct msghdr * msgh);
int sock_to_pid(struct sockaddr_in * client);

#endif
