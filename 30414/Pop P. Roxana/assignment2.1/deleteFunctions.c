#include "list_h.h"

/****************** FUNCTION THAT DELETES THE FIRST ELEMENT OF THE LIST ****************************/
void deleteFirst()
{
    if (List->head!=NULL)
    {
        if (List->head==List->tail)
        {
            free(List->head);
            List->head=NULL;
            List->tail=NULL;
        }
        else
        {
            node * aux=List->head;
            List->head=List->head->next;
            List->head->prev=NULL;
            free(aux);
        }
        List->length--;
    }
}

/****************** FUNCTION THAT DELETES THE LAST ELEMENT OF THE LIST *****************************/
void deleteLast()
{
    if (List->head!=NULL)
    {
        if (List->head==List->tail)
        {
            free(List->head);
            List->head=NULL;
            List->tail=NULL;
        }
        else
        {
            node * aux=List->tail;
            List->tail=List->tail->prev;
            List->tail->next=NULL;
            free(aux);
        }
        List->length--;
    }
}

/****************** FUNCTION THAT DELETES THE ELEMENTS WITH A SPECIFIC DATA **************************/
void deleteElementByKey(int x)
{
    while(List->head->data==x)
        deleteFirst();
    node * p=List->head;
    while (p!=List->tail)
    {
        if (p->data==x)
        {
            node * aux=p;
            p->prev->next=p->next;
            p->next->prev=p->prev;
            p=p->next;
            free(aux);
            List->length--;
        }
        else
        {
            p=p->next;
        }
    }
    if (List->tail->data==x)
    {
        deleteLast();
    }
}

/****************** FUNCTION THAT DELETES THE WHOLE LIST  *****************************************/
void doomTheList()
{
    while (List->length>0)
    {
        deleteFirst();
    }

}
