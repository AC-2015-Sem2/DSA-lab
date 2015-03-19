#ifndef LISTFUNCTIONS_H_INCLUDED
#define LISTFUNCTIONS_H_INCLUDED

#include<stdlib.h>

typedef struct lNode
{
    int data;
    struct lNode* next;
}lNode;

typedef struct lHeader
{
    lNode *head;
    lNode *tail;
}List;

List* list;

lNode* alloclNode();
lNode* createlNode(int);
void addToList(int);
void initList();

#endif // LISTFUNCTIONS_H_INCLUDED
