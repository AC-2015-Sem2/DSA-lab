#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED


#include "list.h"

void push(int content);
void pop();
nodeT * peekStack();
int isEmptyStack();

//! auxiliary
void printStack();

nodeT * stack;
#endif // STACK_H_INCLUDED
