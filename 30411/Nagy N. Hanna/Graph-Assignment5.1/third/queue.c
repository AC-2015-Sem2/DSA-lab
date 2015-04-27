#include "queue.h"

void enqueue(int content){
    if(queue == NULL){
        queue = create(content);
    }else{
        nodeT * aux = queue;
        while(aux->next!=NULL){
            aux=aux->next;
        }
        aux->next=create(content);
    }
}

void dequeue(){
    if(queue!=NULL){
        queue=queue->next;
    }
}

nodeT * peekQueue(){
    return queue;
}

int isEmptyQueue(){
    return queue == NULL;
}


//! auxiliary
void printQueue(){
    nodeT * aux=queue;
    while(aux!=NULL){
        printf("%d ",aux->code );
        aux=aux->next;
    }
    printf("\n");
}
