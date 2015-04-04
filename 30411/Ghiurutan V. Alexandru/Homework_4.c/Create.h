#ifndef CREATE_H_INCLUDED
#define CREATE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CONTENT 100
typedef struct node
{
    int key;
    int ech;
    struct node *left,*right;
} NodeT;

NodeT *createBinTree(FILE *f);


#endif // CREATE_H_INCLUDED
