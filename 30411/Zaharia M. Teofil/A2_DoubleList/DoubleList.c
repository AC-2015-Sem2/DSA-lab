#include "DoubleList.h"
#include <stdlib.h>


// Node
// constructor

Node* newNode(int val) {
    Node* n = (Node*) malloc (sizeof(Node));

    n->val = val;
    n->next = NULL;
    n->prev = NULL;

    return n;
}

// DoubleList
// constructor, destructor
DoubleList* newList() {
    DoubleList* l =
        (DoubleList*) malloc(sizeof(DoubleList));

    l->first = l->last = NULL;
    l->len = 0;

    return l;
}

void freeList(DoubleList* l) {
    doom(l);
    free(l);
}

// element operations
void addFirst(DoubleList* l, int val) {
    Node* n = newNode(val);

    // non-empty list case is more probable
    // insert first for performance
    if (l->len > 0) {
        n->next = l->first;
        l->first->prev = n;
        l->first = n;

    } else {
        l->first = l->last = n;
    }

    l->len++;
}

void addLast(DoubleList* l, int val) {
    Node* n = newNode(val);

    if (l->len > 0) {
        n->prev = l->last;
        l->last->next = n;
        l->last = n;

    } else {
        l->first = l->last = n;
    }

    l->len++;
}


void delFirst(DoubleList* l) {
    if (l->len) {
        Node* temp = l->first->next;

        if (l->len != 1) {
            // if len == 1
            // next == NULL and next->prev doesn't exist
            temp->prev = NULL;
        }

        free(l->first);
        l->first = temp;

        l->len--;
    }
}

void delLast(DoubleList* l) {
    if (l->len) {
        Node* temp = l->last->prev;

        if (l->len != 1) {
            temp->next = NULL;
        }

        free(l->last);
        l->last = temp;

        l->len--;
    }
}

void doom(DoubleList* l) {
    Node* temp;

    while (l->first) {
        temp = l->first->next;
        free(l->first);
        l->first = temp;
    }

    l->first = l->last = NULL;
    l->len = 0;
}

void del(DoubleList* l, int val) {
    Node* k = l->first;
    Node* temp;

    while (k != NULL) {
        temp = k->next;
        if (k->val == val) {

            if (k->prev) {
                k->prev->next = k->next;
            } else {
                l->first = k->next;
            }

            if (k->next) {
                k->next->prev = k->prev;
            } else {
                l->last = k->prev;
            }

            free(k);
            l->len--;
        }

        k = temp;
    }
}

// printers
void printAll(FILE* out, DoubleList* l) {
    if (l->len) {
        Node* k = l->first;

        while (k) {
            fprintf(out, "%d ", k->val);
            k = k->next;
        }

        fprintf(out, "\n");
    }
}

void printFirst(FILE* out, DoubleList* l, int x) {
    if (x >= l->len) {
        printAll(out, l);
    } else {
        Node* k = l->first;

        while (x) {
            fprintf(out, "%d ", k->val);
            k = k->next;
            x--;
        }

        fprintf(out, "\n");
    }
}

void printLast(FILE* out, DoubleList* l, int x) {
    if (x >= l->len) {
        printAll(out, l);
    } else {
        Node* k;
        int i, len = l->len;

        // start from first or last ?
        // less elements to jump
        if (x > len-x) {
            k = l->first;

            for (i = 0; i < len-x; i++) {
                k = k->next;
            }
        } else {
            k = l->last;

            for (i = 1; i < x; i++) {
                k = k->prev;
            }
        }

        while (x) {
            fprintf(out, "%d ", k->val);
            k = k->next;
            x--;
        }

        fprintf(out, "\n");
    }
}
