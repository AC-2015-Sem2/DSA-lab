#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *o;

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
}g;

typedef struct List
{
    struct Node *head;
    struct Node *tail;
}gg;

List Works;


void InsertFirst(int x,List *ItWorks)
{
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->data=x;
    if(ItWorks->head!=NULL)
    {
        temp->next=ItWorks->head;
        ItWorks->head->prev=temp;
        ItWorks->head=temp;
        temp->prev=NULL;
    }
    else
        {
        ItWorks->head=temp;
        temp->next=NULL;
        temp->prev=NULL;
    }
}

void AddLast(int x,List *ItWorks)
{
    struct Node *tempx=(struct Node *)malloc(sizeof(struct Node));
    struct Node *tempx2,*tempx3;
    tempx->data=x;
    tempx->next=NULL;
    if(ItWorks->head==NULL)
        {
        tempx->prev=NULL;
        ItWorks->head=tempx;
        }
    else
    {
    tempx2=ItWorks->head;
    tempx3=ItWorks->head;
    while(tempx2->next!=NULL )
        {
        tempx2=tempx2->next;
        tempx3->prev=tempx3;
        }
    tempx2->next=tempx;
    tempx->prev=tempx2;
    }
}

void DeleteFirst(List *ItWorks)
{
    struct Node *temp;
    if(ItWorks->head!=NULL)
    {
    temp=ItWorks->head->next;
    free(ItWorks->head);
    ItWorks->head=temp;
    }
}

void DeleteLast(List *ItWorks)
{
    struct Node *temp;
    temp=ItWorks->head;
    if(ItWorks->head==NULL) return;
    if(temp->next==NULL)
    {
        DeleteFirst(&Works);
    }
    else
        {
        while(temp->next->next!=NULL)
            {
            temp=temp->next;
            }
        free(temp->next);
        temp->next=NULL;
        }
}

void Doom(List *ItWorks)
{
    while(ItWorks->head!=NULL)
    {
        DeleteFirst(&Works);
    }
}

void DeleteElement(int x,List *ItWorks)
{
    while(ItWorks->head!=NULL && ItWorks->head->data==x)
    {
        DeleteFirst(&Works);
    }
    struct Node *temp,*temp2,*temp3;
    temp=ItWorks->head;

    while(temp->next!=NULL)
    {
        if(temp->next->data==x)
        {
            temp2=temp->next->next;
            temp3=temp->next;
            free(temp->next);
            temp->next=temp2;
            temp->prev=temp3;
        }
       temp=temp->next;
       if(temp==NULL) break;
    }
}

void print(List *ItWorks)
{
    struct Node* temp=ItWorks->head;
    while(temp!=NULL)
    {
        fprintf(o,"%d ",temp->data);
        temp=temp->next;

    }
    fprintf(o,"\n");
}

void ListLenght(int &a,List *ItWorks)
{
    a=0;
    struct Node* temp=ItWorks->head;
    while(temp!=NULL)
    {
        a++;
        temp=temp->next;
    }
}

void PrintNrOfElements(int x,List *ItWorks)
{
    int n,i;
    struct Node *temp;
    temp=ItWorks->head;
    ListLenght(n,&Works);
    if(x>n) x=n;
    for(i=0; i<x; i++)
    {
        fprintf(o,"%d ",temp->data);
        temp=temp->next;
    }
    fprintf(o,"\n");
}


void PrintNrOfElementsLast(int x,List *ItWorks)
{
    int n,i;
    struct Node *temp;
    temp=ItWorks->head;
    ListLenght(n,&Works);
    if(x>=n)
    {
            print(&Works);
            return;
    }
    for(i=0; i<n-x; i++)
        {
            temp=temp->next;
        }
    for(i=n-x; i<n; i++)
    {
        fprintf(o,"%d ",temp->data);
        temp=temp->next;
    }
    fprintf(o,"\n");
}

int main()
{
    FILE *p;
    p=fopen("input.dat","r");
    o=fopen("output.dat","w");
    char a[100],*c,*d;
    while(fgets(a,100,p))
    {
        c=strtok(a," \n");
        d=strtok(NULL," \n");
        if(strcmp(c,"AF") == 0)
        {
            InsertFirst(atoi(d), &Works);
        } else
        if (strcmp(c,"AL") == 0)
        {
            AddLast(atoi(d), &Works);
        }
        else if(strcmp(c,"DF")==0)
        {
            DeleteFirst(&Works);
        }
        else if(strcmp(c,"DL")==0)
        {
            DeleteLast(&Works);
        }
        else if(strcmp(c,"DE")==0)
        {
            DeleteElement(atoi(d), &Works);
        }
        else if(strcmp(c,"PRINT_ALL")==0)
        {
            print(&Works);
        }
        else if(strcmp(c,"PRINT_F")==0)
        {
            PrintNrOfElements(atoi(d), &Works);
        }
        else if(strcmp(c,"PRINT_L")==0)
        {
            PrintNrOfElementsLast(atoi(d), &Works);
        }
        else if(strcmp(c,"DOOM_THE_LIST")==0)
        {
            Doom(&Works);
        }
    }
    return 0;
}
