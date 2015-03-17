#include "header.h"

void ft_AL(unsigned time)
{
    if (tail1 == NULL)
    {
        head1 = (node1*)malloc(sizeof(node1));
        tail1 = head1;
        head1->time = time;
        head1->next = NULL;
    }
    else
    {
        node1 *aux;

        aux = (node1*)malloc(sizeof(node1));
        aux->time = time;
        aux->next = NULL;
        tail1->next = aux;
        tail1 = aux;
    }
}

void ft_enq (unsigned money, unsigned time)
{
    if (tail == NULL)
    {
        head = (node*)malloc(sizeof(node));
        tail = head;
        head->money = money;
        head->time = time;
        head->next = NULL;
    }
    else
    {
        node *aux;
        aux = (node*)malloc(sizeof(node));
        aux->money = money;
        aux->time = time;
        aux->next = NULL;
        tail->next = aux;
        tail = aux;
    }
}

int ft_peek (char c[10], unsigned i)
{
    if (!(strcmp (c, "time")))
    {
        node *aux;

        aux = head;
        while ((i > 0) && (aux != NULL))
        {
            aux = aux->next;
            i--;
        }
        if (aux != NULL)
            return aux->time;
        return (-1);
    }
    if (!(strcmp (c, "money")))
    {
        node *aux;

        aux = head;
        while ((i > 0) && (aux != NULL))
        {
            aux = aux->next;
            i--;
        }
        if (aux != NULL)
            return aux->money;
        return (-1);
    }
    return 0;
}

unsigned ft_compute (int nrs)
{
    unsigned mrc;
    unsigned i;

    i = 0;
    mrc = 0;
    while (nrs > 0)
    {
        if (ft_peek("time", i) == -1)
            return (mrc);
        if (ft_peek("time", i) <= nrs)
            mrc += ft_peek("money", i);
        nrs -= ft_peek("time", i);
        i++;
    }
    return (mrc);
}
