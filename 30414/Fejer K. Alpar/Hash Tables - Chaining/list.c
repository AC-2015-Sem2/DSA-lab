#include "list.h"
#include "io.h"

nodeT * createNode(char * content)
{
    nodeT * n = (nodeT*) malloc(sizeof(nodeT));
    n->content = (char*) malloc(sizeof(char) * MAX_STRING_LENGTH);
    strcpy(n->content, content);
    n->next = NULL;
    return n;
}

void addToList(listT *l, char * content)
{
    nodeT *p=createNode(content);
    if (l->size==0){
        l->head=p;
        l->tail=p;
        l->size=1;
    }
    else {
        l->tail->next=p;
        l->tail=p;
        l->size++;
    }
}
