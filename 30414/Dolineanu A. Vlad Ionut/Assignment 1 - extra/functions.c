#include "functions.h"

node* createNode(int data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->next = NULL;
    newNode->data = data;
    return newNode;
}

void addLast(lst* list, int data)
{
    if(list->tail == NULL)
    {
        list->tail = createNode(data);
        list->head = list->tail;
    }
    else
    {
        node* newNode = createNode(data);
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

void printList(lst* list)
{
    node* aux = list->head;
    while(aux!=NULL)
    {
        printf("%d ", aux->data);
        aux=aux->next;
    }
}

country* createCountry()
{
    country* newCountry = (country*)malloc(sizeof(country));
    newCountry->next = NULL;
    newCountry->waves = createList();
    return newCountry;
}

lst* createList()
{
    lst* newList = (lst*)malloc(sizeof(lst));
    newList->head = NULL;
    newList->tail = NULL;
    return newList;
}
