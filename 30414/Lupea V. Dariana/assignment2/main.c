#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct st_node
{
    int data;
    struct st_node*next;
    struct st_node*prev;
} node;
node *head, *tail;

void AddFirst(int data)
{
    if (head==NULL)
    {
        head=(node*)malloc(sizeof(node*));
        tail=head;
        head->data=data;
        head->next=NULL;
        head->prev=NULL;
    }
    else
    {
        node* newNode=(node*)malloc(sizeof(node));
        newNode->data=data;
        newNode->next=head;
        newNode->prev=NULL;
        head=newNode;
    }
}

void AddLast(int data)
{
    if (head==NULL)
    {
        head=(node*)malloc(sizeof(node));
        head->data=data;
        head->next=NULL;
        head->prev=data;
        tail=head;
    }
    else
    {
        node* newNode=(node*)malloc(sizeof(node));
        newNode->data=data;
        newNode->next=NULL;
        newNode->prev=data;
        tail->next=newNode;
        tail=newNode;
    }
}

void print_list()
{
    FILE *f=fopen("output.dat", "a");
    node* aux=head;
    while (aux!=NULL)
    {
        fprintf(f, "%d ", aux->data);
        aux=aux->next;
    }
    fprintf(f,"\n");
    fclose(f);
}

void DelFirst()
{
    if (head!=NULL)
    {
        node* curent=head;
        head=head->next;
        free(curent);
    }
}

void DelLast()
{
    node* curent=head;
    if (tail!=NULL)
    {
        while (curent->next!=tail)
        {
            curent=curent->next;
        }
            tail->next=NULL;
            tail=tail->prev;
            free(tail);
            tail=curent;
    }
}

void DelAnElement(int x)
{
     node *prevNode=NULL, *currentNode;
     if (head!=NULL&&head->data==x)
        DelFirst();
     prevNode=head;
     currentNode=head;
     currentNode=currentNode->next;
     if (head!=NULL)
     {

         while (currentNode!=NULL)
         {
             if (currentNode->data==x)
             {
                if (currentNode==head)
                {
                    DelFirst();
                }
                else
                {
                    if(currentNode==tail)
                    {
                        DelLast();
                    }
                    else
                    {
                       currentNode->prev->next=currentNode->next;
                       currentNode->next->prev=currentNode->prev;
                       free(currentNode);
                    }
                }
             }

         }

     }
}

void DoomTheList()
{

    while(head->next!=NULL)
    {
        tail=head->next;
        free(head);
        head=tail;
    }
    free(head);
    tail=NULL;
    head=NULL;
}


void PRINT_L(int x)
{
    int cate=0, curr=0;
    FILE* f=fopen("output.dat", "a");
    node* p=head;
    while(p!=NULL)
    {
        cate++;
        p=p->next;
    }
    if(x>cate)
    {
        print_list();
    }

    p=tail;
    if (tail!=head)
    {
        while (p!=NULL&&curr>=x)
        {

            {  curr++;
               fprintf(f,"%d ", p->data);
            }
            p=p->prev;
        }
    }
    fprintf(f,"\n");
    fclose(f);
}

void PRINT_F(int x)
{
    int cate=0;
    FILE* f=fopen("output.dat","a");
    node* p=head;
    while(p!=NULL)
    {
        cate++;
        p=p->next;
    }
    if(x>cate)
    {
        print_list();
    }

    p=head;
    while(x)
    {
        fprintf(f,"%d ", p->data);
        p=p->next;
        x--;
    }
    fprintf(f, "\n");
    fclose(f);

}

int main()
{
     char strng[20]; int value;
     FILE *d;
     d= fopen("input.dat", "r");
     while(fscanf(d, "%s %d", &strng, &value)!=EOF)
     {
         if (strcmp(strng,"AF")==0) AddFirst(value);
         if (strcmp(strng,"AL")==0) AddLast(value);
         if (strcmp(strng,"PRINT_ALL")==0) print_list();
         if (strcmp(strng,"DF")==0) DelFirst();
         if (strcmp(strng,"DL")==0) DelLast();
         if (strcmp(strng,"DOOM_THE_LIST")==0) DoomTheList();
         if (strcmp(strng,"DE")==0) DelAnElement(value);
         if (strcmp(strng,"PRINT_F")==0) PRINT_F(value);
         if (strcmp(strng,"PRINT_L")==0) PRINT_L(value);
     }
     fclose(d);
    return 0;

}


