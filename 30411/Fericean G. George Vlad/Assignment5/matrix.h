#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

int ** adjMatrix;
int nrOfVerteces;


void readFromAdjMatrix(FILE * f);
void printMatrix(int** Matrix);
NodeT** getListfromMatrix(int** matrix);
void printList(NodeT** adjList);
int** getMatrixfromList(NodeT** adjList);


#endif // MATRIX_H_INCLUDED
