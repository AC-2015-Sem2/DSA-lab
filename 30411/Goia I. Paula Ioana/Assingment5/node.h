#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
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


#endif // NODE_H_INCLUDED
