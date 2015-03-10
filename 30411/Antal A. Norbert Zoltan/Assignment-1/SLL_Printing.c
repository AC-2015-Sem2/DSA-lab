#include <stdio.h>
#include <stdlib.h>
#include "SLL_Def.h"
#include "SLL_Printing.h"

void PrintAll(){
    if (head==NULL) {return;}
    NodeT* node = head;
    FILE* pfile = fopen("output.dat", "a");
    while (node!=tail){
        fprintf(pfile, "%d\n", node->data);
        node = node->next;
    }
    fprintf(pfile, "%d\n\n", tail->data);
    fclose(pfile);
}

void PrintFirst(int x){
    if (head==NULL || x<=0) {return;}
    FILE* pfile = fopen("output.dat", "a");
    if (head==tail) {fprintf(pfile, "%d\n\n", head->data); return;}
    NodeT* node = head;
    int i = 0;
    while (i<x && node!=tail){
        fprintf(pfile, "%d\n", node->data);
        node = node->next;
        i++;
    }
    if (i!=x) {fprintf(pfile, "%d\n\n", tail->data);}
    else {fprintf(pfile, "\n");}
    fclose(pfile);
}

void PrintLast(int x){
    if (head==NULL || x<=0) {return;}
    FILE* pfile = fopen("output.dat", "a");
    if (head==tail) {fprintf(pfile, "%d\n\n", head->data); return;}
    NodeT* node = head;
    NodeT* start = head;
    int i = 1;
    while (node!=tail){
        node = node->next;
        i++;
        if (i>x) start = start->next;
    }
    while (start!=tail){
        fprintf(pfile, "%d\n", start->data);
        start = start->next;
    }
    fprintf(pfile, "%d\n\n", tail->data);
    fclose(pfile);
}
