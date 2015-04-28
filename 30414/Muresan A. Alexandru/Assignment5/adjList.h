#ifndef ADJLIST_H_INCLUDED
#define ADJLIST_H_INCLUDED
#include "graphRepresentation.h"
#include "graphTraversals.h"
#include "graphAlgorithms.h"

typedef struct Node{
    int content, nrOfNeighbours;
    int *neighbours;
    struct Node *next;
}adjNode;

adjNode *adjacencyList;
int **matrixFromList;

void addToAdjacencyList(int, int*);
void printVector(int*, int);
void matrixToList();
void printAdjList();
void listToMatrix();
void printAdjMatrixFromList();
#endif // ADJLIST_H_INCLUDED
