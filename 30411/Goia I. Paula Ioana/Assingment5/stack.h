#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include "node.h"

void push(int content);
void pop();
NodeT * peekStack();
int isEmptyStack();

//! auxiliary
void printStack();

NodeT * stack;


#endif // STACK_H_INCLUDED
