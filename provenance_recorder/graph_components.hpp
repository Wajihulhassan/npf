#ifndef GRAPH_COMPONENTS_H
#define GRAPH_COMPONENTS_H

#include "linux-mman.h"
#include "linux-fs.h"
#include "linux-shm.h" 

#include <provmon_proto.h>
#include <string.h>

/* Old PG stuff. delete after transition is complete */
#define CMDLEN 2048
#define MAXENVLEN (CMDLEN-256)

/* Enumerators for graph types (used in place of strcmp's) */
enum {
        SNAP_TYPE_ACTIVITY,
        SNAP_TYPE_ENTITY,
        SNAP_TYPE_AGENT,
	SNAP_TYPE_SELINUX,
        SNAP_SUBTYPE_BOOT,
        SNAP_SUBTYPE_FORK,
        SNAP_SUBTYPE_UNIT,
        SNAP_SUBTYPE_REMOTE_HOST,
        SNAP_SUBTYPE_INODE,
        SNAP_SUBTYPE_PACKET,
        SNAP_SUBTYPE_SQL_OBJECT,
        SNAP_SUBTYPE_USER,
        SNAP_SUBTYPE_GROUP,
	SNAP_TYPE_SELINUX_SUBJECT,
	SNAP_TYPE_SELINUX_OBJECT,
        SNAP_RELATION_WASFORKEDFROM,
        SNAP_RELATION_USED,
        SNAP_RELATION_WASGENERATEDBY,
        SNAP_RELATION_WASCONTROLLEDBY,
        SNAP_RELATION_ACTEDONBEHALFOF,
        SNAP_RELATION_WASDERIVEDFROM,
	SNAP_RELATION_SELINUX_MAY_READ,
	SNAP_RELATION_SELINUX_MAY_WRITE,	
	SNAP_RELATION_SQL_READ,	
	SNAP_RELATION_SQL_USED,
	SNAP_RELATION_SQL_WASMEMBEROF,
	NUM_SNAP_OBJECTS,
};

  /* Key for UUID, which is regretably string-based */
  struct UuidObject {
    unsigned char uuid[16];
    unsigned long cred_id;

    bool operator<(const UuidObject& uo) const
    {
	    int diff = strcmp((char*)uuid,(char*)uo.uuid);

	    if(diff < 0)
		    return true;
	    if(diff > 0)
		    return false;
	    return false;
	    /*
	    for(int i=0; i<16; i++){
		    if(uuid[i] < uo.uuid[i])
			    return true;
		    else if (uuid[i] > uo.uuid[i])
			    return false;
	    }
	    */
	    return false;
    }
  };

  /* Key for Object, which is regretably string-based */
  struct Object {
    TStr name;

    bool operator<(const Object& so) const
    {
      if (name < so.name) return true;
      if (name > so.name) return false;
      return false;
    }
  };

  /* Key for InodeVersionMap */
  struct InodeVersion {
    uint64_t inode;
    uint64_t version;

    bool operator<(const InodeVersion& iv) const
    {
      if (inode < iv.inode) return true;
      if (inode > iv.inode) return false;
      if (version < iv.version) return true;
      if (version > iv.version) return false;
      return false;
    }
  } __attribute__((packed));

  /* Key for EdgeMap */
  struct EdgePair {
    int SrcId;
    int DstId;

    bool operator<(const EdgePair& e) const
    {
      if (SrcId < e.SrcId) return true;
      if (SrcId > e.SrcId) return false;
      if (DstId < e.DstId) return true;
      if (DstId > e.DstId) return false;
      return false;
    }
  } __attribute__((packed));

  /* Key for UserMap */
  struct User {
    uint32_t uid;
    uint32_t suid;
    uint32_t euid;
    uint32_t fsuid;
    
    bool operator<(const User& u) const
    {
      if (uid < u.uid) return true;
      if (uid > u.uid) return false;
      if (suid < u.suid) return true;
      if (suid > u.suid) return false;
      if (euid < u.euid) return true;
      if (euid > u.euid) return false;
      if (fsuid < u.fsuid) return true;
      if (fsuid > u.fsuid) return false;
      return false;
    }
  } __attribute__((packed));

  struct Group {
    uint32_t gid;
    uint32_t sgid;
    uint32_t egid;
    uint32_t fsgid;
    
    bool operator<(const Group& g) const
    {
      if (gid < g.gid) return true;
      if (gid > g.gid) return false;
      if (sgid < g.sgid) return true;
      if (sgid > g.sgid) return false;
      if (egid < g.egid) return true;
      if (egid > g.egid) return false;
      if (fsgid < g.fsgid) return true;
      if (fsgid > g.fsgid) return false;
      return false;
    }
  } __attribute__((packed));

  /* Key for CredIpPortMap */
  struct CredIpPort {
    unsigned long cred_id;
    uint16_t port;
    char * ip_address;

    // we are planning to keep two state of same CredIpPort, one for SockeSend  and another for SocketReceive.
    //state_generated=0 means created during socketSend 
    //state_generated=1 means created during socketReceive
    int state_generated;

    bool operator<(const CredIpPort & cip) const
    {
      if (cred_id < cip.cred_id) return true;
      if (cred_id > cip.cred_id) return false;
      if (port < cip.port) return true;
      if (port > cip.port) return false;
      if (strcmp(ip_address,cip.ip_address) < 0) return true;
      if (strcmp(ip_address,cip.ip_address) > 0) return false;
      if (state_generated < cip.state_generated) return true;
      if (state_generated > cip.state_generated) return false;      
      return false;
    }
  };

static const char * resolve(int type){

	switch(type){
        case SNAP_TYPE_ACTIVITY:
		return "ACTIVITY";
        case SNAP_TYPE_ENTITY:
		return "ENTITY";
        case SNAP_TYPE_AGENT:
		return "AGENT";
	case SNAP_TYPE_SELINUX:
		return "SELINUX";
	case SNAP_SUBTYPE_BOOT:
		return "BOOT";
	case SNAP_SUBTYPE_FORK:
		return "FORK";
	case SNAP_SUBTYPE_UNIT:
		return "UNIT";
	case SNAP_SUBTYPE_REMOTE_HOST:
		return "REMOTE_HOST";
	case SNAP_SUBTYPE_INODE:
		return "INODE";
	case SNAP_SUBTYPE_PACKET:
		return "PACKET";
	case SNAP_SUBTYPE_SQL_OBJECT:
		return "SQL_OBJECT";
	case SNAP_SUBTYPE_USER:
		return "USER";
	case SNAP_SUBTYPE_GROUP:
		return "GROUP";
	case SNAP_TYPE_SELINUX_SUBJECT:
		return "SELINUX_SUBJECT";
	case SNAP_TYPE_SELINUX_OBJECT:
		return "SELINUX_OBJECT";
	case SNAP_RELATION_WASFORKEDFROM:
		return "WASFORKEDFROM";
	case SNAP_RELATION_USED:
		return "USED";
	case SNAP_RELATION_WASGENERATEDBY:
		return "WASGENERATEDBY";
	case SNAP_RELATION_WASCONTROLLEDBY:
		return "WASCONTROLLEDBY";
	case SNAP_RELATION_ACTEDONBEHALFOF:
		return "ACTEDONBEHALFOF";
	case SNAP_RELATION_WASDERIVEDFROM:
		return "WASDERIVEDFROM";
	case SNAP_RELATION_SQL_READ:
		return "SQL_READ";
	case SNAP_RELATION_SQL_USED:
		return "SQL_USED";
	case SNAP_RELATION_SQL_WASMEMBEROF:
		return "SQL_WASMEMBEROF";		
        default:
		printf("Unknown type %d\n",type);
	        return "";
	}

}

static const char * GetGvShape(int type, int subtype){
	switch(type){
        case SNAP_TYPE_ACTIVITY:
		return "rectangle";
        case SNAP_TYPE_ENTITY:
		return "ellipse";
        case SNAP_TYPE_AGENT:
		return "octagon";
	}
	return "";
}

static const char * GetGvFillColor(int type, int subtype){
	switch(type){
        case SNAP_TYPE_ACTIVITY:
		return "#8DD5DE";
        case SNAP_TYPE_ENTITY:
		return "#FFF976";
        case SNAP_TYPE_AGENT:
		return "#F596B1";
	case SNAP_RELATION_WASFORKEDFROM:
		return "purple";
	case SNAP_RELATION_USED:
		return "#00FF00";
	case SNAP_RELATION_WASGENERATEDBY:
		return "#FFD900";
	case SNAP_RELATION_WASCONTROLLEDBY:
		return "purple";
	case SNAP_RELATION_ACTEDONBEHALFOF:
		return "purple";
	case SNAP_RELATION_WASDERIVEDFROM:
		return "#FFD900";
	case SNAP_RELATION_SQL_READ:
		return "#00FF00";
	case SNAP_RELATION_SQL_USED:
		return "#00FF00";
	case SNAP_RELATION_SQL_WASMEMBEROF:
		return "#00FF00";
	}
	return "";
}

static const char * GetGvFontColor(int type, int subtype){
	switch(type){
        case SNAP_TYPE_ACTIVITY:
		return "black";
        case SNAP_TYPE_ENTITY:
		return "black";
        case SNAP_TYPE_AGENT:
		return "black";
	case SNAP_RELATION_WASFORKEDFROM:
		return "black";
	case SNAP_RELATION_USED:
		return "black";
	case SNAP_RELATION_WASGENERATEDBY:
		return "black";
	case SNAP_RELATION_WASCONTROLLEDBY:
		return "black";
	case SNAP_RELATION_ACTEDONBEHALFOF:
		return "black";
	case SNAP_RELATION_WASDERIVEDFROM:
		return "black";
	case SNAP_RELATION_SQL_READ:
		return "black";
	case SNAP_RELATION_SQL_USED:
		return "black";
	case SNAP_RELATION_SQL_WASMEMBEROF:
		return "black";
		
	}
}

struct ObjectMaps{
  std::map <unsigned long,TInt> CredMap;
  std::map <InodeVersion,TInt> InodeVersionMap;
  std::map <Object,TInt> ObjectMap;
  std::map <User,TInt> UserMap;
  std::map <Group,TInt> GroupMap;
  std::map <CredIpPort,TInt> SockRecvMap;
  std::map <CredIpPort,TInt> SockSendMap;
  std::map <struct UuidObject,TInt> UnitMap;
};

#endif




