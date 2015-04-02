#ifndef AVL_DEF_H_INCLUDED
#define AVL_DEF_H_INCLUDED

typedef struct nodeT{
    int data;
    struct nodeT *left, *right;
    int height;
} NodeT;

#endif // AVL_DEF_H_INCLUDED
