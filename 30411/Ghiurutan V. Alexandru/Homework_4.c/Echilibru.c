#include "Echilibru.h"
void calculEchilibru(NodeT *p)
{
    int hLeft=1;
    int hRight=1;
    if(p->left!=NULL)
    {
        drumMaxim(p->left,&hLeft,1);
    }
    else
    {
        hLeft=0;
    }
    if(p->right!=NULL)
    {
        drumMaxim(p->right,&hRight,1);
    }
    else
    {
        hRight=0;
    }
    p->ech=hRight-hLeft;
}
void drumMaxim(NodeT *p,int *maxim,int lung)
{
    if(p!=NULL)
    {
        drumMaxim(p->right,maxim,lung+1);

        if((p->left==NULL)&&(p->right==NULL)&&(*maxim<lung))
        {
            *maxim=lung;
        }
        drumMaxim(p->left,maxim,lung+1);
    }
}
void preorderEchilibru(NodeT *root)
{
    if(root!=NULL)
    {
        calculEchilibru(root);
        preorderEchilibru(root->left);
        preorderEchilibru(root->right);
    }
}
void preorderverify(NodeT *root)
{
    if(root!=NULL)
    {
        verify(root);
        preorderverify(root->left);
        preorderverify(root->right);
    }
}

void verify(NodeT *root)
{
    if(root->ech>1||root->ech<(-1))
    {
        perror("This is not an AVL tree!\n");
        exit(1);
    }
}
void AVLTree(NodeT *root)
{
    preorderEchilibru(root);
    preorderverify(root);
}
