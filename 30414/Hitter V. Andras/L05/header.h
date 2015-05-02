#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

typedef struct nodet
{
    int data;
    int height;
    struct nodet *left;
    struct nodet *right;
} NodeT;


int maxDepth(NodeT* root);
void preorder(NodeT *root);
NodeT* createNode(int d);
NodeT* createBinTree(FILE *f);
int search(NodeT* root, int value);
NodeT *rotateright(NodeT *x);
NodeT * rotateleft(NodeT *x);
NodeT *RR(NodeT *T);
NodeT *LL(NodeT *T);
NodeT *LR(NodeT *T);
NodeT *RL(NodeT *T);
int Balance(NodeT *root);
NodeT* insert(NodeT* T, int value);
NodeT * Delete(NodeT *T,int x);
int isBSTUtil(NodeT *root,int min,int max);
int isBST(NodeT *root);
void prettyPrint(NodeT *root,int recLevel);

#endif // HEADER_H_INCLUDED
