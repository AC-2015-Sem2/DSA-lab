#ifndef LIST_H
#define LIST_H

#include <stdio.h>

typedef struct nodeL {
    struct nodeL *next, *prev;
    char* val;
} NodeL;

typedef struct s_list {
    NodeL *first, *last;
} List;

NodeL* newNodeL(char* val);

// use list = newList to create an
// initialized list
List* newList();
// use to deallocate memory
void freeList(List* l);

void addFirst(List* l, char* val);
void addLast(List* l, char* val);

int iterate(NodeL** n);

List* createList(FILE* in);
void printAll(FILE* out, List* l);

NodeL* getLast(List* l);

#endif // LIST_H
