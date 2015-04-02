#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

#include <stdio.h>

typedef struct bintree {
    char val;
    struct bintree* left;
    struct bintree* right;
} BinTree;

BinTree* btInit();
BinTree* btCreateNode(char c);
BinTree* btCreateBinTree(FILE* f);
int btHeight(BinTree* t);
void prettyPrint(BinTree* t, int recLevel, FILE* f);

#endif // BINARYTREE_H_INCLUDED
