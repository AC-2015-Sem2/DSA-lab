#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"
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
        printf("           ");
    }
    printf("%.0f",root->id);
    printf("\n");
    prettyPrint(root->left,recLevel);
}
void preorder(NodeT *p)
{
    if(p!=0)
    {
        printf("%.0f ",p->id);
        preorder(p->left);
        preorder(p->right);
    }
}
void inorder(NodeT *p)
{
    if(p!=0)
    {
        inorder(p->left);
        printf("%.0f ",p->id);
        inorder(p->right);
    }
}
void postorder(NodeT *p)
{
    if(p!=0)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%.0f ",p->id);
    }
}
void drum(NodeT* p,int *maxi,int lung)
{
    if (p!=NULL)
    {
        drum(p->left,&*maxi,lung+1);
        if ((p->left==NULL)&&(p->right==NULL)&&(*maxi<lung))
            *maxi=lung;
        drum(p->right,&*maxi,lung+1);
    }
}

void calcul_factor_echilibru(NodeT *p)
{
    int hightLeft=1,hightRight=1;
    if(p->left!=NULL)
        drum(p->left,&hightLeft,1);
    else
        hightLeft=0;
    if(p->right!=NULL)
        drum(p->right,&hightRight,1);
    else
        hightRight=0;
    p->fact=hightRight-hightLeft;

}

NodeT* s_rot_right(NodeT *p)
{
    NodeT *q;
    q=p->left;
    p->left=q->right;
    q->right=p;
    calcul_factor_echilibru(p);
    calcul_factor_echilibru(q);
    p=q;
    return p;
}

NodeT* s_rot_left(NodeT *p)
{
    NodeT *q;
    q=p->right;
    p->right=q->left;
    q->left=p;
    calcul_factor_echilibru(p);
    calcul_factor_echilibru(q);
    p=q;
    return p;
}

NodeT* d_rot_right(NodeT *p)
{
    p->left=s_rot_left(p);
    p=s_rot_right(p);
    return p;
}
NodeT* d_rot_left(NodeT *p)
{
    p->right=s_rot_right(p);
    p=s_rot_left(p);
    return p;
}
NodeT* echilibrare(NodeT *p)
{
    NodeT *w;
    calcul_factor_echilibru(p);
    if(p->fact==-2)
    {
        w=p->left;
        calcul_factor_echilibru(w);
        if (w->fact==1)
            p = d_rot_right(p);

        else
            p = s_rot_right(p);


    }
    else if(p->fact==2)
    {
        w=p->right;
        if (w->fact==-1)
            p = d_rot_left(p);

        else
            p = s_rot_left(p);


    }
    return p;
}

NodeT* creare(NodeT *p, float key)
{
    if (p==NULL)
    {
        p=(NodeT*)malloc(sizeof(NodeT));
        p->id=key;
        p->fact=0;
        p->right=NULL;
        p->left=NULL;
        return p;
    }
    else
    {
        if (key<p->id)
            p->left = creare(p->left,key);
        else if (key>p->id)
            p ->right = creare(p->right,key);
    }
    p=echilibrare(p);
    return p;
}
NodeT* inserare(NodeT *p, float key)
{
    if (key<p->id)
        p->left = creare(p->left,key);
    else if (key>p->id)
        p ->right = creare(p->right,key);
    p = echilibrare(p);
    return p;
}
