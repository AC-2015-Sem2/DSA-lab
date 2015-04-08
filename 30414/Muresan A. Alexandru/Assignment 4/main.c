#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct nodT{int  data;
                    struct nodT *right, *left;}NodeT;
FILE *pf_in, *pf_out;
NodeT *root;
NodeT *CreateNode(int d)
{
    NodeT *NewNODE=(NodeT*)malloc(sizeof(NodeT));
    NewNODE->data=d;
    NewNODE->right=NULL;
    NewNODE->left=NULL;
    return NewNODE;
}
NodeT *RotateRight(NodeT *root)
{
    NodeT *NewNODE;
    NewNODE=root->right;
    root->right=NewNODE->left;
    NewNODE->left=root;
    return NewNODE;
}
NodeT *RotateLeft(NodeT *root)
{
    NodeT *NewNODE;
    NewNODE=root->left;
    root->left=NewNODE->right;
    NewNODE->right=root;
    return NewNODE;
}
int TreeHeight(NodeT *root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        if(TreeHeight(root->left)>TreeHeight(root->right))
        {
            return TreeHeight(root->left)+1;
        }
        else
        {
            return TreeHeight(root->right)+1;
        }
    }
}
NodeT *ChangeRoot(NodeT *root)
{
    if(TreeHeight(root->right)-TreeHeight(root->left)>1)
    {
        if(TreeHeight(root->right->left)>TreeHeight(root->right->right))
        {
            root->right=RotateLeft(root->left);
        }
        root=RotateRight(root);
    }
    else
    {
        if(TreeHeight(root->left)-TreeHeight(root->right)>1)
        {
            if(TreeHeight(root->left->right)>TreeHeight(root->left->left))
            {
                root->left=RotateRight(root->left);
            }
            root=RotateLeft(root);
        }
    }
    return root;
}
NodeT *Insert(NodeT *root, int val)
{
    if(root==NULL)
    {
        return CreateNode(val);
    }
    else
    {
        if(root->data<val)
        {
            root->right=Insert(root->right, val);
        }
        else
        {
            root->left=Insert(root->left, val);
        }
        return ChangeRoot(root);
    }

}
void PrettyPrint(NodeT *root, int RecLvl)
{
    int i;
    if(root==NULL)
    {
        RecLvl--;
        return;
    }
    RecLvl++;
    PrettyPrint(root->right, RecLvl);
    for(i=0; i<RecLvl-1;i++)
    {
        fprintf(pf_out,"   ");
    }
    fprintf(pf_out, "%d", root->data);
    fprintf(pf_out, "\n");
    PrettyPrint(root->left, RecLvl);
}
int main()
{
    int TreeNode;
    pf_in=fopen("input.txt", "r");
    pf_out=fopen("output.txt", "w");
    while (fscanf(pf_in, "%d", &TreeNode)>0)
    {
        root=Insert(root, TreeNode);
    }
    PrettyPrint(root, 0);
    return 0;
}
