#include "Insert.h"

NodeT *insertNode(NodeT *p,int x)
{
    if(p==NULL)
    {
        return createNode(x);
    }
    else
    {
        if(p->key>x)
        {
            p->left=insertNode(p->left,x);
        }
        else if(p->key<x)
        {
            p->right=insertNode(p->right,x);
        }
        else
        {
            printf("The node already exists!\n");
        }
    }
    calculEchilibru(p);
    p=balancing(p);
    return p;
}

NodeT *simpleRotationRight(NodeT *p)
{
    NodeT *q;
    q=p->left;
    p->left=q->right;
    q->right=p;
    calculEchilibru(p);
    calculEchilibru(q);
    p=q;
    return p;
}

NodeT *simpleRotationLeft(NodeT *p)
{
    NodeT *q;
    q=p->right;
    p->right=q->left;
    q->left=p;
    calculEchilibru(p);
    calculEchilibru(q);
    p=q;
    return p;
}

NodeT *doubleRotationLeft(NodeT *p)
{
    p->right=simpleRotationRight(p->right);
    p=simpleRotationLeft(p);
    return p;
}

NodeT *doubleRotationRight(NodeT *p)
{
    p->left=simpleRotationLeft(p->left);
    p=simpleRotationRight(p);
    return p;
}

NodeT *createNode(int x)
{
    NodeT *p=(NodeT *)malloc(sizeof(NodeT));
    if(p==NULL)
    {
        perror("Not enough space!\n");
        exit(1);
    }
    p->key=x;
    p->ech=0;
    //A tree with 1 node is balanced
    p->left=NULL;
    p->right=NULL;
    return p;
}
NodeT *balancing(NodeT *p)
{
    NodeT *w;
    if(p->ech==-2)
    {
        w=p->left;
        if(w->ech==1)
        {
            p=doubleRotationRight(p);
        }
        else
        {
            p=simpleRotationRight(p);
        }
    }
    else if(p->ech==2)
    {
        w=p->right;
        if(w->ech==-1)
        {
            p=doubleRotationLeft(p);
        }
        else
        {
            p=simpleRotationLeft(p);
        }
    }
    return p;
}
