#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include "node.h"

void enqueue(int content);
void dequeue();
NodeT * peekQueue();
int isEmptyQueue();

//! auxiliary
void printQueue();

NodeT * queue;


#endif // QUEUE_H_INCLUDED

