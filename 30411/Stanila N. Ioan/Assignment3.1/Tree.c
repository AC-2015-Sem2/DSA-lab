#include "Tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Tree* createNode(char* s) {
    Tree* t = (Tree*)malloc(sizeof(Tree));
    t->val = (char*)malloc((strlen(s) + 1)*sizeof(char));
    strcpy(t->val, s);
    t->left = t->right = NULL;
    return t;
}

void preorder(Tree* t) {
    if (t != NULL) {
        printf("%s ", t->val);
        preorder(t->left);
        preorder(t->right);
    }
}