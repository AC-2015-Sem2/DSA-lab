#include <stdio.h>
#include <stdlib.h>
#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct nodetype
{
    int data;
    struct nodetype *next;
} NodeT;

NodeT* createNode(int code);

#endif // LIST_H_INCLUDED
