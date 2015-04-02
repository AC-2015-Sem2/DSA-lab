#include "listFunctions.h"

nodeL* allocNode()
{
    return (nodeL*)malloc(sizeof(nodeL));
}

nodeL* createNode(char *data)
{
    nodeL *tempNode = allocNode();
    tempNode->data = data;
    tempNode->next = NULL;
    tempNode->prev = NULL;
    return tempNode;
}

void addLast(nodeL** node, char *data)
{
    if(*node == NULL)
    {
        nodeL *tempNode = createNode(data);
        *node = tempNode;
    }
    else
    {
        nodeL *tempNode = *node;
        while(tempNode->next != NULL)
            tempNode = tempNode->next;

        nodeL *auxNode = createNode(data);
        tempNode->next = auxNode;
        auxNode->prev = tempNode;
        tempNode = auxNode;
    }
}

void printList(nodeL *node)
{
    nodeL* tempNode = node;
    while(tempNode != NULL)
    {
        printf("%s ", tempNode->data);
        tempNode = tempNode->next;
    }
}

