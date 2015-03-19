#include <stdlib.h>
#include <stdio.h>

typedef struct cust
{
    int cash, time;
    struct cust *next
        } cust;

typedef struct times
{
    int time;
    struct times *next
        } times;

cust *FirstCustomer,*LastCustomer;
times *FirstTime,*LastTime;

void AddTime(int x)
{
    times *p;
    p=(times*)malloc(sizeof(times));
    p->time=x;
    p->next=NULL;
    if (FirstTime==NULL)
    {
        FirstTime=p;
        LastTime=p;
    }
    else
    {
        LastTime->next=p;
        LastTime=p;
    }
}

void AddCustomer(int x, int y)
{
    cust *p;
    p=(cust*)malloc(sizeof(cust));
    p->cash=x;
    p->time=y;
    p->next=NULL;
    if (FirstCustomer==NULL)
    {
        FirstCustomer=p;
        LastCustomer=p;
    }
    else
    {
        LastCustomer->next=p;
        LastCustomer=p;
    }
}

void DeleteTime()
{
    times *p;
    p=FirstTime;
    if (FirstTime!=LastTime) FirstTime=FirstTime->next;
    else
    {
        FirstTime=NULL;
        LastTime=NULL;
    }
    free(p);
}

void DeleteCustomer()
{
    cust *p;
    p=FirstCustomer;
    if (FirstCustomer!=LastCustomer) FirstCustomer=FirstCustomer->next;
    else
    {
        FirstCustomer=NULL;
        LastCustomer=NULL;
    }
    free(p);
}

int main()
{
    FILE *f,*g;
    int cash,time,time1;
    char name[20];
    f=fopen("input.dat","r");
    g=fopen("output.dat","w");
    while (fscanf(f,"%d",&time)==1) AddTime(time);
    while (fscanf(f,"%s",&name)==1)
    {
        fscanf(f,"%d",&cash);
        fscanf(f,"%d",&time);
        AddCustomer(cash,time);
    }
    cash=0;
    time1=0;
    time=0;
    while (FirstTime!=NULL)
    {
        time=time+FirstTime->time-time1;
        while ((FirstCustomer!=NULL) && (time-FirstCustomer->time>=0))
        {
            cash=cash+FirstCustomer->cash;
            time=time-FirstCustomer->time;
            DeleteCustomer();
        }
        time1=FirstTime->time;
        fprintf(g,"After %d seconds: %d\n",FirstTime->time,cash);
        DeleteTime();
    }
    fclose(f);
    fclose(g);
    return 0;
}
