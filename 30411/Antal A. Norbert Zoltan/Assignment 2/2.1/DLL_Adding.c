#include <stdlib.h>
#include "DLL_Adding.h"
#include "DLL_Def.h"

void AddFirst(int x)
{
    nodeT* node = (nodeT*)malloc(sizeof(nodeT));
    node->data = x;
    if (dll->head==NULL)
    {
        node->prev = NULL;
        node->next =NULL;
        dll->head = node;
        dll->tail = dll->head;
    }
    else
    {
        node->next = dll->head;
        dll->head->prev = node;
        dll->head = node;
        dll->head->prev = NULL;
        if (dll->tail->prev==NULL)
        {
            dll->tail->prev = dll->head;
        }
    }
    dll->length++;
}

void AddLast(int x)
{
    nodeT* node = (nodeT*)malloc(sizeof(nodeT));
    node->data = x;
    if (dll->tail==NULL)
    {
        node->prev = NULL;
        node->next =NULL;
        dll->tail = node;
        dll->head = dll->tail;
    }
    else
    {
        node->prev = dll->tail;
        dll->tail->next = node;
        dll->tail = node;
        dll->tail->next = NULL;
        if (dll->head->next==NULL)
        {
            dll->head->next = dll->tail;
        }
    }
    dll->length++;
}
