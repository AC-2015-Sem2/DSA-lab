#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CONTENT 100

typedef struct node
{
    void *data;
    struct node *left,*right;
} NodeT;

typedef struct nod
{
    void *code;
    struct nod *next,*previous;
} NodeL;

NodeT *createBinTree();

NodeL *getListFromTree(NodeT *);

void traverseList(NodeL*);

NodeT *getTreeFromList(NodeL *);

void prettyPrint(NodeT *,int);

void fatalError();

void *getIntegerContent(char *);

void addLast(void*,NodeL*,NodeL *);

void preorder(NodeT *,NodeL *,NodeL *);

void printSelctedElement(void *);

void printElement(NodeT*);
#endif // LIST_H_INCLUDED
