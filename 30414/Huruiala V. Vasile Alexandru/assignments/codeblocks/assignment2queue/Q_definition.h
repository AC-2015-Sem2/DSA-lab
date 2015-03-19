/*
I chose to use the sentinel to store 2 lists:
a queue for the clients and a list(actually another queue)
for the times at which the sum so far needs to be printed
*/
#include <stdlib.h>
#include <stdio.h>

//This on is for the times
typedef struct struct_NodeT NodeT;
struct struct_NodeT
{
    NodeT* next;
    NodeT* prev;

    void* data;
};

//This one is for the clients
typedef struct struct_NodeQ NodeQ;
struct struct_NodeQ
{
    NodeQ* next;
    NodeQ* prev;

    //3 data, 1 for name, 2 for dosh, 3 for time
    void* data1;
    //NOTE: storing the name is not required for finding the solution
    //it actually gave me problems with a malloc corrupting the heap only in non-debugger mode later on
    void* data2;
    void* data3;
};

typedef struct struct_Sentinel Sentinel;
struct struct_Sentinel
{
    //Pointers to the queue
    NodeQ* Qhead;
    NodeQ* Qtail;

    //Pointers to list of times
    NodeT* Thead;
    NodeT* Ttail;

    //The methods
    void (*ENQ)(Sentinel* S, void* data1, void* data2, void* data3);
    void (*DEQ)(Sentinel* S);
    void (*AddLastTime)(Sentinel* S, void* data);
    void (*RemoveFirstTime)(Sentinel* S);
    void (*readFile)(Sentinel* S, FILE* I);
    void (*solve)(Sentinel* S, FILE* I, FILE* O);

};

void initSent(Sentinel** S);
void DestroySent(Sentinel** S);
