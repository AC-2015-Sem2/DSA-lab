#ifndef REPRESENTATION_H_INCLUDED
#define REPRESENTATION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int ** adjMatrix;
int nrOfVerteces;


void readFromAdjMatrix(FILE * f);
void printMatrix(int** Matrix);
nodeT** getListfromMatrix(int** matrix);
void printList(FILE *f,nodeT** adjList);
int** getMatrixfromList(nodeT** adjList);




#endif // REPRESENTATION_H_INCLUDED
