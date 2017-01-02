#include <iostream>
#include <sys/time.h>
#include <vector>
#include "snap_handlers.hpp"
#include <sys/stat.h>

#include "app_ipc.h"

int plog_process(FILE *log);

int plog_process_raw(int log, ProvenanceGraph & graph);

int plog_ipc_process(int stopping);

int plog_process_provmsg(struct provmsg * msg, ProvenanceGraph * graph);

void stat_test(ProvenanceGraph);
