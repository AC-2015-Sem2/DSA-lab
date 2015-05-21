#include "helperFunctionsForRadix.h"

nodeT * createNode(int data)
{
    nodeT * p=(nodeT*)malloc(sizeof(nodeT));
    p->next=NULL;
    p->data=data;
    return p;
}

queueT* initQueueArray(int n)
{
    queueT * a=(queueT*)malloc(n*sizeof(queueT));
    int i;
    for (i=0;i<n;i++)
    {
        a[i].head=NULL;
        a[i].tail=NULL;
    }
    return a;
}

int dequeue(queueT *q)
{
    if (q->head!=NULL)
    {
        int data=q->head->data;
        nodeT * aux=q->head->next;
        free(q->head);
        q->head=aux;
        return data;
    }
    return 0;
}

void enqueue(queueT *q, int data)
{
    if(q->head==NULL)
    {
        q->head=createNode(data);
        q->tail=q->head;
    }
    else
    {
        nodeT * p=createNode(data);
        q->tail->next=p;
        q->tail=p;
    }
}

int isEmpty(queueT q)
{
    if (q.head==NULL)
    {
        return 1;
    }
        else
    {
        return 0;
    }
}

int getNumberOfDigits(int nr)
{
    int k=0;
    int nr1=nr;
    while(nr1>0)
    {
        nr1/=10;
        k++;
    }
    return k;
}
int getmaxNrOfDigits(int *x, int n)
{
    int max=0;
    int i;
    for(i=0;i<n;i++)
    {
        int nrOfDigits=getNumberOfDigits(x[i]);
        if (max<nrOfDigits)
        {
            max=nrOfDigits;
        }
    }
    return max;
}
