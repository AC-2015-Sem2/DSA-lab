#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int code;
    struct node *next;
} nodeT;

nodeT *head;
nodeT *tail;

void addfirst(int givencode)
{
    if(head==NULL)
    {
        head=(nodeT *)malloc(sizeof(nodeT));
        head->next=NULL;
        head->code=givencode;
        tail=head;
    }
    else
    {
        nodeT *p=(nodeT *)malloc(sizeof(nodeT));
        p->code=givencode;
        p->next=head;
        head=p;
    }
}
void addlast(int givencode)
{
    if(head==NULL)
    {
        head=(nodeT *)malloc(sizeof(nodeT));
        head->code=givencode;
        head->next=NULL;
        tail=head;
    }
    else
    {
        nodeT *p=(nodeT *)malloc(sizeof(nodeT));
        p->code=givencode;
        p->next=NULL;
        tail->next=p;
        tail=p;
    }
}
void deletelast()
{
    nodeT *q,*q1;
    q=head;
    q1=NULL;
    if(q!=NULL)
    {
        while(q!=tail)
        {
            q1=q;
            q=q->next;
        }
        if(q==head)
        {
            //One node.
            head=tail=NULL;
            free(q);
        }
        else
        {
            q1->next=NULL;
            tail=q1;
            free(q);
        }
    }
}
void deletefirst()
{
    nodeT *q;
    if(head!=NULL)
    {
        q=head;
        head=head->next;
        free(q);
        if(head==NULL)
        {
            tail=NULL;
        }
    }
}
void doomthelist()
{
    nodeT *q;
    while(head!=NULL)
    {
        q=head;
        head=q->next;
        free(q);
    }
    tail=NULL;
}
void removegiven(int givenkey)
{
    nodeT *q,*q1;
    q=head;
    q1=NULL;
    while(q!=NULL)
    {
        if(q->code==givenkey)
        {
            break;
        }
        q1=q;
        q=q->next;
    }
    if(q!=NULL)
    {
        if(q==head)
        {
            head=head->next;
            free(q);
            if(head==NULL)
            {
                tail=NULL;
            }
        }
        else
        {
            q1->next=q->next;
            if(q==tail)
            {
                tail=q1;
            }
            free(q);
        }
    }
}
void printall(FILE *pf)
{
    nodeT *q;
    q=head;
    while(q!=NULL)
    {
        fprintf(pf,"%d ",q->code);
        q=q->next;
    }
    if(head!=NULL)
    {
        fprintf(pf,"\n");
    }
}
void printfirstx(FILE *pf,int x)
{
    nodeT *q;
    int nr=0;
    q=head;
    while(q!=NULL)
    {
        if(nr==x)
        {
            break;
        }
        fprintf(pf,"%d ",q->code);
        q=q->next;
        nr++;
    }
    if(head!=NULL)
    {
        fprintf(pf,"\n");
    }
}
void printlastx(FILE *pf,int x)
{
    nodeT *q;
    int nr=0;
    q=head;
    if(q!=NULL)
    {
        while(q!=NULL)
        {
            q=q->next;
            nr++;
        }
        if(x>=nr)
        {
            printall(pf);
        }
        else
        {
            int p=nr-x;
            int y=0;
            q=head;
            while(y!=p)
            {
                q=q->next;
                y++;
            }
            while(q!=NULL)
            {
                fprintf(pf,"%d ",q->code);
                q=q->next;
            }
            fprintf(pf,"\n");
        }
    }
}

int main()
{
    FILE *f=fopen("input.txt","r");
    if(f==NULL)
    {
        perror("Can't open file.");
        exit(1);
    }
    FILE *pf=fopen("output.txt","w");
    if(pf==NULL)
    {
        perror("Can't open file.");
        exit(1);
    }
    char s[20];
    fseek(f,0L,SEEK_SET);
    while(fgets(s,sizeof(s),f)!=NULL)
    {
        int x;
        char *p=strtok(s," ");
        if(strcmp(p,"AF")==0)
        {
            p=strtok(NULL,"\n");
            sscanf(p,"%d",&x);
            addfirst(x);
        }
        if(strcmp(p,"AL")==0)
        {
            p=strtok(NULL,"\n");
            sscanf(p,"%d",&x);
            addlast(x);
        }
        if(strcmp(p,"DE")==0)
        {
            p=strtok(NULL,"\n");
            sscanf(p,"%d",&x);
            removegiven(x);
        }
        if(strcmp(p,"PRINT_F")==0)
        {
            p=strtok(NULL,"\n");
            sscanf(p,"%d",&x);
            printfirstx(pf,x);
        }
        if(strcmp(p,"PRINT_L")==0)
        {
            p=strtok(NULL,"\n");
            sscanf(p,"%d",&x);
            printlastx(pf,x);
        }
        p=strtok(s,"\n");
        if(strcmp(p,"DF")==0)
        {
            deletefirst();
        }
        if(strcmp(p,"DL")==0)
        {
            deletelast();
        }
        if(strcmp(p,"DOOM_THE_LIST")==0)
        {
            doomthelist();
        }
        if(strcmp(p,"PRINT_ALL")==0)
        {
            printall(pf);
        }
    }
    fclose(f);
    fclose(pf);
    return 0;
}
