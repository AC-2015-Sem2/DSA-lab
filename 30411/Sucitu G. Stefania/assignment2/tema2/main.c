#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    int x;
    struct node* next;
    struct node *previous;
} nodet;
nodet *head,*tail;

nodet* find(int n)
{
    nodet *aux;
    aux=head;
    while(aux!=NULL && aux->x!=n)
    {
        aux=aux->next;
    }
    return aux;
}
void AF(int x)
{
    if (head==NULL)
    {

        head=(nodet*)malloc(sizeof(nodet));
        head->previous=NULL;
        head->x=x;
        head->next=NULL;
        tail=head;
    }
    else
    {
        nodet* t=(nodet*)malloc(sizeof(nodet));
        t->x=x;
        t->next=head;
        t->previous=NULL;
        head->previous=t;
        head=t;
    }
}

void AL(int x)
{
    if (head==NULL)
    {

        head=(struct node*)malloc(sizeof(struct node));
        head->x=x;
        head->previous=NULL;
        head->next=NULL;
        tail=head;
    }
    else
    {
        nodet *t=(nodet*)malloc(sizeof(nodet));
        t->x=x;
        t->next=NULL;
        t->previous=tail;
        tail->next=t;
        tail=t;
    }
}


void DF()
{
    if (head!=NULL)
    {
        nodet* t=head;
        head=head->next;
        head->previous=NULL;
        free(t);
    }
}
void DL()
{
    if (head!=NULL)
    {
        if (head==tail)
        {
            free(tail);
            head=NULL;
            tail=NULL;
        }
        else
        {
            nodet* t;
            t=tail->previous;
            free(tail);
            tail=t;
        }
    }
}

void  DOOM_THE_LIST()
{
    if (head!=NULL)
    {

        nodet *t=head,*y=head->next;
        while (y!=NULL)
        {
            free(t);
            t=y;
            y=y->next;
        }

        head=NULL;
        tail=NULL;
    }
}

void DE(int x)
{
    nodet *t;
    t=find(x);
    nodet *y=head;
    if (t!=NULL)
    {
        if (t==head)
        {
            DF();
        }
        else
        {
            if (t==tail)
                DL();
            else{
                nodet *p,*r;
                p=t->previous;
                r=t->next;
                r->previous=p;
                p->next=r;
                free(t);
            }
        }
    }
}

void PRINT_ALL(FILE *af)
{

    nodet *t=head;
    while (t!=NULL)
    {
        fprintf(af,"%d ",t->x);
        t=t->next;
    }
    fprintf(af,"\n");
}

void PRINT_F(int n, FILE *af)
{
    int i;
    nodet *t=head;
    for(i=1; i<=n; i++)
    {
        fprintf(af,"%d ",t->x);
        t=t->next;
    }
    fprintf(af,"\n");
}
void PRINT_L(int n,FILE *af)
{
    nodet *t=head;
    int i;
    t=tail;
    for (i=1; i<n; i++)
    {
        t=t->previous;
    }
    for (i=1; i<n; i++)
    {
        fprintf(af,"%d ",t->x);
        t=t->next;
    }
    fprintf(af,"%d ",t->x);
    fprintf(af,"\n");
}
void citire()
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
            AF(x);
        }
        if(strcmp(a,"AL")==0)
        {
            fscanf(pf," %d",&x);
            AL(x);
        }
        if(strcmp(a,"DF")==0)
        {
            DF();
        }
        if(strcmp(a,"DL")==0)
        {
            DL();
        }
        if(strcmp(a,"DOOM_THE_LIST")==0)
        {

            DOOM_THE_LIST();
        }
        if(strcmp(a,"DE")==0)
        {
            fscanf(pf," %d",&x);
            DE(x);
        }
        if(strcmp(a,"PRINT_ALL")==0)
        {
            PRINT_ALL(af);
        }
        if(strcmp(a,"PRINT_F")==0)
        {
            fscanf(pf," %d",&x);
           PRINT_F(x,af);
        }
        if(strcmp(a,"PRINT_L")==0)
        {
            fscanf(pf," %d",&x);
            PRINT_L(x,af);
        }
    }
}
int main()
{
    citire();
    return 0;
}

