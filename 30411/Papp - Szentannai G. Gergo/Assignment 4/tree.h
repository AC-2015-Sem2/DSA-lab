#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#define MAX_SIZE_OF_CONTENT 100
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node {
    int value;
    struct node *left, *right;
} NodeT;  // Bin. Tree

NodeT* createNode(int);

int sameTree(NodeT* , NodeT* );

NodeT *  createBinTree(FILE*);
NodeT *  createAVL_BST(FILE*);
void prettyPrint(NodeT*,int);

NodeT* insert (NodeT* root, int value);
NodeT* insert_balanced (NodeT** root, int value);

NodeT* search (NodeT* root, int value);

int isBSTUtil(NodeT* root, int min, int max);

int isBST(NodeT* root);

int sameTree(NodeT* a, NodeT* b);

NodeT *  createAVL_BST(FILE* in);

int height (NodeT* p);

int max(int a, int b);

int balanceFactor (NodeT* p);

NodeT* parent(NodeT* root, int value);

void rotate_left(NodeT **p, NodeT **root);

void rotate_right(NodeT **p, NodeT **root);

#endif // TREE_H_INCLUDED
