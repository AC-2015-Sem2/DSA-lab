#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct nodeTree
{
    char *data;
    struct nodeTree *left;
    struct nodeTree *right;
} nodeT;


nodeT *createBinTree(FILE *f);
void printList();   //==traverseList();
void prettyPrint(FILE *pf,nodeT *root,int level);


#endif // BINARYTREE_H_INCLUDED
