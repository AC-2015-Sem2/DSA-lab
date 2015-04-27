# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "node.h"

# define VISITED 1
# define UNVISITED 0

#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

int nrOfVeritces;
int **adjMatrix;
NodeT **listAdr;

void readMatrix(FILE *);
void printMatrix();

void matrixToList();
void printList();
void listToMatrix();
void bfsOnLists(int);
void dfsOnLists(int);
int * findPath(int);


#endif // FUNCTIONS_H_INCLUDED
