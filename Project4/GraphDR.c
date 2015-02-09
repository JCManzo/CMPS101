/*
 * GraphTest.c
 *
 *  Created on: May 21, 2013
 *      Author: Juan Manzo
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"
#define MAX_LEN 2250
#define DUMMY   (0 0)

int main(int argc, char * argv[]){

GraphRef G = newGraph(5);
addEdge(G, 0, 1);
addEdge(G, 0, 2);
addEdge(G, 1, 1);
addEdge(G, 2, 3);
addEdge(G, 2, 4);
addEdge(G, 3, 4);
addEdge(G, 4, 3);
addEdge(G, 4, 2);

freeGraph(&G);

return 0;
}

