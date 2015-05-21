#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int time;
    int money;
    char name[10];
    struct node *next;
} NodeT;

NodeT *head;
NodeT *tail;

void Enque(int money, int time, char *name);
void Deque(void);
void PrintList(void);

#endif // FILE_H_INCLUDED
