//the structure is defined in this header file
#include <stdio.h>
#include <stdlib.h>
typedef struct genericNode
    {
        char * name;
        int money;
        int sec;
        struct genericNode* next;
    } node;
node* head, *tail;

typedef struct genericSecond
    {
        int sec;
        struct genericSecond* next;
    } second;
second * shead, *stail;

///FUNCTIONS PROTOTYPES FOR THE FUNCTION WORKING ON THE QUEUE (THE QUEUE OF PEOPLE)
void enqueue(char * s,int x, int y);
void dequeue();

///FUNCTIONS PROTOTYPES FOR THE FUNCTION WORKING ON THE QUEUE (THE QUEUE OF SECONDS)
second* createNodeS(int x);
void enqueueS(int x);
void dequeueS();
