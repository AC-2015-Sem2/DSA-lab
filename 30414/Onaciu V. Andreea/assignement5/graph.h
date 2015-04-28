#include <stdio.h>

#define UNVISITED 0
#define VISITED 1

void readFromAdjMatrix(FILE * f);


int ** adjMatrix;
int nrOfVerteces;

void printAdjMatrix();
int getNumberOfNeighborsOfVertex(int v);
int * getAllNeighborsOfVertex(int v);
void bfs(int searchNode);
void dfs(int searchNode);
void dfsRecurs(int searchNode);
