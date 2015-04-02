#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structDef.h"

nodeT * createNode(char d)
{
    nodeT *p=(nodeT*)malloc(sizeof(nodeT));
    p->data=d;
    p->left=NULL;
    p->right=NULL;
    return p;
}
nodeT *createStaticBinTree()
{
    nodeT *root;
    root=createNode('1');
    root->left=createNode('2');
    root->left->right=createNode('5');
    root->right=createNode('7');
    root->right->right=createNode('8');
    return root;
}
void inorder(nodeT* root)
{
    if (root!=NULL)
    {
        inorder(root->left);
        printf("%c ",root->data);
        inorder(root->right);

    }
}



nodeT* createTreeFromList()
{
    nodeT *t=NULL;
    if (head!=NULL)
    {

        if (head->data=='*')
        {
            head=head->next;

        }
        else
        {
            t=createNode(head->data);
            head=head->next;
            t->left=createTreeFromList();
            t->right=createTreeFromList();

        }
    }
    return t;
}
void prettyPrint(nodeT *root,int recLevel)
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
    printf("%c",root->data);
    printf("\n");
    prettyPrint(root->left,recLevel);
}
