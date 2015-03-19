#ifndef SENTINEL_H_INCLUDED
#define SENTINEL_H_INCLUDED

#include "list.h"

typedef struct sent {
    int length;
    LIST* head;
    LIST* tail;
} SENT;

void sCreate(SENT* t);
void sAdd_first(SENT* t, int x);
void sAdd_last(SENT* t, int x);
void sDel_first(SENT* t);
void sDel_last(SENT* t);
void sDoom_the_list(SENT* t);
void sDel_x(SENT* t, int x);
void sPrint_all(SENT t, FILE* g);
void sPrint_first_n(SENT t, int n, FILE* g);
void sPrint_last_n(SENT t, int n, FILE* g);

#endif // SENTINEL_H_INCLUDED
