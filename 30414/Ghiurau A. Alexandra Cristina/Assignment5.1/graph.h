#include <stdio.h>
#include "node.h"

void readFromAdjMatrix(FILE * f);

int ** adjMatrix;
int nrOfVerteces;
NodeT **adjArray;

void printAdjMatrix();

int * getAllNeighborsOfVertex1(int v); //for matrix
int getNumberOfNeighborsOfVertex1(int v);
int * getAllNeighborsOfVertex2(int v); //for list
int getNumberOfNeighborsOfVertex2(int v);

///!!! In order to avoid doing two extra functions for dfs and bfs for lists I used pointers to functions although I haven't fully understood how they work..(I know I used them before)
int (*getNumberOfNeighborsOfVertex)(int v);
int * (*getAllNeighborsOfVertex)(int v);
