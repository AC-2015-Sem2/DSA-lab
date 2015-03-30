#include "header.h"

/*************** Function that creates a node for the list*******/
nodeL * createNodeL(char * data)
{
    nodeL *p=(nodeL*)malloc(sizeof(nodeL));
    p->next=NULL;
    p->prev=NULL;
    p->data=(char*)malloc(10*sizeof(char));
    strcpy(p->data,data);
    return p;
}

/*************** Function that adds a node at the end of a list **/
void addLast(nodeL * * head, char * data)
{
    nodeL * tail;
    if ((*head)==NULL)
    {
        (*head)=createNodeL(data);
    }
    else
    {
        tail=(*head);
        while(tail->next!=NULL)
        {
            tail=tail->next;
        }
        nodeL * p=createNodeL(data);
        tail->next=p;
        p->prev=tail;
    }
}

/****************** Function that creates a list from a bin tree ****/
nodeL * getListFromTree(nodeT * root)
{
    if (root==NULL)
    {
        char * data=malloc(sizeof(char)*10);
        strcpy(data,"*");
        addLast(&headG,data);
        return 0;
    }
    {
        addLast(&headG,root->data);
        getListFromTree(root->left);
        getListFromTree(root->right);
    }
    return headG;
}

/***************** Function that traverses the list and also prints its elements */
void traverseList(nodeL * head)
{
    fprintf(g,"The elements in the list are as follows\n");
    nodeL * p=head;
    while(p!=NULL)
    {
        fprintf(g,"%s ",p->data);
        p=p->next;
    }
    fprintf(g,"\n");
}
