#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#define MAX_NR_OF_CHARS = 101

#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"

typedef struct tree {
    char* val;
    struct tree *left, *right;
} Tree;

Tree* createNode(char* s);
void preorder(Tree* t);

#endif // TREE_H_INCLUDED
