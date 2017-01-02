
#include "format.h"

void get_names_list(void *lst,list * names){

    list * l = (list *) lst;
    if (!l) return;
    if (listLength(l) == 0) return ;

    listIter *iter = NULL;
    listNode *node = NULL;
    iter = listGetIterator(l, AL_START_HEAD); 
    while ((node = listNext(iter)) != NULL) {
        Item *i = (Item *)listNodeValue(node);
        get_names_rec(i,names);
    }
    listReleaseIterator(iter);

}

void get_names_rec(void *item, list * names) {


  Item * i = (Item *) item;
  if(!i) {
      return;

  }
  else{
	  //printf("L:%p, R:%p, %d\n",i->left, i->right, i->token1 == CASE && i->next);

    if(i->token1 == NAME){
      int len;
      listAddNodeTail(names,i);
    }

    /* Handle i->left. This always appears to be a normal field or null, never a list */
    if (i->left) 
      get_names_rec(i->left,names);

    /* For CASE only, might need to pop items in this i->next field:*/
    if( i->token1 == CASE && i->next)
      get_names_list(i->next,names);    
    
    /* Handle i-> right. All cases in print_expr boil down to this: */
    if (i->right)
      if((i->token1 > FSTART) 
	 && (i->token1 < FEND)
	 && (i->token2 != UNIQUE) )
	get_names_list(i->right,names);
      else
	get_names_rec(i->right,names);
  }

}

char * prepare_columns_accessed(list * columns_read, int * data_len){ 

  listIter *iter = NULL;
  listNode *node = NULL;
  int data_len_local = 0;

  // First pass just for counting string length

  iter = listGetIterator(columns_read, AL_START_HEAD); 

  while ((node = listNext(iter)) != NULL){
    Item * i = (Item*)listNodeValue(node);

    data_len_local += strlen(i->prefix);
    data_len_local += 2; //for the '.' and the '\0'
    data_len_local += strlen(i->name);

  }
  listReleaseIterator(iter);

  // Second pass to pack it all in
  char * data = malloc(data_len_local);
  int offset = 0, curr_size = 0;
  iter = listGetIterator(columns_read, AL_START_HEAD); 

  while ((node = listNext(iter)) != NULL){
    Item * i = (Item*)listNodeValue(node);

    curr_size = strlen(i->prefix) + 2 + strlen(i->name);
    snprintf(data + offset,curr_size,"%s.%s\0",i->prefix,i->name);
    offset += curr_size;

  }
  listReleaseIterator(iter);

  *data_len = data_len_local;
  return data;

}

int parse_stmt(Stmt * st, int proc_id){

  if (!st){
    printf("SQL parse failed\n");
    return -1;
  }

  //  printf("\nFinal Report\n");
  //  printf("\tColumns Read\n");
  int data_len = 0;

  // Get Names
  list * columns_read = listCreate();
  get_names_list(st->select_expr_list,columns_read);
  char * data = prepare_columns_accessed(columns_read, &data_len);
  provenance_disclose_read(proc_id,data,data_len);
  free(data);


  // Get Names
  list * columns_used = listCreate();
  get_names_list(st->whereList,columns_used);
  data = prepare_columns_accessed(columns_used, &data_len);
  provenance_disclose_used(proc_id,data,data_len);
  free(data);

}

int _parse(int proc_id){

  int rv, i,success=0, failure=0;
  unsigned long time_to_parse, time_to_prov;    
  char benchmark_cmd[100];

  /* Record elapsed time */
  time_to_parse = lpm_get_time();
  rv = yyparse();
  /* printf("%s:\t\t return value was %d\n",__func__,rv); */
  time_to_parse = lpm_get_time() - time_to_parse;
  
  snprintf(benchmark_cmd,100,"echo %lu >> /tmp/lpm_benchmark_proxy_parse_musec.txt",time_to_parse);
  system(benchmark_cmd);

  for (i = 0; i < indexArray; i++) {
	  Stmt *st = stmtArray[i];
	  if (st == NULL)
		  failure++;
	  else {
		  success++;
		  /* Record elapsed time */
		  time_to_prov = lpm_get_time();
		  parse_stmt(st, proc_id);
		  time_to_prov = lpm_get_time() - time_to_prov;
		  snprintf(benchmark_cmd,100,"echo %lu >> /tmp/lpm_benchmark_proxy_prov_musec.txt",time_to_prov);
		  system(benchmark_cmd);
	  }
  }
  
  /* Clean up parsed statements */
  for(i = indexArray-1; i >= 0; i--) {
    free(stmtArray[i]);
    indexArray--;
  }

  return rv;

}

int push_buffer_array(char * buffer, int proc_id){

  yypush_buffer_state( yy_scan_string(buffer) );
  return _parse(proc_id);  

}

int chomp(char *s, int bytes)
{
	int i;
	while(i < bytes){
		if(s[i] == '\n'){
			s[i] = '\0';
			return i;
		}
		i++;
	}
	return i;
} /* chomp */

int push_buffer_stdin(int ac, char **av)
{
  
    printf( "Type an expression...or [q or Q] to quit\n\n");

    int bytes = 0,rv;

    int buflen = 10000;
    char * buffer = (char *)malloc(buflen);

    int proc_id = atoi(av[2]);

    while(1){

      bytes = read(fileno(stdin), buffer, buflen);
      bytes = chomp(buffer, bytes);

      if( buffer[0] == 'q' || buffer[0] == 'Q' )
	      break;
      else if(bytes <= 1)
	      continue;
      else {
	      /* Grammar expects a semicolon at the end of statements */
	      if( (buffer[bytes-1]) != ';' ) {
		      buffer[bytes] = ';';
		      bytes ++;
	      }
	      rv = push_buffer_array(buffer,proc_id);
      }
    }

    free(buffer);

    return rv;

}


int push_buffer_file(int ac, char **av)
{

  FILE *fp;
  int buflen = 10000;
  char * buffer = (char *)malloc(buflen);
  int bytes;

  fp = fopen(av[1],"r");
  bytes = read(fileno(fp), buffer, buflen);
  fclose(fp);

  int proc_id;
  if(ac > 2) 
    proc_id = atoi(av[2]);
  else
    proc_id = getpid();

  /* Grammar expects a semicolon at the end of statements */
  if( (buffer[bytes-1]) != ';' ) {
	  buffer[bytes] = ';';
	  bytes ++;
  }

  int rv = push_buffer_array(buffer,proc_id);

  free(buffer);

  return rv;

}
 
#ifdef __FORMAT__
 
 int main(int ac, char **av)
 {
   int rv;
   if(ac > 1) 
      rv = push_buffer_file(ac,av);
    else if(ac == 1)
      rv = push_buffer_stdin(ac,av);
   return rv;
      
 } 
 
#endif
