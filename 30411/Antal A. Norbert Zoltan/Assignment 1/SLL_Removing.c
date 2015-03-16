#include <stdlib.h>
#include "SLL_Def.h"
#include "SLL_Removing.h"

void DeleteFirst(){
    if (head!=NULL){
        NodeT* node = head;
        head = head->next;
        free(node);
    }
}

void DeleteLast(){
    if (head==NULL) {return;}
    NodeT* node = head;
    if (head == tail) {
        head = NULL;
        tail = NULL;
        return;
    }
    while(node->next!=tail){
        node = node->next;
    }
    NodeT* todel = tail;
    tail = node;
    tail->next=NULL;
    free(todel);
}

void DOOM(){
    if (head==NULL) {return;}
    NodeT* node = head;
    while (node!=tail){
        NodeT* todel = node;
        node = node->next;
        free(todel);
    }
    free(tail);
    head=NULL;
    tail=NULL;
}

void Del(int x){
    NodeT* prev;
    NodeT* node = head;
    while (node!=NULL){
        if (node->data==x){
            if (node==head){
                head = node->next;
                free(node);
                return;
            }
            prev->next = node->next;
            free(node);
            return;
        }
        prev = node;
        node = node->next;
    }
}
