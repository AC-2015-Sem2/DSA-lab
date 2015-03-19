#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct que
{
    char name[15];
    int ruble;
    int time;
    struct que *next;
    struct que *prev;
} QueT;
typedef struct sant
{
    QueT *tail;
    QueT *head;
    int count;
}santinel;
santinel *s;
FILE *pf,*ps;
void enque(char name[15],int money,int seconds)
{
 if (s->count==0)
    {
        s->head=(QueT*)malloc(sizeof(QueT));
        strcpy(s->head->name,name);
        s->head->ruble=money;
        s->head->time=seconds;
        s->head->next=NULL;
        s->head->prev=NULL;
    }
    else
    {
        if (s->count==1)
        {
            s->tail=(QueT*)malloc(sizeof(QueT));
            s->tail->ruble=money;
            s->tail->time=seconds;
            strcpy(s->tail->name,name);
            s->tail->next=NULL;
            s->tail->prev=s->head;
        }
        else
        {
            QueT *now=(QueT*)malloc(sizeof(QueT));
            now->ruble=money;
            now->time=seconds;
            strcpy(now->name,name);
            now->next=NULL;
            now->prev=s->tail;
            s->tail=now;
        }
    }
    s->count++;
}
int main()
{
    s->count=0;//initilize number of elem in the list
    pf=fopen("input.dat","r");
      if (pf==NULL)
    {
        perror("No students!");
        return -100;
    }
    ps=fopen("output.dat","w");
    //read from file
    int period[100];//array to store the periods
    char line[200];
    fseek(pf,0,SEEK_SET);
    char c;
    int number,n=0;
    fscanf(pf,"%d%c",&number,&c);
    while (c==' ')
    {
        n++;
        period[n]=number;
        fscanf(pf,"%d%c",&number,&c);
    }
    n=n+1;
    period[n]=number;//array for periods of length n
    while (fgets(line,sizeof(line),pf)!=NULL)
    {
        //read the command from the line
        char name[15];
        int money,seconds;
        sscanf(line,"%s %d %d",&name,&money,&seconds);
        enque(name,money,seconds);
    }
    int i;
    for (i=1;i<=n;i++)
    {
        int sum=0;int currentTime=0;
        QueT *p=s->head;
        while (currentTime<period[i])
        {
            sum=sum+p->ruble;
            currentTime=currentTime+p->time;
            p=p->next;
        }
        fprintf(ps,"After %d seconds: %d",period[i],sum);
    }
    fclose(ps);
    return 0;
}
