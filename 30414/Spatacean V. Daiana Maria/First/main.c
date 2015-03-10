#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int x;
    struct node* next;
} node;
node *head, *tail;

node* find(int n)
{
    node *aux;
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
        head=(node*)malloc(sizeof(node*));
        head->x=x;
        head->next=NULL;
    }
    else if (tail==NULL)
    {
        tail=head;
        node* a=(node*)malloc(sizeof(node*));
        a->x=x;
        a->next=head;
        head=a;
    }
    else
    {
        node* a=(node*)malloc(sizeof(node*));
        a->x=x;
        a->next=head;
        head=a;
    }
}




void AL(int x)
{
    if (head==NULL)
    {
        head=(struct node*)malloc(sizeof(struct node*));
        head->x;
        head->next=NULL;
    }
    else
    {
        if (tail==NULL)
        {
            struct node *a=(struct node*)malloc(sizeof(struct node*));
            a->x;
            a->next=NULL;
            tail=a;
            head->next=tail;
        }
        else
        {
            struct node *a=(struct node*)malloc(sizeof(struct node*));
            a->x;
            a->next=NULL;
            tail->next=a;
            tail=a;
        }
    }
}

void DF()
{
    if (head!=NULL)
    {
        node* a=head;
        head=head->next;
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
            node* a=tail;
            node* aux=head;
            while (aux->next!=a)
            {
                aux=aux->next;
            }
            aux->next=NULL;
            free(a);
            tail=aux;
        }
    }
}

void  DOOM()
{
    if (head!=NULL)
    {

        node *a=head,*t=head->next;
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
    node *a;
    a=find(x);
    node *t=head;
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
    node* a=head;
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
    node *a=head;
    for(i=1; i<=n; i++)
    {
        fprintf(af,"%d ",a->x);
        a=a->next;
    }
    fprintf(af,"\n");
}

void PRINT_L(int n,FILE *af)
{
    node *a=head;
    int i,j=0;
    while (a!=NULL)
    {
        j++;
        a=a->next;
    }
    a=head;
    if (j<n)
    {
        PRINT_ALL(af);
    }
    else
    {
        for (i=1; i<=j-n; i++)
        {
            a=a->next;
        }
        while (a!=NULL)
        {
            fprintf(af,"%d ",a->x);
            a=a->next;
        }
    }
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

