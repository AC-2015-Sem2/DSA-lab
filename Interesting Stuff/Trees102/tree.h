#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_SIZE_OF_CONTENT 100

typedef struct node {
    void * content;
    struct node *left, *right;
} NodeT;

void (*printElement)(NodeT*);
void * (*getContent)(char*);

NodeT * createBinTree(FILE * f);

void preorder(NodeT *root);
void inorder(NodeT *root);
void postorder(NodeT *root);
void prettyPrint(NodeT *root,int recLevel);
int maxDepth(NodeT *root);
int hasPathSum(NodeT *root, int sum);
int size(NodeT *root);
void printPaths(NodeT *root, int *path, int pathLength);
void mirror(NodeT *root);
void doubleTree(NodeT *root);

//! BST
NodeT * insert(NodeT * root, int content);
int lookup(NodeT * root, int content);
int isBST(NodeT * root);
int sameTree(NodeT * a, NodeT * b);

// print functions
void printStringElement(NodeT * node);
void printIntegerElement(NodeT * node);

void * getStringContent(char * content);
void * getIntegerContent(char * content);


void printArray(int *array, int length);
