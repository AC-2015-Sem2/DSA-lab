#include "list_h.h"
second* createNodeS(int x)
{
    second * p=(second*)malloc(sizeof(second));
    p->sec=x;
    p->next=NULL;
    return p;
}

void enqueueS(int x)
{
    if (shead==NULL)
    {
        shead=createNodeS(x);
        stail=shead;
    }
    else
    {
        second * newNode;
        newNode=createNodeS(x);
        stail->next=newNode;
        stail=newNode;
    }
}

void dequeueS()
{
    if (shead!=NULL)
    {
        second * aux=shead;
        shead=shead->next;
        if (shead==NULL) stail=NULL;
        free(aux);
    }
}

