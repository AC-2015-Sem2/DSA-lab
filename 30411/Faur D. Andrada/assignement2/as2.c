#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


typedef struct NodeT {
    struct NodeT *next;
    struct NodeT *prev;
    int code;
} NodeT;

typedef struct sant {
    int length;
    NodeT *head;
    NodeT *tail;
} Santinel;

NodeT *head, *tail;
Santinel santinela;

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
        head->prev=p;
        head=p;
    }
    santinela.head=head;
    santinela.length++;
    santinela.tail=tail;
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
        p->prev=tail;
        tail=p;
    }
santinela.head=head;
    santinela.length++;
    santinela.tail=tail;
}

void deleteFirst()
{
    NodeT* aux;
    if(head!=NULL)
    {
        aux=head->next;
        aux->prev=NULL;
        free(head);
        head=aux;
    }
    santinela.head=head;
    santinela.length--;
    santinela.tail=tail;
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
        tail->next=NULL;
        free(aux);
    }
    santinela.head=head;
    santinela.length--;
    santinela.tail=tail;
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
         santinela.head=NULL;
    santinela.length=0;
    santinela.tail=NULL;
    }

 void delete_X(int x)
    {
        NodeT* aux;
        aux = head;
        while((aux!=NULL)&&(aux->code!=x))
        {
            aux=aux->next;
        }
        if (aux==head) deleteFirst();
        else if (aux==tail) deleteLast();
        else
        {
            aux->prev->next=aux->next;
            aux->next->prev=aux->prev;
            free (aux);
        }
santinela.head=head;
    santinela.length--;
    santinela.tail=tail;
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
void print_last_X(int x, FILE *f_out)
    {
        NodeT* aux=head;
        int i=0;
        if (x>=santinela.length) printall();
        else
        {
            for (i=0; i<(santinela.length-x); i++)
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
