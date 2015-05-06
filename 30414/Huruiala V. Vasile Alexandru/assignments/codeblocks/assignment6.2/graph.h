#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define UNVISITED 0
#define VISITED 1

void readAdjMatrix(FILE* f, int* size, int*** mat);
void readAdjMatrixEdges(FILE* f, int* size, int*** mat);
void printAdjMatrix(int size, int** mat);
node** AdjMatToAdjList(int** mat, int size);
void printAdjList(node** adjList, int size);
int** AdjListToAdjMat(node** adjList, int size);

void bfsMat(int startingNode, int** mat, int size);
void dfsMat(int startingNode, int** mat, int size);

void bfsLst(int startingNode, node** lst, int size);
void dfsLst(int startingNode, node** lst, int size);

void dfsRecursiveMat(int startingNode, int** mat, int size);
void dfsRecursiveLst(int startingNode, node** lst, int size);
