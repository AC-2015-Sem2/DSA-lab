# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#ifndef PARSETREE_H_INCLUDED
#define PARSETREE_H_INCLUDED

typedef struct nod
{
    struct nod *right, *left;
    char *data;
}NodeT;

typedef struct nod1
{
    struct nod1 *next;
    char *elem;
}NodeQ;

NodeQ *first, *last;

void prettyPrint(NodeT *,int);
NodeT *createTree();
NodeT *createNodeT(char *);
void printQ();
void createQ(FILE *);
void dequeue();
void enqueue(char *);


#endif // PARSETREE_H_INCLUDED
