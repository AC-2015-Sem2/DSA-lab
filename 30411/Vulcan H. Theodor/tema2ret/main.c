#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    int code;
    struct node *prev;
    struct node *next;
} NodeT;
struct node *head,*tail;
void addFirst(int code)
{
    if (head==NULL)
    {
        head=(struct node*)malloc(sizeof(struct node));
        head->code=code;
        head->next=NULL;
        head->prev=NULL;
        tail=head;
    }
    else
    {
        struct node *p=(struct node*)malloc(sizeof(struct node));
        p->code=code;
        p->next=head;
        p->prev=NULL;
        head->prev=p;
        head=p;
    }
}
void printlist(FILE *pf)
{
    struct node *p=head;
    while (p!=NULL)
    {
        fprintf(pf,"%d ",p->code);
        p=p->next;
    }
    fprintf(pf,"\n");
}
void addLast(int code)
{
    if (head==NULL)
    {
        head=(struct node*)malloc(sizeof(struct node));
        head->code=code;
        head->next=NULL;
        head->prev=NULL;
        tail=head;
    }
    else
    {
        struct node *p=(struct node*)malloc(sizeof(struct node));
        p->code=code;
        p->next=NULL;
        p->prev=tail;
        tail->next=p;
        tail=p;
    }
}
void deleteF()
{
    if (head!=NULL)
    {
        struct node *p=head;
        head=head->next;
        head->prev=NULL;
        free(p);
    }
}
void deleteL()
{
    if (head!=NULL)
    {
        struct node *p=tail->prev;
        p->next=NULL;
        free(tail);
        tail=p;
    }
}
void DOOM_THE_LIST()
{
    struct node *p=head;
    struct node *f;

    while (p!=NULL)
    {
        f=p->next;
        free(p);
        p=f;
    }
    head=NULL;
    tail=NULL;
}
void delete_x(int x)
{
    NodeT *p;
    p=head;
    while(p!=NULL && p->code!=x)
    {
        p=p->next;
    }
    if (p!=NULL)
    {
        if (head!=p && tail!=p)
        {
            p->prev->next=p->next;
            p->next->prev=p->prev;
            free(p);
        }
        else
            if (head==p)
                deleteF();
            else
                deleteL();
    }
}
int count_element()
{
    struct node *p=head;
    int c=0;
    while (p!=NULL)
    {
        c++;
        p=p->next;
    }
    return c;
}
void print_f(int x,FILE *f)
{
    struct node *p=head;
    int i;
    for (i=1; i<=x&&p!=NULL; i++,p=p->next)
    {
        fprintf(f,"%d ",p->code);
    }
    fprintf(f,"\n");
}
void print_l(int x,FILE *f)
{
    struct node *p=head;
    int c=count_element();
    if (c<x)
        printlist(f);
    else
    {
        while (c-x!=0)
        {
            p=p->next;
            x++;
        }
        while (p!=NULL)
        {
            fprintf(f,"%d ",p->code);
            p=p->next;
        }
        fprintf(f,"\n");
    }
}
int main()
{
    char a[100];
    int x;
    FILE *pf=fopen("input.dat","r");
    FILE *af=fopen("output.dat","w");
    while (fscanf(pf,"%s",a)==1)
    {
        if(strcmp(a,"AF")==0)
        {
            fscanf(pf," %d",&x);
            addFirst(x);
        }
        if(strcmp(a,"AL")==0)
        {
            fscanf(pf," %d",&x);
            addLast(x);
        }
        if(strcmp(a,"DF")==0)
        {
            deleteF();
        }
        if(strcmp(a,"DL")==0)
        {
            deleteL();
        }
        if(strcmp(a,"DOOM_THE_LIST")==0)
        {
            DOOM_THE_LIST();
        }
        if(strcmp(a,"DE")==0)
        {
            fscanf(pf," %d",&x);
            delete_x(x);
        }
        if(strcmp(a,"PRINT_ALL")==0)
        {
            printlist(af);
        }
        if(strcmp(a,"PRINT_F")==0)
        {
            fscanf(pf," %d",&x);
            print_f(x,af);
        }
        if(strcmp(a,"PRINT_L")==0)
        {
            fscanf(pf," %d",&x);
            print_l(x,af);
        }
    }
    return 0;
}


