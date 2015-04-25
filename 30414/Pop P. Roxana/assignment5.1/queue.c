#include "queue.h"

void enqueue(int content){///add last
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

void dequeue(){///delete first
    if(queue!=NULL){
        queue=queue->next;
    }
}

NodeT * peekQueue(){///peeks at the first element in the queue
    return queue;
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

