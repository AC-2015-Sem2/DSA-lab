#include <stdio.h>
#include <stdlib.h>
FILE *f, *pf;
// QUEUE= FIFO
typedef struct node
{

    int ruble,seconds;
    struct node *next;

} nodeT;
nodeT *head, *tail;


void enqueue(int value, int time)    //addLast();
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    p->ruble=value;
    p->seconds=time;

    if(tail== NULL)
    {
        tail=p;
        tail->next=NULL;
        head=tail;
    }
    else
    {
        tail->next=p;
        tail=p;
        tail->next=NULL;
    }
}

void printQueue()
{
    struct node *v=head;
    if(v!=NULL)
    {
        printf("\nElements are:  ");
        while(v!=NULL)
        {
            printf("\n %d %d",v->ruble,v->seconds);
            v=v->next;
        }
        printf("\n");
    }
    else
        printf("\nQueue is Empty");
}

void deQueue()      //deleteFirst();
{
    nodeT *p;
    if (head!= NULL )
    {
        p=head;
        head= head->next;
        free(p) ;
        if(head==NULL)
            tail=NULL;
    }
}


int earned_money(int total_time, int nr_of_customers)
{
    int j=0,sum=0,s;
    nodeT *aux=head;
    while((j<nr_of_customers-1) && (total_time-(aux->seconds))>=0)
    {
        total_time=total_time-aux->seconds;
        sum=sum+aux->ruble;

        aux=aux->next;
        j++;
    }
    return sum;
}

int main()
{
    f=fopen("customers.txt","r");
    if(f==NULL)
        perror("cannot be opened");
    pf=fopen("output.txt","w");
    if(pf==NULL)
        perror("Cannot be written");
    int time[100], i=0, n, nr=0, money, t;
    char line[100], name[200];

    fseek(f,0,SEEK_SET);
    while(fgets(line,sizeof(line),f)!=NULL)
    {
        nr++;
    }
    printf("\nwe have %d customers at Auchan\n",nr-1);
    fseek(f,0,SEEK_SET);
    while(fscanf(f,"%d ",&(time[i]))>0)    //Reading the first line
    {
        i++;
    }
    n=i;
    for(i=0; i<nr-1; i++)
    {
        fscanf(f,"%s %d %d\n",name,&money,&t);
        enqueue(money,t);
    }


    int k;
    for(i=0; i<n; i++)
    {
        k=earned_money(time[i],nr);
        fprintf(pf,"After %d seconds %d\n",time[i],k);

    }
    fclose(f);
    fclose(pf);

}
