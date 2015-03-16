#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}NodeT;

typedef struct
{
    int lenght;
    NodeT *head;
    NodeT *tail;
}LHeader;
LHeader list;
NodeT* CreateNode (int x)
{
    NodeT *p=(NodeT*)malloc(sizeof(NodeT));
    p->data=x;
    p->next=NULL;
    p->prev=NULL;
    return p;
}
void AddFirst(int x)
{
    NodeT *p=CreateNode(x);
    if(list.head==NULL)
    {
       list.head=p;
       list.tail=p;
       p->next=p->prev=NULL;
    }
    else
    {
        list.head->prev=p;
        p->next=list.head;
        p->prev=NULL;
        list.head=p;
    }
    list.lenght++;
}
void AddLast(int x)
{
    NodeT *p=CreateNode(x);
    if(list.head==NULL)
    {
        list.head=p;
        list.tail=p;
    }
    else
    {
        list.tail->next=p;
        p->prev=list.tail;
        list.tail=p;
    }
    list.lenght++;
}
void DeleteFirst()
{
    NodeT* aux;
    aux=list.head;
    list.head=aux->next;
    list.head->prev=NULL;
    free(aux);
    list.lenght--;
}
void DeleteLast()
{
    NodeT *aux=list.tail;
    list.tail=list.tail->prev;
    if(list.tail==NULL)
        list.head=NULL;
    else
        list.tail->next=NULL;
    free(aux);
    list.lenght--;
}
void DeleteElement(int x) //this function is not working well
{
    NodeT *p=list.head;
    while(p!=NULL)
    {
        if(p->data==x)
            break;
        p=p->next;
    }
    if(p!=NULL)
    {
        if(p==list.head)
        {
            list.head=list.head->next;
            list.head->prev=NULL;
            free(p);
        }
        else
        {
            p->next->prev=p->prev;
            p->prev->next=p->next;
            free(p);
        }
    }

}
void DOOM_LIST()
{
    NodeT *p;
    while(list.head!=NULL)
    {
        p=list.head;
        list.head=list.head->next;
        free(p);
    }
    list.lenght=0;
}
void PrintListFile(FILE *out)
{
    NodeT *aux=list.head;
    while(aux!=NULL)
    {
        fprintf(out,"%d ",aux->data);
        aux=aux->next;
    }
}

void PrintList()
{
    NodeT *aux=list.head;
    if(list.head==list.tail)
        printf("%d ",list.head->data);
    else
    {   while(aux!=list.tail)
        {
            printf("%d ",aux->data);
            aux=aux->next;
        }
        printf("%d ",list.tail->data);
    }
}
void PrintFirst(FILE *out,int x)
{
    int i;
    NodeT *p=list.head;
    if(x>list.lenght)
        PrintListFile(out);
    else
        for(i=0;i<x;i++)
        {
            fprintf(out,"%d ",p->data);
            p=p->next;
        }
    fprintf(out,"\n");
}
void PrintLast(FILE *out,int x)
{
    int i;
    NodeT *p=list.head;
    if(x>list.lenght)
        PrintListFile(out);
    else
    {
        int k=0;
        while(k!=list.lenght-x)
        {
            p=p->next;
            k++;
        }
        for(i=k;i<list.lenght;i++)
        {
            fprintf(out,"%d ",p->data);
            p=p->next;
        }

    }
    fprintf(out,"\n");
}
void ComputeFile(FILE *in,FILE *out)
{
    fseek(in,0,SEEK_SET);
    char a[100];
    int x;
    while(fscanf(in,"%s %d",a,&x)>0)
    {
        if(strcmp(a,"AF")==0)
            AddFirst(x);
         if(strcmp(a,"AL")==0)
            AddLast(x);
        if(strcmp(a,"DF")==0)
            DeleteFirst();
        /*if(strcmp(a,"DE")==0)
            DeleteElement(x);*/
        if(strcmp(a,"DF")==0)
            DeleteLast();
        if(strcmp(a,"DOOM_THE_LIST")==0)
            DOOM_LIST();
        if(strcmp(a,"PRINT_ALL")==0)
            PrintListFile(out);
        if(strcmp(a,"PRINT_F")==0)
            PrintFirst(out,x);
        if(strcmp(a,"PRINT_L")==0)
            PrintLast(out,x);
    }
}
int main()
{
    FILE *out=fopen("output.txt","a");
    FILE *in=fopen("input.dat","r");
    ComputeFile(in,out);
    PrintList();
    //PrintList();
    return 0;
}
