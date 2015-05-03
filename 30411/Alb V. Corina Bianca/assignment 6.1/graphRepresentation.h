#include "graph.h"

void readFromAdjMatrix(FILE * f);
void printAdjMatrix();

void readMatrixBF(FILE * bf);
void printAdjBFMatrix();

int getNumberOfNeighborsOfVertex(int v);
int * getAllNeighborsOfVertex(int v);
