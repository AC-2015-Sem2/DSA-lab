#include <string.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct sent
{
    struct node *head,*tail;
} sent;
typedef struct node
{
    int data;
    struct node *next,*prev;
} node;
void PrintAll();
void AddFirst(int x);
void AddLast(int x);
void DeleteFirst();
void DeleteLast();
void DoomTheListt();
void DeleteElement(int x);
void PrintFirst(int x);
void PrintLast(int x);
FILE *f;

sent *list;

void DeleteFirst()
{
    node *p;
    p=list->head;
    list->head=list->head->next;
    list->head->prev=NULL;
    free(p);
}
void DeleteLast()
{
    node *p;
    if ((list->head==list->tail) && (list->head!=NULL)) free(list->head);
    else
    {
        p=list->tail;
        list->tail=list->tail->prev;
        list->tail->next=NULL;
        p=NULL;
        free(p);
    }
}
void DoomTheListt()
{
    node *p,*q;
    p=list->head;
    do
    {
        q=p;
        p=p->next;
        free(q);
    }
    while (p!=list->tail);
    free(list->tail);
}
void DeleteElement(int x)
{
    node *p;
    if (list->head->data==x) DeleteFirst();
    else
    {
        p=list->head;
        while ((p->data!=x) && (p!=list->tail))
        {
            p=p->next;
        }
        if (p!=list->tail)
        {
            p->prev->next=p->next;
            p->next->prev=p->prev;
            free(p);
        }
        else if (list->tail->data==x)
        {
            p=list->tail;
            list->tail=list->tail->prev;
            list->tail->next=NULL;
            p=NULL;
            free(p);
        }
    }
}

void PrintFirst(int x)
{
    f=fopen("output.dat", "a");
    int i=0;
    node *p;
    p=list->head;
    while ((p!=NULL) && (i<x))
    {
        fprintf(f,"%d ",p->data);
        i++;
        p=p->next;
    }
    fclose(f);
}
void PrintLast(int x)
{
    f=fopen("output.dat", "a");
    int i=0;
    node *p;
    p=list->tail;
    while ((i<=x) && (p!=list->head))
    {
        i++;
        p=p->prev;
    }
    while (p!=list->tail)
    {
        fprintf(f,"%d" ,p->data);
        p->next;
    }
    fprintf(f,"%d",p->data);
    fclose(f);
}
void AddLast(int x)
{
    node *p;
    p=(node*)malloc(sizeof(node));
    p->data=x;
    list->tail->next=p;
    p->next=NULL;
    p->prev=list->tail;
    list->tail=p;
}
void AddFirst(int x)
{
    node *a;
    if (list->head==NULL)
    {
        list->head=(node*)malloc(sizeof(node));
        list->tail=list->head;
        list->head->data=x;
        list->head->next=NULL;
        list->head->prev=NULL;
    }
    else
    {
        a=(node*)malloc(sizeof(node));
        a->prev=NULL;
        a->data=x;
        a->next=list->head;
        list->head->prev=a;
        list->head=a;
    }
}
void PrintAll()
{
    f=fopen("output.dat", "a");
    node *a;
    a=list->head;
    while (a!=NULL)
    {
        fprintf(f,"%d ",a->data);
        a=a->next;
    }
    fclose(f);
}

int main()
{
    int x;
    char s[20];
    FILE *g;
    g=fopen("input.dat","r");
    list=(sent*)malloc(sizeof(sent));
    list->head=NULL;
    list->tail=NULL;
    while (fscanf(g,"%s",&s)==1)
    {


        if (strcmp("AF",s)==0)
        {
            fscanf(g,"%d",&x);
            AddFirst(x);
        }
        else if (strcmp("AL",s)==0)
        {
            fscanf(g,"%d",&x);
            AddLast(x);
        }
        else if (strcmp("DF",s)==0) DeleteFirst();
        else if (strcmp("DL",s)==0) DeleteLast();
        else if (strcmp("DE",s)==0)
        {
            fscanf(g,"%d",&x);
            DeleteElement(x);
        }
        else if (strcmp("PRINT_ALL",s)==0) PrintAll();
        else if (strcmp("PRINT_F",s)==0)
        {
            fscanf(g,"%d",&x);
            PrintFirst(x);
        }
        else if (strcmp("PRINT_L",s)==0)
        {
            fscanf(g,"%d",&x);
            PrintLast(x);
        }
        else if (strcmp("DOOM_THE_LIST",s)==0) DoomTheListt();
    }

    return 0;
}

