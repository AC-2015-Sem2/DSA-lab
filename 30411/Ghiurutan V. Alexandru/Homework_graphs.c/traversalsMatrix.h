#ifndef TRAVERSALSMATRIX_H_INCLUDED
#define TRAVERSALSMATRIX_H_INCLUDED
#include "stack.h"
int getNumberOfNeighborsOfVertex(int v);
int * getAllNeighborsOfVertex(int v);
void bfs(int searchNode);
void dfs(int searchNode);
void dfsRecurs(int searchNode);
void dfsRec(int v,int *neighbors);


#endif // TRAVERSALSMATRIX_H_INCLUDED
