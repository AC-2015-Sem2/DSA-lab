#include "Tree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Tree* createNode(int d) {
    Tree* t = (Tree*)malloc(sizeof(Tree));
    t->val = d;
    t->height = 1;
    t->left = t->right = NULL;
    return t;
}

Tree* insertLeaf(Tree* t, int value) {
    if (t == NULL)
        return createNode(value);
    else {
        if (t->val > value)
            t->left = insertLeaf(t->left, value);
        else
            t->right = insertLeaf(t->right, value);
    }

    t->height = maxEl(uHeight(t->left), uHeight(t->right)) + 1;

    int delta = getDelta(t);

    if (delta == 2 && t->left != NULL)
        return rotRight(t);
    if (delta == -2 && t->right != NULL)
        return rotLeft(t);
    if (delta == 2 && t->left == NULL) {
        t->left = rotLeft(t->left);
        return rotRight(t);
    }
    if (delta == -2 && t->right == NULL) {
        t->right = rotRight(t->right);
        return rotLeft(t);
    }

    return t;
}

Tree* rotLeft(Tree* t) {
    Tree* q = t->right;
    Tree* r = q->left;
    q->left = t;
    t->right = r;
    t->height = maxEl(uHeight(t->left), uHeight(t->right)) + 1;
    q->height = maxEl(uHeight(q->left), uHeight(q->right)) + 1;
    return q;
}

Tree* rotRight(Tree* t) {
    Tree* q = t->left;
    Tree* r = q->right;
    q->right = t;
    t->left = r;
    t->height = maxEl(uHeight(t->left), uHeight(t->right)) + 1;
    q->height = maxEl(uHeight(q->left), uHeight(q->right)) + 1;
    return q;
}

int getDelta(Tree* t) {
    if (t == NULL) {
        return 0;
    } else {
        return uHeight(t->left) - uHeight(t->right);
    }
}

int treeHeight(Tree* t) {
    if (t == NULL) {
        return 0;
    } else {
        int hl = treeHeight(t->left);
        int hr = treeHeight(t->right);
        return hl > hr ? hl + 1 : hr + 1;
    }
}

int uHeight(Tree* t) {
    if (t == NULL)
        return 0;
    return t->height;
}

int maxEl(int a, int b) {
    return a > b ? a : b;
}

Tree* minValNode(Tree* t) {
    while (t->left != NULL) {
        t = t->left;
    }
    return t;
}

Tree* deleteNode(Tree* t, int value) {
    if (t == NULL)
        return t;
    if (t->val < value)
        t->right = deleteNode(t->right, value);
    else if (t->val > value)
        t->left = deleteNode(t->left, value);
    else {
        if (t->left == NULL || t->right == NULL) {
            Tree* q;
            if (t->left != NULL) {
                q = t->left;
            } else {
                q = t->right;
            }
            if (q == NULL) {
                q = t;
                t = NULL;
            } else {
                *t = *q;
            }
            free(q);
        } else {
            Tree* q = minValNode(t->right);
            t->val = q->val;
            t->right = deleteNode(t->right, q->val);
        }
    }

    if (t == NULL)
        return t;

    t->height = maxEl(uHeight(t->left), uHeight(t->right)) + 1;
    int delta = getDelta(t);

    if (delta == 2 && t->left != NULL)
        return rotRight(t);
    if (delta == -2 && t->right != NULL)
        return rotLeft(t);
    if (delta == 2 && t->left == NULL) {
        t->left = rotLeft(t->left);
        return rotRight(t);
    }
    if (delta == -2 && t->right == NULL) {
        t->right = rotRight(t->right);
        return rotLeft(t);
    }
    return t;
}