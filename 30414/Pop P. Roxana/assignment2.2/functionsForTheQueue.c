#include "list_h.h"
node* createNode(char * s,int x, int y)
{
    node * p=(node*)malloc(sizeof(node));
    p->name=s;
    p->money=x;
    p->sec=y;
    p->next=NULL;
    return p;
}

void enqueue(char *s,int x, int y)
{
    if (head==NULL)
    {
        head=createNode(s,x,y);
        tail=head;
    }
    else
    {
        node * newNode;
        newNode=createNode(s,x,y);
        tail->next=newNode;
        tail=newNode;
    }
}

void dequeue()
{
    if (head!=NULL)
    {
        node * aux=head;
        head=head->next;
        if (head==NULL) tail=NULL;
        free(aux);
    }
}

