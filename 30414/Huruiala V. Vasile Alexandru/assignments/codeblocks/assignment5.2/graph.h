#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

#define UNVISITED 0
#define VISITED 1

void readAdjMatrix(FILE* f, int* size, int*** mat);
void printAdjMatrix(int size, int** mat);

node** AdjMatToAdjList(int** mat, int size);
void printAdjList(node** adjList, int size);

void longestPathMat(int startingNode, int endingNode, int** mat, int size);
void longestPathLst(int startingNode, int endingNode, node** lst, int size);
