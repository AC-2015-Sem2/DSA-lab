#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_OF_CONTENT 100
#ifndef TREEANDLIST_H
#define TREEANDLIST_H

typedef struct node {
    void * content;
    struct node *left, *right;
} NodeT;

typedef struct listL{

    void * content;
    struct listL *next, *prev;
}NodeL;
NodeL *head, *tail, *copyhead;

NodeL *createListNode(void *content);
NodeT *createNode(void *content);
NodeT * createBinTree();
NodeL * getListFromTree(NodeT *node);
void createDoublyLinked(NodeT *node);
void traverse(NodeL *aux);
NodeT * getTreeFromList();

void addLast(void * content);

// printing functions

void prettyPrint(NodeT *root,int recLevel);
void printStringElement(NodeT * node);
void * getStringContent(char * content);
void * (*getContent)(char*);
void (*printElement)(NodeT*);

#endif
