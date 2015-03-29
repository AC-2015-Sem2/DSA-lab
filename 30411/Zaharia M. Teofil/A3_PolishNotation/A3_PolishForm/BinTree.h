#ifndef BINTREE_H
#define BINTREE_H

#include "List.h"
#include "Queue.h"
#include <stdio.h>

typedef struct nodeT {
	char* val;
    struct nodeT *l, *r;
} NodeT;

typedef struct bTree {
	NodeT* root;
	int height;
} BTree;

void printNodeT(FILE* out, NodeT* n);

NodeT* newNodeT(char* data);
BTree* newBTree();
void freeBTree(BTree* bt);
void recFree(NodeT* n);

BTree* treeFromList(List* l);
NodeT* recCreate(NodeL** iterator);

List* listFromTree(BTree* bt);
void recList(List* l, NodeT* nt);

int getHeight(BTree* bt);
int recHeight(NodeT* n);

int spacing(int height, int level, int userSet);
int offset(int height, int level, int userSet);

void prettyPrint(FILE* out, BTree* bt);

#endif // BINTREE_H
