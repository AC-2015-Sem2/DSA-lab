#include "list.h"

#include <stdlib.h>

int list_length(LIST* head) {
    if (head != NULL) {
        int n = 1;
        while (head->next != NULL) {
            head = head->next;
            n++;
        }
        return n;
    }
    return 0;
}

void add_first(LIST** head, int x){
    if (*head == NULL) {
        *head = (LIST*)malloc(sizeof(LIST));
        (*head)->val = x;
        (*head)->next = NULL;
    } else {
        LIST* t = (LIST*)malloc(sizeof(LIST));
        t->val = x;
        t->next = *head;
        *head = t;
    }
}

void add_last(LIST** head, int x) {
    if (*head == NULL) {
        *head = (LIST*)malloc(sizeof(LIST));
        (*head)->val = x;
        (*head)->next = NULL;
    } else {
        LIST* t;
        t = (LIST*)*head;
        while (t->next != NULL) {
            t = t->next;
        }
        LIST* q = (LIST*)malloc(sizeof(LIST));
        t->next = q;
        q->val = x;
        q->next = NULL;
    }
}

void del_first(LIST** head) {
    if (*head != NULL) {
        LIST* t = (*head)->next;
        free(*head);
        *head = t;
    }
}

void del_last(LIST** head) {
    if (*head != NULL) {
        LIST* t = *head;
        LIST* q;
        while (t->next != NULL) {
            q = t;
            t = t->next;
        }
        if (t != NULL) {
            free(t);
            q->next = NULL;
        }
    }
}

void doom_the_list(LIST** head) {
    LIST* t = *head;
    LIST* q;
    while (t != NULL) {
        q = t->next;
        free(t);
        t = q;
    }
    *head = NULL;
}

void del_x(LIST** head, int x) {
    if ((*head)->val == x) {
        del_first(head);
    } else {
        LIST* t = *head;
        LIST* q;
        while (t->val != x && t->next != NULL) {
            q = t;
            t = t->next;
        }
        if (t->val == x) {
            q->next = t->next;
            free(t);
        }
    }
}

void print_all(LIST* head, FILE* g) {
    LIST* t = head;
    while (t != NULL) {
        if (g == stdin) {
            printf("%d ", t->val);
        } else {
            fprintf(g, "%d ", t->val);
        }
        t = t->next;
    }
    if (g == stdin) {
        printf("\n");
    } else {
        fprintf(g, "\n");
    }
}

void print_first_n(LIST* head, int n, FILE* g) {
    int i =0;
    LIST* t = head;
    while (i < n && t != NULL) {
        fprintf(g, "%d ", t->val);
        t = t->next;
        i++;
    }
    fprintf(g, "\n");
}

void print_last_n(LIST* head, int n, FILE* g) {
    int na = list_length(head);
    if (n >= na) {
        print_all(head, g);
    } else {
        LIST* t = head;
        for (int i = 0; i < na - n; i++) {
            t = t->next;
        }
        print_all(t, g);
    }
}