#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define ALLOC_NODE() (node*)malloc(sizeof(node))

typedef struct st_node
{
    int data;
    struct st_node* next;
    struct st_node* prev;
}node;

typedef struct sentinel
{
    node* head;
    node* tail;
    int length;
}list;

list *ourList;
FILE* f;

node* createNode(int);
void printList();
void printFirst(int);
void printLast(int);
void addFirst(int);
void addLast(int);
void deleteFirst();
void deleteLast();
void doom();
void deleteX();

#endif // FUNCTIONS_H_INCLUDED
