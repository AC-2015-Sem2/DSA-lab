#include "node.h"

NodeT * createNode(int content)
{
    NodeT * newN = (NodeT*)malloc(sizeof(NodeT));
    newN->content=content;
    newN->next=NULL;
    return newN;
}

void AddLast(int content)
{
    if(L == NULL)
    {
        L = createNode(content);
    }
    else
    {
        NodeT * aux = L;
        while(aux->next!=NULL)
        {
            aux=aux->next;
        }
        aux->next=createNode(content);
    }
}
