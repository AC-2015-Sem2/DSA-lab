#include "list.h"

void enqueue(int content);
void dequeue();
NodeT * peekQueue();
int isEmptyQueue();

//! auxiliary
void printQueue();

NodeT * queue;
