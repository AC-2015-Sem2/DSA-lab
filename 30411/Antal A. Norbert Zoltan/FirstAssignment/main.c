#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
int data;
struct node* next;
} NodeT;

NodeT* head;
NodeT* tail;

void AddFirst(int);
void AddLast(int);
void DeleteFirst();
void DeleteLast();
void DOOM();
void Del(int);
void PrintAll();
void PrintFirst(int);
void PrintLast(int);
void ComProc(char*);

int main()
{
    FILE* ifile = fopen("input.dat", "r");
    char* command = (char*)malloc(30);
    while (fgets(command, 30, ifile))
        ComProc(command);
    return 0;
}

void AddFirst(int x){
    if(head==NULL){
        head = (NodeT*)malloc(sizeof(NodeT));
        head->data = x;
        head->next = NULL;
        if(tail==NULL) tail = head;
    }
    else{
        NodeT* node = (NodeT*)malloc(sizeof(NodeT));
        node->data = x;
        node->next = head;
        head = node;
    }
}

void AddLast(int x){
    if (tail==NULL){
        tail = (NodeT*)malloc(sizeof(NodeT));
        tail->data = x;
        tail->next = NULL;
        if (head==NULL) head = tail;
    }
    else {
    NodeT* node = (NodeT*)malloc(sizeof(NodeT));
    node->data = x;
    tail->next = node;
    tail = node;
    }
}

void DeleteFirst(){
    if (head!=NULL){
        NodeT* node = head;
        head = head->next;
        free(node);
    }
}

void DeleteLast(){
    if (head==NULL) return;
    NodeT* node = head;
    if (head==tail) {
        head = NULL;
        tail = NULL;
        return;
    }
    while(node->next!=tail){
        node = node->next;
    }
    NodeT* todel = tail;
    tail = node;
    tail->next=NULL;
    free(todel);
}

void DOOM(){
    NodeT* node = head;
    while (node!=tail){
        NodeT* todel = node;
        node = node->next;
        free(todel);
    }
    free(tail);
    head=NULL;
    tail=NULL;
}

void Del(int x){
    NodeT* prev;
    NodeT* node = head;
    while (node!=NULL){
        if (node->data==x){
            if (node==head){
                head = node->next;
                free(node);
                return;
            }
            prev->next = node->next;
            free(node);
            return;
        }
        prev = node;
        node = node->next;
    }
}

void PrintAll(){
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
    if (head==NULL || x<=0) return;
    FILE* pfile = fopen("output.dat", "a");
    if (head==tail) {fprintf(pfile, "%d\n\n", head->data); return;}
    NodeT* node = head;
    int i = 0;
    while (i<x && node!= tail){
        fprintf(pfile, "%d\n", node->data);
        node = node->next;
        i++;
    }
    if (i!=x) fprintf(pfile, "%d\n\n", tail->data);
    else fprintf(pfile, "\n");
    fclose(pfile);
}

void PrintLast(int x){
    if (head==NULL || x<=0) return;
    FILE* pfile = fopen("output.dat", "a");
    if (head==tail) {fprintf(pfile, "%d\n\n", head->data); return;}
    NodeT* node = head;
    NodeT* start = head;
    int i = 1;
    while (node!=tail){
        node=node->next;
        i++;
        if (i>x) start=start->next;
    }
    while (start!=tail){
        fprintf(pfile, "%d\n", start->data);
        start = start->next;
    }
    fprintf(pfile, "%d\n\n", tail->data);
    fclose(pfile);
}

void ComProc(char* s){
    char* com = (char*)malloc(30);
    int value;
    sscanf(s, "%s", com);
    if (!strcmp(com, "AF")){
        sscanf(s, "%*s %d", &value);
        AddFirst(value);
        }
    else if(!strcmp(com, "AL")){
        sscanf(s, "%*s %d", &value);
        AddLast(value);
    }
    else if(!strcmp(com, "DF"))
        DeleteFirst();
    else if(!strcmp(com, "DL"))
        DeleteLast();
    else if(!strcmp(com, "DOOM_THE_LIST"))
        DOOM();
    else if(!strcmp(com, "DE")){
        sscanf(s, "%*s %d", &value);
        Del(value);
    }
    else if(!strcmp(com, "PRINT_ALL"))
        PrintAll();
    else if(!strcmp(com, "PRINT_F")){
        sscanf(s, "%*s %d", &value);
        PrintFirst(value);
    }
    else if(!strcmp(com, "PRINT_L")){
        sscanf(s, "%*s %d", &value);
        PrintLast(value);
    }
}
