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
    //! add last

    if(l->tail == NULL)
    {
        nodeT *node = (nodeT*)malloc(sizeof(nodeT));
        node->content = content;
        node->next = NULL;
        l->head = node;
        l->tail = node;
        l->size++;
    }
    else
    {
        nodeT *node = (nodeT*)malloc(sizeof(nodeT));
        node->content = content;
        node->next = NULL;
        l->tail->next = node;
        l->size++;
    }

}
