#include <stdio.h>
#include "node.h"

#define UNVISITED 0
#define VISITED 1

void readFromAdjMatrix(FILE * f);


int **adjMatrix;
int nrOfVerteces;

void printAdjMatrix();

void bfs(int searchNode);
void dfs(int searchNode);
void dfsRecurs(int searchNode);
NodeT **fromMatrixtoList(int **adjMatrix);
int **fromListtoMatrix(NodeT **adjList);
void printAdjList(NodeT **adjList);
int getNumberOfNeighborsOfVertexfromList(int v, NodeT **adjList);
int getNumberOfNeighborsOfVertex(int v);
int *getAllNeighborsOfVertex(int v);
int *getAllNeighborsOfVertexFromList(int v, NodeT **adjList);
void bfsList(int searchNode, NodeT **adjList);
void dfsList(int searchNode, NodeT **adjList);
void dfsRecList(int v, int *mark, NodeT **adjList);
void dfsRecursList(int v, NodeT **adjList);
