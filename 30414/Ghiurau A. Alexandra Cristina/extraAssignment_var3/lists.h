#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef LISTS_H
#define LISTS_H

typedef struct node
{
    int value;
    struct node *next;
} node;

extern node *genericHead, *genericTail;

typedef struct listOfLists
{
    char *countryName;
    node *nextWave;
    struct listOfLists *next;
} listOfLists;

extern listOfLists *head, *tail;
#endif // LISTS_H
