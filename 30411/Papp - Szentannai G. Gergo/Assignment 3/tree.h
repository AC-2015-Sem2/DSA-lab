#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#define MAX_SIZE_OF_CONTENT 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct node {
    char * str;
    struct node *left, *right;
} NodeT;  // Bin. Tree

typedef struct nodel {
    char * str;
    struct nodel *next;
} NodeL; // Singly Linked List




// SLL Functions:
void AL(NodeL**, NodeL**, char*);

void DF(NodeL**);  // Delete First

void PRINT_ALL(NodeL*);




//

NodeT *  createBinTree(FILE*);

void prettyPrint(NodeT*,int);

NodeL * getListFromTree(NodeT*);

void printList(NodeL*);

NodeT * getTreeFromList(NodeL**);


#endif // TREE_H_INCLUDED
