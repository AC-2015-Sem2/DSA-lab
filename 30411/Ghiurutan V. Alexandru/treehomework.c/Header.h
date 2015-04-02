#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CONTENT 100

typedef struct node{
int data;
struct node *left,*right;}NodeT;

typedef struct nod{
char code[10];
struct nod *next,*previous;}NodeL;
NodeL *head;
NodeL *tail;

NodeT *createBinTree();
NodeL *createListFromTree(NodeT *);
void traverseList(NodeL *);
NodeT *getTreeFromList();
void prettyPrint(NodeT *,int recLevel);
void printElement(NodeT *root);
void preorder(NodeT *root);
void addlast(char key[]);

#endif // HEADER_H_INCLUDED
