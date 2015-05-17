#include "list.h"
#include "io.h"

nodeT * createNode(char * content)
{
    nodeT * n = (nodeT*) malloc(sizeof(nodeT));
    n->content = (char*) malloc(sizeof(char) * (MAX_STRING_LENGTH+1));
    strcpy(n->content, content);
    n->next = NULL;
    return n;
}

void addToList(listT *l, char * content)
{
    //! add last
    nodeT *newNode = createNode(content);

    if(l->size == 0)
    {
        l->size +=1;
        l->head = l->tail = newNode;
    }
    else
    {
        l->size +=1;
        l->tail->next = newNode;
        l->tail = newNode;
    }

}
