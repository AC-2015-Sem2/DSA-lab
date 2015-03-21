#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *f, *g;

typedef struct NodeT
{
    int code;
    struct NodeT* next;
} NodeT;


NodeT *head, *tail=NULL;
int total=0;

void addFirst(int code)
{
    if(head==NULL)
    {
        head=(NodeT*)malloc(sizeof(NodeT));
        head->code=code;
        head->next=NULL;
       tail=head;
    }
    else
    {
        NodeT* p=(NodeT*)malloc(sizeof(NodeT));
        p->code=code;
        p->next=head;
        head=p;
    }
    total++;
}

void addLast(int code)
{
    if(head==NULL)
    {
        head=(NodeT *)malloc(sizeof(NodeT));
        head->code=code;
        head->next=NULL;
        tail=head;
    }
    else
    {
        NodeT *p=(NodeT *)malloc(sizeof(NodeT));
        p->code=code;
        p->next=NULL;
        tail->next=p;
        tail=p;
    }
    total++;
}

NodeT* find(int x)
{
    NodeT* aux;
    aux=head;
    while(aux!=NULL && aux->code!=x)
    {
        aux=aux->next;
    }
    return aux;

}


void printlist()
{
    NodeT* aux=head;
    while(aux!=NULL)
    {
        fprintf(g,"%d ",aux->code);
        aux=aux->next;
    }
    fprintf(g,"\n");
}

void deleteFirst()
{
    NodeT *aux;
    if(head!=NULL)
    {
        aux=head;
        head=head->next;
        free(aux);
        if(head==NULL)
            tail=NULL;
    }
    total--;
}

void deleteLast()
{
    if(head!=NULL)
    {
        NodeT *aux;
        if(tail!=NULL)
        {
            aux=head;
            while(aux->next!=tail)
                aux=aux->next;
            tail=aux;
            if(tail==head)
            {
                tail=NULL;
                free(head->next);
                head->next=NULL;
            }
        }
        else
        {
            free(head);
            head=NULL;
        }
    }
    total--;
}

void DOOM_THE_LIST()
{
    while(head!=NULL)
        deleteFirst();
}

void deleteElement(int x)
{
    NodeT *aux1, *aux2=NULL;
    if(head!=NULL)
    {
        if(head->code==x)
        {
            aux1=head;
            head=head->next;
            free(aux1);
        }
        else if(tail!=NULL)
        {
            aux2=head;
            aux1=head->next;
            while(aux1->code!=x&&aux1!=tail)
            {
                aux1=aux1->next;
                aux2=aux2->next;
            }
            if(aux1!=tail)
            {
                aux2->next=aux1->next;
                free(aux1);
            }
            else
            {
                if(tail->code==x)
                {
                    aux2->next=NULL;
                    free(tail);
                    tail=NULL;
                }
            }

        }
    }
    total--;
}
void PRINT_F(int x)
{
    NodeT* aux;
    int a=1;
    if(head!=NULL)
    {
        if(a>=total)
            printlist();
        else
        {
            aux=head;
            while(a<=x&&aux!=tail)
            {
                fprintf(g,"%d ",aux->code);
                aux=aux->next;
                a++;
            }
        }
    }
    fprintf(g,"\n");

}

void PRINT_L (int x)
{
    if(head!=NULL)
    {
        if(x>=total)
            printlist();
        else
        {
            NodeT* aux=head;
            int i=1;
            while(aux!=NULL)
            {
                if(i>=((total-x)+1))
                    fprintf(g,"%d ",aux->code);

                aux=aux->next;
                i++;
            }
            fprintf(g,"\n");

        }
    }
}
int main()
{
    int x=0;
    f=fopen("input.dat","r");
    g=fopen("output.dat","w");
    char string[30]="";


    while(fscanf(f,"%s ",string)==1)
    {
        if(strcmp(string,"DF")==0)
        {
            deleteFirst();
            printlist();
        }
        else if(strcmp(string,"DL")==0)
        {
            deleteLast();
            printlist();
        }
        else if(strcmp(string,"DOOM_THE_LIST")==0)
        {
            DOOM_THE_LIST();
            printlist();
        }
        else if(strcmp(string,"PRINT_ALL")==0)
        {
            printlist();
        }
        else
        {
            if(strcmp(string,"AF")==0)
            {
                fscanf(f,"%d",&x);
                addFirst(x);
            }
            if(strcmp(string,"AL")==0)
            {
                fscanf(f,"%d",&x);
                addLast(x);
            }
            if(strcmp(string,"DE")==0)
            {
                fscanf(f,"%d",&x);
                deleteElement(x);
            }
            if(strcmp(string,"PRINT_F")==0)
            {
                fscanf(f,"%d",&x);
                PRINT_F(x);
            }
            if(strcmp(string,"PRINT_L")==0)
            {
                fscanf(f,"%d",&x);
                PRINT_L(x);
            }
        }
    }
    fclose(f);
    fclose(g);

    return 0;
}
