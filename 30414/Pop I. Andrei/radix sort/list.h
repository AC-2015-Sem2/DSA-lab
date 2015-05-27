#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct nod
{
    int data;
    struct nod *next;
}NodeT;

NodeT **head, **tail; // list of digits

NodeT *createNewNode(int);
void addToList(int, int);
void deleteList(int);


#endif // LIST_H_INCLUDED
