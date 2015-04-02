#include "binaryTree.h"

#include <stdlib.h>

BinTree* btInit() {
    BinTree* t = NULL;
    return t;
}

BinTree* btCreateNode(char c) {
    BinTree* t = (BinTree*)malloc(sizeof(BinTree));
    t->val = c;
    t->left = t->right = NULL;
    return t;
}

BinTree* btCreateBinTree(FILE* f) {
    BinTree* t = NULL;
    char c;
    fscanf(f, " %c ", &c);
    if (c == '*') {
        return NULL;
    } else {
        t = btCreateNode(c);
        t->left = btCreateBinTree(f);
        t->right = btCreateBinTree(f);
    }
    return t;
}

int btHeight(BinTree* root) {
    if (root == NULL) {
        return 0;
    } else {
        int hl = btHeight(root->left);
        int hr = btHeight(root->right);
        if (hl > hr) {
            return hl + 1;
        } else {
            return hr + 1;
        }
    }
}

void printElement(BinTree* t, FILE* f) {
    if (f == stdin) {
        printf("%c ", t->val);
    } else {
        fprintf(f, "%c ", t->val);
    }
}

void prettyPrint(BinTree* t, int recLevel, FILE* f) //! root, index, length, reccurence level
{
    if(t == NULL) {
        recLevel--; //! reached leaf, must decrement recurence level
        return;
    }
    recLevel++; //! otherwise increment it
    prettyPrint(t->right, recLevel, f); //! keep going right in the tree
    int j=0;
    //! print spaces for the appropriate recurence level
    for(j=0; j < recLevel-1; j++) {
        printf("   ");
    }
    //! then print value
    printElement(t, f);
    //! print a new line
    printf("\n");
    prettyPrint(t->left, recLevel, f); //! keep going left in the tree
}