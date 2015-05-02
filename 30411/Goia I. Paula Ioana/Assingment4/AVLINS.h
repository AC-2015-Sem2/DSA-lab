#ifndef AVLINS_H_INCLUDED
#define AVLINS_H_INCLUDED

typedef struct NodeT
{
    int key;
    struct NodeT*left,*right;
    int height;
}NodeT;
void prettyPrint(NodeT *p,int recLevel);
int height(NodeT *N);
int max(int a, int b);
NodeT* newNode(int key);
NodeT *RIGHTrotation(NodeT *p);
NodeT *LEFTrotation(NodeT *p);
int getBalance(NodeT *N);
NodeT* insert(NodeT* node, int key);
void inorder(NodeT* root);
void preorder(NodeT* root);
NodeT * MINvalue(NodeT* node);
NodeT* deleteNODE(NodeT* root, int key);


#endif // AVLINS_H_INCLUDED
