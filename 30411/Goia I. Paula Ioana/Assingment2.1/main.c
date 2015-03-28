#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct NodeT
{
    char s[20];
    int x,y;
    struct NodeT* next;
} NodeT;
NodeT *head, *tail;
FILE *in,*out;
void addLast(char s[20],int x,int y)
{
    if(head==NULL)
    {
        head=(NodeT*)malloc(sizeof(NodeT));
        strcpy(head->s,s);
        head->x=x;
        head->y=y;
        head->next=NULL;
        tail=head;
    }
    else if (tail==NULL)
    {
        NodeT* p=(NodeT*)malloc(sizeof(NodeT));
        strcpy(p->s,s);
        p->x=x;
        p->y=y;
        p->next=NULL;
        tail=p;
    }
    else
    {
        NodeT* p=(NodeT*)malloc(sizeof(NodeT));
        strcpy(p->s,s);
        p->x=x;
        p->y=y;
        p->next=NULL;
        tail->next=p;
        tail=p;
    }
}
void delete_first()
{
    NodeT *p;
    if(head!=NULL )
    {
        p=head;
        head=head ->next ;
        free(p) ;
        if (head== NULL)
            tail=NULL;
    }
}
void showMeTheMoney(int t[10],int l)
{
    NodeT*p=head;
    int time,cash=0,i=1;
    time=0;
    for(i=1; i<=l; i++)
    {
        while(head!=NULL)
        {
            time=time+(p->y);
            if(time>t[i])
            {
                fprintf(out,"At the time %d I have: %d rubles\n",t[i],cash);
                i++;
                delete_first();
                cash=cash+(p->x);
                p=head;
            }
            else
            {
                if(head!=NULL && time<=t[i])
                {
                    cash=cash+(p->x);
                    delete_first();
                    p=head;
                }
            }

        }
        if(head==NULL)fprintf(out,"At the time %d I have: %d rubles\n",t[i],cash);
    }
}

int t[10];
int main()
{

    in=fopen("in.txt","r");
    out=fopen("out.txt","w");
    int n,x,y;
    char s[20];
    int c=fscanf(in,"%d",&n);
    int l=0;
    while(c!=0)
    {
        l++;
        t[l]=n;

        c=fscanf(in,"%d",&n);
    }
    while(fscanf(in,"%s %d %d",s,&x,&y)>0)
    {
        addLast(s,x,y);
    }
    showMeTheMoney(t,l);
    return 0;
}
