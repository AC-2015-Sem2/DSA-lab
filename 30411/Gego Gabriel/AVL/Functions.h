#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

typedef struct NodeT
{
    int value;
    struct NodeT*left,*right;
    int height;
} NodeT;

void PreetyPrint(NodeT *a,int level);

int height(NodeT *N);
int max(int a, int b);

NodeT* createNode(int value);

NodeT *RotateRight(NodeT *a);
NodeT *RotateLeft(NodeT *a);
int getBalanceTree(NodeT *N);
NodeT* insertNode(NodeT* node, int value);

void inorder(NodeT* root);
void preorder(NodeT* root);

#endif
