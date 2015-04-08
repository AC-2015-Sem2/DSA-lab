#include "functions.h"

int height(NodeT *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}

int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

int getBalance(NodeT *root)
{
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

void postOrder(NodeT *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        postOrder(root->left);
        postOrder(root->right);
    }
}

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
    printf("%d",root->data);
    printf("\n");

    prettyPrint(root->left,recLevel);
}
