#include "list_h.h"

/****************** FUNCTION THAT PRINTS ALL THE ELEMENTS OF A LIST *****************/
void printAll(FILE * g)
{
    node * p=List->head;
    while (p!=NULL)
    {
        fprintf(g,"%d ",p->data);
        p=p->next;
    }
    fprintf(g,"\n");
}

/****************** FUNCTION THAT PRINTS THE FIRST x ELEMENTS OF A LIST *************/
void printFirst(FILE * g,int x)
{
    node*p=List->head;
    int k=1;
    while((p!=NULL)&&(k<=x))
    {
        fprintf(g,"%d ",p->data);
        p=p->next;
        k++;
    }
    fprintf(g,"\n");
}

/****************** FUNCTION THAT PRINTS THE LAST x ELEMENTS OF A LIST **************/
void printLast(FILE * g, int x)
{
    node * p=List->tail;
    int k=1;
    while((p!=List->head)&&(k<x))
    {
        p=p->prev;
        k++;
    }
    while (p!=NULL)
    {
        fprintf(g,"%d ",p->data);
        p=p->next;
    }
    fprintf(g,"\n");
}
