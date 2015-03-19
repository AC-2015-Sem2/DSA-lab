#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int x;
    int y;
    struct node *next;
}NodeT;
typedef struct
{
    NodeT *head;
    NodeT *tail;
}ListT;
ListT L;
NodeT* CreateNode(int x,int y)
{
    NodeT *p=(NodeT*)malloc(sizeof(NodeT));
    p->next=NULL;
    p->x=x;
    p->y=y;
    return p;
}
void AddLast(int x,int y)
{
    if(L.head==NULL)
    {
        L.head=CreateNode(x,y);
        L.tail=L.head;
        L.head->next=NULL;
    }
    else
    {
        NodeT *p=CreateNode(x,y);
        L.tail->next=p;
        L.tail=p;
        L.tail->next=NULL;
    }
}
void DeleteFirst()
{
    if(L.head==L.tail)
        L.head=L.tail=NULL;
    else
    {
        NodeT *p=L.head;
        L.head=L.head->next;
        free(p);
    }
}
void DOOM_LIST()
{
    NodeT *p;
    while(L.head!=NULL)
    {
        p=L.head;
        L.head=L.head->next;
        free(p);
    }
}
void money (int time,FILE *out)
{
    NodeT *p=L.head;
    int sec=time;
    int money=0;
    while(p!=NULL)
    {
        if(time>p->y)
        {
            money=money+p->x;
        }
        else
            break;
        p=p->next;
    }
    fprintf(out,"After %d seconds: %d\n",sec,money);
}
void ComputeFile(FILE *in,FILE *out)
{
    fseek(in,0,SEEK_SET);
    int seconds[10];
    int i;
    int x,y;
    char a[100];
    for(i=0;i<6;i++)
    {
        fscanf(in,"%d ",&seconds[i]);
        fseek(in,24,SEEK_SET);
        while(fscanf(in,"%s %d %d",a,&x,&y)==3)
        {
            AddLast(x,y);
        }
        money(seconds[i],out);
        DOOM_LIST();
    }
}
void PrintList()
{
    NodeT *aux=L.head;
    while(aux!=NULL)
    {
        printf("%d %d\n",aux->x,aux->y);
        aux=aux->next;
    }
}
int main()
{
    FILE *in=fopen("input.dat","r");
    FILE*out=fopen("output.txt","a");
    ComputeFile(in,out);
    PrintList();
    return 0;
}
