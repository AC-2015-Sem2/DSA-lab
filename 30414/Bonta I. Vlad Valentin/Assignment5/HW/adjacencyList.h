#ifndef ADJACENCYLIST_H_INCLUDED
#define ADJACENCYLIST_H_INCLUDED

#include "graphRepresentation.h"
#include "graphTraversals.h"
#include "graphAlgorithms.h"

typedef struct Node{
    int content, numberOfNeighbors;
    int *neighbors;
    struct Node *next;
}adjNode;

adjNode *adjacencyList;
int **adjMatrixFromList;

void addToAdjacencyList(int, int*);
void printVector(int*, int);
void matrixToList();
void printAdjList();
void listToMatrix();
void printAdjMatrixFromList();

#endif
