#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct nod
{
    int x,y;
    char name[20];
    struct node *next;
} Node;
typedef struct node
{
    int code;
    struct node *next;
} NodeT;
NodeT *head,*tail;
typedef struct sent
{
    Node *head;
    Node *tail;
    int length;
} santinels;
santinels *s;
void enqueue(int x,int y,char name[20])
{
    if (s==NULL)
    {
        s=(santinels*)malloc(sizeof(santinels));
        s->head=(Node*)malloc(sizeof(Node));
        s->head->x=x;
        s->head->y=y;
        strcpy(s->head->name,name);
        s->head->next=NULL;
        s->tail=s->head;
        s->length=1;
    }
    else
    {

        Node *p=(Node*)malloc(sizeof(Node));
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
        Node *p=s->head->next;
        free(s->head);
        s->length--;
        s->head=p;
    }

}
void addLast(int code)
{
    if (head==NULL)
    {
        head=(struct node*)malloc(sizeof(struct node*));
        head->code=code;
        head->next=NULL;
    }
    else
    {
        if (tail==NULL)
        {
            struct node *p=(struct node*)malloc(sizeof(struct node*));
            p->code=code;
            p->next=NULL;
            tail=p;
            head->next=tail;
        }
        else
        {
            struct node *p=(struct node*)malloc(sizeof(struct node*));
            p->code=code;
            p->next=NULL;
            tail->next=p;
            tail=p;
        }
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
void citire()
{
    FILE *pf=fopen("input.dat","r");
    int time,t=0;
    int money=0;
    while (fscanf(pf,"%d ",&time)==1)
    {
        addLast(time);
    }
    int x,y;
    char name[20];
    while (fscanf(pf,"%s %d %d",name,&x,&y)==3)
    {
        enqueue(x,y,name);
    }
    fclose(pf);
}
void calc()
{
    FILE *pf=fopen("output.dat","w");
    int timp,money1=0;
    int t=0;
    while (head!=NULL)
    {
        timp=head->code;

        while (t<=timp)
        {
            if (s->head!=NULL)
                if (t+s->head->y>timp)
                {
                    fprintf(pf,"After %d seconds: %d\n",timp,money1);
                    break;
                }
                else
                {
                    if (s->head!=NULL)
                    {
                        t+=s->head->y;
                        money1+=s->head->x;
                        dequeue();
                    }
                    else
                    {
                        fprintf(pf,"After %d seconds: %d\n",timp,money1);
                        break;
                    }

                }
            else
                {
                        fprintf(pf,"After %d seconds: %d\n",timp,money1);
                        break;
                }

        }
        deletefirst();
    }

}
int main()
{
    citire();
    calc();
    return 0;
}
