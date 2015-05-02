#ifndef MYHW_H_INCLUDED
#define MYHW_H_INCLUDED

#include "graph.h"
#include "list.h"

#define N 7

List* adjList;

List* createListFromMatrix();
int** createMatrixFromList(List* l);
int LISTgetNumberOfNeighborsOfVertex(int v);
int * LISTgetAllNeighborsOfVertex(int v);

#endif // MYHW_H_INCLUDED
