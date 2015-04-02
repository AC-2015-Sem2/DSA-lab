# include <stdio.h>
# include <stdlib.h>

#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

typedef struct nod
{
    struct nod *left, *right;
    char *data;
}NodeT;

typedef struct nod1
{
    struct nod1 *next, *prev;
    char *elem;
}NodeL;


NodeT *createBinaryTree();
void prettyPrint(NodeT *,int);
NodeT *getFromList(NodeL **);
void traverseList(NodeL *);
NodeL *getList(NodeT *);
void constructList(NodeT *, NodeL **);
void addNode(NodeL **, char *);
NodeT *create(FILE *);
NodeT *newNode(char *);


#endif // TREE_H_INCLUDED
