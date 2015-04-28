#include <stdio.h>

#define UNVISITED 0
#define VISITED 1

void readFromAdjMatrix(FILE * f);


int ** adjMatrix;
int ** adjMatrix2;
int nrOfVerteces;
int getNumberOfNeighborsOfVertex1(int v);
int getAllNeighborsOfVertex1(int v);

void printAdjMatrix();
void printNEWAdjMatrix();
void printList();

void bfs(int searchNode);
void dfs(int searchNode);
void dfsRecurs(int searchNode);

