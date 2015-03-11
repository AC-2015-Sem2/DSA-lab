#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct s_Node {
    void* data;
    struct s_Node* next;
} Node;

typedef struct s_List {
    Node *first;
} List;

void initList(List* l);
void deleteList(List* l);

Node* createNode(void* data);

void addFirst(List* l, void* data);
void addLast(List* l, void* data);
void delFirst(List* l);
void printList(List* l);

void printNode(Node* n);
int getData(Node* n);
void setData(Node* n, int newData);

#endif // LIST_H
