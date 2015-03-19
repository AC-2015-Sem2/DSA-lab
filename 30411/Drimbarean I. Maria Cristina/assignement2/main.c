#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    int number;
    struct  node *next;
    struct node *prev;
} NodeT;
typedef struct santinel
{
    NodeT *head;
    NodeT *tail;
    int count;
} sant;
sant *s;
FILE *pi,*po;
void addFirst(int x)
{
    if (s->count==0)
    {
        s->head=(NodeT*)malloc(sizeof(NodeT));
        s->head->number=x;
        s->head->next=NULL;
        s->head->prev=NULL;
    }
    else
    {
        if (s->count==1)
        {
            NodeT *now=(NodeT*)malloc(sizeof(NodeT));
            now->number=x;
            now->next=s->head;
            now->prev=NULL;
            s->head=now;
            s->tail=s->head->next;
        }
        else
        {
            NodeT *now=(NodeT*)malloc(sizeof(NodeT));
            now->number=x;
            now->next=s->head;
            now->prev=NULL;
            s->head=now;
        }
    }
    s->count++;
}
void addLast(int x)
{
    if (s->count==0)
    {
        s->head=(NodeT*)malloc(sizeof(NodeT));
        s->head->number=x;
        s->head->next=NULL;
        s->head->prev=NULL;
    }
    else
    {
        if (s->count==1)
        {
            s->tail=(NodeT*)malloc(sizeof(NodeT));
            s->tail->number=x;
            s->tail->next=NULL;
            s->tail->prev=s->head;
        }
        else
        {
            NodeT *now=(NodeT*)malloc(sizeof(NodeT));
            now->number=x;
            now->next=NULL;
            now->prev=s->tail;
            s->tail=now;
        }
    }
    s->count++;
}
void deleteFirst()
{
    if (s->count!=0)
    {
        s->head->next=s->head;
        s->count--;
    }
}
void deleteLast()
{
    if (s->count!=0)
    {
        if (s->tail!=NULL)
        {
            s->tail->prev=s->tail;
            s->count--;
        }
        else
        {
            s->head=NULL;
            s->count--;
        }
    }
}
void doom()
{
    NodeT *p;
    while (s->head!=NULL)
    {
        p=s->head;
        s->head=s->head->next;
        free(p);
    }
    s->tail=NULL;
    s->count=0;
}
void deleteValue(int x)
{
    int i;
    NodeT *p;
    for (i=1; i<=s->count; i++)
    {
        p=s->head;
        if (p->number==x)
        {
            p->prev->next=p->next;
            s->count--;
        }
        else p=p->next;
    }
}
void printAll ()
{
    NodeT *p;
    p=s->head;
    while (p!=NULL)
    {
        fprintf(po,"%d ",p->number);
        p=p->next;
    }
    fprintf(po,"\n");

}
void printFirst(int x)
{
    if (x>s->count || s->count==x) printAll();
    else {
        int i;
        for(i=1;i<=x;i++)
        {
            NodeT *p;
            p=s->head;
            fprintf(po,"%d ",p->number);
            p=p->next;
        }
        fprintf(po,"\n");
    }
}
void printLast(int x)
{
    int i;
    if (s->count==x || s->count<x) printAll();
    else {
        NodeT *p=s->tail;
        for (i=1;i<=x;i++)
        {
            fprintf(po,"%d ",p->number);
            p=p->prev;
        }
        fprintf(po,"\n");
    }
}
int main()
{
    //allocat space for santinel
    s=(sant*)malloc(sizeof(sant));
    //open files for use
    pi=fopen("input.dat","r");
    po=fopen("output.dat","w");
    //set the counter inside the santinel on 0
    s->count=0;
    //start reading the lines and choose the operations
    fseek(pi,0,SEEK_SET);
    char line[15];
    while (fgets(line,sizeof(line),pi)!=NULL)
    {
        char oper[12];
        int number;
        sscanf(line,"%s %d",oper,&number);
        if (strcmp(oper,"AF")==0) addFirst(number);
        if (strcmp(oper,"AL")==0) addLast(number);
        if (strcmp(oper,"DF")==0) deleteFirst();
        if (strcmp(oper,"DL")==0) deleteLast();
        if (strcmp(oper,"DOOM_THE_LIST")==0) doom();
        if (strcmp(oper,"DE")==0) deleteValue(number);
        if (strcmp(oper,"PRINT_ALL")==0) printAll();
        if (strcmp(oper,"PRINT_F")==0) printFirst(number);
        if (strcmp(oper,"PRINT_L")==0) printLast(number);
    }
    fclose(po);
    return 0;
}
