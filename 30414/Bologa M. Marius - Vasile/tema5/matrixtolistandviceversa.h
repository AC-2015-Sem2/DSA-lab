#ifndef MATRIXTOLISTANDVICEVERSA_H_INCLUDED
#define MATRIXTOLISTANDVICEVERSA_H_INCLUDED

#include "graphRepresentation.h"
#include "graphTraversals.h"
#include "graphAlgorithms.h"

typedef struct Node{
    int data, nrNeighbors;
    int *neighbors;
    struct Node *next;
}adjacencyNode;

adjacencyNode *adjList;
int **matrixFromAdjList;

void printVector(int* vect, int size);
void matrixToList();
void printAList();
void listToMatrix();
void printAdjMatrixFromList();



#endif // MATRIXTOLISTANDVICEVERSA_H_INCLUDED
