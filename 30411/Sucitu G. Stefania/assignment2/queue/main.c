#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct client
{
    int x,y;
    char name[20];
    struct node *next;
} client;
client *chead,*ctail;
typedef struct node
{
    int c;
    struct node *next;
} node;
node *head,*tail;
void enqueue(int x,int y,char name[20])
{
    if (chead==NULL)
    {
        chead=(client*)malloc(sizeof(client));
        chead->x=x;
        chead->y=y;
        strcpy(chead->name,name);
        chead->next=NULL;
        ctail=chead;
    }
    else
    {

        client *t=(client*)malloc(sizeof(client));
        t->x=x;
        t->y=y;
        strcpy(t->name,name);
        t->next=NULL;
        ctail->next=t;
        ctail=t;
    }
}
void dequeue()
{
    if (chead!=NULL)
    {
        node *t=chead->next;
        free(chead);
        chead=t;
    }

}
void AL(int c)
{
    if (head==NULL)
    {
        head=(struct node*)malloc(sizeof(struct node*));
        head->c=c;
        head->next=NULL;
    }
    else
    {
        if (tail==NULL)
        {
            struct node *t=(struct node*)malloc(sizeof(struct node*));
            t->c=c;
            t->next=NULL;
            tail=t;
            head->next=tail;
        }
        else
        {
            struct node *t=(struct node*)malloc(sizeof(struct node*));
            t->c=c;
            t->next=NULL;
            tail->next=t;
            tail=t;
        }
    }
}
void DF()
{
    if (head!=NULL)
    {
        struct client *t=head;
        head=head->next;
        free(t);
    }
}
void read()
{
    FILE *pf=fopen("input.dat","r");
    int time;
    while (fscanf(pf,"%d ",&time)==1)
    {
        AL(time);
    }
    int x,y;
    char name[20];
    while (fscanf(pf,"%s %d %d",name,&x,&y)==3)
    {
        enqueue(x,y,name);
    }
    fclose(pf);
}
void sum()
{

    FILE *pf=fopen("output.dat","w");
    int sec,mon=0;
    int q=0;
    while (head!=NULL)
    {
        sec=head->c;

        while (q<=sec)
        {
            if (chead!=NULL)
                if (q+chead->y>sec)
                {
                    fprintf(pf,"After %d seconds: %d\n",sec,mon);
                    break;
                }
                else
                {
                    if (chead!=NULL)
                    {
                    q+=chead->y;
                        mon+=chead->x;
                        dequeue();
                    }
                    else
                    {
                        fprintf(pf,"After %d seconds: %d\n",sec,mon);
                        break;
                    }

                }
            else
                {
                       fprintf(pf,"After %d seconds: %d\n",sec,mon);
                        break;
                }

        }
        DF();
    }

}
int main()
{
    read();
    sum();
    return 0;
}
