#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include "node.h"

typedef struct list {
    NodeT* content;
    struct list* next;
} List;

void addElement(List**);
void addContentForElement(List**, int);
void printList(List*);
#endif // LIST_H_INCLUDED
