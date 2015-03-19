#include <stdlib.h>
#include <stdio.h>

///DEFINING THE A NODE IN THE LIST
typedef struct genericNode
{
    int data;
    struct genericNode * next;
    struct genericNode * prev;
}node;

///DEFINING A SENTINEL
typedef struct genericSentinel
{
    node * head, * tail;
    int length;
} sentinel;

sentinel * List;

///PROTOTYPES FOR THE ADD FUNCTIONS + INIT
void initList();
void addFirst(int data);
void addLast(int data);

///PROTOTYPES FOR THE PRINTING FUNCTIONS
void printAll(FILE * g);
void printFirst(FILE * g,int x);
void printLast(FILE * g, int x);

///PROTOTYPES FOR THE DELETING FUNCTIONS
void deleteLast();
void deleteFirst();
void deleteElementByKey(int x);
void doomTheList();


