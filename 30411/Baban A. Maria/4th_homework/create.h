#ifndef CREATE_H_INCLUDE
#define CREATE_H_INCLUDE
#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int k; //content
    int e; //check echilibrum
    struct node *left;
    struct node *right;
} NodeT;

#endif // CREATE_H_INCLUDE
