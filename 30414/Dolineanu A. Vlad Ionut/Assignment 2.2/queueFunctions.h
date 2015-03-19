#ifndef QUEUEFUNCTIONS_H_INCLUDED
#define QUEUEFUNCTIONS_H_INCLUDED

#include <stdlib.h>

typedef struct qNode
{
    char *name;
    int x;
    int y;
    struct qNode* next;
}Node;

typedef struct qHeader
{
    Node *first;
    Node *last;
}Queue;

Queue* queue;

Node* allocNode();
Node* createNode(char*, int, int);
void enqueue(char*, int, int);
Node* peek();
void initQueue();

#endif // QUEUEFUNCTIONS_H_INCLUDED
