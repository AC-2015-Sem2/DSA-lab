#include <stdio.h>
#include <stdlib.h>
#include<string.h>
FILE *f, *g;
typedef struct NodeT
{
    int data;
    struct NodeT* next;
    struct NodeT* prev;
} NodeT;
typedef struct santinel
{
    NodeT* head;
    NodeT* tail;
} sant;
void init(sant *s)
{
    s->head=NULL;
    s->tail=NULL;
}
void addfirst(sant *s,int data)
{
    if(s->head==NULL)
    {
        s->head=(NodeT*)malloc(sizeof(NodeT));
        s->head->data=data;
        s->head->next=NULL;
        s->tail=s->head;
    }
    else
    {
        NodeT *new;
        new=(NodeT*)malloc(sizeof(NodeT));
        new->data=data;
        new->next=s->head;
        s->head->prev=new;
        s->head=new;
    }
}
void addlast(sant *s,int data)
{
    if(s->head==NULL)
    {
        s->head=(NodeT*)malloc(sizeof(NodeT));
        s->head->data=data;
        s->head->next=NULL;
        s->tail=s->head;
    }
    else
    {
        NodeT *new;
        new=(NodeT*)malloc(sizeof(NodeT));
        new->data=data;
        new->prev=s->tail;
        s->tail->next=new;
        new->next=NULL;
        s->tail=new;

    }
}
void delfirst(sant *s)
{
    if(s->head==NULL)
        return;
    else
    {
        s->head=s->head->next;
        free(s->head->prev);
    }
}
void dellast(sant *s)
{  if(s->head==NULL)
        return;
   else
    s->tail->prev->next=NULL;
    s->tail=s->tail->prev;
}
void doom(sant *s)
{
    NodeT *x=s->head;
    while(x!=NULL)
    {
        s->head = x->next;
        free(x);
        x=s->head;
    }
    s->tail=NULL;
}
void delelem(sant *s,int data)geo
{
    NodeT *x=s->head, *previous=s->head;
    while(x!=NULL)
    {
        if(x->data==data)
        {
            if(s->head==x)
                s->head = x->next;
            if(s->tail==x)
            {
                previous->next=NULL;
                s->tail = previous;
            }
            previous ->next = x->next;
            free(x);
            return ;
        }
        else
        {
            previous =x;
            x=x->next;
        }
    }
}
void printfirst(sant *s,int nr)
{
    NodeT *x=s->head;
    while(nr>0)
    {
        fprintf(g,"%d ",x->data);
        x=x->next;
        nr--;
    }
    fprintf(g,"\n");
}
void printlast(sant *s,int nr)
{
    NodeT *x=s->tail;
    while(nr>0)
    {
        fprintf(g,"%d ",x->data);
        x=x->prev;
        nr--;
    }
    fprintf(g,"\n");
}
void printall(sant *s)
{
    NodeT *x=s->head;
    while(x!=NULL)
    {
        fprintf(g,"%d ",x->data);
        x=x->next;
    }
    fprintf(g,"\n");
}
int main()
{
    sant *s;
    s=(sant*)malloc(sizeof(s));
    init(s);
    int x=0;
    f=fopen("input.dat","r");
    g=fopen("output.dat","w");
    char string[30];


    while(fscanf(f,"%s ",string)==1)
    {
        if(strcmp(string,"DF")==0)
        {
            delfirst(s);
            printall(s);
        }
        else if(strcmp(string,"DL")==0)
        {
            dellast(s);
            printall(s);
        }
        else if(strcmp(string,"DOOM_THE_LIST")==0)
        {
            doom(s);
            printall(s);
        }
        else if(strcmp(string,"PRINT_ALL")==0)
        {
            printall(s);
        }
        else
        {
            if(strcmp(string,"AF")==0)
            {
                fscanf(f,"%d",&x);
                addfirst(s,x);
            }
            if(strcmp(string,"AL")==0)
            {
                fscanf(f,"%d",&x);
                addlast(s,x);
            }
            if(strcmp(string,"DE")==0)
            {
                fscanf(f,"%d",&x);
                delelem(s,x);
            }
            if(strcmp(string,"PRINT_F")==0)
            {
                fscanf(f,"%d",&x);
                printfirst(s,x);
            }
            if(strcmp(string,"PRINT_L")==0)
            {
                fscanf(f,"%d",&x);
                printlast(s,x);
            }
        }
    }
    fclose(f);
    fclose(g);

    return 0;
}
