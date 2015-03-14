#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef struct node
{
    int money;
    int time;
    struct node *next;
} nodeT;
nodeT *head, *tail;
void Enqueue(int x,int y)
{
    if (head==0)
    {
        nodeT *aux=(nodeT*)malloc(sizeof(nodeT));
        aux->money=x;
        aux->time=y;
        aux->next=head;
        head=aux;
        tail=head;
    }
    else
    {
        nodeT *aux=(nodeT*)malloc(sizeof(nodeT));
        aux->money=x;
        aux->time=y;
        aux->next=0;
        tail->next=aux;
        tail=aux;
    }
}
void Dequeue()
{
    if (head==0)
        return;
    else
    {
        nodeT *aux=head;
        head=head->next;
        free(aux);
    }
}
void PrintList()
{
    nodeT *aux=head;
    while (aux!=0)
    {
        printf("%d %d\n",aux->money,aux->time);
        aux=aux->next;
    }
}
FILE *f=fopen("input.dat","r");
FILE *f2=fopen("output.txt","w");
int main()
{
    int a[50],x,y,i=0,k=1;
    char c[20];

    while (fscanf(f,"%d",&k)==1)
    {
        a[i]=k;
        i++;
    }
    while (fscanf(f,"%s",c)==1)
    {
        fscanf(f,"%d",&x);
        fscanf(f,"%d",&y);
        Enqueue(x,y);
    }
    int q;
    int rubles=0;
    for(q=0;q<i;q++)
    {
        int seconds=0;
        nodeT *aux=head;
        while (seconds+aux->time<=a[q]&&aux->next!=0)
        {
            rubles+=aux->money;
            seconds+=aux->time;
            Dequeue();
            aux=head;
        }
        fprintf(f2,"%s %d %s %d\n","After",a[q],"seconds:",rubles);
    }
fclose(f);
fclose(f2);
}

