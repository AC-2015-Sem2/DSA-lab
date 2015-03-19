#include <stdlib.h>
#include "DLL_Deleting.h"
#include "DLL_Def.h"

void DeleteFirst()
{
    if (dll->head!=NULL)
    {
        dll->head = dll->head->next;
        if (dll->head!=NULL)
        {
            free(dll->head->prev);
            dll->head->prev = NULL;
        }
        dll->length--;
    }
}

void DeleteLast()
{
    if (dll->tail!=NULL)
    {
        dll->tail = dll->tail->prev;
        if (dll->tail!=NULL)
        {
            free(dll->tail->next);
            dll->tail->next = NULL;
        }
        dll->length--;
    }
}

void DOOM()
{
    if (dll->head==NULL)
    {
        return;
    }
    nodeT* node;
    while (dll->head!=NULL)
    {
        node = dll->head;
        dll->head = dll->head->next;
        free(node);
    }
    dll->length = 0;
}

void Del(int x)
{
    nodeT* node = dll->head;
    while (node!=NULL)
    {
        if (node->data==x)
        {
            if (node==dll->head)
            {
                DeleteFirst();
            }
            else if (node==dll->tail)
            {
                DeleteLast();
            }
            else
            {
                node->prev->next = node->next;
                node->next->prev = node->prev;
                free(node);
            }
            dll->length--;
            return;
        }
        node = node->next;
    }
}
