#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
typedef struct node{
    int data;
    struct node *next;
    } NodeT;
NodeT *head, *tail;
void AddFirst(int data){
    if (head==0){
        head=(NodeT*)malloc(sizeof(NodeT));
        head->data=data;
        tail=head;
        head->next=0;
    }
    else {
        NodeT *A=(NodeT*)malloc(sizeof(NodeT));
        A->data=data;
        A->next=head;
        head=A;
    }
}
void AddLast(int data){
    if (head==0){
        head=(NodeT*)malloc(sizeof(NodeT));
        head->data=data;
        tail=head;
        head->next=0;
        }
    else {
        NodeT *A=(NodeT*)malloc(sizeof(NodeT));
        A->data=data;
        tail->next=A;
        A->next=0;
        tail=A;
    };
}
void DeleteFirst(){
    if (head==0)
        return;
    else {
        NodeT *aux=head;
        head=aux->next;
        free(aux);
    }
    }
void DeleteLast(){
    if (head==0)
        return;
    else {
        NodeT *aux=head;
        while (aux->next!=tail)
            aux=aux->next;
        aux->next=0;
        free(tail);
        tail=aux;
    }
}
void Doom(){
    if (head==0)
        return;
    else {
        while (head!=0)
        {
            NodeT *aux=head;
            head=head->next;
            free(aux);
        }
        free(head);
    }
 }
void DeleteElem(int data){
    if (head==0)
        return;
    else
    {
        NodeT *aux1,*aux2;
        if (head->data==data)
        {
            DeleteFirst();
        }
        else
        {

            aux2=head;
            aux1=aux2;
            while (aux1!=0)
            {

                if (aux1->data==data)
                {
                    aux2->next=aux1->next;
                    free(aux1);
                }
                else
                {
                   aux2=aux1;
                   aux1=aux1->next;
                }
            }
        }
    }
}

void PrintAll(FILE *f2){
    NodeT *aux;
    aux=head;
    while(aux!=0)
    {
        fprintf(f2,"%d ",aux->data);
        aux=aux->next;
    }
    if(head!=0)
    {
        fprintf(f2,"\n");
    }
}
void PrintFirstX(FILE *f2,int x){
    NodeT *aux;
    int nr=0;
    aux=head;
    while(aux!=0)
    {
        if(nr==x)
        {
            break;
        }
        fprintf(f2,"%d ",aux->data);
        aux=aux->next;
        nr++;
    }
    if(head!=0)
    {
        fprintf(f2,"\n");
    }
}
void PrintLastX(FILE *f2,int x){
    NodeT *aux;
    int nr=0;
    aux=head;
    if(aux!=0)
    {
        while(aux!=0)
        {
            aux=aux->next;
            nr++;
        }
        if(x>=nr)
        {
            PrintAll(f2);
        }
        else
        {
            int p=nr-x;
            int y=0;
            aux=head;
            while(y!=p)
            {
                aux=aux->next;
                y++;
            }
            while(aux!=0)
            {
                fprintf(f2,"%d ",aux->data);
                aux=aux->next;
            }
            fprintf(f2,"\n");
        }
    }
}
int main()
{
    FILE *f=fopen("input.txt","r");
    FILE *f2=fopen("output.txt","w");
    int x;
    char s[20];

    while (fscanf(f,"%s",&s)==1)
    {


        if (strcmp("AF",s)==0)
        {
            fscanf(f,"%d",&x);
            AddFirst(x);
        }
        else if (strcmp("AL",s)==0)
        {
            fscanf(f,"%d",&x);
            AddLast(x);
        }
        else if (strcmp("DF",s)==0)
            DeleteFirst();
        else if (strcmp("DL",s)==0)
            DeleteLast();
        else if (strcmp("DOOM_THE_LIST",s)==0)
            Doom();
        else if (strcmp("DE",s)==0)
        {
            fscanf(f,"%d",&x);
            DeleteElem(x);
        }
        else if (strcmp("PRINT_ALL",s)==0)
            PrintAll(f2);
        else if (strcmp("PRINT_F",s)==0)
        {
            fscanf(f,"%d",&x);
            PrintFirstX(f2,x);
        }
        else if (strcmp("PRINT_L",s)==0)
        {
            fscanf(f,"%d",&x);
            PrintLastX(f2,x);
        }
    }
    fclose(f);
    fclose(f2);
    return 0;
}


