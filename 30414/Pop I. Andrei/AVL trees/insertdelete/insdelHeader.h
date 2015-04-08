# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

#ifndef INSERTHEADER_H_INCLUDED
#define INSERTHEADER_H_INCLUDED

typedef struct nod
{
    int data;
    int height;
    struct nod *right, *left;
}NodeT;

NodeT *createNode(int);
NodeT *insertNode(NodeT *, int);
void prettyPrint(NodeT *, int);
NodeT *rightRotation(NodeT *);
NodeT *leftRotation(NodeT *);
NodeT *Balance(NodeT *);
int getBalance(NodeT *);
int maxim(int, int);
NodeT *deleteNode(NodeT*, int);


#endif // INSERTHEADER_H_INCLUDED
