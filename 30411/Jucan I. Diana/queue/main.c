#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct customer
{
    int x,y;
    char name[45];
    struct node *next;
} customer;
customer *first,*last;

typedef struct nodeT
{
    int code;
    struct nodeT *next;
} nodeT;
nodeT *head,*tail;

void dequeue()
{
    if (first!=NULL)
    {
        nodeT *t=first->next;
        free(first);
        first=t;
    }

}

void enqueue(char name[40],int x,int y)
{
    if (first==NULL)
    {
        first=(customer*)malloc(sizeof(customer));
        first->x=x;
        first->y=y;
        strcpy(first->name,name);
        first->next=NULL;
        last=first;
    }
    else
    {

        customer *t=(customer*)malloc(sizeof(customer));
        t->x=x;
        t->y=y;
        strcpy(t->name,name);
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
void deletefirst()
{
    if (head!=NULL)
    {
        struct customer *t=head;
        head=head->next;
        free(t);
    }
}
void addLast(int code)
{
    if (head==NULL)
    {
        head=(struct nodeT*)malloc(sizeof(struct nodeT*));
        head->code=code;
        head->next=NULL;
    }
    else
    {
        if (tail==NULL)
        {
            struct nodeT *t=(struct nodeT*)malloc(sizeof(struct nodeT*));
            t->code=code;
            t->next=NULL;
            tail=t;
            head->next=tail;
        }
        else
        {
            struct nodeT *t=(struct nodeT*)malloc(sizeof(struct nodeT*));
            t->code=code;
            t->next=NULL;
            tail->next=t;
            tail=t;
        }
    }
}

void citire()
{
    FILE *pf=fopen("input.dat","r");
    int time;
    while (fscanf(pf,"%d ",&time)==1)
    {
        addLast(time);
    }
    int x,y;
    char name[20];
    while (fscanf(pf,"%s %d %d",name,&x,&y)==3)
    {
        enqueue(name,x,y);
    }
    fclose(pf);
}
void fun()
{

    FILE *pf=fopen("output.dat","w");
    int times,money1=0;
    int k=0;
    while (head!=NULL)
    {
        times=head->code;

        while (k<=times)
        {
            if (first!=NULL)
                if (k+first->y>times)
                {
                    fprintf(pf,"After %d seconds: %d\n",times,money1);
                    break;
                }
                else
                {
                    if (first!=NULL)
                    {
                    k+=first->y;
                        money1+=first->x;
                        dequeue();
                    }
                    else
                    {
                        fprintf(pf,"After %d seconds: %d\n",times,money1);
                        break;
                    }

                }
            else
                {
                        fprintf(pf,"After %d seconds: %d\n",times,money1);
                        break;
                }

        }
        deletefirst();
    }

}
int main()
{

    FILE *f=fopen("input.dat","r");
    if(f==NULL)
    {
        perror("we cannot open the file!");
        return -1;
    }
    int timp;
    while (fscanf(f,"%d ",&timp)==1)
        addLast(timp);
    int x,y;
    char name[20];
    while (fscanf(f,"%s %d %d",name,&x,&y)==3)
    {
        enqueue(name,x,y);
    }
    fclose(f);
    fun();
    return 0;
}
