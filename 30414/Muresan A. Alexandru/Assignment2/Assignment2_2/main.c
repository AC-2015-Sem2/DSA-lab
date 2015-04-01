#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct nod{int time, cash;
                   struct nod *next;}NODE;
typedef struct nodT{int seconds;
                    struct nodT *next}TIME;
TIME *first, *last;
NODE *head, *tail;
void Enqueue( int cash, int time)
{
    if (tail==NULL)
    {
        head=(NODE*)malloc(sizeof(NODE));
        head->time=time;
        head->cash=cash;
        head->next=NULL;
        tail=head;
    }
    else
    {
        NODE *NewNODE=(NODE*)malloc(sizeof(NODE));
        NewNODE->time=time;
        NewNODE->cash=cash;
        NewNODE->next=NULL;
        tail->next=NewNODE;
        tail=NewNODE;
    }
}
void Dequeue()
{
    if (head!=NULL)
    {
        head=head->next;
    }
}
void EnqueueT(int time)
{
    TIME *NewNODE=(TIME*)malloc(sizeof(TIME));
    if(first==NULL)
    {
        NewNODE->seconds=time;
        NewNODE->next=NULL;
        first=NewNODE;
        last=first;
    }
    else
    {
        NewNODE->seconds=time;
        NewNODE->next=NULL;
        last->next=NewNODE;
        last=NewNODE;
    }
}
void DequeueT()
{
    TIME *NewNODE=first;
    first=first->next;
    free(NewNODE);
}
void Process(int intervals, FILE *pf_out)
{
    NODE *NewNODE=head;
    int cashier_money=0, i, time=0;
    for(i=0;i<intervals;i++)
    {
        fprintf(pf_out,"After %d seconds: ", first->seconds);
        while ((NewNODE!=NULL)&&(time+NewNODE->time<=first->seconds))
        {
            time+=NewNODE->time;
            cashier_money+=NewNODE->cash;
            Dequeue();
            NewNODE=head;
        }
        fprintf(pf_out, "%d", cashier_money);
        if(first!=NULL)
        {
            DequeueT();
        }
        fprintf(pf_out, "\n");
    }
}
int main()
{
    FILE *pf_in=fopen("input.dat", "r");
    FILE *pf_out=fopen("output.dat", "w");
    int cash, time, intervals=0;
    char name[100], *p, s[]=" \n";
    fgets(name, sizeof(name), pf_in);
    p=strtok(name, s);
    while(p)
    {
        intervals++;
        time=atoi(p);
        EnqueueT(time);
        p=strtok(NULL,s);
    }
    while(fscanf(pf_in, "%s %d %d", &name, &cash, &time)!=EOF)
    {
        Enqueue(cash, time);
    }
    Process(intervals, pf_out);
    return 0;
}
