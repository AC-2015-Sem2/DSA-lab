#ifndef TOLIST_H_INCLUDED
#define TOLIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int content;
    struct node * next;
}NodeT;

NodeT * createNode(int content);



#endif // TOLIST_H_INCLUDED
