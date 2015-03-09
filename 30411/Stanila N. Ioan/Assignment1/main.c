#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
    int val;
    struct list* next;
} LIST;

//list foos
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
//end

//app foos
void pseudo_cmd();
//end

int main()
{
    pseudo_cmd();
    return 0;
}

void pseudo_cmd() {
    FILE* f;
    f = fopen("input.dat", "r");
    FILE* g;
    g = fopen("output.dat", "a");

    LIST* head = NULL;

    char com[15];
    char subcom[15];
    int x = 0;

    while (!feof(f)) {
        fscanf(f, " %[^\n]s", com);
//        fprintf(g, "%d \n", list_length(head));
//        print_all(head, g);
//        fprintf(g, "///////\n");
//        fprintf(g, "%s\n", com);
        sscanf(com, "%s %d", subcom, &x);

        if (!strcmp(subcom, "AF"))
            add_first(&head, x);
        else if (!strcmp(subcom, "AL"))
            add_last(&head, x);
        else if (!strcmp(subcom, "DF"))
            del_first(&head);
        else if (!strcmp(subcom, "DL"))
            del_last(&head);
        else if (!strcmp(subcom, "DOOM_THE_LIST"))
            doom_the_list(&head);
        else if (!strcmp(subcom, "DE"))
            del_x(&head, x);
        else if (!strcmp(subcom, "PRINT_ALL"))
            print_all(head, g);
        else if (!strcmp(subcom, "PRINT_F"))
            print_first_n(head, x, g);
        else if (!strcmp(subcom, "PRINT_L"))
            print_last_n(head, x, g);

    }
    doom_the_list(&head);
}

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
        (*head)->val = x;
    } else {
        LIST* t;
        t = *head;
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
        del_first(&(*head));
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
        fprintf(g, "%d ", t->val);
        t = t->next;
    }
    fprintf(g, "\n");
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