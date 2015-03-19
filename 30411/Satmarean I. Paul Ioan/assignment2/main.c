#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE * pf1;
FILE * pf2;

typedef struct NodeT{
    int code;
    struct NodeT* next;
    struct NodeT* prev;
}NodeT;

typedef struct sent{
    NodeT* head;
    NodeT* tail;
}sent;

void initList(sent* a)
{
    a->head=NULL;
    a->tail=NULL;
}

void addFirst(sent* a,int code)
{
    if(a->head!=NULL)
    {
        if(a->tail!=NULL)
        {
            NodeT * p=(NodeT*)malloc(sizeof(NodeT));
            p->next=a->head;
            a->head->prev=p;
            p->prev=NULL;
            p->code=code;
            a->head=p;
        }else if(a->tail==NULL)
        {
            NodeT * p=(NodeT*)malloc(sizeof(NodeT));
            p->next=a->head;
            a->head->prev=p;
            a->tail=a->head;
            p->prev=NULL;
            p->code=code;
            a->head=p;
        }
    }else
    {
        NodeT * p=(NodeT*)malloc(sizeof(NodeT));
        p->next=NULL;
        p->prev=NULL;
        p->code=code;
        a->head=p;
    }


}

void addLast(sent* a, int code)
{
    if(a->head!=NULL)
    {
        if(a->tail!=NULL)
        {
             NodeT * p=(NodeT*)malloc(sizeof(NodeT));
             p->code=code;
             p->prev=a->tail;
             p->next=NULL;
             a->tail->next=p;
             a->tail=p;

    }
        else
        {
            NodeT * p=(NodeT*)malloc(sizeof(NodeT));
            p->code=code;
            p->next=NULL;
            p->prev=a->head;
            a->tail=p;
            a->head->next=a->tail;
        }
    }
    else
    {
        NodeT * p=(NodeT*)malloc(sizeof(NodeT));
        p->next=NULL;
        p->prev=NULL;
        p->code=code;
        a->head=p;
    }
}

void deleteFirst(sent* a)
{
    if(a->head!=NULL)
    {
        if(a->tail!=NULL)
        {
            NodeT *p=a->head;
            a->head=p->next;
            a->head->prev=NULL;
            free(p);
            if(a->tail==a->head)
            {
                a->tail=NULL;
            }
        }
        else
        {
             NodeT *p=a->head;
             a->head=NULL;
             free(p);
        }
    }
}

void deleteLast(sent* a)
{
    if(a->head!=NULL)
    {
        if(a->tail!=NULL)
        {
            NodeT *p=a->tail;
            p->prev->next=NULL;
            a->tail=p->prev;
            p->prev=NULL;
            free(p);
        }
        else
        {
             NodeT *p=a->head;
             a->head=NULL;
             free(p);
        }
    }
}

void DOOM_THE_LIST(sent* a)
{
    while(a->head!=NULL)
    {
        deleteFirst(a);
    }
}

void printList(sent a)
{
    NodeT* aux;
    aux=a.head;
    while(aux!=NULL)
    {
        fprintf(pf2,"%d ",aux->code);
        aux=aux->next;
    }
    fprintf(pf2,"\n");
}

void PRINT_F(sent *a,int x)
{
    if(a->head!=NULL)
    {
        NodeT* aux=a->head;
        while(a!=NULL&&x>0)
        {
           fprintf(pf2,"%d ",aux->code);
            aux=aux->next;
            x--;
        }
    }
    fprintf(pf2,"\n");
}

void PRINT_L(sent *a,int x,NodeT* p)
{
    if(x!=1&&p!=a->head)
    {
        int i=p->code;
        p=p->prev;
        PRINT_L(a,x-1,p);
        fprintf(pf2,"%d ",i);
    }
    else fprintf(pf2,"%d ",p->code);
}

void deleteElement(sent *a,int x)
{
    if(a->head!=NULL)
    {
        if(a->tail!=NULL)
        {
            NodeT *aux=a->head;
            while(aux!=NULL)
            {
                if(aux->code==x)
                {
                    if(aux==a->head) {deleteFirst(a); break;}
                    else
                    if(aux==a->tail) {deleteLast(a); break;}
                    else{
                    aux->next->prev=aux->prev;
                    aux->prev->next=aux->next;
                    free(aux);
                    break;
                    }
                }
                aux=aux->next;
            }
        }else
        {
            if(a->head->code==x)
                deleteFirst(a);
        }
    }
}

void select(sent*a)
{
    char s[30]="";
    int x=0;

    //selectie pe baza de input
    while(fscanf(pf1,"%s ",s)==1)
          {
              if(strcmp(s,"DF")==0)
              {
                  deleteFirst(a);

              }else
              if(strcmp(s,"DL")==0)
              {
                  deleteLast(a);

              }else
              if(strcmp(s,"DOOM_THE_LIST")==0)
              {
                  DOOM_THE_LIST(a);

              }else
              if(strcmp(s,"PRINT_ALL")==0)
              {
                  printList(*a);
              }else
              {
                  if(strcmp(s,"AF")==0)
                    {
                        fscanf(pf1,"%d",&x);
                        addFirst(a,x);
                    }
                     if(strcmp(s,"AL")==0)
                    {
                        fscanf(pf1,"%d",&x);
                        addLast(a,x);
                    }
                     if(strcmp(s,"DE")==0)
                    {
                        fscanf(pf1,"%d",&x);
                        deleteElement(a,x);
                    }
                     if(strcmp(s,"PRINT_F")==0)
                    {
                        fscanf(pf1,"%d",&x);
                        PRINT_F(a,x);
                    }
                     if(strcmp(s,"PRINT_L")==0)
                    {
                        fscanf(pf1,"%d",&x);
                        PRINT_L(a,x,a->tail);
                        fprintf(pf2,"\n");
                    }
              }
          }
}

int main()
{
    sent a;
    initList(&a);


     //deschidem fisierele
    pf1=fopen("input.dat","r");
    pf2=fopen("output.dat","w");

    //selectam functia pe baza de imput din fisier
    select(&a);

    //indchidem fisiere
    fclose(pf1);
    fclose(pf2);


    return 0;
}
