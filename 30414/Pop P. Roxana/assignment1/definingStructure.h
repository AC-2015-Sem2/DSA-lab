//the structure is defined in this header file
#include <stdio.h>
#include <stdlib.h>
typedef struct nod
    {
        int data;
        struct nod* next;
    } NODE;
NODE* head, *tail;

