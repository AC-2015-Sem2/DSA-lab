#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include "Queue.h"
#include "Tree.h"

#include <stdio.h>

#define LINE_SIZE = 101

FILE* openFile(char* name);

Queue* createQueue(FILE* f);
Tree* buildBinaryTree(Queue** q);


#endif // FUNCTIONS_H_INCLUDED
