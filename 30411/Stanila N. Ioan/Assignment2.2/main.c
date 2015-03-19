#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

typedef struct queue {
    char* name;
    int money;
    int seconds;
    struct queue* next;
} Queue;

void enqueue(Queue** t, char* name, int money, int seconds);
void dequeue(Queue** t);

void how_much_money(Queue* t, LIST* l);

int main()
{
    Queue* t = NULL;
    LIST* l = NULL;

    FILE* f = fopen("input.dat", "r");
    if (f == NULL) {
        perror("input.dat");
        exit(1);
    }

    char* line = (char*)malloc(200*sizeof(char));
    char* name = (char*)malloc(50*sizeof(char));

    int x = 0;
    while (fscanf(f, "%d ", &x)) {
        add_last(&l, x);
    }

    int money;
    int time;
    while (!feof(f)) {
        fscanf(f, " %[^\n]s ", line);
        sscanf(line, " %s %d %d ", name, &money, &time);
        enqueue(&t, name, money, time);
    }
    free(line);
    free(name);

    print_all(l, stdin);

    how_much_money(t, l);

    doom_the_list(&l);

    return 0;
}

void enqueue(Queue** t, char* name, int money, int seconds) {
    if (*t == NULL) {
        *t = (Queue*)malloc(sizeof(Queue));
        (*t)->name = (char*)malloc((strlen(name) + 1)*sizeof(char));
        strcpy((*t)->name, name);
        (*t)->money = money;
        (*t)->seconds = seconds;
        (*t)->next = NULL;
    } else {
        Queue* q = NULL;
        for (q = *t; q->next != NULL; q = q->next);
        Queue* w = (Queue*)malloc(sizeof(Queue));
        w->name = (char*)malloc((strlen(name) + 1)*sizeof(char));
        strcpy(w->name, name);
        w->money = money;
        w->seconds = seconds;
        w->next = NULL;
        q->next = w;
    }
}
void dequeue(Queue** t) {
    if (*t != NULL) {
        Queue* q = (*t)->next;
        free((*t)->name);
        free(*t);
        *t = q;
    }
}

void how_much_money(Queue* t, LIST* l) {
    FILE* g = fopen("output.dat", "w");
    if (g == NULL) {
        perror("output.dat");
        exit(1);
    }

    int tim = 0;
    int cashold = 0, cash = 0;
    while (l != NULL) {
        while (t != NULL && l->val >= tim) {
            cashold = cash;
            cash += t->money;
            tim += t->seconds;
            t = t->next;
        }
        fprintf(g, "After %d seconds: %d\n", l->val, cashold);
        l = l->next;
    }
}
