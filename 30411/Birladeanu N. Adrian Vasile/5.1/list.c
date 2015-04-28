#include "list.h"

NodeT* createNode(int code)
{
    NodeT* p=(NodeT*)malloc(sizeof(NodeT));
    p->data=code;
    p->next=NULL;
    return p;
}
