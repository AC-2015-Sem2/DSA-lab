#include "functions.h"
#include <string.h>



node* createNode(int data)
{
    node* tempNode = ALLOC_NODE();
    tempNode->next = NULL;
    tempNode->prev = NULL;
    tempNode->data = data;
    return tempNode;
}

void printList()
{
    node* tempNode = ALLOC_NODE();
    tempNode = ourList->head;

    FILE* f = fopen("output.dat", "a");

    while(tempNode != NULL)
    {
        fprintf(f, "%d ", tempNode->data);
        tempNode = tempNode->next;
    }
    fprintf(f, "\n");
    fclose(f);
}

void printFirst(int x)
{
    int count = 1;
    node* aux = ourList->head;
    FILE* f = fopen("output.dat", "a");
    while(aux != NULL && count <= x)
    {
        fprintf(f, "%d ", aux->data);
        aux = aux->next;
        count++;
    }
    fprintf(f, "\n");
    fclose(f);
}

void printLast(int x)
{
    FILE* f = fopen("output.dat", "a");

    node* tempNode = ALLOC_NODE();
    tempNode = ourList->tail;

    int i;
    for(i = 1; i < x; i++)
        if(tempNode->prev != NULL)
            tempNode = tempNode->prev;

    while(tempNode != NULL)
    {
        fprintf(f, "%d ", tempNode->data);
        tempNode = tempNode->next;
    }
    fprintf(f, "\n");

    fclose(f);
}

void addFirst(int data)
{
    if(ourList->head == NULL)
    {
        ourList->head = createNode(data);
        ourList->tail = ourList->head;
        ourList->length++;
    }
    else
    {
        node* tempNode = createNode(data);
        tempNode->next = ourList->head;
        ourList->head->prev = tempNode;
        ourList->head = tempNode;
        ourList->length++;
    }
}

void addLast(int data)
{
    if(ourList->tail == NULL)
    {
        ourList->tail = createNode(data);
        ourList->head = ourList->tail;
        ourList->length++;
    }
    else
    {
        node* tempNode = createNode(data);
        ourList->tail->next = tempNode;
        tempNode->prev = ourList->tail;
        ourList->tail = tempNode;
        ourList->length++;
    }
}

void deleteFirst()
{
    if(ourList->head == ourList->tail)
    {
        free(ourList->head);
        ourList->head = NULL;
        ourList->tail = NULL;
        ourList->length=0;
    }
    else
    {
        node* tempNode = ALLOC_NODE();
        tempNode = ourList->head;
        ourList->head = ourList->head->next;
        free(tempNode);
        ourList->length--;
    }
}

void deleteLast()
{
    if(ourList->head == ourList->tail)
    {
        free(ourList->tail);
        ourList->head = NULL;
        ourList->tail = NULL;
        ourList->length=0;
    }
    else
    {
        node* tempNode = ALLOC_NODE();
        tempNode = ourList->tail;
        ourList->tail = ourList->tail->prev;
        free(tempNode);
        ourList->length--;
    }
}

void doom()
{
    node* tempNode = ALLOC_NODE();
    node* auxNode = ALLOC_NODE();
    tempNode = ourList->head;
    auxNode = tempNode;
    while(tempNode != NULL)
    {
        tempNode = tempNode->next;
        free(auxNode);
        auxNode = tempNode;
    }
    ourList->head = NULL;
    ourList->tail = NULL;
    ourList->length = 0;
}

void deleteX(int x)
{
    node* tempNode = ALLOC_NODE();

    if(ourList->head->data == x)
        deleteFirst();
    if(ourList->tail->data == x)
        deleteLast();

    tempNode = ourList->head;
    int i;
    for(i=0; i < ourList->length; i++)
    {
        tempNode = tempNode->next;
        if(tempNode->data == x)
        {
            tempNode->prev->next = tempNode->next;
            tempNode->next->prev = tempNode->prev;
            node* auxNode = ALLOC_NODE();
            auxNode = tempNode;
            tempNode = tempNode->next;
            free(auxNode);
            tempNode = tempNode->prev;
        }
    }

}
