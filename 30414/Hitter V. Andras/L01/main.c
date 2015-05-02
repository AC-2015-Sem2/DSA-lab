#include <stdlib.h>
#include <stdio.h>


typedef struct node
{
    int data;
    struct node* next;
} node;

node *head,*tail;
FILE *fp, *g;

void addlast(int data)
{
    node *a;
    a=(node*)malloc(sizeof(node));
    a->data=data;
    a->next=NULL;
    if(head==NULL)
    {
        head=a;
    }
    else
    {
        tail->next=a;
    }
    tail=a;
}

void addfirst(int data)
{
    node *a;
    if (head==NULL)
    {
        head=(node*)malloc(sizeof(node));
        tail=head;
        head->data=data;
        head->next=NULL;
    }
    else
    {
        a=(node*)malloc(sizeof(node));
        a->data=data;
        a->next=head;
        head=a;
    }
}

void deleteFirst()
{
    node *b=head;
    if (head!=NULL)
    {
        head=head->next;
        free(b);
    }
}

void deleteLast()
{
    node *aux=head;
    if(head!=NULL)
    {
    if(head->next==NULL)
    {
        head=NULL;
    }
    else
    {
        while(aux->next->next!=NULL)
        {
            aux=aux->next;
        }
        tail=aux;
        free(aux->next);
        aux->next=NULL;

    }
    }
}

void print()
{
    node *a;
    a=head;
    while (a!=NULL)
    {
        printf("%d ",a->data);
        a=a->next;
    }
    printf("\n");
}

void printinf()
{
    node *a;
    a=head;
    while (a!=NULL)
    {
        fprintf(g,"%d ",a->data);
        a=a->next;
    }
    fprintf(g,"\n");
}
void doom_the_list()
{
    while(head->next!=tail)
    {
        deleteFirst();
    }
    head=NULL;
    tail=head;
}

void DeleteElement(int data)
{
    node *aux=head, *aux2;
    if (head->data==data) deleteFirst();
    else
    {
            while((aux->next->data!=data) && (aux->next->next!=NULL))
            {
                aux=aux->next;
            }
            if(aux->next->data==data)
            {
            aux2=aux->next;
            aux->next=aux->next->next;
            free(aux2);
            }
            else {if (tail->data==data) deleteLast();}
    }
}

void printFirst(int data)
{
    node *a;
    a=head;
    while ((data!=0)&&(a!=NULL))
    {
        fprintf(g,"%d ",a->data);
        a=a->next;
        data=data-1;
    }
    fprintf(g,"\n");
}

void printLast(int data)
{
    node *a,*aux;
    a=head;
    aux=head;
    int c=0;
    while (aux!=NULL)
    {
        c=c+1;
        aux=aux->next;
    }
    if (c<=data) printinf();
    else
    {
        while(a!=NULL)
        {
        if (c>data) {c=c-1;a=a->next;}
            else
                if (c<=data) {c=c-1;fprintf(g,"%d ",a->data);a=a->next;}
    }
    fprintf(g,"\n");
    }
}

int main()
{
int x,k=1;
char s[20];
     fp = fopen("input.dat","r");
     g=fopen("output.dat","w");

      if( fp == NULL )
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }

    while (k==1)
    {
        fscanf(fp,"%s%d",s,&x);
        if (s[0]=='\0') k=0;
        if (strcmp(s, "AF")==0) {addfirst(x);print();}
        if (strcmp(s, "AL")==0) {addlast(x);print();}
        if (strcmp(s, "DF")==0) {deleteFirst();print();}
        if (strcmp(s, "DL")==0) {deleteLast();print();}
        if (strcmp(s, "DE")==0) {DeleteElement(x);print();}
        if (strcmp(s, "DOOM_THE_LIST")==0) {doom_the_list();print();}
        if (strcmp(s, "PRINT_ALL")==0) {printinf();print();}
        if (strcmp(s, "PRINT_F")==0) {printFirst(x);print();}
        if (strcmp(s, "PRINT_L")==0) {printLast(x);print();}
        s[0]='\0';
    }
    fclose(fp);
    fclose(g);
    return 0;
}
//alexx.cosma@gmail.com
