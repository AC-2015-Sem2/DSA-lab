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

void addToList(listT l, char * content)
{
     if(l.tail == NULL)
    {
        nodeT *x = (nodeT*)malloc(sizeof(nodeT));
        x->next = NULL;
        x->content = content;
        l.head = x;
        l.tail = x;
        l.size++;
    }
    else
    {
        nodeT *y = (nodeT*)malloc(sizeof(nodeT));
        y->content = content;
        y->next = NULL;
        l.tail->next = y;
        l.size++;
    }
}
