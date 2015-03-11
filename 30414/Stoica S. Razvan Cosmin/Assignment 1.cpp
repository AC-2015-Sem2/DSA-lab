#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *o;

typedef struct Node
{
    int data;
    struct Node* next;
}g;

struct Node *head,*tail;

void InsertFirst(int x)
{
    struct Node *temp = (struct Node *) malloc (sizeof(struct Node));
    temp->data=x;
    temp->next=NULL;
    if(head!=NULL) temp->next=head;
    head=temp;
}

void ListLenght(int &a)
{
    a=0;
    struct Node* temp=head;
    while(temp!=NULL)
    {
        a++;
        temp=temp->next;
    }
}

void PrintNrOfElements(int x)
{
    int n,i;
    struct Node *temp;
    temp=head;
    ListLenght(n);
    if(x>n) x=n;
    for(i=0; i<x; i++)
    {
        fprintf(o,"%d ",temp->data);
        temp=temp->next;
    }
    fprintf(o,"\n");
}

void AddLast(int x)
{
    struct Node *tempx=(struct Node *)malloc(sizeof(struct Node));
    struct Node *tempx2;
    tempx->data=x;
    tempx->next=NULL;
    if(head==NULL)
        {
        head=tempx;
    }
    else
    {
    tempx2 = head;
    while(tempx2->next!=NULL)
        {
        tempx2=tempx2->next;
        }
    tempx2->next=tempx;
    }
}

void DeleteFirst()
{
    struct Node *temp;
    if(head!=NULL)
    {
    temp=head->next;
    free(head);
    head=temp;
    }
}

void DeleteLast()
{
    struct Node *temp;
    temp=head;
    if(head==NULL) return;
    if(temp->next==NULL)
    {
        DeleteFirst();
    }
    else{
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
    }
}

void Doom()
{
    while(head!=NULL)
    {
        DeleteFirst();
    }
}

void DeleteElement(int x)
{
    while(head!=NULL && head->data==x)
    {
        DeleteFirst();
    }
    struct Node *temp,*temp2;
    temp=head;

    while(temp->next!=NULL)
    {
        if(temp->next->data==x)
        {
            temp2=temp->next->next;
            free(temp->next);
            temp->next=temp2;
        }
       temp=temp->next;
       if(temp==NULL) break;
    }

}

void print()
{
    struct Node* temp=head;
    while(temp!=NULL)
    {
        fprintf(o,"%d ",temp->data);
        temp=temp->next;
    }
    fprintf(o,"\n");
}

void PrintNrOfElementsLast(int x)
{
    int n,i;
    struct Node *temp;
    temp=head;
    ListLenght(n);
    if(x>=n)
    {
            print();
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
            InsertFirst(atoi(d));
        } else
        if (strcmp(c,"AL") == 0)
        {
            AddLast(atoi(d));
        }
        else if(strcmp(c,"DF")==0)
        {
            DeleteFirst();
        }
        else if(strcmp(c,"DL")==0)
        {
            DeleteLast();
        }
        else if(strcmp(c,"DE")==0)
        {
            DeleteElement(atoi(d));
        }
        else if(strcmp(c,"PRINT_ALL")==0)
        {
            print();
        }
        else if(strcmp(c,"PRINT_F")==0)
        {
            PrintNrOfElements(atoi(d));
        }
        else if(strcmp(c,"PRINT_L")==0)
        {
            PrintNrOfElementsLast(atoi(d));
        }
        else if(strcmp(c,"DOOM_THE_LIST")==0)
        {
            Doom();
        }
    }
    return 0;
}
