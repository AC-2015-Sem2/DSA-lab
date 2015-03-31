#ifndef HEADER_C_INCLUDED
#define HEADER_C_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodeTree
{
    struct nodeTree *left;
    struct nodeTree *right;
    char *data;
} TreeT;

TreeT *createNodeTree(char *data);
TreeT *createBinTree(FILE *f);
void prettyPrint(TreeT *root,int recLevel);

#endif // HEADER_C_INCLUDED
