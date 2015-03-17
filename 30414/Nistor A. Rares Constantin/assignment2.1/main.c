# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct nod
{
    int data;
    struct nod *next;
    struct nod *prev;
}NODE;

typedef struct nod1
{
    NODE *head;
    NODE *tail;
}SENTINEL;

SENTINEL *l;

void PRINT_ALL(FILE *output)
{
    NODE *p;
    p=l->head;
    while(p!=NULL)
    {
        fprintf(output,"%d ",p->data);
        p=p->next;
    }

    fprintf(output,"\n");
}

void AF(int data)
{
    NODE *newnode;

    if(l->head==NULL)
    {
        l->head=(NODE*) malloc(sizeof(NODE));
        l->head->data=data;
        l->head->next=NULL;
        l->head->prev=NULL;
        l->tail=l->head;
    }

    else
    {
        newnode=(NODE*) malloc(sizeof(NODE));
        newnode->data=data;
        newnode->next=l->head;
        newnode->prev=NULL;
        l->head->prev=newnode;
        l->head=newnode;

    }
}

void AL(int data)
{
    NODE *newnode;

    if(l->head==NULL)
    {

        l->head=(NODE*) malloc(sizeof(NODE));
        l->head->data=data;
        l->head->next=NULL;
        l->head->prev=NULL;
        l->tail=l->head;

    }

    else
    {
        newnode=(NODE*) malloc(sizeof(NODE));
        newnode->data=data;
        newnode->next=NULL;
        newnode->prev=l->tail;
        l->tail->next=newnode;
        l->tail=newnode;

    }
}

void DF()
{
    if(l->head!=NULL)
    {
        l->head=l->head->next;
        free(l->head->prev);
        l->head->prev=NULL;
    }
}

void DL()
{
    if(l->tail!=NULL)
    {
        l->tail=l->tail->prev;
        free(l->tail->next);
        l->tail->next=NULL;
    }
}


void DOOM_THE_LIST()
{
    while(l->head->next!=NULL)
    {   l->head=l->head->next;
        free(l->head->prev);
        l->head->prev=NULL;
    }
    free(l->head);
    l->head=NULL;
    l->tail=NULL;
}

void DE(int x)
{
    NODE *p,*position;
    while(l->head!=NULL&&l->head->data==x)
        DF();
    while(l->tail!=NULL&&l->tail->data==x)
        DL();

        position=l->head;
        p=l->head;
        p=p->next;

        while(p!=NULL)
        {
            while(p!=NULL && p->data==x)
            {
                position=p;
                p->prev->next=p->next;
                p->next->prev=p->prev;
                p=p->next;
                free(position);
            }


            p=p->next;
        }
}

void PRINT_F(int x,FILE *output)
{
    NODE *p=l->head;
    int i=1;
    while(i<=x && p!=NULL)
    {
        fprintf(output,"%d ",p->data);
        p=p->next;
        i++;
    }
    fprintf(output,"\n");
}

void PRINT_L(int x, FILE *output)
{
    int nr=0,i;

    NODE *p=l->head;

    while(p!=NULL)
    {
        p=p->next;
        nr++;;
    }

    if(x>=nr)
        PRINT_ALL(output);
    else
    {
        p=l->head;
        for(i=1; i<=nr-x; i++)
            p=p->next;

        while(p!=NULL)
        {
            fprintf(output,"%d ",p->data);
            p=p->next;
        }
        fprintf(output,"\n");
    }
}

int main()
{
    FILE *input, *output;
    int x;
    char s[100];

    l = (SENTINEL*) malloc(sizeof(SENTINEL));
    l->head=0;
    l->tail=0;

    input=fopen("input.dat", "r");
    output=fopen("output.dat", "w");

    while(fscanf(input,"%s",s)!=EOF)
    {

        if(strcmp(s,"AF")==0)
        {
            fscanf(input,"%d",&x);
            AF(x);
        }
        else if(strcmp(s,"AL")==0)
        {
            fscanf(input,"%d",&x);
            AL(x);
        }
        else if(strcmp(s,"DF")==0)
            DF();
        else if(strcmp(s,"DL")==0)
            DL();
        else if(strcmp(s,"PRINT_ALL")==0)
            PRINT_ALL(output);
        else if(strcmp(s,"DOOM_THE_LIST")==0)
            DOOM_THE_LIST();
        else if(strcmp(s,"DE")==0)
        {
            fscanf(input,"%d",&x);
            DE(x);
        }
        else if(strcmp(s, "PRINT_F")==0)
        {
            fscanf(input,"%d",&x);
            PRINT_F(x,output);
        }
        else
        {
            fscanf(input,"%d",&x);
            PRINT_L(x,output);
        }
    }

    return 0;
}
