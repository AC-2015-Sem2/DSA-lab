#ifndef _node_
#define _node_

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int content;
    struct node * next;
}NodeT;

NodeT * createNode(int content);

#endif
