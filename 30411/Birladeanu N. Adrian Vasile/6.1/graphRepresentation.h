#include "graph.h"

void readFromAdjMatrix(FILE * f);
void readFromEdgeMatrix(FILE * f);
void printAdjMatrix();

int getNumberOfNeighborsOfVertex(int v);
int * getAllNeighborsOfVertex(int v);
