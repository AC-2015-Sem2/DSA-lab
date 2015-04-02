#include "Queue.h"

#include <stdlib.h>

NodeQ* newNode(void* newDat) {
	NodeQ* newN = (NodeQ*)malloc(sizeof(NodeQ));
	newN->dat = newDat;
	newN->next = NULL;

	return newN;
}

Queue* newQueue() {
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->first = NULL;

	return q;
}

void freeQueue(Queue* q) {
	if (!q)
		return;

	NodeQ* tmp;

	while (q->first) {
		tmp = q->first->next;
		free(q->first);
		q->first = tmp;
	}

	free(q);
}


int isEmpty(Queue* q) {
	if (q->first)
		return 0;
	else
		return 1;
}


void enqueue(Queue* q, void* newDat) {
	NodeQ* newN = newNode(newDat);

	NodeQ* k = q->first;
	
	if (k) {
		while (k->next) {
			k = k->next;
		}
		k->next = newN;
	}
	else {
		q->first = newN;
	}
}

void dequeue(Queue* q) {
	if (!q)
		return;
	if (!q->first)
		return;

	NodeQ* tmp = q->first->next;
	free(q->first);
	q->first = tmp;
}

void* getFirst(Queue* q) {
	if (!q)
		return NULL;

	return q->first->dat;
}

