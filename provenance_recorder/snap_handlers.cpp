#include "snap_handlers.hpp"

#include "slog.h"

//#define LPM_STORAGE_OPTIMIZATION 1
//#define DUMP_TO_GRAPHVIZ 1

void exit_nicely() {
  exit(1);
}

void handle_err(char * cmd, char * err){
  fprintf(stderr, "%s command failed: %s\n", cmd,err);
  exit_nicely();
}

unsigned long  lpm_get_time()
{
	struct timeval t;
	gettimeofday(&t, NULL);
	return 1000000 * t.tv_sec + t.tv_usec;
}


char * argv_to_label(char * cstring, int len, int argc){

  int item_count = 0;
  int quote_count = 0;
  for (int n = 0; n < len; n++){
    if(cstring[n] == 0)
      item_count++;
    else if(cstring[n] == '\"' || cstring[n] == '\'')
      quote_count++;
  }

  // For argv item1\0item2\0item3="escaped quotes"\0
  // Format is '{"item1","item2","item3=\"escaped quotes\"}'
  int newlength = 2 + len + item_count * 3 + quote_count * 2;
  char * newstring = (char *)malloc(newlength);
  if(!newstring){
    printf("Out of memory\n");
    exit_nicely();
  }

  int newcursor = 0;
  int oldcursor = 0;
  while(oldcursor < len && newcursor < MAXENVLEN){
    if(cstring[oldcursor] != 0){
      // Escape quotation marks
      if(cstring[oldcursor] == '\"' || cstring[oldcursor] == '\''){
	newstring[newcursor] = '\\'; newcursor++;
	newstring[newcursor] = '\\'; newcursor++;
	cstring[oldcursor] = '\"';
      }
      // Replace non-UTF8 encoded bytes with a space
      else if (cstring[oldcursor] >= 128 || cstring[oldcursor] < 0)
	cstring[oldcursor] = ' ';

      newstring[newcursor] = cstring[oldcursor];

      //printf("(%c,%d)\n",newstring[newcursor],newstring[newcursor]);
      newcursor++;
    }
    // If we encounter a null terminator it marks a new item or EOL
    // If new item
    else if(cstring[oldcursor] == 0
	&& oldcursor < len-1) {
	argc -= 1;
	if(argc == 0){
	  newstring[newcursor] = '\0';
	  return newstring;
	}
	newstring[newcursor] = ' '; newcursor ++;
    }
    oldcursor++;
  }

  // If EOL 
  newstring[newcursor] = '\0';
  
  return newstring;  
  
}


char * print_uuid_be(uuid_be *uuid)
{
  int i,c=0;
  char * rv = (char *)malloc(37);
  for (i = 0; i < 16; i++) {
    if (i == 4 || i == 6 || i == 8 || i == 10){
      rv[c] = '-';
	    c++;
    }
    sprintf(rv+c,"%02x", uuid->b[i]);	  
    c+=2;
    
    rv[c] = (char)uuid->b[i];
    snprintf(&rv[c],1,"%02x", uuid->b[i]);
  }
  
  return rv;
}

ProvenanceGraph::ProvenanceGraph(){

  Graph = TNEANet::New();

}

void ProvenanceGraph::EraseGraph(){

  Graph = TNEANet::New();
  Objects.CredMap.clear();
  Objects.UnitMap.clear();
  CredToUnitMap.clear();
  Objects.InodeVersionMap.clear();
  Objects.ObjectMap.clear();
  Objects.UserMap.clear();
  Objects.GroupMap.clear();
  Objects.SockRecvMap.clear();
  Objects.SockSendMap.clear();

}

int ProvenanceGraph::handle(int type, struct provmsg *msg) {
  
  if(type == PROVMSG_BOOT)
    return handle_boot(msg);
  /*
  else if(type == PROVMSG_CREDFORK)
    return handle_credfork(msg);
  else if(type == PROVMSG_CREDFREE)
    return handle_credfree(msg);
  else if(type == PROVMSG_EXEC)
    return handle_exec(msg);
  else if(type == PROVMSG_FILE_P)	  
    return handle_file_p(msg);
  else if(type == PROVMSG_SETID)
    return handle_setid(msg);
  else if(type == PROVMSG_MMAP)
    return handle_mmap(msg);
  else if(type == PROVMSG_SOCKSEND)
    return handle_socksend(msg);
  else if(type == PROVMSG_SOCKRECV)
    return handle_sockrecv(msg);
  */
  else if(type == PROVMSG_SQL_READ)
    return handle_sql(msg,SNAP_RELATION_SQL_READ);
  else if(type == PROVMSG_SQL_USED)
    return handle_sql(msg,SNAP_RELATION_SQL_USED);
  else if(type == PROVMSG_UNIT_START)
    return handle_unit_start(msg);
  else if(type == PROVMSG_UNIT_END)
  return handle_unit_end(msg);
  return -1;
}

int ProvenanceGraph::GetEdgeAttr(TNEANet::TEdgeI Edge, char const * key){

  /*
  TStrV attrs,values;
  Edge.GetStrAttrNames(attrs);
  Edge.GetStrAttrVal(values);
  for(int i=0; i < attrs.Len(); i++){
    if(attrs[i] == key)
      return values[i];
  }
  */
  return Graph->GetIntAttrDatE(Edge.GetId(),TStr(key));
}

TStr ProvenanceGraph::GetNodeAttr(TNEANet::TNodeI Node, char const * key){

  TStrV attrs,values;
  Node.GetStrAttrNames(attrs);
  Node.GetStrAttrVal(values);
  for(int i=0; i < attrs.Len(); i++){
    if(attrs[i] == key)
      return values[i];
  }
  return TStr("");
}

void ProvenanceGraph::DumpToDotRecursive(int TgtId, FILE * OutFd){

  TNEANet::TNodeI tgt = Graph->GetNI(TgtId);
  TNEANet::TEdgeI Edge;
  TInt EdgeId;
  TStrV attrs,values;
  TNEANet::TNodeI TargetNode = Graph->GetNI(TgtId);
  std::map<int,int> ancestors;

  int type, subtype;
  type = Graph->GetIntAttrDatN(TgtId,"type");
  subtype = Graph->GetIntAttrDatN(TgtId,"subtype");

  int fontsize = 40;
  char * style = "filled,setlinewidth(5)";
  char * label;

  label = GetNodeLabel(type,subtype,TgtId);

  printf("Handling Node %d of type %s and subtype %s, label is %s\n",TgtId,resolve(type),resolve(subtype),label);

  fprintf(OutFd,"node%d[label=\"%s\",shape=\"%s\",fillcolor=\"%s\",fontcolor=\"%s\",fontsize=\"%d\",style=\"%s\"];\n",
	  TgtId,
	  label,
	  GetGvShape(type,subtype),
	  GetGvFillColor(type,subtype),
	  GetGvFontColor(type,subtype),
	  fontsize,
	  style);

  free(label);
	  
  // Delete Information on Outgoing Edges
  /*
  for(int i=0; i<TargetNode.GetOutDeg(); i++){		  
	  EdgeId = TargetNode.GetOutEId(i);		  
  */
  for(int i=0; i<TargetNode.GetInDeg(); i++){		  
	  EdgeId = TargetNode.GetInEId(i);		  
	  Edge = Graph->GetEI(EdgeId);

	  //DumpToDotRecursive(e.DstId,OutFd);
	  DumpToDotRecursive(Edge.GetSrcNId(),OutFd);
	  
	  type = Graph->GetIntAttrDatE(EdgeId,"rel");
	  
	  fprintf(OutFd,"node%d -> node%d ",Edge.GetSrcNId(),Edge.GetDstNId());
	  fprintf(OutFd,"[ label=\"%s\",fontsize=\"%d\",color=\"%s\",",resolve(type),
		  fontsize,GetGvFillColor(type,subtype));
	  fprintf(OutFd, "weight=1,penwidth=8,arrowsize=2,fontcolor=\"%s\"];\n",GetGvFontColor(type,subtype));
  }

}

void ProvenanceGraph::DumpToDot(int TgtId, FILE * OutFd){

	/* Debug code to print graph structure */
	printf("Graph (%d, %d)\n", Graph->GetNodes(), Graph->GetEdges());
	for (PNEANet::TObj::TNodeI NI = Graph->BegNI(); NI < Graph->EndNI(); NI++) {
		printf("  %d --> ", NI.GetId());
		for(int e=0; e<NI.GetOutDeg(); e++)
			printf(" %d", NI.GetNbrNId(e));
		printf("\n");
	}

	fprintf(OutFd,"digraph test {\n");
	fprintf(OutFd,"graph[size=\"11,8.5\",dpi=900,center=\"true\",nodesep=\"0.25\",ranksep=\"2\",fontname=\"Helvetica-Bold\",outputorder=edgesfirst];\n");
	fprintf(OutFd,"node [fontname = \"Helvetica-Bold\", border=\"0\"];\n");
	fprintf(OutFd,"edge [fontname = \"Helvetica-Bold\"];\n");
	fprintf(OutFd,"margin=\"0\";\n");
	fprintf(OutFd,"center=true;\n");
	fprintf(OutFd,"rankdir=\"BT\";\n");
	fprintf(OutFd,"pagedir=\"TL\";\n");
	fprintf(OutFd,"bgcolor=\"#FFFFFF\";\n");
	fprintf(OutFd,"orientation=\"portrait\";\n");
	fprintf(OutFd,"\n");
	fprintf(OutFd," \n");
	fprintf(OutFd,"\n");

	DumpToDotRecursive(TgtId,OutFd);

	fprintf(OutFd,"}\n");

}

char * ProvenanceGraph::GetNodeLabel(int type, int subtype, int NodeId) {

  int label_len=40;
  char * label = (char *)malloc(label_len);
  switch (type) {
  case SNAP_TYPE_ACTIVITY:
	  //printf("Label is %s, ID is %d\n",Graph->GetStrAttrDatN(NodeId,"label").CStr(),Graph->GetIntAttrDatN(NodeId,"id"));
	  if(Graph->GetStrAttrDatN(NodeId,"label").Len() > 0){
		  snprintf(label,label_len,"%s",Graph->GetStrAttrDatN(NodeId,"label").CStr());
	  }
	  else
		  snprintf(label,label_len,"%lu",Graph->GetIntAttrDatN(NodeId,"id"));
	  break;
  case SNAP_TYPE_ENTITY:
	  switch(subtype){
	  case SNAP_SUBTYPE_INODE:
		  snprintf(label,label_len,"%lu:%lu",
			   Graph->GetIntAttrDatN(NodeId,"inode"),
			   Graph->GetIntAttrDatN(NodeId,"version"));
		  break;
	  case SNAP_SUBTYPE_SQL_OBJECT:
		  snprintf(label,label_len,"%s", Graph->GetStrAttrDatN(NodeId,"name").CStr());
		  break;
	  }

  case SNAP_TYPE_AGENT:
	  switch(subtype){	  
	  case SNAP_SUBTYPE_REMOTE_HOST:
		  snprintf(label,label_len,"%s", Graph->GetStrAttrDatN(NodeId,"name").CStr());
		  break;
	  case SNAP_SUBTYPE_USER:
		  snprintf(label,label_len,"%d", Graph->GetIntAttrDatN(NodeId,"uid"));
		  break;
	  }

  }
  return label;

}


void ProvenanceGraph::DumpNode(int TgtId){

  TNEANet::TEdgeI Edge;
  int EdgeId;
  TStrV attrs, values;
  TIntV valueI;
  TNEANet::TNodeI TargetNode = Graph->GetNI(TgtId);
      
  printf("Node %d has %d incoming edges and %d outgoing edges\n",
	 TgtId, TargetNode.GetInDeg(),TargetNode.GetOutDeg());

  TargetNode.GetAttrNames(attrs); 
  TargetNode.GetAttrVal(values); 
  for(int i=0; i < attrs.Len(); i++){
    printf("\t%s: %s\n",attrs[i].CStr(),values[i].CStr());
  }
      
  for(int i=0; i<TargetNode.GetInDeg(); i++){
    EdgeId = TargetNode.GetInEId(i);
    printf("\tEID=%d\n",EdgeId);
    Edge = Graph->GetEI(EdgeId);
    printf("\t\t%d -> %d\n",Edge.GetSrcNId(),Edge.GetDstNId());
    
    Edge.GetAttrNames(attrs); 
    Edge.GetIntAttrVal(valueI); 
    for(int i=0; i < attrs.Len(); i++){
      printf("\t\t\t%s: %d\n",attrs[i].CStr(),valueI[i].Val);
    }
  }
  
  for(int i=0; i<TargetNode.GetOutDeg(); i++){
    EdgeId = TargetNode.GetOutEId(i);
    printf("\tEID=%d\n",EdgeId);
    Edge = Graph->GetEI(EdgeId);
    printf("\t%d -> %d\n",Edge.GetSrcNId(),Edge.GetDstNId());
    
    Edge.GetAttrNames(attrs); 
    Edge.GetIntAttrVal(valueI); 
    for(int i=0; i < attrs.Len(); i++){
      printf("\t\t\t%s: %d\n",attrs[i].CStr(),valueI[i].Val);
    }
  }

  return;


  
}
 
std::map<int,int> ProvenanceGraph::RecurseAncestors(int TgtId) {

  TNEANet::TNodeI tgt = Graph->GetNI(TgtId);
  TNEANet::TEdgeI Edge;
  TInt EdgeId;
  TStrV attrs,values;
  std::map<int,int> ancestors;

  /* Check to see if this node already has a cache entry */
  if (ANCESTOR_CACHE && AncestorCache.find(TgtId) != AncestorCache.end() ) { 
    /* We have already traversed this subgraph.
       Copy results into current ancestor list and return */
    for (std::map<int,int>::iterator it=AncestorCache[TgtId].begin();
	 it!=AncestorCache[TgtId].end(); ++it) 
	  ancestors[it->first] = 0;
  }
  /* Add self to ancestor list if an inode and recurse "WasGeneratedBy" */  
  else {
    ancestors[TgtId] = 0;  

    for(int i=0; i < tgt.GetOutDeg(); i++) {
      EdgeId = tgt.GetOutEId(i);
      Edge = Graph->GetEI(EdgeId);
      
      std::map<int,int> subancestors = RecurseAncestors(Edge.GetDstNId());

      for (std::map<int,int>::iterator it=subancestors.begin();
	   it!=subancestors.end(); ++it) 
	      ancestors[it->first] = 0;

    }

    if(ANCESTOR_CACHE)
      AncestorCache[TgtId] = ancestors;
  }

  return ancestors;

}

/* Use this function to get INODE ANCESTORS ONLY */
int ProvenanceGraph::GetAncestors(uint64_t inode, uint64_t version){

  struct InodeVersion IvKey;
  IvKey.inode = inode;
  IvKey.version = version;

  int TgtId = get_or_create_node(Graph, Objects, SNAP_TYPE_ENTITY,SNAP_SUBTYPE_INODE, (void *) &IvKey);

  std::map<int,int> ancestors = RecurseAncestors(TgtId);

  return 0;
}

int ProvenanceGraph::get_or_create_node(PNEANet & CurrGraph, struct ObjectMaps & CurrObjects, int type, int subtype, void * key){

  TInt NodeId = -1;
  switch (type) {
    
  case SNAP_TYPE_ACTIVITY:{
	  switch(subtype){
	  case SNAP_SUBTYPE_UNIT: {
		  if ( CurrObjects.UnitMap.find(*(UuidObject*)key) != CurrObjects.UnitMap.end() ){
			  NodeId = CurrObjects.UnitMap[*(UuidObject*)key];      
		  }
		  else{
			  NodeId = Graph->AddNode(Graph->GetMxNId());			  
			  Graph->AddIntAttrDatN(NodeId,(*(UuidObject*)key).cred_id,"id");
			  Graph->AddStrAttrDatN(NodeId,"","label");
			  Graph->AddIntAttrDatN(NodeId,type,"type");
			  Graph->AddIntAttrDatN(NodeId,subtype,"subtype");
			  CurrObjects.UnitMap[*(UuidObject*)key] = NodeId;
			  CredToUnitMap[(*(UuidObject*)key).cred_id] = (*(UuidObject*)key);
		  }
		  break;
	  }
	  default:{
		  if ( Objects.CredMap.find(*(TInt*)key) != Objects.CredMap.end() )
			  NodeId = Objects.CredMap[*(TInt*)key];      
		  else{
			  NodeId = Graph->AddNode(Graph->GetMxNId());
			  Graph->AddIntAttrDatN(NodeId,*(TInt*)key,"id");
			  Graph->AddStrAttrDatN(NodeId,"","label");
			  Graph->AddIntAttrDatN(NodeId,type,"type");
			  Graph->AddIntAttrDatN(NodeId,subtype,"subtype");
			  Objects.CredMap[*(TInt*)key] = NodeId;
		  }
		  break;
	  }
	  }
  }

  case SNAP_TYPE_ENTITY:{  
	  switch(subtype){
	  case SNAP_SUBTYPE_INODE:{
		  InodeVersion iv = *(InodeVersion*)key;
		  if ( Objects.InodeVersionMap.find(iv) != Objects.InodeVersionMap.end() )
			  NodeId = Objects.InodeVersionMap[iv];      
		  else {
			  NodeId = Graph->AddNode(Graph->GetMxNId());
			  Graph->AddFltAttrDatN(NodeId,iv.inode,"inode");
			  Graph->AddFltAttrDatN(NodeId,iv.version,"version");
			  Graph->AddIntAttrDatN(NodeId,SNAP_TYPE_ENTITY,"type");
			  Graph->AddIntAttrDatN(NodeId,SNAP_SUBTYPE_INODE,"subtype");
			  Objects.InodeVersionMap[*(InodeVersion*)key] = NodeId;
		  }
		  break;
	  }
		  
	  case SNAP_SUBTYPE_SQL_OBJECT:{
		  Object so = *(Object*)key;
		  if ( Objects.ObjectMap.find(so) != Objects.ObjectMap.end() ){
			  NodeId = Objects.ObjectMap[so];      
		  }
		  else {
			  NodeId = Graph->AddNode(Graph->GetMxNId());
			  Graph->AddStrAttrDatN(NodeId,so.name,"name");
			  Graph->AddIntAttrDatN(NodeId,type,"type");
			  Graph->AddIntAttrDatN(NodeId,subtype,"subtype");
			  Objects.ObjectMap[*(Object*)key] = NodeId;
		  }
		  break;
	  }
	  }
  }
  case SNAP_TYPE_AGENT: {
	  switch(subtype){	  
	  case SNAP_SUBTYPE_REMOTE_HOST:{
		  Object so = *(Object*)key;
		  if ( Objects.ObjectMap.find(so) != Objects.ObjectMap.end() )
			  NodeId = Objects.ObjectMap[so];      
		  else {
			  NodeId = Graph->AddNode(Graph->GetMxNId());
			  Graph->AddStrAttrDatN(NodeId,so.name,"name");
			  Graph->AddIntAttrDatN(NodeId,type,"type");
			  Graph->AddIntAttrDatN(NodeId,subtype,"subtype");
			  Objects.ObjectMap[*(Object*)key] = NodeId;
		  }
		  break;
	  }
	  case SNAP_SUBTYPE_USER:{
		  User user = *(User*)key;
		  if ( Objects.UserMap.find(user) != Objects.UserMap.end() )
			  NodeId = Objects.UserMap[user];      
		  else {
			  NodeId = Graph->AddNode(Graph->GetMxNId());
			  Graph->AddIntAttrDatN(NodeId,user.uid,"uid");
			  Graph->AddIntAttrDatN(NodeId,user.suid,"suid");
			  Graph->AddIntAttrDatN(NodeId,user.euid,"euid");
			  Graph->AddIntAttrDatN(NodeId,user.fsuid,"fsuid");
			  Graph->AddIntAttrDatN(NodeId,SNAP_TYPE_AGENT,"type");
			  Graph->AddIntAttrDatN(NodeId,SNAP_SUBTYPE_USER,"subtype");
			  Objects.UserMap[*(User*)key] = NodeId;
		  }
				  break;
	  }
	  }
  }
  }

  return NodeId;

}

int ProvenanceGraph::get_edge(PNEANet & CurrGraph, int SrcId, int DstId) {

  TNEANet::TEdgeI Edge;
    
  for(int i=0; i< Graph->GetEdges(); i++){
    Edge = Graph->GetEI(i);
    if(Edge.GetSrcNId() == SrcId
       && Edge.GetDstNId() == DstId)
      return i;
  }

  return -1;

}

int ProvenanceGraph::create_edge(PNEANet & CurrGraph, int SrcId, int DstId, int rel) {

  int EdgeId = Graph->AddEdge(SrcId,DstId,Graph->GetMxEId());
  Graph->AddIntAttrDatE(EdgeId,rel,"rel");

  return EdgeId;

}

int ProvenanceGraph::get_or_create_edge(PNEANet & CurrGraph, int SrcId, int DstId, int rel) {

  /* Check to see if the edge already exists */
  /* Only create new if edge does not already exist */ 
  if( SrcId == DstId )
    return -1;

  int EdgeId = get_edge(CurrGraph,SrcId,DstId);

  /* Only create new if edge does not already exist */
  if(EdgeId < 0) 
    EdgeId = create_edge(CurrGraph, SrcId,DstId,rel);

  return EdgeId;

}

int ProvenanceGraph::handle_boot(struct provmsg *msg){

  struct provmsg_boot *m = (struct provmsg_boot *) msg;
 
  /* Extract the uuid into a string */
  //char * uuid = print_uuid_be(&m->uuid);

  /* Create new Cred Node */
  int BootId = get_or_create_node(Graph, Objects, SNAP_TYPE_ACTIVITY,SNAP_SUBTYPE_BOOT,(void *) &m->msg.cred_id);
  //Graph->AddStrAttrDatN(BootId,uuid,"uuid");

  Objects.CredMap[m->msg.cred_id] = BootId;

  return 0;
}

int ProvenanceGraph::handle_credfork(struct provmsg *msg) {

  struct provmsg_credfork *m = (struct provmsg_credfork *) msg;

  int NewForkId, OldForkId, EdgeId;

  /* Get parent Cred Node */
  OldForkId = get_or_create_node(Graph, Objects, SNAP_TYPE_ACTIVITY,SNAP_SUBTYPE_FORK,(void *) &m->msg.cred_id);

  /* Create new child Cred Node */
  NewForkId = get_or_create_node(Graph, Objects, SNAP_TYPE_ACTIVITY,SNAP_SUBTYPE_FORK,(void *) &m->forked_cred);
  Graph->AddIntAttrDatN(NewForkId,m->msg.cred_id,"parentid");

  slog(SLOG_LIVE,SLOG_LIVE,"[%d/%d] credfork [%d/%d]",m->msg.cred_id,OldForkId,m->forked_cred,NewForkId);

  EdgeId = get_or_create_edge(Graph, NewForkId,OldForkId,SNAP_RELATION_WASFORKEDFROM);

  return 0;

}

int ProvenanceGraph::handle_exec(struct provmsg *msg){

  struct provmsg_exec *m = (struct provmsg_exec *) msg;

  /* Extract the uuid into a string */
  //char * uuid = print_uuid_be(&m->inode.sb_uuid);
  char * new_label =  argv_to_label(m->argv_envp, msg_getlen(msg) - sizeof(*m),m->argc);

  TInt cred_id = m->msg.cred_id;

  TInt ForkId = get_or_create_node(Graph, Objects, SNAP_TYPE_ACTIVITY,SNAP_SUBTYPE_FORK, (void *) &cred_id);

  /* Get previous Id, if any */
  TStr label = TStr("");//Graph->GetStrAttrDatN(ForkId,"label");

  /* Update label if one already exists */

  if(strlen(label.CStr()) > 0)
    label = label + "\n" + new_label;
  else
    label = new_label;

  Graph->AddStrAttrDatN(ForkId,label,"label");

  slog(SLOG_DEBUG,SLOG_DEBUG,"%s: [%lu] exec %s",__func__,m->msg.cred_id,Graph->GetStrAttrDatN(ForkId,"label").CStr());

  /* Note: Right now this actually overwrites old information
     if multiple processes are launched in the same fork */
  Graph->AddIntAttrDatN(ForkId,m->inode.ino,"inode");
  Graph->AddIntAttrDatN(ForkId,m->inode.version,"version");
  //Graph->AddStrAttrDatN(ForkId,uuid,"uuid");

  //free(uuid);
  free(new_label);

  return 0;

}

int ProvenanceGraph::handle_file_p(struct provmsg *msg){

  struct provmsg_file_p *m = (struct provmsg_file_p *) msg;
  TInt InodeVersionId;

  /* Basically just ignoring "May Execute" */
  if (!(m->mask & MAY_READ) &&
      !(m->mask & MAY_WRITE) &&
      !(m->mask & MAY_APPEND) )
    return 0;

  /* Extract the uuid into a string */
  //char * uuid = print_uuid_be(&m->inode.sb_uuid);

  /* Lookup the InodeVersion node */
  struct InodeVersion iv;
  iv.inode = m->inode.ino;
  iv.version = m->inode.version;

  InodeVersionId = get_or_create_node(Graph, Objects, SNAP_TYPE_ENTITY,
				      SNAP_SUBTYPE_INODE,
				      (InodeVersion *)&iv);

  //Graph->AddStrAttrDatN(InodeVersionId,uuid,"uuid");

  /* Get the Cred node  */
  TInt CredId = Objects.CredMap[m->msg.cred_id];

  TInt EdgeId;
  /* If a write/append */
  if ( (m->mask & MAY_WRITE) ||
       (m->mask & MAY_APPEND) ) {
    EdgeId = get_or_create_edge(Graph, InodeVersionId,CredId,SNAP_RELATION_WASGENERATEDBY);

    /* Pre-compute ancestors for the new node */
    if(ANCESTOR_CACHE)
      RecurseAncestors(InodeVersionId);

  }

  /* If a read */
  /* Check to see if there already exists a write node between these two nodes */
  /* If so, do not create this read relationship because doing so would create */
  /* a cycle. If you have written to the file your knowledge of its contents */
  /* is implied */
  if ( m->mask & MAY_READ && get_edge(Graph, InodeVersionId,CredId) < 0 ){
    EdgeId = get_or_create_edge(Graph, CredId,InodeVersionId,SNAP_RELATION_USED);
  }
  return 0;
}

int ProvenanceGraph::handle_credfree(struct provmsg *msg){

  struct provmsg_credfork *m = (struct provmsg_credfork *) msg;

  /* I guess if we see a credfree it is safe to remove it from the map! */
  Objects.CredMap.erase (m->msg.cred_id);

  return 0;

}

int ProvenanceGraph::handle_setid(struct provmsg *msg){

  struct provmsg_setid *m = (struct provmsg_setid *) msg;

  TInt CredId = get_or_create_node(Graph, Objects, SNAP_TYPE_ACTIVITY,SNAP_SUBTYPE_FORK,(TInt *)&m->msg.cred_id);

  /* Create user / group keys */
  struct User user;
  user.uid = m->uid;
  user.suid = m->suid;
  user.euid = m->euid;
  user.fsuid = m->fsuid;

  struct Group group;
  group.gid = m->gid;
  group.sgid = m->sgid;
  group.egid = m->egid;
  group.fsgid = m->fsgid;
  
  /* If user does not already exist, create */
  TInt UserId = get_or_create_node(Graph, Objects, SNAP_TYPE_AGENT,
				   SNAP_SUBTYPE_USER,
				   (User *)&user);

  /* If group does not already exist, create */
  TInt GroupId;
  if ( Objects.GroupMap.find(group) == Objects.GroupMap.end() ){
    GroupId = Graph->AddNode(Graph->GetMxNId());
    
    Graph->AddIntAttrDatN(GroupId,m->uid,"uid");
    Graph->AddIntAttrDatN(GroupId,m->suid,"suid");
    Graph->AddIntAttrDatN(GroupId,m->euid,"euid");
    Graph->AddIntAttrDatN(GroupId,m->fsuid,"fsuid");
    Graph->AddIntAttrDatN(GroupId,SNAP_TYPE_AGENT,"type");
    Graph->AddIntAttrDatN(GroupId,SNAP_SUBTYPE_GROUP,"subtype");

    Objects.GroupMap[group] = GroupId;
  }
  else
    GroupId = Objects.GroupMap[group];

  TInt UserEdgeId,GroupEdgeId;
  /* If setId was previously called for the cred, we have to conservatively
     assume that both ID's are responsbile. So adding multiple User Nodes for
     a single cred is ok */
  UserEdgeId = get_or_create_edge(Graph, CredId,UserId,SNAP_RELATION_WASCONTROLLEDBY);

  /* If setId was previously called for the cred, we have to conservatively
     assume that both ID's are responsbile. So adding multiple Group Nodes for
     a single cred is ok */

  /* .... But only create this relationship if it doesn't already exist */
  GroupEdgeId = get_or_create_edge(Graph, UserId,GroupId,SNAP_RELATION_ACTEDONBEHALFOF);

  return 0;

}

int ProvenanceGraph::handle_socksend(struct provmsg *msg){

  struct provmsg_socksend *m = (struct provmsg_socksend *) msg;
  struct sockaddr * addr = (struct sockaddr *) &m->addr; 

  struct CredIpPort cip;

  /* Extract the uuid into a string */
  //char * uuid = print_uuid_be(&m->inode.sb_uuid);

  /* Case 1: Address is type IPv4 */
  if(addr->sa_family == AF_INET && m->addr_len > 0){

    cip.cred_id = m->msg.cred_id;
    cip.port = ((struct sockaddr_in *)addr)->sin_port;
    cip.ip_address = inet_ntoa(((struct sockaddr_in *)addr)->sin_addr);

    printf("[%d] %s %s:%d\n",cip.cred_id,__func__,cip.ip_address,cip.port);

    TInt CredIpPortId;
    if ( Objects.SockSendMap.find(cip) == Objects.SockSendMap.end() ){
      CredIpPortId = Graph->AddNode(Graph->GetMxNId());
      Graph->AddStrAttrDatN(CredIpPortId,cip.ip_address,"ip_address");
      Graph->AddFltAttrDatN(CredIpPortId,cip.port,"port");
      Graph->AddIntAttrDatN(CredIpPortId,m->protocol,"protocol");
      Graph->AddIntAttrDatN(CredIpPortId,m->protocol,"family");
      Graph->AddIntAttrDatN(CredIpPortId,SNAP_TYPE_ENTITY,"type");
      Graph->AddIntAttrDatN(CredIpPortId,SNAP_SUBTYPE_PACKET,"subtype");

      /* Update map if new CredIpPort Node was created */
      Objects.SockSendMap[cip] = CredIpPortId;
    }
    else
      CredIpPortId = Objects.SockSendMap[cip];

    /* Get the Cred node */
    TInt CredId = Objects.CredMap[m->msg.cred_id];
    
    TInt EdgeId = get_or_create_edge(Graph, CredIpPortId,CredId,SNAP_RELATION_WASGENERATEDBY);

  }
  /* Case 2: Address is type IPv6 */
  else if(addr->sa_family == AF_INET6 && m->addr_len > 0){
  }

  return 0;
}

/* DOES NOT WORK RIGHT NOW */
int ProvenanceGraph::handle_sockrecv(struct provmsg *msg){

  struct provmsg_sockrecv *m = (struct provmsg_sockrecv *) msg;
  struct sockaddr * addr = (struct sockaddr *) &m->addr; 

  struct CredIpPort cip;

  /* Extract the uuid into a string */
  //char * uuid = print_uuid_be(&m->inode.sb_uuid);

  //printf("%s: Family is %d, AF_INET is %d, addr_len is %d\n",__func__,addr->sa_family,AF_INET,m->addr_len);

  /* Case 1: Address is type IPv4 */
	//changing sa_family to 0 from AF_INET
  if(addr->sa_family == 0  && m->addr_len > 0){
     cip.cred_id = m->msg.cred_id;
    cip.port = ((struct sockaddr_in *)addr)->sin_port;
    cip.ip_address = inet_ntoa(((struct sockaddr_in *)addr)->sin_addr);
    
    cip.state_generated=1;   //credIpPort for socketReceive
    printf("[%d] %s %s:%d\n",cip.cred_id,__func__,cip.ip_address,cip.port);

    TInt CredIpPortId;
    if ( Objects.SockRecvMap.find(cip) == Objects.SockRecvMap.end() ){
      CredIpPortId = Graph->AddNode(Graph->GetMxNId());
      Graph->AddStrAttrDatN(CredIpPortId,cip.ip_address,"ip_address");
      Graph->AddFltAttrDatN(CredIpPortId,cip.port,"port");
      Graph->AddIntAttrDatN(CredIpPortId,m->protocol,"protocol");
      Graph->AddIntAttrDatN(CredIpPortId,m->protocol,"family");
      Graph->AddIntAttrDatN(CredIpPortId,SNAP_TYPE_ENTITY,"type");
      Graph->AddIntAttrDatN(CredIpPortId,SNAP_SUBTYPE_PACKET,"subtype");
      
      /* Update map if new CredIpPort Node was created */
      Objects.SockRecvMap[cip] = CredIpPortId;
    }
    else
      CredIpPortId = Objects.SockRecvMap[cip];

    /* Get the Cred node */
    TInt CredId = Objects.CredMap[m->msg.cred_id];

    TInt EdgeId = get_or_create_edge(Graph, CredId,CredIpPortId,SNAP_RELATION_USED);


  }
  /* Case 2: Address is type IPv6 */
  else if(addr->sa_family == AF_INET6 && m->addr_len > 0){
  }

  return 0;
}

int ProvenanceGraph::handle_inode_p(struct provmsg *msg){

  // Step 1: Create InodeVerison object, then get or create vertex for it.
  // Step 2: Look up cred object
  // Step 3: Draw edge between InodeVersion and Cred nodes
  // Step 1: Create InodeVerison object, then get or create vertex for it.
  // Step 2: Look up cred object
  // Step 3: Draw edge between InodeVersion and Cred nodes

  struct provmsg_inode_p *m = (struct provmsg_inode_p *) msg;
  TInt InodeVersionId;

  // ignoring "may execute" following implementation of handle_file_p 
  if (!(m->mask & MAY_READ) &&
      !(m->mask & MAY_WRITE) &&
      !(m->mask & MAY_APPEND) )
    return 0;
  
  /* Lookup the InodeVersion node */
  struct InodeVersion iv;
  iv.inode = m->inode.ino;
  iv.version = m->inode.version;
  InodeVersionId = get_or_create_node(Graph, Objects, SNAP_TYPE_ENTITY,
				      SNAP_SUBTYPE_INODE,
				      (InodeVersion *)&iv);


 /* Get the Cred node  */
  TInt CredId = Objects.CredMap[m->msg.cred_id];

 TInt EdgeId;
  /* If a write/append */
  if ( (m->mask & MAY_WRITE) ||
       (m->mask & MAY_APPEND) ) {
    EdgeId = get_or_create_edge(Graph, InodeVersionId,CredId,SNAP_RELATION_WASGENERATEDBY);

    slog(SLOG_LIVE,SLOG_LIVE,"%s: %d.%d [%d] --[WasGeneratedBy]--> %lu [%d]",__func__,
	 m->inode.ino,m->inode.version,InodeVersionId,
	 m->msg.cred_id,CredId);
  }
  /* If a read */
  /* Check to see if there already exists a write node between these two nodes */
  /* If so, do not create this read relationship because doing so would create */
  /* a cycle. If you have written to the file your knowledge of its contents */
  /* is implied */
  if ( m->mask & MAY_READ && get_edge(Graph, InodeVersionId,CredId) < 0 ){
    EdgeId = get_or_create_edge(Graph, CredId,InodeVersionId,SNAP_RELATION_USED);

    slog(SLOG_LIVE,SLOG_LIVE,"%s: %lu [%d] --[Used]--> %d.%d [%d]",__func__,
	 m->msg.cred_id,CredId,
	 m->inode.ino,m->inode.version,InodeVersionId);

  }

  return 0;

}


int ProvenanceGraph::handle_mmap(struct provmsg *msg){

  struct provmsg_mmap *m = (struct provmsg_mmap *) msg;
  TInt InodeVersionId;

  /* So looking at the provenance logs, a few things never happen:
      - mmap is never invoked with just MAY_EXECUTE
      - mmap is never invoked with just MAY_READ
     mmap is always invoked as either RW or RX.
     the file on disk still isn't changed at all. Therefore,
     I think we should only care about the R permission for mmap  */
  if (!(m->prot & PROT_READ)) {
    slog(SLOG_LIVE,SLOG_LIVE,"%s: read not requested.",__func__);
    return 0;
  }

  /* Extract the uuid into a string */
  // char * uuid = print_uuid_be(&m->inode.sb_uuid);                                                                                          
  /* Lookup the InodeVersion node */
  struct InodeVersion iv;
  iv.inode = m->inode.ino;
  iv.version = m->inode.version;
  InodeVersionId = get_or_create_node(Graph, Objects, SNAP_TYPE_ENTITY,
                                      SNAP_SUBTYPE_INODE,
                                      (InodeVersion *)&iv);

  /* Get the Cred node  */
  TInt CredId = Objects.CredMap[m->msg.cred_id];

  TInt EdgeId;
  EdgeId = get_or_create_edge(Graph, CredId,InodeVersionId,SNAP_RELATION_USED);
  /*
  slog(SLOG_LIVE,SLOG_LIVE,"%s: %lu [%d] --[Used]--> %d.%d [%d]",__func__,
       m->msg.cred_id,CredId,
       m->inode.ino,m->inode.version,InodeVersionId);
  */
  return 0;
}




int ProvenanceGraph::handle_link(struct provmsg *msg){return 0;}
int ProvenanceGraph::handle_unlink(struct provmsg *msg){return 0;}
int ProvenanceGraph::handle_setattr(struct provmsg *msg){return 0;}
int ProvenanceGraph::handle_inode_alloc(struct provmsg *msg){return 0;}
int ProvenanceGraph::handle_inode_dealloc(struct provmsg *msg){return 0;}
int ProvenanceGraph::handle_sockalias(struct provmsg *msg){return 0;}
int ProvenanceGraph::handle_mqsend(struct provmsg *msg){return 0;}
int ProvenanceGraph::handle_mqrecv(struct provmsg *msg){return 0;}
int ProvenanceGraph::handle_shmat(struct provmsg *msg){return 0;}
int ProvenanceGraph::handle_readlink(struct provmsg *msg){return 0;}

int ProvenanceGraph::handle_sql(struct provmsg *msg, int relation_type) {

  struct provmsg_sql_read *m = (struct provmsg_sql_read *) msg;

  TInt TableId, ColumnId, UnitId;
  TInt UsedId,MemberOfId;

  // Get or Create Unit
  struct UuidObject uuid = CredToUnitMap[m->msg.cred_id];
  UnitId = get_or_create_node(Graph, Objects, SNAP_TYPE_ACTIVITY,
			      SNAP_SUBTYPE_UNIT,
			      (void *) &uuid);
  struct Object Table, Column;
  // New way
  int start_pos = 0;
  for (int n = 0; n < m->data_len; n++){
	  if(m->data[n] == 0){
		  int table_pos,column_pos;
		  int table_len,column_len;
		  table_pos = start_pos;
		  for(int o = start_pos; o < n; o++){
			  if(m->data[o] == '.'){
				  column_pos = o + 1;
				  table_len = o - start_pos;
				  column_len = n - o - 1;
				  m->data[o] = '\0';
				  break;
			  }				  
		  } 

		  // Get or Create Table 
		  Table.name = m->data+start_pos;
		  TableId = get_or_create_node(UnitGraphs[uuid], UnitGraphsObjects[uuid], SNAP_TYPE_ENTITY,
					       SNAP_SUBTYPE_SQL_OBJECT,
					       (void *) &Table);
		  
		  // Get or Create Column
		  
		  Column.name = m->data+column_pos;
		  
		  ColumnId = get_or_create_node(UnitGraphs[uuid], UnitGraphsObjects[uuid], SNAP_TYPE_ENTITY,
						SNAP_SUBTYPE_SQL_OBJECT,
						(void *) &Column);
		  
		  UsedId = get_or_create_edge(Graph, UnitId,ColumnId,relation_type);
		  MemberOfId = get_or_create_edge(Graph, ColumnId,TableId,SNAP_RELATION_SQL_WASMEMBEROF);
		  
		  char * relation_str;
		  if(relation_type == SNAP_RELATION_SQL_READ)
		    relation_str = "READ";
		  else if(relation_type == SNAP_RELATION_SQL_READ)
		    relation_str = "USED";

		  slog(SLOG_DEBUG,SLOG_DEBUG,"%s: [%d (nID=%d)] %s (eID=%d) %s (nID=%d), which WASMEMBEROF (eID=%d) %s (nID=%d)", 
		       __func__,
		       m->msg.cred_id,
		       UnitId,
		       relation_str,
		       UsedId,
		       Column.name.CStr(),
		       ColumnId,
		       MemberOfId,
		       Table.name.CStr(),
		       TableId);

		  if(n < (m->data_len - 1))
			  start_pos = n + 1;
	  }
  }
 
  return 0;

}

int ProvenanceGraph::handle_unit_start(struct provmsg *msg) {

  struct provmsg_unit_start *m = (struct provmsg_unit_start *) msg;

  TInt UnitId, HostId;

  struct Object Host;
  Host.name = m->id;

  
  struct UuidObject uuid;
  memcpy(&uuid.uuid,m->uuid.b,16);
  uuid.cred_id = m->msg.cred_id;

  /* Get or create new unit graph */
  if (UnitGraphs.find(uuid) == UnitGraphs.end() ) {
    UnitGraphs[uuid] = TNEANet::New();
    struct ObjectMaps UnitGraphObjects;
    UnitGraphsObjects[uuid] = UnitGraphObjects;
  }
    
  /* Get or Create Unit */
  UnitId = get_or_create_node(UnitGraphs[uuid], UnitGraphsObjects[uuid], SNAP_TYPE_ACTIVITY,
			      SNAP_SUBTYPE_UNIT,
			      (void *) & uuid);

  /* Get or Create Table */
  HostId = get_or_create_node(UnitGraphs[uuid], UnitGraphsObjects[uuid], SNAP_TYPE_AGENT,
			      SNAP_SUBTYPE_REMOTE_HOST,
			      (void *) &Host);

  
  TInt EdgeId = get_or_create_edge(UnitGraphs[uuid], UnitId,HostId,SNAP_RELATION_ACTEDONBEHALFOF);

  slog(SLOG_DEBUG,SLOG_DEBUG,"%s: [%d (nID=%d)] begin unit of work on behalf of (eID=%d) user %s (nID=%d)",
       __func__,
       m->msg.cred_id,
       UnitId,
       EdgeId,
       m->id,
       HostId);
 
}

int ProvenanceGraph::handle_unit_end(struct provmsg *msg) {

  struct provmsg_unit_end *m = (struct provmsg_unit_end *) msg;
  char benchmark_cmd[100];
  TInt UnitId;

  struct UuidObject uuid;
  memcpy(&uuid.uuid,m->uuid.b,16);
  uuid.cred_id = m->msg.cred_id;
  UnitId = 0;

  slog(SLOG_DEBUG,SLOG_DEBUG,"%s: Cleaning up work for unit %d, node id %d",
       __func__,
       m->msg.cred_id,
       UnitId);

#ifdef DUMP_TO_GRAPHVIZ
  char * uuid_str =  print_uuid_be((uuid_be *)uuid.uuid);
  char filename[50];
  snprintf(filename,50,"./dots/%s.dot",uuid_str);
  free(uuid_str);
  // draw the small graph using GraphViz                                                                                
  slog(SLOG_LIVE,SLOG_LIVE,"%s: Printing dot file for node %d to file %s",__func__,UnitId,filename);
  FILE * OutFd = fopen(filename,"w");
  DumpToDot(UnitId,OutFd);
  fclose(OutFd);
#endif

#ifdef LPM_STORAGE_OPTIMIZATION
  UnitGraphs.erase(uuid);
  UnitGraphsObjects.erase(uuid);
  CredToUnitMap.erase(uuid.cred_id);
#endif

}

