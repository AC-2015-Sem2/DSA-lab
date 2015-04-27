#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int code;
    struct node *next;
}nodeT;

nodeT *create(int value);

#endif // LIST_H_INCLUDED
