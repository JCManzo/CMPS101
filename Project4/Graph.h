/*
* Graph.h
*
*  Created on: May 21, 2013
*      Author: Juan Manzo
*/

#if !defined(_GRAPH_H_INCLUDE_)
#define _GRAPH_H_INCLUDE_
#include "List.h"

/* defines constant macros INF AND NIL to be -10 and 10 respectively. */
#define INF -12345
#define NIL 12345

typedef struct Graph * GraphRef;

/*** Constructors-Destructors ***/
GraphRef newGraph(int n);
void freeGraph(GraphRef* pG);

/*** Access functions ***/
int getOrder(GraphRef G);
int getSize(GraphRef G);
int getSource(GraphRef G);
int getParent(GraphRef G, int u);
int getDist(GraphRef G, int u);
void getPath(ListRef L, GraphRef G, int u);

/*** Manipulation procedures ***/
void makeNull(GraphRef G);
void addEdge(GraphRef G, int u, int v);
void addArc(GraphRef G, int u, int v);
void BFS(GraphRef G, int s);

/*** Other operations ***/
void printPath(GraphRef G, ListRef L);
#endif


