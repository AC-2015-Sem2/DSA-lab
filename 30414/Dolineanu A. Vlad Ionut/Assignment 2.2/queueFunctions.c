#include "queueFunctions.h"

Node* allocNode(){
    return (Node*)malloc(sizeof(Node));
}

Node* createNode(char *name, int x, int y)
{
    Node* tempNode = allocNode();
    tempNode->name = name;
    tempNode->x = x;
    tempNode->y = y;
    tempNode->next = NULL;
    return tempNode;
}

void enqueue(char *name, int x, int y)
{
    if(queue->last == NULL)
    {
        Node* tempNode = createNode(name, x, y);
        queue->last = tempNode;
        queue->first = queue->last;
    }
    else
    {
        Node* tempNode = createNode(name, x, y);
        queue->last->next = tempNode;
        queue->last = tempNode;
    }
}

Node* peek()
{
    return queue->first;
}

void initQueue()
{
    queue = (Queue*)malloc(sizeof(queue));
    queue->first = NULL;
    queue->last = NULL;
}
