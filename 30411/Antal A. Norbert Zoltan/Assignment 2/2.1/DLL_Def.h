#ifndef DLL_DEF_H_INCLUDED
#define DLL_DEF_H_INCLUDED

typedef struct node {
    int data;
    struct node *prev, *next;
} nodeT;

typedef struct sent {
    nodeT *head, *tail;
    int length;
} sentT;

sentT* dll;

#endif // DLL_DEF_H_INCLUDED
