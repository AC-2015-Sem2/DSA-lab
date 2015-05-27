# include "list.h"

NodeT *createNewNode(int data)
{
    NodeT *newNode = (NodeT*) malloc (sizeof(NodeT));
    newNode -> next =NULL;
    newNode -> data = data;
    return newNode;
}

void addToList(int data, int c)
{
    NodeT *newNode = createNewNode(data);
    newNode -> data = data;

    if(head[c] == NULL)
    {
        head[c] = tail[c] = newNode;
    }
    else
    {
        tail[c] -> next = newNode;
        tail[c] = newNode;
    }
}

void printList()
{
    int i;
    NodeT *p;

    for(i=0; i<=9; i++)
    {
        p = head[i];
        printf("%d  ->  ", i);

        while(p!=NULL)
        {
            printf("%d ", p->data);
            p = p->next;
        }

        printf("\n");

    }
}

void deleteList(int c)
{
    NodeT *p = head[c], *aux;

    while(p!=NULL)
    {
        aux = p->next;
        free(p);
        p = aux;
    }

    head[c] = NULL;
}
