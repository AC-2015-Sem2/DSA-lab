
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *f, *g;
typedef struct genNodeT
{
    struct genNodeT * left, * right;
    char * data;
} nodeT;

typedef struct genNodeL
{
    struct genNodeL * next,*prev;
    char * data;
} nodeL;

///global pointer
nodeL * headG;
///functions for the tree
nodeT * createBinTree();
nodeT * getTreeFromList(nodeL * head);
void prettyPrint(nodeT *root,int recLevel);

///functions for the list
nodeL * getListFromTree(nodeT * root);
void traverseList(nodeL * head);


