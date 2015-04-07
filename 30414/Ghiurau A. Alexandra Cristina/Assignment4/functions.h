#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
    int height;
} NodeT;

NodeT *createNode(int data);
NodeT *createBinTree();
NodeT *insert(NodeT *node, int data);

int height(NodeT *root);
int max(int a, int b);
int getBalance(NodeT *root);
void prettyPrint(NodeT *root,int recLevel);
void postOrder(NodeT *root);


void rightRotation(NodeT **root2);
void leftRotation(NodeT **root2);
void rightLeftRotation(NodeT **root3);
void leftRightRotation(NodeT **root3);


#endif // FUNCTIONS_H_INCLUDED
