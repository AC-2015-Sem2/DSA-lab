#include "node.h"

NodeT * createNode(int data){
    NodeT * p = (NodeT*)malloc(sizeof(NodeT));
    p->content=data;
    p->next=NULL;
    return p;
}
