#include "queue.h"

void enqueue(int content){
    if(queue == NULL){
        queue = createNode(content);
    }else{
        NodeT * aux = queue;
        while(aux->next!=NULL){
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

NodeT * peekQueue(){
    return queue;
}

int isEmptyQueue(){
    return queue == NULL;
}
