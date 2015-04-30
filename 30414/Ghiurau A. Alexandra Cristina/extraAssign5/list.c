#include "node.h"
#include "graph.h"
#include "stack.h"
#include "queue.h"

void addLast(int content){
    if(head == NULL){
        head = createNode(content);
    }else{
        NodeT * aux = head;
        while(aux->next!=NULL){
            aux=aux->next;
        }
        aux->next=createNode(content);
    }
}
void printList(){
    NodeT * aux = head;
    while(aux!=NULL){
        printf("%d ",aux->content);
        aux=aux->next;
    }
    printf("\n");
}
