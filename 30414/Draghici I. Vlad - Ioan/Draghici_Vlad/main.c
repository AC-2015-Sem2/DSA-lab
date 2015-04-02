#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int x;
    struct node *next;
}NodeT;

NodeT *head,*tail;

void AF (int x)
{
    if(head==NULL)
    {
        head=(NodeT*)malloc(sizeof(NodeT*));
        head->x=x;
        head->next=NULL;
        tail=head;
    }
    else if(tail==NULL)
    {
        tail=head;
        NodeT* p=(NodeT*)malloc(sizeof(NodeT*));
        p->x=x;
        p->next=head;
        head=p;
    }
    else
    {
        NodeT* p=(NodeT*)malloc(sizeof(NodeT*));
        p->x=x;
        p->next=head;
        head=p;
    }
}
void AL(int x)
{
    if(head==NULL)
    {
        head=(NodeT*)malloc(sizeof(NodeT*));
        head->x=x;
        head->next=NULL;
        tail=head;
    }
    else
    {
        NodeT* p=(NodeT*)malloc(sizeof(NodeT*));
        p->x=x;
        p->next=NULL;
        tail->next=p;
        tail=p;

    }
}
void PrintList()
{
    NodeT *aux=head;
    while(aux!=NULL)
    {
        printf("%d ",aux->x);
        aux=aux->next;
    }
}


int main()
{

    return 0;
}
