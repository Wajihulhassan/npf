#ifndef FORMAT_H
#define FORMAT_H

#include <assert.h>
#include "adlist.h"
#include "sql.h"
#include "sql.tab.h"
#include "database_provenance.h"
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <sys/resource.h>

char funcArray[FEND];

extern Stmt *stmtArray[100];
extern int indexArray;


void get_names_rec(void *,list * n);
void get_names_list(void *lst,list * names);
void get_names_rec(void *item, list * names);
int parse_stmt(Stmt * st, int proc_id);
int _parse();

int push_buffer_array(char * buffer, int proc_id);
int push_buffer_stdin(int ac, char **av);
int push_buffer_file(int ac, char **av);

#endif
