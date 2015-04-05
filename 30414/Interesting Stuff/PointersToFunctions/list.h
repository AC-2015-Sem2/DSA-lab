#include "node.h"

/**
    Main Idea:      have functions as structure members
    Solution:       pointers to functions
    Achievement:    dynamic modification of method at runtime

    Side-note:      the "list" structure simulates an object (like in OOP languages)
*/
typedef struct list{
    node * head;
    node * tail;
    int length;
    void (*addFirst)(void*);
    void (*printList)();
}listT;

listT * listObj;

void addFirst(void * data);

void initList();

void setPrintFunctionToV1();
void setPrintFunctionToV2();

//! we have two variants of the print function, each does something a bit different than the other
void printListV1();
void printListV2();

node * createNode(void * data);
