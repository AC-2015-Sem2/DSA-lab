#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#define MAX_NR_OF_CHARS 15

#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
    int val;
    int height;
    struct tree *left, *right;
} Tree;

Tree* createNode(int d);

Tree* insertLeaf(Tree* t, int value);
Tree* rotLeft(Tree* t);
Tree* rotRight(Tree* t);

int getDelta(Tree* t);
int treeHeight(Tree* t);
int uHeight(Tree* t);

Tree* minValNode(Tree* t);
Tree* deleteNode(Tree* t, int value);

//util
int maxEl(int a, int b);

#endif // TREE_H_INCLUDED
