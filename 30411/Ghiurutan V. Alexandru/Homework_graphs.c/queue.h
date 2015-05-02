#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include "readAdjMatrix.h"
NodeT *queue;
void enqueue(int code);
void dequeue();
NodeT *peekQueue();
int isEmptyQueue();


#endif // QUEUE_H_INCLUDED
