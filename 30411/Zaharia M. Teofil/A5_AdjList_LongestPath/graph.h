#include <stdio.h>

#define UNVISITED 0
#define VISITED 1

void readFromAdjMatrix(FILE * f);


int ** adjMatrix;
int nrOfVerteces;

void printAdjMatrix(int** adjMatrix);

int getNumberOfNeighborsOfVertex(int v);
int * getAllNeighborsOfVertex(int v);


void bfs(int startNode);
void dfs(int startNode);
void dfsRecurs(int searchNode);

// V << E use adj matrix
// V >> E use adj list

int** adjLists;
int* adjListLengths;

void createAdjLists (int** adjMatrix);
void printAdjLists();
int** createAdjMatrixFromLists (int** adjLists, int* adjListLengths);


void append(char** dest, int src);
int dfsRecLen(int v, int* mark, char** c);
char* longestSimplePathFrom(int startNode, int* len);
char* longestSimplePath();

