#include "LinkedList.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

NodeT* newNode(char* content) {
    NodeT* nt = (NodeT*) malloc (sizeof(NodeT));

    int len = strlen(content);
    nt->data = (char*) malloc ((len+1) * sizeof(char));
    strcpy(nt->data, content);
    nt->next = NULL;

    return nt;
}

NodeT* delNode(NodeT* n) {
    if (n) {
        free(n->data);
        free(n);
    }

    return NULL;
}

ListT* newList() {
    ListT* lt = (ListT*) malloc (sizeof(ListT));
    lt->head = NULL;
    lt->size = 0;
    return lt;
}

ListT* delList(ListT* l) {
    if (l) {
        NodeT* aux;
        while(l->head) {
            aux = l->head->next;
            l->head = delNode(l->head);
            l->head = aux;
        }
    }
    free(l);
    return NULL;
}

void addToList(ListT* l, char* content) {
    NodeT* nt = newNode(content);

    if (l->head == NULL) {
        l->head = nt;
    } else {
        NodeT* k = l->head;
        while (k->next != NULL) {
            k = k->next;
        }
        k->next = nt;
    }

    l->size++;
}

void printContent(NodeT* n) {
    if (n == NULL) {
        printf("NULL");
    } else {
        printf("%s ", n->data);
    }
}
