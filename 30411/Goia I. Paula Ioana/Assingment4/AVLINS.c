#include <stdio.h>
#include <stdlib.h>
#include "avlins.h"
void prettyPrint(NodeT *root,int recLevel)
{
    if(root==NULL)
    {
        recLevel--;
        return;
    }
    recLevel++;
    prettyPrint(root->right,recLevel);
    int j=0;
    for(j=0; j<recLevel-1; j++)
    {
        printf("     ");
    }
    printf("%d",root->key);
    printf("\n");
    prettyPrint(root->left,recLevel);
}
int height(NodeT *p)
{
    if (p == NULL)
        return 0;
    return p->height;
}


int max(int a, int b)
{
    if (a > b)return a;
    else return b;
}

NodeT* newNode(int key)
{
    NodeT* p = (NodeT*)malloc(sizeof(NodeT));
    p->key   = key;
    p->left   = NULL;
    p->right  = NULL;
    p->height = 1;
    return(p);
}

NodeT *RIGHTrotation(NodeT *p)
{
    NodeT *x = p->left;
    NodeT *t = x->right;
    x->right = p;
    p->left = t;
    p->height = max(height(p->left), height(p->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    return x;
}

NodeT *LEFTrotation(NodeT *p)
{
    NodeT *y = p->right;
    NodeT *t = y->left;
    y->left = p;
    p->right = t;
    p->height = max(height(p->left), height(p->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
    return y;
}

int getBalance(NodeT *p)
{
    if (p == NULL)
        return 0;
    return height(p->left) - height(p->right);
}


NodeT* insert(NodeT* p, int key)
{
    if (p == NULL)
        return(newNode(key));
    if (key < p->key)
        p->left  = insert(p->left, key);
    else
        p->right = insert(p->right, key);
    p->height = max(height(p->left), height(p->right)) + 1;
    int balance = getBalance(p);
    if (balance > 1 && key < p->left->key)
        return RIGHTrotation(p);
    if (balance < -1 && key > p->right->key)
        return LEFTrotation(p);
    if (balance > 1 && key > p->left->key)
    {
        p->left =  LEFTrotation(p->left);
        return RIGHTrotation(p);
    }
    if (balance < -1 && key < p->right->key)
    {
        p->right = RIGHTrotation(p->right);
        return LEFTrotation(p);
    }

    return p;
}

void inorder(NodeT* root)
{
    if (root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->key);
        inorder(root->right);
    }
}

void preorder(NodeT* root)
{
    if (root!=NULL)
    {
        printf("%d ",root->key);
        preorder(root->left);
        preorder(root->right);
    }
}


NodeT * MINvalue(NodeT* node)
{
    NodeT* p = node;
    while (p->left != NULL)
        p = p->left;
    return p;
}

NodeT* deleteNODE(NodeT* root, int key)
{
    if (root == NULL)
        return root;

    if ( key < root->key )
        root->left = deleteNODE(root->left, key);
    else if( key > root->key )
        root->right = deleteNODE(root->right, key);
    else
    {
        if( (root->left == NULL) || (root->right == NULL) )
        {
            NodeT *temp = root->left ? root->left : root->right;
            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
             *root = *temp;
            free(temp);
        }
        else
        {
            NodeT* temp = MINvalue(root->right);
            root->key = temp->key;
            root->right = deleteNODE(root->right, temp->key);
        }
    }
    if (root == NULL)
      return root;

    root->height = max(height(root->left), height(root->right)) + 1;

    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0)
        return RIGHTrotation(root);
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  LEFTrotation(root->left);
        return RIGHTrotation(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return LEFTrotation(root);
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = RIGHTrotation(root->right);
        return LEFTrotation(root);
    }
    return root;
}
