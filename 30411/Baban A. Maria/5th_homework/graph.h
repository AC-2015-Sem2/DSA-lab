#include <stdio.h>

#define UNVISITED 0
#define VISITED 1

void readFromAdjMatrix(FILE * f);


int **adjMatrix;
int nrOfVerteces;

void printAdjMatrix();

void bfs(int searchNode);
void dfs(int searchNode);
void dfsRecurs(int searchNode);

int **adjList;
int *adjListlength;

void createAdjList (int** adjMatrix);
void printAdjList();
int **list2matrix(int** adjLists, int* adjListLengths);


void append(char** dest, int src);
int dfsRecLen(int v, int* mark, char** c);

