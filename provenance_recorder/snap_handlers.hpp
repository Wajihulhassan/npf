#ifndef SNAP_HANDLERS_H
#define SNAP_HANDLERS_H

#include <stdio.h>
#include "stdafx.h"

#include "linux-mman.h"
#include "linux-fs.h"
#include "linux-shm.h" 

#include <provmon_proto.h>

#include <map>
#include <string>
#include <exception>

#include "graph_components.hpp"

#include "slog.h"

void exit_nicely();
void handle_err(char * cmd, char * err);
char * argv_to_label(char * cstring, int len, int argc);
char * print_uuid_be(uuid_be *uuid);

/* Throttled Ancestor Cache Optimization */
#define ANCESTOR_CACHE false

class ProvenanceGraph {

  int handle_boot(struct provmsg *msg);
  int handle_credfork(struct provmsg *msg);
  int handle_credfree(struct provmsg *msg);
  int handle_setid(struct provmsg *msg);
  int handle_exec(struct provmsg *msg);
  int handle_inode_p(struct provmsg *msg);
  int handle_mmap(struct provmsg *msg);
  int handle_file_p(struct provmsg *msg);
  int handle_link(struct provmsg *msg);
  int handle_unlink(struct provmsg *msg);
  int handle_setattr(struct provmsg *msg);
  int handle_inode_alloc(struct provmsg *msg);
  int handle_inode_dealloc(struct provmsg *msg);
  int handle_socksend(struct provmsg *msg);
  int handle_sockrecv(struct provmsg *msg);
  int handle_sockalias(struct provmsg *msg);
  int handle_mqsend(struct provmsg *msg);
  int handle_mqrecv(struct provmsg *msg);
  int handle_shmat(struct provmsg *msg);
  int handle_readlink(struct provmsg *msg);

  int handle_sql(struct provmsg *msg, int relation_type);
  int handle_unit_start(struct provmsg *msg);
  int handle_unit_end(struct provmsg *msg);

  int get_or_create_node(PNEANet &, struct ObjectMaps &, int type, int subtype, void * key);
  int get_or_create_edge(PNEANet &, int SrcId, int DstId, int rel);
  int create_edge(PNEANet &, int SrcId, int DstId, int rel);
  int get_edge(PNEANet &, int SrcId, int DstId);

  void DumpNode(int TgtId);

public:

  PNEANet Graph;
  struct ObjectMaps Objects;

  /* Structured for being able to look up graph components using
     provenance semantics */
  std::map <struct UuidObject,PNEANet> UnitGraphs;
  std::map <struct UuidObject,struct ObjectMaps> UnitGraphsObjects;
  std::map <unsigned long, UuidObject> CredToUnitMap;


  /* Structures for query performance optimization */
  std::map <TInt, std::map<int,int> > AncestorCache;

  ProvenanceGraph();

  void EraseGraph();	

  int handle(int type, struct provmsg *msg);

  void Dump(FILE * file) { return Graph->Dump(file); }
  int GetNodeCount() { return Graph->GetMxNId(); };
  int GetEdgeCount() { return Graph->GetMxEId(); };
  
  int GetAncestors(uint64_t inode, uint64_t version);
  
  std::map<int,int> RecurseAncestors(int TgtId);
  void CleanAncestors(int TgtId);

  TStr GetNodeAttr(TNEANet::TNodeI Node, char const * key);
  int GetEdgeAttr(TNEANet::TEdgeI Edge, char const * key);

  char * GetNodeLabel(int type, int subtype, int NodeId);
  void DumpToDot(int TgtId, FILE * OutFd);
  void DumpToDotRecursive(int TgtId, FILE * OutFd);

  const char * GetGVShape(int type, int subtype);
  const char * GetGVFillColor(int type, int subtype);
  const char * GetGVFontColor(int type, int subtype);
	

};

#endif
