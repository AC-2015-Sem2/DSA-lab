#include "Print.h"

void prettyPrint(NodeT *root,int recLevel)
{
    if(root==NULL)
    {
        recLevel--;
        return;
    }
    else
    {
        recLevel++;
        prettyPrint(root->right,recLevel);
        int j;
        for(j=0; j<recLevel-1; j++)
        {
            printf("     ");
        }
        printElement(root);
        printf("\n");
        prettyPrint(root->left,recLevel);
    }
}
void printElement(NodeT *root)
{
    printf("%d ",root->key);
}
