#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_SIZE_OF_CONTENT 100

typedef struct node {
    void * content;
    struct node *left, *right;
} NodeT;

NodeT * createBinTree(FILE * f);

void postorder(NodeT *root);
int size(NodeT *root);
int search(NodeT * root, int content);
void mirror(NodeT *root);
void printPaths(NodeT *root, int *path, int pathLength);
