#ifndef DOUBLE_LIST_H
#define DOUBLE_LIST_H

#include <stdio.h>

typedef struct node {
    int val;
    struct node *next, *prev;
} Node;

// constructor
Node* newNode(int val);

typedef struct double_list {
    Node *first, *last;
    int len;
} DoubleList;

// constructor, destructor
DoubleList* newList();
void freeList(DoubleList* l);

// element operations
void addFirst(DoubleList* l, int val);
void addLast(DoubleList* l, int val);

void delFirst(DoubleList* l);
void delLast(DoubleList* l);
void doom(DoubleList* l);
void del(DoubleList* l, int val);

// printers
void printAll(FILE* out, DoubleList* l);
void printFirst(FILE* out, DoubleList* l, int x);
void printLast(FILE* out, DoubleList* l, int x);

#endif // DOUBLE_LIST_H
