#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

typedef struct queue {
    char* val;
    struct queue* next;
} Queue;

void enqueue(Queue** q, char* s);
void dequeue(Queue** q);
void printQueue(Queue* q);

#endif // QUEUE_H_INCLUDED
