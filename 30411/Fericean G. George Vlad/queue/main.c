#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct cs
{
    int x,y;
    char name[20];
    struct node *next;
} Customer;
typedef struct node
{
    int data;
    struct node *next;
} NodeT;
NodeT *head,*tail;
typedef struct sent
{
    Customer *head;
    Customer *tail;
    int length;
} sant;
sant *s;
void enqueue(int x,int y,char name[20])
{
    if (s==NULL)
    {
        s=(sant*)malloc(sizeof(sant));
        s->head=(Customer*)malloc(sizeof(Customer));
        s->head->x=x;
        s->head->y=y;
        strcpy(s->head->name,name);
        s->head->next=NULL;
        s->tail=s->head;
        s->length=1;
    }
    else
    {

        Customer *p=(Customer*)malloc(sizeof(Customer));
        p->x=x;
        p->y=y;
        strcpy(p->name,name);
        p->next=NULL;
        s->tail->next=p;
        s->tail=p;
        s->length++;
    }
}
void dequeue()
{
    if (s->head!=NULL)
    {
        Customer *p=s->head->next;
        free(s->head);
        s->length--;
        s->head=p;
    }

}
void addLast(int data)
{
    if(head==NULL)
    {
        head=(NodeT *)malloc(sizeof(NodeT));
        head->data=data;
        head->next=NULL;
        tail=head;
    }
    else
    {
        NodeT *p=(NodeT *)malloc(sizeof(NodeT));
        p->data=data;
        p->next=NULL;
        tail->next=p;
        tail=p;
    }
}
void deletefirst()
{
    if (head!=NULL)
    {
        struct node *p=head;
        head=head->next;
        free(p);
    }
}
void dettime()
{
    FILE *pf=fopen("output.dat","w");
    int timp,money=0;
    int t=0;
    while (head!=NULL)
    {
        timp=head->data;

        while (t<=timp)
        {
            if (s->head!=NULL)
                if (t+s->head->y>timp)
                {
                    fprintf(pf,"After %d seconds: %d\n",timp,money);
                    break;
                }
                else
                {
                    if (s->head!=NULL)
                    {
                        t=t+s->head->y;
                        money=money+s->head->x;
                        dequeue();
                    }
                    else
                    {
                        fprintf(pf,"After %d seconds: %d\n",timp,money);
                        break;
                    }

                }
            else
            {
                fprintf(pf,"After %d seconds: %d\n",timp,money);
                break;
            }

        }
        deletefirst();
    }

}
int main()
{
    FILE *pf=fopen("input.dat","r");
    int time;
    int x,y;
    char name[20];
    while (fscanf(pf,"%d ",&time)==1)
    {
        addLast(time);
    }

    while (fscanf(pf,"%s %d %d",name,&x,&y)==3)
    {
        enqueue(x,y,name);
    }
    fclose(pf);
    dettime();
    return 0;
}
