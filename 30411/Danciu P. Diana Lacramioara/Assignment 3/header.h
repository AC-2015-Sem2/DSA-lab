#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodeList
{
    struct nodeList *next;
    struct nodeList *prev;
    int data;
} ListT;

typedef struct nodeTree
{
    struct nodeTree *left;
    struct nodeTree *right;
    int data;
} TreeT;

/* usual tree functions */
TreeT *createStaticTree(void);
void preorder(TreeT *root);
void inorder(TreeT *root);
void postorder(TreeT *root);
int MaxDepth(TreeT *root);

/*functions for my problem */
void AddNodeLast(int code);
TreeT *createNodeTree(int data);
TreeT *createBinTree(void);
ListT *getListFromTree(TreeT *root);
TreeT *getTreeFromList(ListT **head);
void prettyPrint(TreeT *root,int recLevel);
void traverseList(ListT *firstFromList);

#endif // HEADER_H_INCLUDED
