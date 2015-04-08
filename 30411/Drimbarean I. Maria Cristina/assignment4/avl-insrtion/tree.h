#include <stdlib.h>
#include <stdio.h>
#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
typedef struct node
{
    int data;
    struct node *right;
    struct node *left;
    int height;
} NodeT;

void printElement(NodeT * node);
void prettyPrint(NodeT *root,int recLevel);
NodeT *createStaticTree(void);
NodeT* createNode(int x);
int max(int a,int b);
int height(NodeT *N);
NodeT *newNode(int data);
NodeT *rightRotate(NodeT *y);
NodeT *leftRotate(NodeT *x);
int getBalance(NodeT *N);
#endif // TREE_H_INCLUDED
