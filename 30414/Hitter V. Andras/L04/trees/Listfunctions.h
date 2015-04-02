#ifndef LISTFUNCTIONS_H_INCLUDED
#define LISTFUNCTIONS_H_INCLUDED

void AddLast(char x)
{
    if (head==NULL)
    {
        head=(NodeL *)malloc(sizeof(NodeL));
        head->next=NULL;
        head->prev=NULL;
        head->data=x;
        tail=head;
    }
    else
    {
        NodeL *a=(NodeL *)malloc(sizeof(NodeL));
        a->data=x;
        a->next=NULL;
        a->prev=tail;
        tail->next=a;
        tail=a;
    }
}

void printAll(NodeL *head)
{
    NodeL *aux;
    {
        aux=head;
        while (aux!=NULL)
        {
            int i=aux->data;
            if(i!=42)
                printf("%d ",aux->data);
            else
                printf("%c ",aux->data);
            aux=aux->next;
        }
        printf("\n");
    }
}


#endif // LISTFUNCTIONS_H_INCLUDED
