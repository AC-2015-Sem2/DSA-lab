#include "Queue.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void enqueue(Queue** q, char* s) {
    if (*q == NULL) {
        *q = (Queue*)malloc(sizeof(Queue));
        (*q)->val = (char*)malloc((strlen(s) + 1)*sizeof(char));
        strcpy((*q)->val, s);
        (*q)->next = NULL;
    } else {
        Queue* t = *q;
        for (t = *q; t->next != NULL; t = t->next);
        Queue* t1 = (Queue*)malloc(sizeof(Queue));
        t1->val = (char*)malloc((strlen(s) + 1)*sizeof(char));
        strcpy(t1->val, s);
        t1->next = NULL;
        t->next = t1;
    }
}

void dequeue(Queue** q) {
    if (*q != NULL) {
        Queue* t = (*q)->next;
        free((*q)->val);
        free(*q);
        *q = t;
    }
}

void printQueue(Queue* q) {
    while (q != NULL) {
        printf("%s ", q->val);
        q = q->next;
    }
    printf("\n");
}