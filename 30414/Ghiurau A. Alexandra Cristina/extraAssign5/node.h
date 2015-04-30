#ifndef _node_
#define _node_

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int content;
    struct node * next;
}NodeT;

NodeT *head;
/*
typedef struct list{
    int data;
    struct list * next;
}listL;
listL * head;*/

NodeT **adjList;



NodeT * createNode(int content);

//listL * createNodeForList(int data);

#endif
