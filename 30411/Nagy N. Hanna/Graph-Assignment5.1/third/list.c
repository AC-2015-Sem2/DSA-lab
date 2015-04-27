#include "list.h"

nodeT* create(int value)
{
    nodeT* p=(nodeT*)malloc(sizeof(nodeT));
    p->code=value;
    p->next=NULL;
    return p;
}
