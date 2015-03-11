#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct st_node
{
    int value;
    struct st_node *next;
} node;
node *head;
node *tail;

void printAll();
void addFirst(int value);
void addLast(int value);
void deleteFirst();
void deleteLast();
void deleteAll();
int deleteX(int value);
void printFirstX(int value, FILE *fileOutput);
void printLastX(int value,  FILE *fileOutput);
