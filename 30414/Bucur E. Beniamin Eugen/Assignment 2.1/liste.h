#ifndef LISTE_H
# define LISTE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct  str
{
    int data;
    struct str *prev;
    struct str *next;
}               node;

typedef struct  sant
{
    node    *head;
    node    *tail;
    int     dim;
}               ST;
ST *santinel;

void ft_compute_size();
void ft_AF(int data);
void ft_AL(int data);
void ft_DF();
void ft_DL();
void ft_DOOM_THE_LIST();
void ft_DE(int x);
void ft_PRINT_ALL();
void ft_PRINT_F(int x);
void ft_PRINT_L(int x);

#endif

