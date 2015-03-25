#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_OF_CONTENT 100

typedef struct node {
    void * content;
    struct node *left, *right;
} NodeT;

void (*printElement)(NodeT*);
void * (*getContent)(char*);

NodeT * createBinTree();
NodeT * createStaticBinTree();
void preorder(NodeT *root);
void inorder(NodeT *root);
void postorder(NodeT *root);
void prettyPrint(NodeT *root,int recLevel);

// print functions
void printStringElement(NodeT * node);
void printIntegerElement(NodeT * node);

void * getStringContent(char * content);
void * getIntegerContent(char * content);
