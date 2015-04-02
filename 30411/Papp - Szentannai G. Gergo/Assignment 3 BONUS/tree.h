#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#define MAX_SIZE_OF_CONTENT 10

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char * str;
    struct node *left, *right;
} NodeT;  // Bin. Tree

NodeT *  createBinTree(FILE*);

void prettyPrint(NodeT*,int);

float calc (NodeT*);

#endif // TREE_H_INCLUDED
