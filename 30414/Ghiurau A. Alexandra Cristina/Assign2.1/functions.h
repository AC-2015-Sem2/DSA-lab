#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node
{
    int value;
    struct node *next;
    struct node *prev;
} node;

typedef struct list_sentinel
{
    int length;
    node *head;
    node *tail;
} list_sentinel;

list_sentinel *s;


void printAll();
void addFirst(int value);
void addLast(int value);
void deleteFirst();
void deleteLast();
void deleteAll();
void deleteX(int value);
void printFirstX(int value, FILE *fileOutput);
void printLastX(int value,  FILE *fileOutput);
