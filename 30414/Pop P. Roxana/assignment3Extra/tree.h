#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *f, *g;

typedef struct genNodeT
{
    struct genNodeT * left, * right;
    char * data;
} nodeT;

///function prototypes
nodeT * createBinTree();
void prettyPrint(nodeT *root,int recLevel);
