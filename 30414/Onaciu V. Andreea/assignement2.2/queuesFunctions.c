#include <stdlib.h>
#include <stdio.h>
///Queue for memorize customers'information
typedef struct queue
{
    int money;
    int time;
    struct queue *next;
} node;
node *head,*tail;
///Queue for memorize the seconds
typedef struct timeQueue
{
    int seconds;
    struct timeQueue* next;
} nodQueue;
nodQueue *headT,*tailT;

/// Function that adds an element on the queue.
void enqueue(FILE* f,int x,int y)
{
    if (head==NULL)
    {
        head=(node *)malloc(sizeof(node));
        head->next=NULL;
        head->money=x;
        head->time=y;
        tail=head;
    }
    else
    {
        node *newnode=(node *)malloc(sizeof(node));
        newnode->money=x;
        newnode->time=y;
        tail->next=newnode;
        newnode->next=NULL;
        tail=newnode;
    }
}
/// Function that eliminates an element on the queue.
void dequeue()
{
    if (head!=NULL)
    {
        node *first=head;
        head=head->next;
        free(first);
        if (head==NULL)
            tail=NULL;
    }
}

void enqueueT(FILE* f,int x)
{
    if (headT==NULL)
    {
        headT=(nodQueue *)malloc(sizeof(nodQueue));
        headT->next=NULL;
        headT->seconds=x;
        tailT=headT;
    }
    else
    {
        nodQueue *newnode=(nodQueue *)malloc(sizeof(nodQueue));
        newnode->seconds=x;
        tailT->next=newnode;
        newnode->next=NULL;
        tailT=newnode;
    }
}

void dequeueT()
{
    if (headT!=NULL)
    {
        nodQueue *first=headT;
        headT=headT->next;
        free(first);
        if (headT==NULL)
            tailT=NULL;
    }
}

void problemSol(FILE *g)
{
    int sum=0; ///Variable for adding the money that the cashier receives.
    int timeleft=0;/// Variable use to compute the time left.
    int sec=0;/// Variable use to calculate the seconds that passed from the start moment.

    while (headT!=NULL)
    {
        timeleft=headT->seconds-sec;
        while ((head!=NULL)&&(timeleft-head->time>=0))
        {
            sum=sum+head->money;
            timeleft=timeleft-head->time;
            sec=head->time+sec;
            dequeue();
        }
        fprintf(g,"After %d seconds: %d\n",headT->seconds,sum);
        dequeueT();
    }

}
