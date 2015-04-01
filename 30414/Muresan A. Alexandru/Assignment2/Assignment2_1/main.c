#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct nod{int data; struct nod *prev, *next;}NODE;
NODE *head, *tail;
void AddFirst(int data)
{
    if (head==NULL)
    {
        head=(NODE*)malloc(sizeof(NODE));
        head->data=data;
        head->next=NULL;
        head->prev=NULL;
        tail=head;
    }
    else
    {
        NODE *NewNODE=(NODE*)malloc(sizeof(NODE));
        NewNODE->next=head;
        NewNODE->prev=NULL;
        head->prev=NewNODE;
        NewNODE->data=data;
        head=NewNODE;
    }
}
void AddLast(int data)
{
    if (head==NULL)
    {
        head=(NODE*)malloc(sizeof(NODE));
        head->data=data;
        head->next=NULL;
        head->prev=NULL;
        tail=head;
    }
    else
    {
        NODE *NewNODE=(NODE*)malloc(sizeof(NODE));
        NewNODE->next=NULL;
        NewNODE->prev=tail;
        tail->next=NewNODE;
        NewNODE->data=data;
        tail=NewNODE;
    }
}
void DelFirst()
{
    NODE *aux;
    if(head!=NULL)
    {
        aux=head;
        aux=aux->next;
        free(head);
        head=aux;
        head->prev=NULL;
    }
}
void DelLast()
{
    NODE *aux;
    if(head!=NULL)
    {
        aux=tail;
        aux=aux->prev;
        free(tail);
        tail=aux;
        tail->next=NULL;
    }

}
void DoomList()
{
    head=NULL;
    tail=NULL;
}
void DeleteCertainElement(int x)
{
    NODE *CurrNODE=head;
    if(head->data==x)
        DelFirst();
    else
    {
        if(tail->data==x)
        {
            DelLast();
        }
        else
        {
            while(CurrNODE!=NULL)
            {
                if(CurrNODE->data==x)
                {
                    CurrNODE->prev->next=CurrNODE->next;
                    CurrNODE->next->prev=CurrNODE->prev;
                }
                CurrNODE=CurrNODE->next;
            }
        }
    }
}
void PrintAll(FILE *pf_out)
{
    NODE *CurrNODE=head;
    while(CurrNODE!=NULL)
    {
        fprintf(pf_out,"%d ",CurrNODE->data);
        CurrNODE=CurrNODE->next;
    }
    fprintf(pf_out,"\n");
}
void PrintFirst(int x, FILE *pf_out)
{
    int nr=0;
    NODE *CurrNODE=head;
    while((CurrNODE!=NULL) &&( x>0))
    {
        fprintf(pf_out,"%d ", CurrNODE->data);
        CurrNODE=CurrNODE->next;
        x-=1;
    }
    fprintf(pf_out,"\n");
}
void PrintLast(int x, FILE *pf_out)
{
    int nr=0;
    NODE *CurrNODE=head;
    while(CurrNODE!=NULL)
    {
        nr++;
        CurrNODE=CurrNODE->next;
    }
    if(x>=nr)
    {
        PrintAll(pf_out);
    }
    else
    {
        CurrNODE=tail;
        while(x>=1)
        {
            x-=1;
            CurrNODE=CurrNODE->prev;
        }
        while(CurrNODE!=NULL)
        {
            fprintf(pf_out,"%d ",CurrNODE->data);
            CurrNODE=CurrNODE->next;
        }
    }
    fprintf(pf_out, "\n");
}
int main()
{
    FILE *pf_in=fopen("input.dat", "r");
    FILE *pf_out=fopen("output.dat", "w");
    char action[20];
    int value;
    while(fscanf(pf_in,"%s %d", &action, &value)!=EOF)
    {
        if((strcmp(action,"AF"))==0)
        {
            AddFirst(value);
        }
        if((strcmp(action,"AL"))==0)
        {
            AddLast(value);
        }
        if((strcmp(action,"DF"))==0)
        {
            DelFirst();
        }
        if((strcmp(action,"DL"))==0)
        {
            DelLast();
        }
        if((strcmp(action,"DOOM_THE_LIST"))==0)
        {
            DoomList();
        }
        if((strcmp(action,"DE"))==0)
        {
            DeleteCertainElement(value);
        }
        if((strcmp(action,"PRINT_ALL"))==0)
        {
            PrintAll(pf_out);
        }
        if((strcmp(action,"PRINT_F"))==0)
        {
            PrintFirst(value, pf_out);
        }
        if((strcmp(action,"PRINT_L"))==0)
        {
            PrintLast(value, pf_out);
        }
    }
    fclose(pf_in);

    return 0;
}

