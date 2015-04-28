#include "queue.h"

void enqueue(int code)
{
    if(queue==NULL)
    {
        queue=createNode(code);
    }
    else
    {
        NodeT *auxNode=queue;
        while(auxNode->next!=NULL)
        {
            auxNode=auxNode->next;
        }
        auxNode->next=createNode(code);
    }
}

void dequeue()
{
    if(queue!=NULL)
    {
        NodeT *auxNode=queue;
        queue=queue->next;
        free(auxNode);
    }
}

NodeT *peekQueue()
{
    return queue;
}

int isEmptyQueue()
{
    return (queue==NULL);
}
