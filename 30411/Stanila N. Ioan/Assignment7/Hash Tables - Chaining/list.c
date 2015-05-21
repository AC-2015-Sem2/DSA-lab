#include "list.h"
#include "io.h"

nodeT * createNode(char * content)
{
    nodeT * n = (nodeT*) malloc(sizeof(nodeT));
    n->content = (char*) malloc(sizeof(char) * (MAX_STRING_LENGTH + 1));
    strcpy(n->content, content);
    n->next = NULL;
    return n;
}

void addToList(listT* l, char * content)
{
    //! add last
    nodeT* n = createNode(content);
    if (l->head == NULL) {
        l->head  = l->tail = n;
        l->size++;
    } else {
        l->tail->next = n;
        l->tail = n;
        l->size++;
    }
}