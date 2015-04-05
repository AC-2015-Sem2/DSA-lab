#ifndef AVL_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "NodeT.h"

#define MAX_SIZE_OF_CONTENT 100

// General tree functions
NodeT* createBinTree();
NodeT* createStaticBinTree();
void preorder(NodeT* root);
void inorder(NodeT* root);
void postorder(NodeT* root);
void prettyPrint(NodeT* root, int recLevel);


// AVL functions
void updateHeight(NodeT* root);
int balance(NodeT* root);
int childCount(NodeT* root);
NodeT* minNode(NodeT* root);

NodeT* rotL(NodeT* root);
NodeT* rotR(NodeT* root);
NodeT* rotLR(NodeT* root);
NodeT* rotRL(NodeT* root);

NodeT* insertIn(NodeT* root, NodeT* newNode);
NodeT* remFrom(NodeT* root, NodeT* toDel);


#endif // AVL_TREE_H
