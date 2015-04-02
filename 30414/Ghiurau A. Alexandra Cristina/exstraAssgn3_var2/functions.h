#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#define MAX_SIZE_OF_CONTENT 100
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    void * content;
    struct node *left, *right;
} NodeT;

void * (*getContent)(char*);
void (*printElement)(NodeT*, FILE *fileOutput);

void printStringElement(NodeT * node, FILE *fileOutput);
void * getStringContent(char * content);
NodeT *createNode(void *content);
NodeT *createBinTree(FILE *file);
void prettyPrint(NodeT *root,int recLevel, FILE *fileOutput);

#endif // FUNCTIONS_H_INCLUDED
