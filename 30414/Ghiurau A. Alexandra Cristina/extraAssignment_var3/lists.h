#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef LISTS_H
#define LISTS_H

typedef struct listOfLists
{
    int value;
    struct listOfLists *next;
} listOfLists;

extern listOfLists *genericHead, *genericTail;

typedef struct node
{
    char *countryName;
    listOfLists *nextWave;
    struct node *next;
} node;

extern node *head, *tail;
#endif // LISTS_H
