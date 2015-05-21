#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct s_node {
    char* data;
    struct s_node* next;
} NodeT;

typedef struct s_list {
    NodeT* head;
    int size;
} ListT;

NodeT* newNode(char* content);
NodeT* delNode(NodeT* n);
ListT* newList();
ListT* delList(ListT* l);
void addToList(ListT* l, char* content);
void printContent(NodeT* n);

#endif // LINKEDLIST_H
