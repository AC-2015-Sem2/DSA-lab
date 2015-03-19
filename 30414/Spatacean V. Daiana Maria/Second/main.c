#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int x;
    struct node* next;
    struct node* previous;
} noden;
noden *head, *tail;

noden* find(int n)
{
    noden *aux;
    aux=head;
    while(aux!=NULL && aux->x!=n)
    {
        aux=aux->next;
    }
    return aux;
}
void AF(int x)
{
    if (head==NULL)
    {
        head=(noden*)malloc(sizeof(noden));
        head->previous=NULL;
        head->x=x;
        head->next=NULL;
        tail=head;
    }
    else
    {
        noden* a=(noden*)malloc(sizeof(noden));
        a->x=x;
        a->next=head;
        a->previous=NULL;
        head->previous=a;
        head=a;
    }

}


void AL(int x)
{
    if (head==NULL)
    {
        head=(struct node*)malloc(sizeof(struct node));
        head->x=x;
        head->next=NULL;
        head->previous=NULL;
        tail=head;
    }

        else
        {
             noden *a=( noden*)malloc(sizeof(struct node));

            a->x=x;
            a->next=NULL;
            a->previous=NULL;
            tail->next=a;
            tail=a;
        }
    }


void DF()
{
    if (head!=NULL)
    {
        noden* a=head;
        head=head->next;
        head->previous=NULL;
        free(a);
    }
}
void DL()
{
    if (head!=NULL)
    {
        if (head==tail)
        {
            free(tail);
            head=NULL;
            tail=NULL;
        }
        else
        {
            noden* a;
            a->tail=previous;
            free(tail);
            tail=a;
        }
    }
}

void  DOOM()
{
    if (head!=NULL)
    {

        noden *a=head,*t=head->next;
        while (t!=NULL)
        {
            free(a);
            a=t;
            t=t->next;
        }

        head=NULL;
        tail=NULL;
    }
}




void DE(int x)
{
    noden *a;
    a=find(x);
    noden *t=head;
    if (a!=NULL)
    {
        if (a==head)
        {
            DF();
        }
        else
        {
            while (t->next!=a)
            {
                t=t->next;
            }
            t->next=a->next;
            free (a);
        }
    }
}




void PRINT_ALL(FILE *af)
{
    noden* a=head;
    while (a!=NULL)
    {
        fprintf(af,"%d ",a->x);
        a=a->next;
    }
    fprintf(af,"\n");
}

void PRINT_F(int n, FILE *af)
{
    int i;
    noden *a=head;
    for(i=1; i<=n; i++)
    {
        fprintf(af,"%d ",a->x);
        a=a->next;
    }
    fprintf(af,"\n");
}

void PRINT_L(int n,FILE *af)
{
    noden *a=head;
    int i;
    a=tail;
   for (i=1;i<n;i++)
   {
       a=a->previous;
   }

        for (i=1; i<n; i++)
        {
            fprintf(af,"%d ",a->x);
            a=a->next;
        }

    fprintf(af,"%d ",a->x);
    fprintf(af,"\n");
}





void read()
{
    char v[100];
    int x;
    FILE *f=fopen("input.dat","r");
    FILE *p=fopen("output.dat","w");
    while (fscanf(f,"%s",v)==1)
    {
        if(strcmp(v,"AF")==0)
        {
            fscanf(f," %d",&x);
            AF(x);
        }
        if(strcmp(v,"AL")==0)
        {
            fscanf(f," %d",&x);
            AL(x);
        }
        if(strcmp(v,"DF")==0)
        {
            DF();
        }
        if(strcmp(v,"DL")==0)
        {
            DL();
        }
        if(strcmp(v,"DOOM")==0)
        {
            DOOM();
        }
        if(strcmp(v,"DE")==0)
        {
            fscanf(f," %d",&x);
            DE(x);
        }
        if(strcmp(v,"PRINT_ALL")==0)
        {
            PRINT_ALL(p);
        }
        if(strcmp(v,"PRINT_F")==0)
        {
            fscanf(f," %d",&x);
            PRINT_F(x,p);
        }
        if(strcmp(v,"PRINT_L")==0)
        {
            fscanf(f," %d",&x);
            PRINT_L(x,p);
        }
    }
}



int main()
{
    read();
    return 0;
}
