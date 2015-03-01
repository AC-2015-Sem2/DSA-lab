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
}lst;

typedef struct country_elem{
char name[20];
lst *waves;
struct country_elem *next;
}country;

node* createNode(int data);
country* createCountry();
lst* createList();
void addLast(lst* list, int data);
void printList(lst* list);



#endif // FUNCTIONS_H_INCLUDED
