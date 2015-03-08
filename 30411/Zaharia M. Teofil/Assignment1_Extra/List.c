#include "List.h"

void initList(List* l) {
    l->first = NULL;
}

void deleteList(List* l) {
    Node* aux;
    while (l->first->next != NULL) {
        aux = l->first->next;
        free(l->first);
        l->first = aux;
    }
    free(l->first);
}

Node* createNode(void* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = data;

    return newNode;
}

void addFirst(List* l, void* data) {
    Node* newNode = createNode(data);

    if(l->first == NULL) {
        l->first = newNode;
    } else {
        newNode->next = l->first;
        l->first = newNode;
    }
}

void addLast(List* l, void* data) {
    Node* newNode = createNode(data);

    if(l->first == NULL) {
        l->first = newNode;
    } else {
        Node* aux = l->first;
        while (aux->next != NULL) {
            aux = aux->next;
        }
        aux->next = newNode;
    }
}

void delFirst(List* l) {
    Node* aux = l->first->next;
    free(l->first);
    l->first = aux;
}

void printList(List* l) {
    Node* aux = l->first;

    while (aux != NULL) {
        printNode(aux);
        aux = aux->next;
    }

    printf("\n");
}

void printNode(Node* n) {
    printf ("%d ", (int)n->data);
}

int getData(Node* n) {
    return (int)n->data;
}

void setData(Node* n, int newData) {
    n->data = (void*)newData;
}
