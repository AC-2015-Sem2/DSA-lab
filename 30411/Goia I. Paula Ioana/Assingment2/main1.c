#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NodeT
{
    int code;
    struct NodeT* next;
    struct NodeT* prev;
} NodeT;
typedef struct Sant
{
    NodeT *head;
    NodeT*tail;
    int l;
} Sant;

void initializeSent(Sant*santi)
{
    santi->head=NULL;
    santi->tail=NULL;
    santi->l=0;
}
//NodeT *head, *tail;
FILE *in,*out;

void addFirst(Sant*santi,int code)
{

    if(santi->head==NULL)
    {
        NodeT * p=(NodeT*)malloc(sizeof(NodeT));
        p->next=NULL;
        p->prev=NULL;
        p->code=code;
        santi->head=p;
        santi->l++;
    }
    else
    {
        if(santi->tail==NULL)
        {
            NodeT * p=(NodeT*)malloc(sizeof(NodeT));
            p->next=santi->head;
            santi->head->prev=p;
            santi->tail=santi->head;
            p->prev=NULL;
            p->code=code;
            santi->head=p;
            santi->l++;
        }
        else
        {
            NodeT * p=(NodeT*)malloc(sizeof(NodeT));
            p->next=santi->head;
            santi->head->prev=p;
            p->prev=NULL;
            p->code=code;
            santi->head=p;
            santi->l++;
        }

    }
}
void addLast(Sant* santi,int code)
{
    if(santi->head==NULL)
    {

        NodeT * p=(NodeT*)malloc(sizeof(NodeT));
        p->next=NULL;
        p->prev=NULL;
        p->code=code;
        santi->head=p;
    }
    else if (santi->tail==NULL)
    {
       NodeT * p=(NodeT*)malloc(sizeof(NodeT));
            p->code=code;
            p->next=NULL;
            p->prev=santi->head;
            santi->tail=p;
            santi->head->next=santi->tail;

    }
    else
    {
          NodeT * p=(NodeT*)malloc(sizeof(NodeT));
             p->code=code;
             p->prev=santi->tail;
             p->next=NULL;
             santi->tail->next=p;
             santi->tail=p;
    }
}

void printlist(Sant* santi)
{

    NodeT* aux=santi->head;
    while(aux!=NULL)
    {
        fprintf(out,"%d ",aux->code);
        aux=aux->next;
    }
    fprintf(out,"\n");
}
void delete_first(Sant*santi)
{
    NodeT *p;
    if(santi->head!=NULL )
    {
        p=santi->head ;
        santi->head=p->next ;
        santi->head->prev=NULL;
        free(p) ;
        if (santi->head== NULL)
            santi->tail=NULL;
        santi->l--;
    }
}

void delete_last(Sant*santi)
{
    if(santi->head!=NULL)
    {
        if(santi->tail==NULL)
        {

            NodeT *p=santi->head;
             santi->head=NULL;
             free(p);
             santi->l--;

        }
        else
        {
             NodeT *p=santi->tail;
            p->prev->next=NULL;
            santi->tail=p->prev;
            p->prev=NULL;
            free(p);
            santi->l--;
        }
    }
}
void delete_element(Sant*santi,int nr)
{
    NodeT *q;
    q=santi->head;

    while(q!=NULL)
    {
        if(q->code==nr)break;
        q=q->next;
    }
    if(q!=NULL)
    {
        if(q==santi->head)
        {
            santi->head =santi->head->next;
            santi->head->prev=NULL;
            if (santi->head== NULL)santi->tail=NULL;
            santi->l--;
        }
        else
        {
            q->next->prev=q->prev;
            q->prev->next=q->next;
            if(q==santi->tail )
            {
                santi->tail=q->prev;
                santi->tail->next=NULL;
                santi->l--;
            }

        }
    }
}
void doom_the_list(Sant*santi)
{
    while (santi->head!= NULL )
    {
        santi->head=santi->head->next;
        santi->l--;
    }
    santi->tail=NULL;
}
void print_first(Sant*santi, int z)
{
    int i=1;
    NodeT* p=santi->head;
    while(i<=z)
    {
        if(p!=NULL)
        {
            fprintf(out,"%d ",p->code);
            p=p->next;
            i++;
        }
        else break;
    }
    fprintf(out,"\n");
}

void print_last(Sant*santi,int z)
{
    int i=1,n;
    NodeT* p=santi->head;
    n=santi->l;
    while(i<=n-z)
    {
        if(p!=NULL)
        {
            p=p->next;
            i++;
        }
        else break;
    }
    while(i<=n)
    {
        if(p!=NULL)
        {
            fprintf(out,"%d ",p->code);
            p=p->next;
            i++;
        }
        else break;
    }
    fprintf(out,"\n");
}
int main()
{
    Sant* santi=(Sant*)malloc(sizeof(Sant));
    initializeSent(santi);
    //santi->head=NULL;
    // santi->tail=NULL;
    char s[30];
    int x;
    out=fopen("out.txt","w");
    in=fopen("in.txt","r");
    int c;
    c=fscanf(in,"%s %d",s,&x);
    while(c>0)
    {
        //printf("%s %d\n",s,x);
        if(!strcmp(s,"AL"))addLast(santi,x);
        if(!strcmp(s,"AF"))addFirst(santi,x);
        if(!strcmp(s,"DE"))delete_element(santi,x);
        if(!strcmp(s,"PRINT_F"))print_first(santi,x);
        if(!strcmp(s,"PRINT_L"))print_last(santi,x);
        if(!strcmp(s,"PRINT_ALL"))printlist(santi);
        if(!strcmp(s,"DOOM_THE_LIST"))doom_the_list(santi);
        if(!strcmp(s,"DF"))delete_first(santi);
        if(!strcmp(s,"DL"))delete_last(santi);
        strcpy(s,"");
        c=fscanf(in,"%s %d",s,&x);

    }
    return 0;
}
