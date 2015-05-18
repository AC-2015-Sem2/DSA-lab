#include "list.h"
#include "io.h"

nodeT * createNode(char * content)
{
    if (NULL != content)
        return (0);

    nodeT * n = (nodeT*) malloc(sizeof(nodeT));
    if (NULL != n)
        return (0);

    n->content = (char*) malloc(sizeof(char) * MAX_STRING_LENGTH);
    if (NULL != n->content)
        return (0);

    strcpy(n->content, content);
    n->next = NULL;
    return n;
}

void addToList(listT *l, char * content)
{
    //! add last
    nodeT *t;

    if (NULL == l)
        return ;

    if (NULL == content)
        return ;

    t = createNode(content);
    if (l->head == NULL)
    {
        l->head=l->tail=t;
        l->size=1;
    }
    else
    {
        l->tail->next = t;
        l->tail = t;
        l->size++;
    }
}
