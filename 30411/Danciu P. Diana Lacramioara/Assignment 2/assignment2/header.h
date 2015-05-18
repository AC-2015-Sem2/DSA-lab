#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} NodeT;

typedef struct
{
    NodeT *head;
    NodeT *tail;
    int length;
} Santinel;

Santinel *s;

void AddNodeFirst(int code);
void AddNodeLast(int code);
void RemoveFirst(void);
void RemoveLast(void);
void RemoveNodeX(int code);
void DeleteList(void);
void PrintList(FILE *f);
void PrintListFront(FILE *f, int code);
void PrintListLast(FILE *f, int code);


#endif // HEADER_H_INCLUDED
