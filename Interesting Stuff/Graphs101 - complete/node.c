#include "node.h"

NodeT * createNode(int content){
    NodeT * newN = (NodeT*)malloc(sizeof(NodeT));
    newN->content=content;
    newN->next=NULL;
    return newN;
}
