#include "list.h"
#include "io.h"

nodeT * createNode(char * content)
{
    nodeT * n = (nodeT*) malloc(sizeof(nodeT));
    n->content = (char*) malloc(sizeof(char) * MAX_STRING_LENGTH+1);
    strcpy(n->content, content);
    n->next = NULL;
    return n;
}

void addToList(listT* l, char * content)
{
    //! add last
    if (l->size==0)
        {
            l->head=createNode(content);
            l->size=1;
            l->tail=NULL;
        }
        else {if (l->size==1)
        {
            l->tail=createNode(content);
            l->head->next=l->tail;
            l->size=2;
        }
          else if (l->size>1)
          {
              nodeT *newNode=createNode(content);
              l->size++;
              l->tail->next=newNode;
              l->tail=newNode;
              free(newNode);
          }
        }

}
