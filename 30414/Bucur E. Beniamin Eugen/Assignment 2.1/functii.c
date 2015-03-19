#include "liste.h"

void ft_compute_size()
{
    int     i;
    node    *aux;

    i = 0;
    aux = santinel->head;
    while (aux != NULL)
    {
        aux = aux->next;
        i++;
    }
    santinel->dim = i;
}

void ft_AF(int data)
{
    if (santinel->head == NULL)
    {
        santinel->head = (node*)malloc(sizeof(node));
        santinel->tail = santinel->head;
        santinel->head->data = data;
        santinel->head->next = NULL;
        santinel->head->prev = NULL;
    }
    else
    {
        node *aux;

        aux = (node*)malloc(sizeof(node));
        aux->data = data;
        aux->next = santinel->head;
        aux->prev = NULL;
        santinel->head->prev = aux;
        santinel->head = aux;
    }
}

void ft_AL(int data)
{
    if (santinel->tail == NULL)
    {
        santinel->head = (node*)malloc(sizeof(node));
        santinel->tail = santinel->head;
        santinel->head->data = data;
        santinel->head->next = NULL;
        santinel->head->prev = NULL;
    }
    else
    {
        node *aux;

        aux = (node*)malloc(sizeof(node));
        aux->data = data;
        aux->next = NULL;
        aux->prev = santinel->tail;
        santinel->tail->next = aux;
        santinel->tail = aux;
    }
}

void ft_DF()
{
    if (santinel->head != NULL)
    {
        node *aux;
        aux = santinel->head->next;
        if (santinel->head->next != NULL)
            santinel->head->next->prev = NULL;
        free (santinel->head);
        santinel->head = aux;
    }
}

void ft_DL()
{
    if (santinel->head == santinel->tail)
        ft_DF();
    else if ((santinel->tail != NULL) && (santinel->head != NULL))
    {
        node *aux;

        aux = santinel->tail->prev;
        free(santinel->tail);
        aux->next = NULL;
        santinel->tail = aux;
    }
}

void ft_DOOM_THE_LIST()
{
    while (santinel->head != NULL)
        ft_DF();
}

void ft_DE(int x)
{
    node    *aux;
    node    *aux2;

    if (santinel->head->data == x)
    {
        aux2 = santinel->head->next;
        free (santinel->head);
        santinel->head = aux2;
        santinel->head->prev = NULL;
    }
    aux = santinel->head;
    while (aux != santinel->tail)
    {
        if (aux->next->data == x)
        {
            if (aux->next != santinel->tail)
            {
                aux2 = aux->next;
                aux->next = aux->next->next;
                aux->next->prev = aux;
                free (aux2);
            }
            else
            {
                free (aux->next);
                santinel->tail = aux;
                aux->next = NULL;
            }
        }
        if (aux != santinel->tail)
            aux = aux->next;
    }

}

void ft_PRINT_ALL()
{
    FILE    *out;
    node    *aux;

    out = fopen ("output.dat", "a");
    aux = santinel->head;
    while (aux != NULL)
    {
        fprintf (out, "%d ", aux->data);
        aux = aux->next;
    }
    fprintf (out, "\n");
}

void ft_PRINT_F(int x)
{
    FILE    *out;
    node    *aux;

    if (x <= 0)
        return ;
    out = fopen ("output.dat", "a");
    aux = santinel->head;
    while ((aux != NULL) && (x != 0))
    {
        fprintf (out, "%d ", aux->data);
        aux = aux->next;
        x--;
    }
    fprintf (out, "\n");
}

void ft_PRINT_L(int x)
{
    FILE    *out;
    node    *aux;

    if (x <= 0)
        return ;
    out = fopen ("output.dat", "a");
    aux = santinel->tail;
    while ((aux != NULL) && (x != 1))
    {
        aux = aux->prev;
        x--;
    }
    while (aux != NULL)
    {
        fprintf (out, "%d ", aux->data);
        aux = aux->next;
    }
    fprintf (out, "\n");
}
