#include <stdio.h>
#include <stdlib.h>

typedef struct genericList{

    void * data;
    struct genericList * next;

} node;

node *head, *tail;

void addFirst(void * data);
void printList();
node * createNode(void * data);
void printBasedOnType(void * data);
