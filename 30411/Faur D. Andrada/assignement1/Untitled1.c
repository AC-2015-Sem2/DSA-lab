#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


void addFirst(int code);
void addLast(int code);
void deleteFirst();
void deleteLast();
void doom();
void delete_X(int x);
void printall();
void print_first_X(int x);
int length_of_list();
void print_last_X(int x,FILE *f_out);





typedef struct NodeT
{
    int code;
    struct NodeT* next;
} NodeT;


NodeT *head, *tail;

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

    else
    {
        NodeT* p=(NodeT*)malloc(sizeof(NodeT));
        p->code=code;
        p->next=NULL;
        tail->next=p;
        tail=p;
    }
}

void deleteFirst()
{
    NodeT* aux;
    if(head!=NULL)
    {
        aux=head->next;
        free(head);
        head=aux;
    }
}

void deleteLast()
{
    NodeT* aux;
    if(head!=NULL)
    {
        aux=head->next;
        tail=head;
        while (aux->next != NULL)
        {
            tail=aux;
            aux=aux->next;
        }
        free(tail->next);
        tail->next = NULL;
    }

    void doom()
    {
        NodeT* aux;
        while (head != NULL)
        {
            aux = head;
            head = aux->next;
            free(aux);
        }
    }

    void delete_X(int x)
    {
        NodeT* aux;
        NodeT* prev_aux;
        aux = head;
        prev_aux=NULL;
        while((aux!=NULL)&&(aux->code!=x))
        {
            prev_aux = aux;
            aux=aux->next;
        }
        if (aux==head) deleteFirst();
        else if (aux==tail) deleteLast();
        else
        {
            prev_aux->next=aux->next;
            free (aux);
        }

    }

    void printall()
    {
        NodeT* aux=head;
        while(aux!=NULL)
        {
            printf("%d ",aux->code);
            aux=aux->next;
        }
    }

    void print_first_X(int x)
    {
        NodeT* aux=head;
        int i=0;
        while((aux!=NULL)&&(i<x))
        {
            printf("%d ",aux->code);
            aux=aux->next;
            i++;
        }
    }

    int length_of_list()
    {
        int i=0;
        NodeT* aux=head;
        while(aux!=NULL)
        {
            i++;
            aux=aux->next;
        }
        return i;
    }

    void print_last_X(int x, FILE *f_out)
    {
        NodeT* aux=head;
        int i=0;
        int n=length_of_list();
        if (x>=n) printall();
        else
        {
            for (i=0; i<(n-x); i++)
                aux=aux->next;
            while(aux!=NULL)
            {

                fprintf(f_out,"%d ",aux->code);
                aux=aux->next;
            }
        }
    }

    int main()
    {
        int x;
        FILE *f_in=fopen("input.dat","r");
        if (f_in == NULL)
        {
            perror("cannot open the file!");
        }

        FILE *f_out=fopen("output.dat","a");
        char option[15];

        while (fscanf(f_in,"%s",option)>0)
        {

            if (strcmp(option,"AF")==0)
            {
                fscanf(f_in,"%d",&x);
                addFirst(x);
            }

            if (strcmp(option,"AL")==0)
            {
                fscanf(f_in,"%d",&x);
                addLast(x);
            }

            if (strcmp(option,"DF")==0)
            {
                deleteFirst();
            }

            if (strcmp(option,"DL")==0)
            {
                deleteLast();
            }

            if (strcmp(option,"DOOM_THE_LIST")==0)
            {
                doom();
            }

            if (strcmp(option,"DE")==0)
            {
                fscanf(f_in,"%d",&x);
                delete_X(x);
            }

            if (strcmp(option,"PRINT_ALL")==0)
            {
                printall();
            }

            if (strcmp(option,"PRINT_F")==0)
            {
                fscanf(f_in,"%d",&x);
                print_first_X(x);
            }

            if (strcmp(option,"PRINT_L")==0)
            {
                fscanf(f_in,"%d",&x);
                print_last_X(x,f_out);
            }


        }

        fclose(f_in);
        fclose(f_out);


        return 0;
    }
