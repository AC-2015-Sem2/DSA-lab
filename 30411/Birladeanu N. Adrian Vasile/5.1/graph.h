#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

int getNumberOfNeighborsOfVertex(int v, NodeT** adjList);
int *getAllNeighborsOfVertex(int v, NodeT** adjList);
void bfs(NodeT** adjList, int searchNode);
void dfs(NodeT** adjList, int searchNode);
void dfsRec(int v, int * mark, NodeT** adjList);
void dfsRecurs(int v, NodeT** adjList);


#endif // GRAPH_H_INCLUDED
