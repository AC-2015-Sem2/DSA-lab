#include "list.h"
#include "io.h"

nodeT * createNode(char * content)
{
    nodeT* n = (nodeT*)malloc(sizeof(nodeT));
    n->content = (char*)malloc(sizeof(char) * (MAX_STRING_LENGTH + 1));
    strcpy(n->content, content);
    n->next = NULL;
    return n;
}

void addToList(listT* l, char* content)
{
    if(l->head == NULL)
    {
        l->head = createNode(content);
        l->tail = l->head;
    }
    else
    {
        nodeT* New = createNode(content);
        l->tail->next = New;
        l->tail = New;
    }
    l->size++;
}
