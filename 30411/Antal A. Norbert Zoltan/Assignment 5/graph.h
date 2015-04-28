#include <stdio.h>

#define UNVISITED 0
#define VISITED 1

void readFromAdjMatrix(FILE * f);


int ** adjHolder;
_Bool isM;
int nrOfVerteces;
int* nrNeighbors;

void printAdjMatrix();

void bfs(int searchNode);
void dfs(int searchNode);
void dfsRecurs(int searchNode);
void toList();
void toMatrix();

