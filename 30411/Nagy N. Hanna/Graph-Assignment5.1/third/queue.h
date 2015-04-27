#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "list.h"

void enqueue(int content);
void dequeue();
nodeT * peekQueue();
int isEmptyQueue();

//! auxiliary
void printQueue();

nodeT * queue;

#endif // QUEUE_H_INCLUDED
