#include "file.h"

void Enque(int money, int time, char *name) //add last in the queue
{
    NodeT *elem;

    if (head == NULL)
    {
        head = (NodeT*)malloc(sizeof(NodeT));
        head->money = money;
        head->time = time;
        strcpy(head->name,name);
        head->next = NULL;
    }
    else if (tail == NULL)
    {
        tail = (NodeT*)malloc(sizeof(NodeT));
        tail->money=money;
        tail->time = time;
        strcpy(tail->name,name);
        head->next  = tail;
        tail->next = NULL;
    }
    else
    {
        elem = (NodeT *)malloc(sizeof(NodeT));
        tail->next = elem;
        tail = elem;
        elem->next = NULL;
        elem->money = money;
        strcpy(elem->name,name);
        elem->time = time;
    }
}

void Deque(void) //delete first
{
    NodeT *elem;
    if (head != NULL)
    {
        elem = head;
        head = head->next;
        free(elem);
        if (head == NULL)
            tail = NULL;
    }
}

void PrintList(void)
{
    NodeT *aux = head;

    while (aux != NULL)
    {
        printf("%s %d %d\n", aux->name, aux->money, aux->time);
        aux=aux->next;
    }
}
