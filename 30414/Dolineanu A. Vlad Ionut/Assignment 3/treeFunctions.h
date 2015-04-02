#ifndef TREEFUNCTIONS_H_INCLUDED
#define TREEFUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include "listFunctions.h"

FILE* f;

typedef struct nodeT{
    int data;
    struct nodeT* left;
    struct nodeT* right;
}nodeT;

nodeT* allocTreeNode();
nodeT* createTreeNode(int);
nodeT* createBinaryTree();
void preorder(nodeT* , nodeL**);
nodeL* getListFromTree(nodeT*);
void prettyPrint(nodeT* ,int);
nodeT* createTreeFromList(nodeL**);
nodeT* getTreeFromList(nodeL*);

#endif // TREEFUNCTIONS_H_INCLUDED
