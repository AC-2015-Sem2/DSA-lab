#include "listFunctions.h"

lNode* alloclNode()
{
    return (lNode*)malloc(sizeof(lNode));
}

lNode* createlNode(int data)
{
    lNode* templNode = alloclNode();
    templNode->data = data;
    templNode->next = NULL;
    return templNode;
}



void initList()
{
    list = (List*)malloc(sizeof(List));
    list->head = alloclNode();
    list->head = NULL;
    list->tail = alloclNode();
    list->tail = NULL;
}

void addToList(int data)
{
    if(list->tail == NULL)
    {
        lNode* templNode = createlNode(data);
        list->tail = templNode;
        list->head = list->tail;
    }
    else
    {
        lNode* templNode = createlNode(data);
        list->tail->next = templNode;
        list->tail = templNode;
    }
}
