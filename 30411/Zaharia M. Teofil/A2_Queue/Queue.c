#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>


// constructor, destructor
Queue* newQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));

    q->first = NULL;
    q->len = 0;

    return q;
}

void freeQueue(Queue* q) {
    while (q->len) {
        dequeue(q);
    }
    q->first = NULL;
    free(q);
}

// ops
void enqueue(Queue* q, int newVal, int newTime) {
    Node* newNode = (Node*) malloc(sizeof(Node));

    newNode->val = newVal;
    newNode->time = newTime;
    newNode->next = NULL;

    if (q->first == NULL) {
        q->first = newNode;
    } else {
        // add last
        Node* aux;
        aux = q->first;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = newNode;
    }

    q->len++;
}

void dequeue(Queue* q) {
    if (q->first != NULL) {
        Node* aux = q->first->next;
        free(q->first);
        q->first = aux;

        q->len--;
    }
}

// getters
Node* peek(Queue* q) {
    return q->first;
}

int isEmpty(Queue* q) {
    return (q->first == NULL);
}

// printers
void print(Node* n) {
    if (n != NULL) {
        printf("val:%d  time:%d\n", n->val, n->time);
    }
}
