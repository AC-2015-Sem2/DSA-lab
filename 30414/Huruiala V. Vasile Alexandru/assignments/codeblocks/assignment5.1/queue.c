#include "queue.h"

void enq(node** tail, int data, int* firstNode)
{
    node* NewNode = createNode(data);
    if(*tail == NULL)
    {
        *tail = NewNode;
        *firstNode = 1;
    }
    else
    {
        (*tail)->next = NewNode;
        *tail = NewNode;
        *firstNode = 0;
    }
}

void deq(node** head)
{
    if(*head != NULL)
    {
        node* del = *head;
        *head = (*head)->next;
        del->data = 0;
        del->next = NULL;
        free(del);
    }
}

void printQ(node* head)
{
    node* aux = head;
    while(aux != NULL)
    {
        printf("%d ", aux->data);
        aux = aux->next;
    }
    printf("\n");
}

