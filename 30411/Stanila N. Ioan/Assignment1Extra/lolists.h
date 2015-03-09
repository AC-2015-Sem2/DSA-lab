#ifndef LOLISTS_H_INCLUDED
#define LOLISTS_H_INCLUDED

#include "list.h"

typedef struct lolists {
    char* name;
    LIST* wave;
    struct lolists* next;
} LoLISTS;

void add_list(LoLISTS** aux);
void add_name(LoLISTS** aux, char* name, int length);
void add_wave_last(LoLISTS** aux, int x);
void doom_lolists(LoLISTS** aux);


#endif // LOLISTS_H_INCLUDED
