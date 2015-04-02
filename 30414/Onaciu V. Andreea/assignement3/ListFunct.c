#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structDef.h"
void addLast(char x)
{
    if (head==NULL)
    {
        head=(nodeL *)malloc(sizeof(nodeL));
        head->next=NULL;
        head->prev=NULL;
        head->data=x;
        tail=head;
    }
    else
    {
        nodeL *newnode=(nodeL *)malloc(sizeof(nodeL));
        newnode->data=x;
        newnode->next=NULL;
        newnode->prev=tail;
        tail->next=newnode;
        tail=newnode;
    }
}
void printAll(nodeL* head)
{
    nodeL *p=head;
    while (p!=NULL)
    {
        printf("%c",p->data);
        p=p->next;
    }
    printf(" \n");
}
nodeL *createListFromTree(nodeT* root)
{
    if (root==NULL)
        addLast('*');
    else
    {
        addLast(root->data);
        createListFromTree(root->left);
        createListFromTree(root->right);
    }
    return head;
}
