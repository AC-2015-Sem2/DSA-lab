#include <stdio.h>

#define UNVISITED 0
#define VISITED 1

void readFromAdjMatrix(FILE * f);


int ** adjMatrix;
int nrOfVerteces;

void printAdjMatrix();

void bfs(int searchNode);
void dfs(int searchNode);
void dfsRecurs(int searchNode);

void  adjMatrix_list();
void  printAdjList();
void  bfsList(int);
void  dfsList(int);
void  adjList_Matrix();
