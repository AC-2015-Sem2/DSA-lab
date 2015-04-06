#include "insert.h"
#include "create.h"
NodeT *createNode(int x)
{
    NodeT *p=(NodeT *)malloc(sizeof(NodeT));
    p->k=x;
    p->e=0;
    p->left=NULL;
    p->right=NULL;
    return p;
}
NodeT *insertNode(NodeT *p,int data)
{
    if(p==NULL)
    {
        return createNode(data);
    }
    else
    {
        if(p->k>data)
        {
            p->left=insertNode(p->left,data);
        }
        else if(p->k<data)
        {
            p->right=insertNode(p->right,data);
        }
        else
        {
            printf("The node already exists!\n");
        }
        p=balancedTree(p);
        return p;
    }
}

NodeT* createStaticTree()
{
    NodeT* root=createNode(4);
    root->left=createNode(2);
    root->right=createNode(5);
    root->left->left=createNode(1);
    root->left->right=createNode(7);
    root->right->left=createNode(3);
    return root;
}

//4 types of rotations
NodeT *rotateRight(NodeT *p)
{
    NodeT *q;
    q=p->left;
    p->left=q->right;
    echilibrum(p);
    echilibrum(q);
    p=q;
    return p;
}

NodeT *rotateLeft(NodeT *p)
{
    NodeT *q;
    q=p->right;
    p->right=q->left;
    q->left=p;
    echilibrum(p);
    echilibrum(q);
    p=q;
    return p;
}

NodeT *rotateRight_Left(NodeT *p)
{
    p->right=rotateRight(p->right);
    p=rotateLeft(p);
    return p;
}

NodeT *rotateLeft_Right(NodeT *p)
{
    p->left=rotateLeft(p->left);
    p=rotateRight(p);
    return p;
}

NodeT *balancedTree(NodeT *p)
{
    preorderEchilibrum(p);
    NodeT *j;
    if(p->e==-2)
    {
        j=p->left;
        if(j->e==1)
        {
            p=rotateLeft_Right(p);
        }
        else
        {
            p=rotateRight(p);
        }
    }
    else if(p->e==2)
    {
        j=p->right;
        if(j->e==-1)
        {
            p=rotateRight_Left(p);
        }
        else
        {
            p=rotateLeft(p);
        }
    }
    return p;
}
