#include "liste.h"

void print_list()
{
    node *aux;

    aux = head;
    while (aux != NULL)
    {
        printf ("%d ", aux->data);
        aux = aux->next;
    }
}

void ft_AF(int data)
{
    if (head == NULL)
    {
        head = (node*)malloc(sizeof(node));
        tail = head;
        head->data = data;
        head->next = NULL;
    }
    else
    {
        node *aux;
        aux = (node*)malloc(sizeof(node));
        aux->data = data;
        aux->next = head;
        head = aux;
    }
}

void ft_AL(int data)
{
    if (tail == NULL)
    {
        head = (node*)malloc(sizeof(node));
        tail = head;
        head->data = data;
        head->next = NULL;
    }
    else
    {
        node *aux;
        aux = (node*)malloc(sizeof(node));
        aux->data = data;
        aux->next = NULL;
        tail->next = aux;
        tail = aux;
    }
}

void ft_DF()
{
    if (head != NULL)
    {
        node *aux;
        aux = head->next;
        free (head);
        head = aux;
    }
}

void ft_DL()
{
    if (head == tail)
        ft_DF();
    else if ((tail != NULL) && (head != NULL))
    {
        node *aux;
        aux = head;
        while (aux->next != tail)
            aux = aux->next;
        free (aux->next);
        aux->next = NULL;
        tail = aux;
    }
}

void ft_DOOM_THE_LIST()
{
    while (head != NULL)
        ft_DF();
}

void ft_DE(int x)
{
    node *aux, *aux2;

    if (head->data == x)
    {
        aux2 = head->next;
        free (head);
        head = aux2;
    }
    aux = head;
    while (aux != tail)
    {
        if (aux->next->data == x)
        {
            if (aux->next != tail)
            {
                aux2 = aux->next;
                aux->next = aux->next->next;
                free (aux2);
            }
            else
            {
                free (aux->next);
                tail = aux;
                aux->next = NULL;
            }
        }
        if (aux != tail)
            aux = aux->next;
    }

}

void ft_PRINT_ALL()
{
    FILE    *out;
    node    *aux;

    out = fopen ("output.dat", "a");
    aux = head;
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
    aux = head;
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
    int     y;

    if (x <= 0)
        return ;
    out = fopen ("output.dat", "a");
    aux = head;
    y = 0;
    while (aux != NULL)
    {
        y++;
        aux = aux->next;
    }
    aux = head;
    while (aux != NULL)
    {
        if (y <= x)
            fprintf (out, "%d ", aux->data);
        aux = aux->next;
        y--;
    }
    fprintf (out, "\n");
}
