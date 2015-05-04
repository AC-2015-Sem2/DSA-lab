#include "list.h"
//#include "node.h"

NodeT *head, *tail;

void addLast(int code)
{
    if(head==NULL)          // hogyha ures peldaul, exact ca inainte
    {

        head=(NodeT*)malloc(sizeof(NodeT*));
        head->content=code;
        head->next=NULL;
        tail=head;
    }
    else
    {
        NodeT* r=(NodeT*)malloc(sizeof(NodeT*));
        r->content=code;
        r->next=NULL;
        tail->next=r;
        tail=r;
    }

}

void printList()
{
    NodeT* aux=head;
    while(aux!=NULL)
    {
        printf("%d ",aux->content);
        aux=aux->next;
    }
    printf("\n");
}
