#include "queue.h"

void enqueue(int content){
    if(queue == NULL){
        queue = createNode(content);
    }
    else
    {
        NodeT * aux = queue;
        while(aux->next!=NULL)
        {
            aux=aux->next;
        }
        aux->next=createNode(content);
    }
}

void dequeue(){
    if(queue!=NULL){
        queue=queue->next;
    }
}

int peekQueue(){
    return queue->content;
}

int isEmptyQueue(){
    return queue == NULL;
}


//! auxiliary
void printQueue(){
    NodeT * aux=queue;
    while(aux!=NULL){
        printf("%d ",aux->content );
        aux=aux->next;
    }
    printf("\n");
}

