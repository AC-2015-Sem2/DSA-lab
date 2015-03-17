#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct list_t
{
    int sum, time;
    struct list_t* next;
} LIST;

LIST *head, *tail;

void enqueue (int x, int y)
{
    if (head == NULL)
    {
        head=(LIST*)malloc(sizeof(LIST));
        head->sum=x;
        head->time=y;
        head->next=NULL;
        tail=head;
    }
    else
    {
        LIST* t=(LIST*)malloc(sizeof(LIST));
        t->sum=x;
        t->time=y;
        t->next=NULL;
        tail->next=t;
        tail=t;
    }
}

void dequeue ()
{
    if (head != NULL)
    {
        LIST* t = head->next;
        free(head);
        head = t;
    }
}


int main()
{
    head=NULL;
    tail=NULL;
    FILE *f=fopen("input.txt","r");
    if(f==0)
        puts("error");
    int ok=1, index_time=-1, t, T[10], money=0, i=0, x, y, n=0;
    char s[15];

    while(ok==1)
    {
        ok=fscanf(f, "%d", &t);
        index_time++;
        T[index_time]=t;
    }

    while(ok!=EOF)
    {
        ok=fscanf(f, "%s %d %d", s, &x, &y);
        if(ok!=EOF)
        {
            enqueue(x, y);
            n++;
        }
    }

    while(n!=0 && i<index_time)//index_time=nr of given values of the time; n=nr of customers in the queue
    {
        if(i!=0)
            t+=T[i]-T[i-1];
        else
            t=T[0];
        for(ok=0; ok<n && (t-(head->time)>=0); ok++)//ok is a random variable that is being reused
        {
            t-=head->time;
            money+=head->sum;
            dequeue();
        }
        n-=ok;
        printf("after %d seconds: %d\n", T[i], money);
        i++;
    }

    if(n==0 && i<index_time)//no more customers, but still there are other values of time
        for(ok=i; ok<index_time; ok++)
            printf("after %d seconds: %d\n", T[ok], money);



    fclose(f);
    return 0;
}
