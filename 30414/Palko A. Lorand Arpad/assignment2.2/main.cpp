
#include <stdlib.h>
#include <stdio.h>
using namespace std;

typedef struct customer
{
    int cash, time;
    struct customer * next;
} customer;
customer *FirstC, *LastC;

typedef struct time
{
    int time;
    struct time *next;
} time;
time *FirstT, *LastT;

void addlastcustomer(int data1, int data2)
{
    customer *a;
        a=(customer*)malloc(sizeof(customer));
        a->cash=data1;
        a->time=data2;
        a->next=NULL;
        if (FirstC==NULL)
        {
            FirstC=a;
            LastC=a;
        }
    else
    {
        LastC->next=a;
        LastC=a;
    }
}

void addlasttime(int data)
{
    time *a;
        a=(time*)malloc(sizeof(time));
        a->time=data;
        a->next=NULL;
    if (FirstT==NULL){
        FirstT=a;
        LastT=a;
    }
    else
    {
        LastT->next=a;
        LastT=a;
    }
}

void deletefirstcustomer()
{
    customer *a;
    a=FirstC;
    if(FirstC!=LastC)
        FirstC=FirstC->next;
    else{
        FirstC=NULL;
        LastC=NULL;
    }
    free(a);
}

void deletfirsttime()
{
    time *a;
    a=FirstT;
    if (FirstT!=LastT)
        FirstT=FirstT->next;
    else
    {
      FirstT=NULL;
      LastT=NULL;
    }
    free(a);
}

int main()
{
    int time,time1,cash;
    char name[20];
    FILE *f;
    FILE *g;
    f=fopen("input.dat","r");
    g=fopen("output.dat","w");
    while (fscanf(f,"%d",&time)==1)
        addlasttime(time);
    while (fscanf(f, "%s",&name)==1)
    {
        fscanf(f, "%d",&cash);
        fscanf(f, "%d",&time);
        addlastcustomer(cash,time);
    }
    cash=0;
    time=0;
    time1=0;
    while(FirstT!=NULL){
       time=time+FirstT->time-time1;
       while ((FirstC!=NULL) && (time-FirstC->time>=0))
       {
           cash=cash+FirstC->cash;
           time=time-FirstC->time;
           deletefirstcustomer();
       }
       time1=FirstT->time;
       deletfirsttime();
       fprintf(g,"After %d seconds: %d \n", time1, cash);
    }
    fclose(f);
    fclose(g);
    return 0;
}
