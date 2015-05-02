

#include <stdio.h>

#define UNVISITED 0
#define VISITED 1

void readFromAdjMatrix(FILE * f);


int ** adjMatrix;
int nrOfVerteces;

void printAdjMatrix();

void bfs(int searchNode);
int dfs(int searchNode,int stopNode);
void dfsRecurs(int searchNode);

