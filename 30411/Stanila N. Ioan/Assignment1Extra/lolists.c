#include "lolists.h"

#include <stdlib.h>
#include <string.h>

void add_list(LoLISTS** aux) {
    LoLISTS* t = (LoLISTS*)malloc(sizeof(LoLISTS));
    *aux = t;
    (*aux)->wave = NULL;
    (*aux)->next = NULL;
    (*aux)->name = NULL;
}

void add_name(LoLISTS** aux, char* name, int length) {
    if ((*aux)->name == NULL) {
        (*aux)->name = (char*)malloc((length + 1)*sizeof(char));
        strcpy((*aux)->name, name);
    } else {
        strcpy((*aux)->name, name);
    }
}

void add_wave_last(LoLISTS** aux, int x) {
    add_last(&((*aux)->wave), x);
}

void doom_lolists(LoLISTS** aux) {
    LoLISTS* t;
    while (*aux != NULL) {
        t = *aux;
        free(t->name);
        doom_the_list(&(t->wave));
        *aux = t->next;
        free(t);
    }
}