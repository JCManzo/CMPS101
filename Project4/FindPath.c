/*
 * FindPath.c
 *
 *  Created on: May 21, 2013
 *      Author: Juan Manzo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"

#define MAX_LEN 4250

int main(int argc, char * argv[]){
  int numVerts, numQueries, insertVert, fromVert, toVert;
  char seps[]   = " ,\t\n";
  char line[MAX_LEN];
  char *token;
  int var, i = 0;
  FILE *in;

  /*check command line for correct number of arguments*/
  if( argc != 2 ){
   printf("Usage: %s infile \n", argv[0]);
   exit(1);
  }
     
	in = fopen(argv[1], "r");

  if( in == NULL ){
      printf("Unable to open file %s for reading\n", argv[1]);
      exit(1);
  }

  /*Get first line which contains numVerts and numQueries. Split at " " delimitter.*/
  fgets(line, MAX_LEN, in);
  token = strtok(line, " ");
   
  /*Convert char to int and store in corresponding variables.*/  
  numVerts = atoi(token);
  token = strtok(NULL, " ");
  numQueries= atoi(token);

  GraphRef G = newGraph(numVerts);

  for(i = 0; i < numVerts; i++ ) {
  /*Reads the text file until i == numVerts.*/
    fgets(line, MAX_LEN, in);


    /*Split our token by using our seps delimitter array. Convert to integer.*/
    token = strtok (line, seps);
    insertVert  = atoi(token);
    
    while (token != NULL) {
      sscanf (token, "%d", &var);
      addEdge(G, insertVert, var);
      token = strtok (NULL, seps);
    }
  }
  ListRef L = newList();

  for(i = 0; i < numQueries; i++) {
    fgets(line, MAX_LEN, in);
    token = strtok(line, " ");
    
    fromVert = atoi(token);
    token = strtok(NULL, " ");
    toVert = atoi(token); 
    
    BFS(G, fromVert);
    getPath(L, G, toVert);
    printPath( G, L);
  }
   
  fclose(in);
  freeList(&L);
  freeGraph(&G);  
    
  return 0;
}

