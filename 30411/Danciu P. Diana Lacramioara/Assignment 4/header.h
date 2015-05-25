#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct nodeTree
{
    struct nodeTree *left;
    struct nodeTree *right;
    int data;
    int ht; //height
} TreeT;

TreeT *createNodeTree(int data);
TreeT *createBinTree(void);
int BF(TreeT *T);
int height(TreeT *T);
TreeT *rotate_right(TreeT *x);
TreeT *rotate_left(TreeT *x);
TreeT *RR(TreeT *T);
TreeT *LL(TreeT *T);
TreeT *LR(TreeT *T);
TreeT *RL(TreeT *T);
TreeT* Insert(TreeT *T, int x);
TreeT* Delete(TreeT *T,int x);
void prettyPrint(TreeT *root,int recLevel);

#endif // HEADER_H_INCLUDED
