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

void inorder(NodeT *root);
int maxDepth(NodeT *root);
int search(NodeT * root, int content);
int hasPathSum(NodeT *root, int sum);
void doubleTree(NodeT *root);
