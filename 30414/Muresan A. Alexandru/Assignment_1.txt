#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct nod{int data; struct nod *next;} NODE;
NODE *head, *tail;
void AddFirst(int data)
{
    if(head==NULL)
    {
        head=(NODE*)malloc(sizeof(NODE));
        head->data=data;
        head->next=NULL;
        tail=head;
    }
    else
    {
        NODE* NewNODE=(NODE*)malloc(sizeof(NODE));
        NewNODE->data=data;
        NewNODE->next=head;
        head=NewNODE;
    }
}
void AddLast(int data)
{
    if(head==NULL)
    {
        head=(NODE*)malloc(sizeof(NODE));
        head->data=data;
        head->next=NULL;
        tail=head;
    }
    else
    {
        NODE* NewNODE=(NODE*)malloc(sizeof(NODE));
        NewNODE->data=data;
        tail->next=NewNODE;
        NewNODE->next=NULL;
        tail=NewNODE;
    }
}
void DelFirst()
{
    if(head!=NULL)
    {
        head=head->next;
    }
}
void DoomList()
{
    head=NULL;
    tail=NULL;
}
void DelLast()
{
    if(head!=NULL)
    {
        NODE* CurrNODE=(NODE*)malloc(sizeof(NODE));
        CurrNODE=head;
        while(CurrNODE->next!=tail)
        {
            CurrNODE=CurrNODE->next;
        }
        CurrNODE->next=NULL;
        tail=CurrNODE;
    }
}
void DelCertainElement(int x)
{
    NODE* PrevNODE=NULL;//we need to memorize a previous element for deleting
    if(head!=NULL)
    {
        NODE* CurrNODE;
        CurrNODE=head;
        while (CurrNODE!=NULL)
        {
            if(CurrNODE->data==x)
            {
                if(CurrNODE==head)
                {
                    DelFirst();
                }
                else
                {
                    if(CurrNODE==tail)
                    {
                        DelLast();
                    }
                    else
                    {
                        PrevNODE->next=CurrNODE->next;
                    }
                }

            }
            PrevNODE=CurrNODE;
            CurrNODE=CurrNODE->next;
        }
    }
}
void PrintAll()
{
    FILE *pf_out=fopen("output.dat", "a");
    NODE* p;
    p=head;
    if(head!=NULL)
    {
        while(p!=NULL)
        {
            fprintf(pf_out,"%d ",p->data);
            p=p->next;
        }
    }
    fprintf(pf_out,"\n");
    fclose(pf_out);
}
void PrintFirst(int x)
{
    NODE* CurrNODE=head;
    FILE* pf_out=fopen("output.dat", "a");
    while (x)
    {
        fprintf (pf_out,"%d ",CurrNODE->data);
        CurrNODE=CurrNODE->next;
        x--;
    }
    fclose(pf_out);
}
void PrintLast(int x)
{
   FILE *pf_out=fopen("output.dat", "a");
    int curr=0, nr=0;//curr=index for current position of the pointer p; nr=number of elements;
    NODE *p=head;
    int n;
    while(p!=NULL)
    {
        nr++;
        p=p->next;
    }
    p=head;
    if(head!=NULL)
    {
        while(p!=NULL)
        {
            curr++;
            if(curr>nr-x)//if pointer p reaches the last-but-third element it starts to print the elements
            {
                fprintf(pf_out,"%d ",p->data);
            }
            p=p->next;
        }
    }
    fprintf(pf_out,"\n");
    fclose(pf_out);
}
int main()
{
    FILE *pf_in=fopen("input.dat", "r");
    char action[20];
    int value;
    while(fscanf(pf_in,"%s %d", &action, &value)!=EOF)
    {
        if(strcmp(action, "AF")==0)
        {
            AddFirst(value);
        }
        if(strcmp(action, "AL")==0)
        {
            AddLast(value);
        }
        if(strcmp(action, "PRINT_ALL")==0)
        {
            PrintAll();
        }
        if(strcmp(action,"DOOM_THE_LIST")==0)
        {
            DoomList();
        }
        if(strcmp(action,"DF")==0)
        {
            DelFirst();
        }
        if(strcmp(action,"DL")==0)
        {
            DelLast();
        }
        if(strcmp(action,"DE")==0)
        {
            DelCertainElement(value);
        }
        if(strcmp(action,"PRINT_F")==0)
        {
            PrintFirst(value);
        }
        if(strcmp(action,"PRINT_L")==0)
        {
            PrintLast(value);
        }
    }
    fclose(pf_in);
    return 0;
}
