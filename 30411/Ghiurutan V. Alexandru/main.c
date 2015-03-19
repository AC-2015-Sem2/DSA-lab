#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "customer.h"

typedef struct node
{
    int money;
    int time;
    struct node *next;
    struct node *previous;
} nodeT;

typedef struct s
{
    nodeT *head;
    nodeT *tail;
    int length;
} SENTINEL;

SENTINEL *sentinel;

void enqueue(int x,int y)
{
    if(sentinel==NULL)
    {
        sentinel=(SENTINEL *)malloc(sizeof(SENTINEL));
        sentinel->head=(nodeT *)malloc(sizeof(nodeT));
        sentinel->head->money=x;
        sentinel->head->time=y;
        sentinel->head->next=NULL;
        sentinel->head->previous=NULL;
        sentinel->tail=sentinel->head;
        (sentinel->length)++;
    }
    else
    {
        nodeT *p=(nodeT *)malloc(sizeof(nodeT));
        p->money=x;
        p->time=y;
        p->next=NULL;
        p->previous=sentinel->tail;
        sentinel->tail->next=p;
        sentinel->tail=p;
        (sentinel->length)++;
    }
}
void callqueue(FILE *f,FILE *pf,int nrc)
{
    char tab[50];
    int x,y,t,i,nr,t1;
    char c;
    nr=0;
    t1=0;
    fseek(f,0L,SEEK_SET);
    fgets(tab,sizeof(tab),f);
    for(i=0; i<nrc; i++)
    {
        fgets(tab,sizeof(tab),f);
        sscanf(tab,"%*s %d %d",&x,&y);
        enqueue(x,y);
    }
    fseek(f,0L,SEEK_SET);
    nodeT *q=sentinel->head;
    do
    {
        fscanf(f,"%d%c",&t,&c);

        while(q!=NULL)
        {
            if(t-(q->time+t1)<0)
            {
                break;
            }
            else
            {
                nr+=q->money;
                t1=q->time;
                q=q->next;
            }
        }

        fprintf(pf,"After %d seconds: %d\n",t,nr);
    }
    while(c==' ');
}

int main(int argc,char *argv[])
{
    int nrc;
    if(argc!=3)
    {
        perror("Incorrect number of arguments!\n");
        return -1;
    }
    if(strcmp(argv[1],"input.txt")!=0)
    {
        printf("Incorrect argument \"%s\".",argv[1]);
        return -2;
    }
    if(strcmp(argv[2],"output.txt")!=0)
    {
        printf("Incorrect argument \"%s\".",argv[2]);
        return -3;
    }
    FILE *pf,*f;
    f=fopen(argv[1],"r");
    if(f==NULL)
    {
        perror("Can't open file!\n");
        return -4;
    }
    pf=fopen(argv[2],"w");
    if(pf==NULL)
    {
        perror("Can't create file!");
        return -5;
    }
    nrc=numberofcustomers(f);
    callqueue(f,pf,nrc);
    fclose(f);
    fclose(pf);
    free(sentinel->head);
    free(sentinel->tail);
    free(sentinel);
    return 0;
}
