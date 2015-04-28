#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include "queue.h"
NodeT *stack;
void push(int code);
void pop();
NodeT *peekStack();
int isEmptyStack();


#endif // STACK_H_INCLUDED
