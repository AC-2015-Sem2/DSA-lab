#ifndef SLL_DEF_H_INCLUDED
#define SLL_DEF_H_INCLUDED

typedef struct node{
int data;
struct node* next;
} NodeT;

NodeT* head;
NodeT* tail;

#endif // SLL_DEF_H_INCLUDED
