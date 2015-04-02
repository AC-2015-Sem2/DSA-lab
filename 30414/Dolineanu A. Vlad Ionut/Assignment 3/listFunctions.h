#ifndef LISTFUNCTIONS_H_INCLUDED
#define LISTFUNCTIONS_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
FILE* f;

typedef struct nodeL{
    char *data;
    struct nodeL* next;
    struct nodeL* prev;
}nodeL;

nodeL* allocNode();
nodeL* createNode(char*);
void addLast(nodeL** , char*);
void printList(nodeL*);

#endif // LISTFUNCTIONS_H_INCLUDED
