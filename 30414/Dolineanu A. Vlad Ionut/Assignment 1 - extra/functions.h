#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>

typedef struct st_node
{
    int data;
    struct st_node* next;
}node;

typedef struct list_elem{
    node* head;
    node* tail;
}waveList;

typedef struct country_elem{
char name[20];
waveList *waves;
struct country_elem *next;
}country;

node* createNode(int data);
country* createCountry();
waveList* createList();
void addLast(waveList* list, int data);
void printList(waveList* list);
void readElements(int *sentinelNumber, int *countryNumber, waveList *sentinels, country** first, country** last);



#endif // FUNCTIONS_H_INCLUDED
