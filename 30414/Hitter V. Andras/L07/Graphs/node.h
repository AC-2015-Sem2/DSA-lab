#ifndef _node_
#define _node_

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int content;
    struct node * next;
}NodeT;

void AddLast(int content);
NodeT * createNode(int content);
NodeT* MatrixToList();
void ListToMatrix(NodeT *L,FILE *f);
NodeT* L;

#endif
