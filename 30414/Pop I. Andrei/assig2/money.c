# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct nod
{
    int money;
    int time;
    struct nod *next;
}NODE;

typedef struct nod1
{
    int seconds;
    struct nod1 *next;
}TIME;

NODE *head, *tail;
TIME *first, *last;

void enqueue(int money, int time)
{
    NODE *newnode=(NODE*) malloc(sizeof(NODE));

    if(tail==NULL)
    {
        head=tail=newnode;
        newnode->money=money;
        newnode->time=time;
    }
    else
    {
        newnode->next=NULL;
        tail->next=newnode;
        tail=newnode;
        newnode->money=money;
        newnode->time=time;
    }

}

void dequeue()
{
    NODE *myNode=head;

    head=head->next;
    free(myNode);
}

NODE *peek()
{
    return head;
}

void print()
{
    NODE *myNode=head;

    while(myNode!=NULL)
    {
        printf("%d %d\n", myNode->money, myNode->time);
        myNode=myNode->next;
    }

}

void enqueueT(int time)
{
    TIME *myNode=(TIME*) malloc(sizeof(TIME));

    if(first==NULL)
    {
        first=last=myNode;
        myNode->next=NULL;
        myNode->seconds=time;
    }
    else
    {
        myNode->next=NULL;
        last->next=myNode;
        myNode->seconds=time;
        last=myNode;
    }
}

void dequeueT()
{
    TIME *myNode=first;

    first=first->next;
    free(myNode);
}

void decide(int moments, FILE *out)
{
    NODE *myNode=head;
    int amount=0, i, time=0;

    for(i=0; i<moments; i++)
    {
        fprintf(out,"After %d seconds: ", first->seconds);
        while(myNode!=NULL && first->seconds >= time + myNode->time)
        {
            time+=myNode->time;
            amount+=myNode->money;
            dequeue();
            myNode=peek();
        }
        fprintf(out,"%d\n", amount);
        if(first!=NULL)
            dequeueT();
    }
}

int main()
{
    FILE *in, *out;
    int money, time, moments=0;
    char name[100], *p, s[]=" \n";

    in=fopen("input.dat", "r");
    out=fopen("output.dat", "w");

    fgets(name, sizeof(name), in);
    p=strtok(name, s);
    while(p)
    {
        moments+=1;
        time=atoi(p);
        enqueueT(time);
        p=strtok(NULL, s);

    }

    while(fscanf(in,"%s %d %d", name, &money, &time)!=EOF)
    {
        enqueue(money, time);
    }

    decide(moments, out);

    return 0;
}
