#include <stdlib.h>
#include "SLL_Def.h"
#include "SLL_Adding.h"

void AddFirst(int x){
    if(head==NULL){
        head = (NodeT*)malloc(sizeof(NodeT));
        head->data = x;
        head->next = NULL;
        if(tail==NULL) {tail = head;}
    }
    else{
        NodeT* node = (NodeT*)malloc(sizeof(NodeT));
        node->data = x;
        node->next = head;
        head = node;
    }
}

void AddLast(int x){
    if (tail==NULL){
        tail = (NodeT*)malloc(sizeof(NodeT));
        tail->data = x;
        tail->next = NULL;
        if (head==NULL) {head = tail;}
    }
    else {
    NodeT* node = (NodeT*)malloc(sizeof(NodeT));
    node->data = x;
    tail->next = node;
    tail = node;
    }
}
