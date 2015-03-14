#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    int code;
    struct node *next;
    struct node *previous;
} nodeT;

typedef struct
{
    nodeT *head;
    nodeT *tail;
    int length;
} SENTINEL;

SENTINEL *sentinel;
void addfirst(int givencode)
{
    if(sentinel->head==NULL)
    {
        sentinel->head=(nodeT *)malloc(sizeof(nodeT));
        sentinel->head->code=givencode;
        sentinel->head->next=NULL;
        sentinel->head->previous=NULL;
        sentinel->tail=sentinel->head;
        (sentinel->length)++;
    }
    else
    {
        nodeT *p=(nodeT *)malloc(sizeof(nodeT));
        p->next=sentinel->head;
        p->code=givencode;
        sentinel->head->previous=p;
        if(sentinel->head->next==NULL)
        {
            //One node
            sentinel->tail->previous=p;
        }
        sentinel->head=p;
        (sentinel->length)++;
    }
}

void addlast(int givencode)
{
    if(sentinel->head==NULL)
    {
        sentinel->head=(nodeT *)malloc(sizeof(nodeT));
        sentinel->head->next=NULL;
        sentinel->head->previous=NULL;
        sentinel->head->code=givencode;
        sentinel->tail=sentinel->head;
        (sentinel->length)++;
    }
    else
    {
        nodeT *p=(nodeT *)malloc(sizeof(nodeT));
        p->next=NULL;
        p->code=givencode;
        p->previous=sentinel->tail;
        sentinel->tail=p;
        (sentinel->length)++;
    }
}

void deletelast()
{
    nodeT *q=sentinel->tail;
    if(sentinel->head!=NULL)
    {
        sentinel->tail=sentinel->tail->previous;
        sentinel->tail->next=NULL;
        if(sentinel->tail==NULL)
        {
            sentinel->head=NULL;
        }
        free(q);
        (sentinel->length)--;
    }
}

void deletefirst()
{
    nodeT *q=sentinel->head;
    if(q!=NULL)
    {
        sentinel->head=sentinel->head->next;
        sentinel->head->previous=NULL;
        if(sentinel->head==NULL)
        {
            //One node
            sentinel->tail=NULL;
        }
        else
        {
            sentinel->head->previous=NULL;
        }
        free(q);
        (sentinel->length)--;
    }
}

void deletegiven(int givencode)
{
    nodeT *q;
    //Step 1:Accessing the node
    for(q=sentinel->head; q!=NULL; q=q->next)
    {
        if(q->code==givencode)
        {
            break;
        }
    }
    if(q!=NULL)
    {
        //Step 2:Deleting the node
        if(q==sentinel->head&&q==sentinel->tail)
        {
            //One node
            sentinel->head=NULL;
            sentinel->tail=NULL;
            free(q);
            (sentinel->length)--;
        }
        else if(q==sentinel->head)
        {
            sentinel->head=sentinel->head->next;
            sentinel->head->previous=NULL;
            free(q);
            (sentinel->length)--;
        }
        else
        {
            q->previous->next=q->next;
            q->next->previous=q->previous;
            free(q);
            (sentinel->length)--;
        }
    }
}

void doomthelist()
{
    nodeT *q;
    while(sentinel->head!=NULL)
    {
        q=sentinel->head;
        sentinel->head=q->next;
        free(q);
    }
    sentinel->tail=NULL;
}

void printall(FILE *pf)
{
    nodeT *q;
    q=sentinel->head;
    while(q!=NULL)
    {
        fprintf(pf,"%d ",q->code);
        q=q->next;
    }
    if(sentinel->head!=NULL)
    {
        fprintf(pf,"\n");
    }
}

void printfirstx(FILE *pf,int x)
{
    nodeT *q;
    int nr;
    for(q=sentinel->head,nr=0; q!=NULL; q=q->next,nr++)
    {
        if(nr==x)
        {
            break;
        }
        fprintf(pf,"%d ",q->code);
    }
    if(sentinel->head!=NULL)
    {
        fprintf(pf,"\n");

    }
}

void printlastx(FILE *pf,int x)
{
    nodeT *q;
    int nr;
    if(x>=sentinel->length)
    {
        printall(pf);
    }
    else
    {
        for(q=sentinel->tail,nr=1; nr!=x; q=q->previous,nr++)
        {
            ;
        }
        while(q!=NULL)
        {
            fprintf(pf,"%d ",q->code);
            q=q->next;
        }
        fprintf(pf,"\n");
    }
}

int main()
{
    char s[20];
    FILE *pf,*f;
    f=fopen("input.txt","r");
    if(f==NULL)
    {
        perror("Can't open file \"input.txt\"\n");
        return -1;
    }
    fseek(f,0L,SEEK_SET);
    pf=fopen("output.txt","w");
    if(pf==NULL)
    {
        perror("Can't create file \"output.txt\"\n");
        return(-2);
    }
    while(fgets(s,sizeof(s),f)!=NULL)
    {
        char *p=strtok(s," ");
        int x;
        if(strcmp("AF",p)==0)
        {
            p=strtok(NULL,"\0");
            sscanf(p,"%d",&x);
            addfirst(x);
        }
        if(strcmp("AL",p)==0)
        {
            p=strtok(NULL,"\0");
            sscanf(p,"%d",&x);
            addlast(x);
        }
        if(strcmp("DE",p)==0)
        {
            p=strtok(NULL,"\0");
            sscanf(p,"%d",&x);
            deletegiven(x);
        }
        if(strcmp("PRINT_F",p)==0)
        {
            p=strtok(NULL,"\0");
            sscanf(p,"%d",&x);
            printall(pf);
        }
        if(strcmp("PRINT_L",p)==0)
        {
            p=strtok(NULL,"\0");
            sscanf(p,"%d",&x);
            printlastx(pf,x);
        }
        p=strtok(s,"\n");
        if(strcmp("DF",p)==0)
        {
            deletefirst();
        }
        if(strcmp("DL",p)==0)
        {
            deletelast();
        }
        if(strcmp("PRINT_ALL",p)==0)
        {
            printall(pf);
        }
        if(strcmp("DOOM_THE_LIST",p)==0)
        {
            doomthelist();
        }
    }
    fclose(pf);
    fclose(f);
    return 0;
}
