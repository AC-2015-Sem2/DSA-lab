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
        head=(nodeT*)malloc(sizeof(nodeT));
        head->money=x;
        head->time=y;
        tail=head;
        head->next=0;
    }
    else
    {
        nodeT *aux=(nodeT*)malloc(sizeof(nodeT));
        aux->money=x;
        aux->time=y;
        tail->next=aux;
        aux->next=0;
        tail=aux;
    }
}
void Dequeue()
{
        nodeT *aux=head;
        head=aux->next;
        free(aux);
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
    int a[50],x,y,i=0,k;
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
    int q, rubles=0, seconds=0;
    for(q=0;q<i;q++)
    {
        while (head!=0&&(seconds+head->time<=a[q]))
        {
            rubles+=head->money;
            seconds+=head->time;
            Dequeue();
        }
        fprintf(f2,"%s %d %s %d\n","After",a[q],"seconds:",rubles);
    }

fclose(f);
fclose(f2);
}

