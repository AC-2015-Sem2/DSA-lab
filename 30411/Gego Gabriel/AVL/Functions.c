#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Functions.h"


int height(NodeT *a)
{
    if (a == NULL)
        return 0;
    return a->height;
}


int max(int a, int b)
{
    if (a > b)return a;
    else return b;
}


NodeT* createNode(int d)
{
    NodeT *a;
    a = (NodeT*)malloc(sizeof(NodeT));
    a->value=d;
    a->left=a->right=NULL;
    a->height=1;
    return a;
}




NodeT *RotateRight(NodeT *a)
{
    NodeT *q = a->left;
    NodeT *t = q->right;
    q->right = a;
    a->left = t;
    a->height = max(height(a->left), height(a->right))+1;
    q->height = max(height(q->left), height(q->right))+1;

    return q;
}

NodeT *RotateLeft(NodeT *a)
{
    NodeT *z = a->right;
    NodeT *t = z->left;
    z->left = a;
    a->right = t;
    a->height = max(height(a->left), height(a->right))+1;
    z->height = max(height(z->left), height(z->right))+1;
    return z;
}

int getBalanceTree(NodeT *a)
{
    if (a == NULL)
        return 0;
    return height(a->left) - height(a->right);
}


NodeT* insertNode(NodeT* a, int value)
{
    if (a == NULL)
        return(createNode(value));
    if (value < a->value)
        a->left  = insertNode(a->left, value);
    else
        a->right = insertNode(a->right, value);
    a->height = max(height(a->left), height(a->right)) + 1;
    int balance = getBalanceTree(a);
    if (balance < -1 && value > a->right->value)
        return RotateLeft(a);
    if (balance > 1 && value < a->left->value)
        return RotateRight(a);

    if (balance < -1 && value < a->right->value)
    {
        a->right = RotateRight(a->right);
        return RotateLeft(a);
    }
    if (balance > 1 && value > a->left->value)
    {
        a->left =  RotateLeft(a->left);
        return RotateRight(a);
    }

    return a;
}

void inorder(NodeT* root)
{
    if (root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->value);
        inorder(root->right);
    }
}

void preorder(NodeT* root)
{
    if (root!=NULL)
    {
        printf("%d ",root->value);
        preorder(root->left);
        preorder(root->right);
    }
}


void PreetyPrint(NodeT *root,int level)
{
    int i;
    if(root==NULL)
    {
        level--;
        return;
    }
    level++;
    PreetyPrint(root->right,level);
    for(i=0; i<level-1; i++)
    {
        printf("\t");
    }
    printf ( "%d \n" ,root->value );
    PreetyPrint(root->left,level);

}





