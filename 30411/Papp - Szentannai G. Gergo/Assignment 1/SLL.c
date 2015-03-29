#include "SLL.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int code;
    struct node* next;
} NodeT;

extern NodeT *head, *tail;

/*
    If there are no elements, then head==tail==NULL.
    If there is only one element, then head==tail.
*/

void AF(int x)  // Add First
{
    if ((head==NULL)&&(tail==NULL))
    {
        head=tail=(NodeT*)malloc(sizeof(NodeT*));
        head->code=x;
        head->next=NULL;
    }
    else if((tail==head)&&(tail!=NULL))
    {
        head=(NodeT*)malloc(sizeof(NodeT*));
        head->code=x;
        head->next=tail;
        tail->next=NULL;
    }
    else
    {
        NodeT*p=(NodeT*)malloc(sizeof(NodeT*));
        p->code=x;
        p->next=head;
        head=p;
    }
    tail->next=NULL;
}

void AL(int x)  // Add Last
{
    if ((head==NULL)&&(tail==NULL))
    {
        head=tail=(NodeT*)malloc(sizeof(NodeT*));
        head->code=x;
        head->next=NULL;
    }
    else if((tail==head)&&(tail!=NULL))
    {
        NodeT*aux=(NodeT*)malloc(sizeof(NodeT*));
        aux->code=head->code;
        aux->next=tail;
        tail->code=x;
        tail->next=NULL;
        head=aux;

    }
    else
    {
        NodeT*p=(NodeT*)malloc(sizeof(NodeT*));
        p->code=x;
        p->next=NULL;
        tail->next=p;
        tail=p;
    }
    tail->next=NULL;
}

void DF()  // Delete First
{
    if ((head==NULL)||(head==tail))
    {
        head=tail=NULL;
    }
    else
    {
        NodeT*p=(NodeT*)malloc(sizeof(NodeT*));
        p=head;
        head=head->next;
        free(p);
    }
}

void DL()  // Delete Last
{
    if ((head==NULL)&&(head==tail))
    {
        head=tail=NULL;
    }
    else
    {
        NodeT*p=(NodeT*)malloc(sizeof(NodeT*));
        p=tail;
        NodeT*aux=head;
        while(aux->next!=tail)
        {
            aux=aux->next;
        }
        tail=aux;
        tail->next=NULL;
        free(p);
    }
}

void DOOM_THE_LIST()  // Delete all elements
{
    while (tail!=NULL)
        DF();
    head=tail=NULL;
}

void DE(int x)  // Delete element with code x
{
    NodeT* aux=(NodeT*)malloc(sizeof(NodeT*));
    if(head->code==x)
        DF();
    else if(tail->code==x)
        DL();
    else
    {
        aux=head;
        while((aux!=NULL)&&(aux->code!=x))
        {
            aux=aux->next;
        }
        if (aux!=NULL)
        {
            NodeT* p=aux->next;
            aux->next=aux->next->next;
            free(p);
        }
    }

}

void PRINT_ALL()  // Print all elements
{
    NodeT* aux=(NodeT*)malloc(sizeof(NodeT*));
    aux=head;
    FILE *f;
    f=fopen("output.dat","a");
    if (f==NULL)
    {
        perror("Cannot create/open file");
    }
    while(aux!=NULL)
    {
        fprintf(f,"%d ",aux->code);
        aux=aux->next;
    }
    fprintf(f,"\n");
    fclose(f);
}

void PRINT_F(int x)  // Print First x elements
{
    int i=0;
    NodeT*aux=head;
    FILE *f;
    f=fopen("output.dat","a");
    if (f==NULL)
    {
        perror("Cannot create/open file");
    }
    while(i<x&&aux!=NULL)
    {
        fprintf(f,"%d ",aux->code);
        aux=aux->next;
        i++;
    }
    fprintf(f,"\n");
}

void PRINT_L(int x)  // Print Last x elements
{
    int i=0;
    NodeT*aux=head;
    FILE *f;
    f=fopen("output.dat","a");
    if (f==NULL)
    {
        perror("Cannot create/open file");
    }
    while(aux!=NULL)  // Finding number of elements in list
    {
        i++;
        aux=aux->next;
    }
    if (i<=x)
        PRINT_ALL();
    else
    {
        aux=head;
        int j=0;
        while(aux!=NULL)
        {
            j++;
            if(j>i-x)  // Print starting at the x-th element
            {
                fprintf(f,"%d ",aux->code);
            }
            aux=aux->next;
        }
        fprintf(f,"\n");
    }
}
