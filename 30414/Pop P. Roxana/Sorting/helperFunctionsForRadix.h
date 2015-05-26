#ifndef HELPERFUNCTIONSFORRADIX_H_INCLUDED
#define HELPERFUNCTIONSFORRADIX_H_INCLUDED

#include <stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
} nodeT;

typedef struct queue
{
    nodeT * head, *tail;
} queueT;

///function prototypes
queueT* initQueueArray(int n);
int dequeue(queueT *q);
void enqueue(queueT *q, int data);
int isEmpty(queueT q);
int getmaxNrOfDigits(int *x, int n);

#endif // HELPERFUNCTIONSFORRADIX_H_INCLUDED
