#ifndef TREES_H
# define TREES_H

# include <stdio.h>
# include <stdlib.h>
# include <strings.h>

typedef struct  node
{
    struct node *left;
    struct node *right;
    char        data[20];
}               NodeT;

typedef struct  lnode
{
    struct lnode    *next;
    struct lnode    *prev;
    char            data[20];
}               NodeL;
NodeL *head, *tail;

void ft_AL(char *a);
NodeT *createNode(char *a);
NodeT *createBinTree();
NodeL *getListFromTree(NodeT *root);
NodeT *getTreeFromList(NodeL **aux);
void traverseList(NodeL *aux);
void prettyPrint(NodeT *root,int recLevel);

#endif TREES_H
