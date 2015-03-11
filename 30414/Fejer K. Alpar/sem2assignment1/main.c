#include <string.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct node
{
    int data;
    struct node* next;
} node;
void print_alll();
void adf(int x);
void adl(int x);
void def();
void del();
void doom_the_listt();
void dee(int x);
void print_fi(int x);
void print_la(int x);
FILE *f;

node *head=NULL,*tail=NULL;

void def()
{
    node *p;
    p=head;
    head=head->next;
    free(p);
}
void del()
{
    node *p;
    if (head==tail) free(head);
    else
    {
        p=head;
        while (p->next!=tail) p=p->next;
        p->next=NULL;
        free(tail);
        tail=p;
    }
}
void doom_the_listt()
{
    node *p,*q;
    p=head;
    do
    {
        q=p;
        p=p->next;
        free(q);
    }
    while (p!=tail);
    free(tail);
}
void dee(int x)
{
    node *p,*q;
    if (head->data==x) def();
    else
    {
        q=head;
        p=q->next;
        while ((p->data!=x) && (p!=tail))
        {
            q=p;
            p=p->next;
        }
        if (p!=tail)
        {
            q->next=p->next;
            free(p);
        }
        else if (tail->data==x){q->next=NULL;
        free(tail);}
    }
}

void print_fi(int x)
{
    f=fopen("output.dat", "a");
    int i=0;
    node *p;
    p=head;
    while ((p!=NULL) && (i<x))
    {
        fprintf(f,"%d ",p->data);
        i++;
        p=p->next;
    }
    fclose(f);
}
void print_la(int x)
{
    f=fopen("output.dat", "a");
    int i=0;
    node *p,*q;
    q=head;
    p=head;
    while (p!=tail)
    {
        p=p->next;
        if (i==x) q=q->next;
        else i++;
    }
    if (i==x)q=q->next;
    while (q!=p)
    {
        fprintf(f,"%d ",q->data);
        q=q->next;
    }
    fclose(f);
}
void adl(int x)
{
    node *a;
    a=(node*)malloc(sizeof(node));
    a->data=x;
    tail->next=a;
    a->next=NULL;
    tail=a;
}
void adf(int x)
{
    node *a;
    if (head==NULL)
    {
        head=(node*)malloc(sizeof(node));
        tail=head;
        head->data=x;
        head->next=NULL;
    }
    else
    {
        a=(node*)malloc(sizeof(node));
        a->data=x;
        a->next=head;
        head=a;
    }
}
void print_alll()
{
    f=fopen("output.dat", "a");
    node *a;
    a=head;
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
    while (fscanf(g,"%s",&s)==1)
    {


        if (strcmp("AF",s)==0)
        {
            fscanf(g,"%d",&x);
            adf(x);
        }
        else if (strcmp("AL",s)==0)
        {
            fscanf(g,"%d",&x);
            adl(x);
        }
        else if (strcmp("DF",s)==0) def();
        else if (strcmp("DL",s)==0) del();
        else if (strcmp("DE",s)==0) {fscanf(g,"%d",&x); dee(x);}
        else if (strcmp("PRINT_ALL",s)==0) print_alll();
        else if (strcmp("PRINT_F",s)==0)
        {
            fscanf(g,"%d",&x);
            print_fi(x);
        }
        else if (strcmp("PRINT_L",s)==0)
        {
            fscanf(g,"%d",&x);
            print_la(x);
        }
        else if (strcmp("DOOM_THE_LIST",s)==0) doom_the_listt();
    }

return 0;
}

