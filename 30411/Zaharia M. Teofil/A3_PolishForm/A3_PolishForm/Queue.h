#ifndef QUEUE_H
#define QUEUE_H

typedef struct nodeQ {
	void* dat;
	struct nodeQ* next;
} NodeQ;

typedef struct queue {
	NodeQ* first;
} Queue;

NodeQ* newNode(void* newDat);
Queue* newQueue();
void freeQueue(Queue* q);

int isEmpty(Queue* q);

void enqueue(Queue* q, void* newDat);
void dequeue(Queue* q);
void* getFirst(Queue* q);

#endif