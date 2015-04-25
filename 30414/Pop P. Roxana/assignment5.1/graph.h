#include <stdio.h>
#include "node.h"

#define UNVISITED 0
#define VISITED 1

///number of vertices
int nrOfVerteces;

int ** adjMatrix;
///prototypes for the matrix functions
void printAdjMatrix();
void readFromAdjMatrix(FILE * f);
int getNumberOfNeighborsOfVertexM(int v);
int * getAllNeighborsOfVertexM(int v);

///pointers to functions
int (*getNumberOfNeighborsOfVertex)(int v);
int * (*getAllNeighborsOfVertex)(int v);

///prototypes for the traversal functions
void bfs(int searchNode);
void dfs(int searchNode);
void dfsRecurs(int searchNode);

NodeT**adjArray;
///prototypes for the adjacency list functions
NodeT** fromMatrixToList(int **adjMatrix);
void fromAdjListToMatrix(NodeT** adjList);
int getNumberOfNeighborsOfVertexL(int v);
int * getAllNeighborsOfVertexL(int v);
