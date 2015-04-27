#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

int getNumberOfNeighborsOfVertex(int v, nodeT** adjList);
int *getAllNeighborsOfVertex(int v, nodeT** adjList);
void bfs(nodeT** adjList, int searchNode);
void dfs(nodeT** adjList, int searchNode);
void dfsRec(int v, int * mark, nodeT** adjList);
void dfsRecurs(nodeT** adjList,int v );


#endif // GRAPH_H_INCLUDED
