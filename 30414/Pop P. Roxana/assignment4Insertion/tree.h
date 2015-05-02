#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE * f, *g;
typedef struct node
{
    int data;
    int height;
    struct node* left;
    struct node* right;
} nodeT;

///necessary function prototypes
int max(int a, int b);
int height(nodeT*p);
nodeT * createNode(int data);
nodeT * createBinTree();
int balanceFactor(nodeT * p);
void prettyPrint(nodeT *root,int recLevel);

///rotation function prototypes
void singleLeftRotation(nodeT **k1);
void singleRightRotation(nodeT **k2);
void rightLeftRotation(nodeT ** k3);
void leftRightRotation(nodeT ** k3);

///insertion function prototype
nodeT* insertNew(nodeT*root, int value);
