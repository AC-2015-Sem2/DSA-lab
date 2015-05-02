#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VISITED 1
#define UNVISITED 0

typedef struct node
{
    int content;
    struct node *next;
} NodeT;
int **adjMatrix;
int nrOfVertices;
NodeT *createNode(int content);
#endif // NODE_H_INCLUDED
