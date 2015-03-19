#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue
{
    int time;
    int money;
    struct Queue* next;
}St;

typedef struct List
{
    struct Queue *head;
    struct Queue *tail;
}gg;

List *Sentinel;

void Initialization()
{
    Sentinel=(List*)malloc(sizeof(List));
    Sentinel->head=NULL;
    Sentinel->tail=NULL;
}

void Enque(int timex,int moneyx)
{
    St *tempx=(struct Queue *)malloc(sizeof(struct Queue));
    St *tempx2;
    tempx->time=timex;
    tempx->money=moneyx;
    tempx->next=NULL;
    if(Sentinel->head==NULL)
        {
        Sentinel->head=tempx;
        }
    else
    {
    tempx2 = Sentinel->head;
    while(tempx2->next!=NULL)
        {
        tempx2=tempx2->next;
        }
    tempx2->next=tempx;
    }
}

void Deque()
{
    struct Queue *temp;
    if(Sentinel->head!=NULL)
    {
    temp=Sentinel->head->next;
    free(Sentinel->head);
    Sentinel->head=temp;
    }
}

void peek(int &moneyx,int &timex)
{
    if(Sentinel->head!=NULL)
    {
    struct Queue *temp = (struct Queue *) malloc (sizeof(struct Queue));
    temp=Sentinel->head;
    timex=temp->time;
    moneyx=temp->money;
    }
}

void sum(int timex,int moneyx,int &sumtime,int &summoney)
{
    if(Sentinel->head!=NULL)
    {
    sumtime=sumtime+timex;
    summoney=summoney+moneyx;
    }
}


int main()
{
    FILE *IN,*OUT;
    IN=fopen("input.dat","r");
    OUT=fopen("output.dat","w");
    int x[100],i=0,j,sumtime=0,summoney=0,timex,moneyx,g=1;
    char a[100],*money,*time,r[100];
    Initialization();
    while(!feof(IN))
        {
        fscanf(IN,"%s",r);
        if(r[0]<'0' || r[0]>'9') break;
        x[i]=atoi(r);
        i++;
        }
    while(fgets(a,100,IN))
    {
        if(g==1)
        {
            money=strtok(a," ");
            time=strtok(NULL," \n");
            g++;
        }
        else
            {
            strtok(a," \n");
            money=strtok(NULL," ");
            time=strtok(NULL," ");
            }
        Enque(atoi(time),atoi(money));
    }
    for(j=0; j<i; j++)
    {
        peek(timex,moneyx);
        sum(moneyx,timex,sumtime,summoney);
        Deque();
        if(sumtime>x[j]) fprintf(OUT,"After %d seconds: %d\n",x[j],summoney-timex);
        else fprintf(OUT,"After %d seconds: %d\n",x[j],summoney);
    }

    return 0;
}
