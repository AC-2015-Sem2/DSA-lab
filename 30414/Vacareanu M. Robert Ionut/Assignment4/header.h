#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct Node{
    int data;
    int weight;
    struct Node *left, *right;
}NodeT;
NodeT* createNode(int);
NodeT* createBinTree();
int calculateWeight(struct Node* );
void prettyPrint(NodeT*, int );
NodeT* rotateRight(struct Node* );
NodeT* rotateLeft(struct Node* );
void preOrder(NodeT* );
NodeT* balanceTree(struct Node* );
NodeT* insertNodeUtil(struct Node* , int );
NodeT* insertNode(struct Node* , int );

#endif // HEADER_H_INCLUDED
