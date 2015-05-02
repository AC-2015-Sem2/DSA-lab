#include "list.h"

void addElement(List** t) {
    List* l = *t;
    if (l == NULL) {
        l = (List*)malloc(sizeof(List));
        l->next = NULL;
        l->content = NULL;
    } else {
        List* la;
        for (la = l; la->next != NULL; la = la->next);
        List* lb = (List*)malloc(sizeof(List));
        lb->content = NULL;
        lb->next = NULL;
        la->next = lb;
    }
    *t = l;
}

void addContentForElement(List** t, int val) {
    if ((*t)->content == NULL) {
        (*t)->content = createNode(val);
    } else {
        NodeT* na;
        for (na = (*t)->content; na->next != NULL; na = na->next);
        na->next = createNode(val);
    }
}

void printList(List* l) {
    int i = 0;
    while (l != NULL) {
        printf("%c -> ", 65 + i);
        NodeT* n = l->content;
        while (n != NULL) {
            printf("%c ", 65 + n->content);
            n = n->next;
        }
        printf("\n");
        l = l->next;
        i++;
    }
}