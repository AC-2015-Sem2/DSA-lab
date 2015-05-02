#include "node.h"

NodeT *createNode(int code)
{
    NodeT *newNode=(NodeT *)malloc(sizeof(NodeT));
    newNode->content=code;
    newNode->next=NULL;
    return newNode;
}
