# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct nod
{
    int data;
    struct nod *next;
}NODE;


NODE *head, *tail;

void PRINT_ALL(FILE *output)
{   NODE *p;
    p=head;

    while(p!=NULL)
    {
        fprintf(output,"%d ",p->data);
        p=p->next;
    }
    fprintf(output,"\n");
}

void AF(int data)
{   NODE *newnode;
    if(head==NULL)
    {
        head=(NODE*)malloc(sizeof(NODE));
        head->data=data;
        head->next=NULL;
        tail=head;
    }

    else
    {
        newnode=(NODE*)malloc(sizeof(NODE));
        newnode->data=data;
        newnode->next=head;
        head=newnode;
    }
}

void AL(int data)
{    NODE *newnode;
    if(head==NULL)
    {
        head=(NODE*)malloc(sizeof(NODE));
        head->data=data;
        head->next=NULL;
        tail=head;

    }

    else
    {
        newnode=(NODE*)malloc(sizeof(NODE));
        tail->next=newnode;
        newnode->next=NULL;
        newnode->data=data;
        tail=newnode;
    }
}

void DF()
{   NODE *position;
    position=head;
    if(head!=NULL)
    {
        head=head->next;
        free(position);
    }
}

void DL()
{   NODE *position;
    position=head;
    if(tail!=NULL)
    {
        while(position->next!=tail)
            position=position->next;
        tail=position;
        position=position->next;
        tail->next=NULL;
        free(position);
    }
}

void DOOM_THE_LIST()
{   NODE *p, *position;
    p=head;
    position=head;
    head=NULL;
    tail=NULL;
    while(p!=NULL)
    {   p=p->next;
        free(position);
        position=p;
    }
}

void DE(int x)
{
    NODE *p,*position,*z;
    while(head!=NULL&&head->data==x)
        DF();
    while(tail!=NULL&&tail->data==x)
        DL();

        position=head;
        p=head;
        p=p->next;

        while(p!=NULL)
        {
            while(p->data==x)
            {
                position->next=p->next;
                z=p;
                p=p->next;
                free(z);
            }

            position=p;
            p=p->next;
        }
}

void PRINT_F(int x,FILE *output)
       {
           NODE *p=head;
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

    NODE *p=head;

    while(p!=NULL)
    {
        p=p->next;
        nr++;;
    }

    if(x>=nr)
        PRINT_ALL(output);
    else
    {
        p=head;
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
    input=fopen("input.dat","r");
    output=fopen("output.dat","w");

    int x;
    char s[100];

    while(fscanf(input,"%s",s)!=EOF)
    {
        if(strcmp(s,"PRINT_ALL")==0)
                PRINT_ALL(output);
        else
            if(strcmp(s,"AF")==0)
            {
                fscanf(input,"%d",&x);
                AF(x);
            }
        else
            if(strcmp(s,"AL")==0)
            {
                fscanf(input,"%d",&x);
                AL(x);
            }
        else
            if(strcmp(s,"DF")==0)
                DF();
        else
            if(strcmp(s,"DL")==0)
                DL();
        else
            if(strcmp(s,"DOOM_THE_LIST")==0)
                DOOM_THE_LIST();
        else
            if(strcmp(s,"DE")==0)
            {
                fscanf(input,"%d",&x);
                DE(x);
            }
        else
            if(strcmp(s,"PRINT_F")==0)
            {
                fscanf(input,"%d",&x);
                PRINT_F(x,output);
            }
        else
            if(strcmp(s,"PRINT_L")==0)
            {
                fscanf(input,"%d",&x);
                PRINT_L(x,output);
            }
    }

    return 0;
}
