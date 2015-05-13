#include "node.h"

NodeT * createNode(int content){
    NodeT * newN = (NodeT*)malloc(sizeof(NodeT));
    newN->content=content;
    newN->next=NULL;
    return newN;
}

void AL(NodeT **aRef, int code)
{
    if ((*aRef)==NULL)
    {
        (*aRef)=(NodeT*)malloc(sizeof(NodeT*));
        (*aRef)->content=code;
        (*aRef)->next=NULL;
    }
    else if((*aRef)->next==NULL)
    {
        NodeT *aux=(NodeT*)malloc(sizeof(NodeT*));
        aux->content=code;
        aux->next=NULL;
        (*aRef)->next=aux;
    }
    else
    {
        NodeT *aux=(NodeT*)malloc(sizeof(NodeT*));
        aux=(*aRef);
        while (aux->next!=NULL)
        {
            aux=aux->next;
        }
        aux->next=(NodeT*)malloc(sizeof(NodeT*));
        aux->next->content=code;
        aux->next->next=NULL;
    }
}
