#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node1
{
    char nume[31];
    int rub,t;
    struct node *next;
} NodeC;
typedef struct node
{
    int code;
    struct node *next;
} NodeT;
NodeT *head,*tail;
NodeC *head1, *tail1;
void enqueue(int rub,int t,char nume[31])
{
    if (head1==NULL)
    {
        head1=(NodeC*)malloc(sizeof(NodeC));
        head1->rub=rub;
        head1->t=t;
        strcpy(head1->nume,nume);
        head1->next=NULL;
        tail1=head1;
    }
    else
    {

        NodeC *p=(NodeC*)malloc(sizeof(NodeC));
        p->rub=rub;
        p->t=t;
        strcpy(p->nume,nume);
        p->next=NULL;
        tail1->next=p;
        tail1=p;
    }
}
void dequeue()
{
    if (head1!=NULL)
    {
        NodeC *p=head1->next;
        free(head1);
        head1=p;
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
void read()
{
    int timp;
    int t=0;
    int money=0;
    FILE *p=fopen("input.dat","r");
    while (fscanf(p,"%d ",&timp)==1)
    {
        addLast(timp);
    }
    int a,b;
    char nume[31];
    while (fscanf(p,"%s %d %d",nume,&a,&b)==3)
    {
        enqueue(a,b,nume);
    }
    fclose(p);
}
int main()
{
    read();
    FILE *pf=fopen("output.dat","w");
    int timp,money1=0;
    int t=0;
    while (head!=NULL)
    {
        timp=head->code;

        while (t<=timp)
        {
            if (head1!=NULL)
                if (t+head1->t>timp)
                {
                    fprintf(pf,"After %d seconds: %d\n",timp,money1);
                    break;
                }
                else
                {
                    if (head1!=NULL)
                    {
                        t+=head1->t;
                        money1+=head1->rub;
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
    return 0;
}

