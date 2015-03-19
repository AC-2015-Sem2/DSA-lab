#ifndef HEADER_H
# define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct  str
{
    unsigned money;
    unsigned time;
    struct str *next;
}               node;

typedef struct  str1
{
    unsigned time;
    struct str1 *next;
}               node1;

node *head, *tail;
node1 *head1, *tail1;

void        ft_AL(unsigned data);
void        ft_enq (unsigned money, unsigned time);
int         ft_peek (char c[10], unsigned i);
unsigned    ft_compute (int nrs);

#endif
