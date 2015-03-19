#include "sentinel.h"

void sCreate(SENT* t) {
    t->head = NULL;
    t->tail = NULL;
}

void sAdd_first(SENT* t, int x) {
    add_first(&(t->head), x);
    t->length = list_length(t->head);
}

void sAdd_last(SENT* t, int x) {
    add_last(&(t->head), x);
    t->length = list_length(t->head);
}

void sDel_first(SENT* t) {
    del_first(&(t->head));
    t->length = list_length(t->head);
}

void sDel_last(SENT* t) {
    del_last(&(t->head));
    t->length = list_length(t->head);
}

void sDoom_the_list(SENT* t) {
    doom_the_list(&(t->head));
    t->length = list_length(t->head);
}

void sDel_x(SENT* t, int x) {
    del_x(&(t->head), x);
    t->length = list_length(t->head);
}

void sPrint_all(SENT t, FILE* g) {
    print_all(t.head, g);
}

void sPrint_first_n(SENT t, int n, FILE* g) {
    print_first_n(t.head, n, g);
}

void sPrint_last_n(SENT t, int n, FILE* g) {
    print_last_n(t.head, n, g);
}