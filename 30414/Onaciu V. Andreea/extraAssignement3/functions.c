#include <stdio.h>
#include <stdlib.h>
#include "structuresDef.h"
#include <string.h>
nodeT * createNode(char s[10])
{
    nodeT *p=(nodeT*)malloc(sizeof(nodeT));
    strcpy(p->data,s);
    p->left=NULL;
    p->right=NULL;
    return p;
}
nodeT* createTreeFromList()
{
    nodeT *t=NULL;
    if (head!=NULL)
    {

        if (strcmp(head->data,"!")==0)
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
    printf("%s",root->data);
    printf("\n");
    prettyPrint(root->left,recLevel);
}
void addLast(char x[10])
{
    if (head==NULL)
    {
        head=(nodeL *)malloc(sizeof(nodeL));
        head->next=NULL;
        head->prev=NULL;
        strcpy(head->data,x);
        tail=head;
    }
    else
    {
        nodeL *newnode=(nodeL *)malloc(sizeof(nodeL));
        strcpy(newnode->data,x);
        newnode->next=NULL;
        newnode->prev=tail;
        tail->next=newnode;
        tail=newnode;
    }
}
void printAll(nodeL* head)
{
    nodeL *p=head;
    while (p->next->next!=NULL)
    {
        printf("%s\n",p->data);
        p=p->next;
    }
    printf(" \n");
}


