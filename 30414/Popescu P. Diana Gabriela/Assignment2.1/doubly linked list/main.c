#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
typedef struct dllist
{
    int val;
    struct dllist *next, *prev;
} doublyLinkedList;

typedef struct{
doublyLinkedList* head;
doublyLinkedList* tail;
}ws;
ws* sentinel;

void addFirst(int data)
{
    if(sentinel->head==NULL)
    {
        sentinel->head=(doublyLinkedList*)malloc(sizeof(doublyLinkedList));
        sentinel->head->val=data;
        sentinel->head->next=NULL;
        sentinel->head->prev=NULL;
        sentinel->tail=sentinel->head;
    }
    else
    {
        doublyLinkedList *carina=(doublyLinkedList*)malloc(sizeof(doublyLinkedList));
        carina->val=data;
        carina->next=sentinel->head;
        carina->prev=NULL;
        sentinel->head->prev=carina;
        sentinel->head=carina;
    }
}

void addLast(int data)
{
    if(sentinel->head==NULL)
    {
        sentinel->head=(doublyLinkedList*)malloc(sizeof(doublyLinkedList));
        sentinel->head->val=data;
        sentinel->head->next=NULL;
        sentinel->head->prev=NULL;
        sentinel->tail=sentinel->head;
    }
    else
    {
        doublyLinkedList* dia=(doublyLinkedList*)malloc(sizeof(doublyLinkedList));
        dia->val=data;
        dia->next=NULL;
        dia->prev=sentinel->tail;
        sentinel->tail->next=dia;
        sentinel->tail=dia;
    }

}

void delFirst()
{
    if(sentinel->head!=NULL)
    {
        doublyLinkedList* rares=sentinel->head->next;
        rares->prev=NULL;
        free(sentinel->head);
        sentinel->head=rares;
    }
}

void delLast()
{
    if(sentinel->head!=NULL)
    {
        doublyLinkedList* brandon=sentinel->tail->prev;
        brandon->next=NULL;
        free(sentinel->tail);
        sentinel->tail=brandon;
    }
}

void doomTheList()
{
    doublyLinkedList* t = sentinel->head;
    doublyLinkedList* q;
    while (t != NULL)
    {
        q = t->next;
        free(t);
        t = q;
    }
    sentinel->head=NULL;
    sentinel->tail=NULL;
}
/*
void doomTheList()
{
while(sentinel->head!=sentinel->tail)
    delFirst();
delFirst();//the last element is being deleted
sentinel->head=NULL;
sentinel->tail=NULL;
}
*/
void delX(int x)
{
    if(sentinel->head->val==x)
        delFirst();
    else if(sentinel->tail->val==x)
        delLast();
    else
    {
        doublyLinkedList* t = sentinel->head->next;
        while(t->val!=x && t!=sentinel->tail)
            t=t->next;
        if(t!=sentinel->tail)
        {
            t->prev->next=t->next;
            t->next->prev=t->prev;
            free(t);
        }
    }
}

void printAll(FILE* g)
{
    doublyLinkedList* t = sentinel->head;
    while (t != NULL)
    {
        if (g == stdin)
            printf("%d ", t->val);
        else
            fprintf(g, "%d ", t->val);
        t = t->next;
    }
    if (g == stdin)
        printf("\n");
    else
        fprintf(g, "\n");
}

void printFirstN(int n, FILE* g)
{
    int i;
    doublyLinkedList* t = sentinel->head;
    for(i=0; i < n && t != NULL; i++)
    {
        if (g == stdin)
            printf("%d ", t->val);
        else
            fprintf(g, "%d ", t->val);
        t = t->next;
    }
    if (g == stdin)
        printf("\n");
    else
        fprintf(g, "\n");
}

void printLastN(int n, FILE* g)
{
    int i;
    doublyLinkedList* t = sentinel->tail;
    for(i=0; i < n && t != NULL; i++)
    {
        if (g == stdin)
            printf("%d ", t->val);
        else
            fprintf(g, "%d ", t->val);
        t = t->prev;
    }
    if (g == stdin)
        printf("\n");
    else
        fprintf(g, "\n");
}

int main()
{
    sentinel=(ws*)malloc(sizeof(ws));
    sentinel->head=NULL;
    sentinel->tail=NULL;
    FILE* f=fopen("input.txt", "r");
    FILE* g=fopen("output.txt", "w");
    if(f==0 || g==0)
        printf("error");
    char s[20];
    int i, ok=1;

    while(ok!=EOF)
    {
        ok=fscanf(f, "%s", s);
        if(ok!=EOF)
        {
            if(strcmp("AL", s)==0)
            {
                fscanf(f, "%d", &i);
                addLast(i);
            }
            else if(strcmp("AF", s)==0)
             {
                fscanf(f, "%d", &i);
                addFirst(i);
            }
            else if(strcmp("DF", s)==0)
                delFirst();
            else if(strcmp("DL", s)==0)
                delLast();
            else if(strcmp("DOOM_THE_LIST", s)==0)
                doomTheList();
            else if(strcmp("DE", s)==0)
             {
                fscanf(f, "%d", &i);
                delX(i);
            }
            else if(strcmp("PRINT_ALL", s)==0)
                printAll(g);
            else if(strcmp("PRINT_F", s)==0)
            {
                fscanf(f, "%d", &i);
                printFirstN(i, g);
            }
            else if(strcmp("PRINT_L", s)==0)
             {
                fscanf(f, "%d", &i);
                printLastN(i, g);
            }
            else printf("no action to be done");
        }
    }
    fclose(f);
    fclose(g);
    return 0;
}
