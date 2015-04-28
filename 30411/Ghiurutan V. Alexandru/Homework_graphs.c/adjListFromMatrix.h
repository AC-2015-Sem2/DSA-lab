#ifndef ADJLISTFROMMATRIX_H_INCLUDED
#define ADJLISTFROMMATRIX_H_INCLUDED
#include "traversalsMatrix.h"

int **adjList;
int *adjListlength;

void createAdjList (int** adjMatrix);
void printAdjList();
int **listToMatrix(int** adjLists, int* adjListLengths);
void bfsAdj(int searchNode);
void dfsAdj(int searchNode);
void dfsRecursAdj(int searchNode);
void append(char** dest, int src);
int dfsRecLen(int v, int* mark, char** c);



#endif // ADJLISTFROMMATRIX_H_INCLUDED
