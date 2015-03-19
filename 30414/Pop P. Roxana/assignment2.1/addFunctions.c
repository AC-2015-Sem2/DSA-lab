#include "list_h.h"
#include <stdio.h>
/******************* FUNCTION WHICH CRETAES A NEW NODE **************************************/
node * createNode(int data)
{
    node * p=(node*)malloc(sizeof(node));
    p->next=NULL;
    p->prev=NULL;
    p->data=data;
    return p;
}

/******************* FUNCTION THAT INITIALIZES THE LIST **************************************/
void initList()
{
    List=(sentinel*)malloc(sizeof(sentinel));
    List->head=NULL;
    List->tail=NULL;
    List->length=0;
}

/******************* FUNCTION WHICH ADS A NEW ELEMENT AT THE FRONT OF THE LIST ***************/
void addFirst(int data)
{
    if (List->head==NULL)
    {
        List->head=createNode(data);
        List->tail=List->head;
    }
    else
    {
        node * p=createNode(data);
        p->next=List->head;
        List->head->prev=p;
        List->head=p;
    }
    List->length++;
}

/********************* FUNCTION WHICH ADS A NEW ELEMENT AT THE END OF THE LIST *****************/
void addLast(int data)
{
    if (List->head==NULL)
    {
        List->head=createNode(data);
        List->tail=List->head;
    }
    else
    {
        node * p=createNode(data);
        List->tail->next=p;
        p->prev=List->tail;
        List->tail=p;
    }
    List->length++;
}
