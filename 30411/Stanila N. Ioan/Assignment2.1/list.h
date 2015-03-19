#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdio.h>

typedef struct list_t {
    int val;
    struct list_t* prev;
    struct list_t* next;
} LIST;

int list_length(LIST* head);
void add_first(LIST** head, int x);
void add_last(LIST** head, int x);
void del_first(LIST** head);
void del_last(LIST** head);
void doom_the_list(LIST** head);
void del_x(LIST** head, int x);
void print_all(LIST* head, FILE*);
void print_first_n(LIST* head, int n, FILE*);
void print_last_n(LIST* head, int n, FILE*);

#endif // LIST_H_INCLUDED
