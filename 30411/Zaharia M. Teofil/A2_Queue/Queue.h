#ifndef QUEUE_H
#define QUEUE_H

typedef struct s_node {
    int val, time;
    struct s_node* next;
} Node;

typedef struct s_queue {
    Node* first;
    int len;
} Queue;


// constructor, destructor
Queue* newQueue();
void freeQueue(Queue* q);

// ops
void enqueue(Queue* q, int newVal, int newTime);
void dequeue(Queue* q);

// getter
Node* peek(Queue* q);
int isEmpty(Queue* q);

// printer
void print(Node* n);

#endif // QUEUE_H
