#include "queue.h"

void enqueue(int content)
{
    if(queue == NULL)
    {
        queue = createNode(content);
    }
    else
    {
        NodeT * aux = queue;
        while(aux->next!=NULL)
        {
            aux=aux->next;
        }
        aux->next=createNode(content);
    }
}

void dequeue()
{
    if(queue!=NULL)
    {
        queue=queue->next;
    }
}

NodeT * peekQueue()
{
    return queue;
}

int isEmptyQueue()
{
    return queue == NULL;
}


//! auxiliary
void printQueue()
{
    NodeT * aux=queue;
    while(aux!=NULL)
    {
        printf("%d ",aux->content );
        aux=aux->next;
    }
    printf("\n");
}

void printList()
{
    printf("Printing the list...\n");
    NodeT * aux=L;
    while(aux!=NULL)
    {
        if(aux->content!=-1)
        {
            printf("%d ",aux->content );
            aux=aux->next;
        }
        else
        {
            printf("_ ");
            aux=aux->next;
        }
    }
    printf("\n\n");
}

