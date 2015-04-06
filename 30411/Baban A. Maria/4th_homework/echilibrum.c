#include "echilibrum.h"
void echilibrum(NodeT *p)
{
    int leftH=1;
    int rightH=1;
    if(p->left!=NULL)
        maxPath(p->left,&leftH,1);
    else
        leftH=0;
    if(p->right!=NULL)
        maxPath(p->right,&rightH,1);
    else
        rightH=0;
    p->e=rightH-leftH;
}

void maxPath(NodeT *p,int *maximum,int lung)
{
    if(p!=NULL)
    {
        maxPath(p->right,maximum,lung+1);

        if((p->left==NULL)&&(p->right==NULL)&&(*maximum<lung))
        {
            *maximum=lung;
        }
        maxPath(p->left,maximum,lung+1);
    }
}

void preorderEchilibrum(NodeT *root)
{
    if(root!=NULL)
    {
        echilibrum(root);
        preorderEchilibrum(root->left);
        preorderEchilibrum(root->right);
    }
}

void preorderCheck(NodeT *root)
{
    if(root!=NULL)
    {
        check(root);
        preorderCheck(root->left);
        preorderCheck(root->right);
    }
}

//check if AVL tree
void check(NodeT *root)
{
    if(root->e>1||root->e<(-1))
    {
        perror("This is not an AVL tree!\n");
        exit(1);
    }
}

void AVLTree(NodeT *root)
{
    preorderEchilibrum(root);
    preorderCheck(root);
}

