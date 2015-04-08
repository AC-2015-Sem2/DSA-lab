#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
typedef struct Node{
    int data;
    int weight;
    struct Node *left, *right;
}NodeT;
NodeT* createNode(int );
int CalculateWeight(struct Node* );
void prettyPrint(struct Node* , int );
NodeT* rotateRight(struct Node* );
NodeT* rotateLeft(struct Node* );
NodeT* balanceTree(struct Node* );
NodeT* insertNodeUtil(struct Node* , int );
NodeT* insertNode(struct Node* , int );
NodeT* minValueNode(struct Node* );
NodeT* deleteNode(struct Node* , int );

#endif // HEADER_H_INCLUDED
