#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *f;
FILE *g;
typedef struct nod
{
    int data;
    struct nod *next;
}NODE;
NODE *head, *tail;
void printAll()
{
    NODE *p;
    p=head;
    while(p!=NULL)
    {
        fprintf(g, "%d", p->data);
        p=p->next;
    }
}
void addLast(int data)
{
    if(tail==NULL)
    {
        head=(NODE*)malloc(sizeof(NODE));
        head->data=data;
        head->next=NULL;
        tail=head;
    }
    else
    {
        NODE *newnode=(NODE*)malloc(sizeof(NODE));
        tail->next=newnode;
        newnode->next=NULL;
        newnode->data=data;
        tail=newnode;
    }
}
void addFirst(int data)
{
    if(head==NULL)
    {
        head=(NODE*)malloc(sizeof(NODE));
        head->data=data;
        head->next=NULL;
        tail=head;
    }
    else
    {
        NODE *newnode=(NODE*)malloc(sizeof(NODE));
        newnode->data=data;
        newnode->next=head;
        head=newnode;
    }
}
void deleteFirst()
{
    NODE *p;
    p=head;
    if(head!=NULL)
    {
        head=p->next;
    }
}
void deleteLast()
{
    NODE *p;
    p=head;
    while(p!=NULL)
    {
        if(p->next->next==NULL)
        {
            p->next=NULL;
            tail=p;
        }
        p=p->next;
    }
}
void doomTheList()
{
    NODE *p, *s;
    s=head;
    p=s;
    if(p!=NULL)
    {
        while(s!=NULL)
        {
            s=s->next;
            p=NULL;
            p=s;
        }
    }
}
void deleteElement(int x)
{
    NODE *p;
    p=head;
    while(p!=NULL)
    {
        if(p->data==x)
            p->next=p->next->next;
    }
}
void print_F(int x)
{
    NODE *p;
    int i=1;
    p=head;
    while(p!=NULL&&i<=x)
    {
        fprintf(g, "%d", p->data);
        p=p->next;
        i++;
    }
}
int main ()
{
    char s[100], c;
    int i, x;
    f=fopen("input.dat", "r");
    g=fopen("output.dat", "w");
    while(!feof(f))
    {
        i=0;
        while(c!=' ')
        {
            fscanf(f, "%c", &s[i]);
            c=s[i];
            i++;
        }
        if(strcmp(s, "AF")==0)
        {
            fscanf(f, "%d", &x);
            addFirst(x);
        }
        if(strcmp(s, "AL")==0)
        {
            fscanf(f, "%d", &x);
            addLast(x);
        }
        if(strcmp(s, "DF")==0)
            deleteFirst();
        if(strcmp(s, "DL")==0)
            deleteLast();
        if(strcmp(s, "DOOM_THE_LIST")==0)
            doomTheList();
        if(strcmp(s, "DE")==0)
        {
            fscanf(f, "%d", &x);
            deleteElement(x);
        }
        if(strcmp(s, "PRINT_ALL")==0)
            printAll();
        if(strcmp(s, "PRINT_F")==0)
        {
            fscanf(f, "%d", &x);
            print_F(x);
        }
    }
    return 0;
}
