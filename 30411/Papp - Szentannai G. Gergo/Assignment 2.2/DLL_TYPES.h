#ifndef DLL_TYPES_H_INCLUDED
#define DLL_TYPES_H_INCLUDED

typedef struct node
{
    int code;
    struct node *next;
    struct node *prew;
} NodeT;

typedef struct sent
{
    NodeT *head;
    NodeT *tail;
    int *length;
}sentinel;

#endif // DLL_TYPES_H_INCLUDED
