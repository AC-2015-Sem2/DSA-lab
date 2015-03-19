#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *pf1, *pf2;

typedef struct NodeT{
        int code;
        struct NodeT* next;
}NodeT;

//global

NodeT *head, *tail=NULL;
int ne=0;

void addFirst(int code)
{
    if(head==NULL)
        {
            head=(NodeT*)malloc(sizeof(NodeT));
            head->code=code;
            head->next=NULL;
        }
    else if (tail==NULL)
        {
            tail=head;
            NodeT* p=(NodeT*)malloc(sizeof(NodeT));
            p->code=code;
            p->next=tail;
            head=p;
        }
    else
    {
        NodeT* p=(NodeT*)malloc(sizeof(NodeT));
        p->code=code;
        p->next=head;
        head=p;
    }
    ne++;
}

void addLast(int code)
{
    if(head==NULL)
        {
            head=(NodeT*)malloc(sizeof(NodeT));
            head->code=code;
            head->next=NULL;
            tail=head;
        }
        else if (tail==NULL)
        {
            NodeT* p=(NodeT*)malloc(sizeof(NodeT));
            p->code=code;
            p->next=NULL;
            tail=p;
            head->next=tail;
        }
        else
        {
            NodeT* p=(NodeT*)malloc(sizeof(NodeT));
            p->code=code;
            p->next=NULL;
            tail->next=p;
            tail=p;
        }
        ne++;
}

NodeT* find(int x)
{
    NodeT* aux;
    aux=head;
    while(aux!=NULL&&aux->code!=x)
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
            fprintf(pf2,"%d ",aux->code);
            aux=aux->next;
        }
        fprintf(pf2,"\n");
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
    ne--;
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
        }else{
             free(head);
             head=NULL;
             }
    }
    ne--;
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
            }else
        if(tail!=NULL)
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
            else{
                if(tail->code==x)
                    {
                        aux2->next=NULL;
                        free(tail);
                        tail=NULL;
                    }
            }

        }
    }
    ne--;
}
void PRINT_F(int x)
{
    NodeT* aux;
    int i=1;
    if(head!=NULL)
    {
        if(i>=ne)
            printlist();
        else
        {
        aux=head;
        while(i<=x&&aux!=tail)
        {
            fprintf(pf2,"%d ",aux->code);
            aux=aux->next;
            i++;
        }
        }
    }
    fprintf(pf2,"\n");

}

void PRINT_L (int x)
{
    if(head!=NULL)
    {
        if(x>=ne)
            printlist();
        else
        {
            NodeT* aux=head;
            int i=1;
            while(aux!=NULL)
            {if(i>=((ne-x)+1))
                fprintf(pf2,"%d ",aux->code);

                aux=aux->next;
                i++;
            }
            fprintf(pf2,"\n");

        }
    }
}

void select()
{
    char s[30]="";
    int x=0;

    //selectie pe baza de input
    while(fscanf(pf1,"%s ",s)==1)
          {
              if(strcmp(s,"DF")==0)
              {
                  deleteFirst();

              }else
              if(strcmp(s,"DL")==0)
              {
                  deleteLast();

              }else
              if(strcmp(s,"DOOM_THE_LIST")==0)
              {
                  DOOM_THE_LIST();

              }else
              if(strcmp(s,"PRINT_ALL")==0)
              {
                  printlist();
              }else
              {
                  if(strcmp(s,"AF")==0)
                    {
                        fscanf(pf1,"%d",&x);
                        addFirst(x);
                    }
                     if(strcmp(s,"AL")==0)
                    {
                        fscanf(pf1,"%d",&x);
                        addLast(x);
                    }
                     if(strcmp(s,"DE")==0)
                    {
                        fscanf(pf1,"%d",&x);
                        deleteElement(x);
                    }
                     if(strcmp(s,"PRINT_F")==0)
                    {
                        fscanf(pf1,"%d",&x);
                        PRINT_F(x);
                    }
                     if(strcmp(s,"PRINT_L")==0)
                    {
                        fscanf(pf1,"%d",&x);
                        PRINT_L(x);
                    }
              }
          }
}
int main()
{
    //deschidem fisierele
    pf1=fopen("input.dat","r");
    pf2=fopen("output.dat","w");

    //selectam functia pe baza de imput din fisier
    select();

    //indchidem fisiere
    fclose(pf1);
    fclose(pf2);

    return 0;
}
