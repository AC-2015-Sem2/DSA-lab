#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct st_node
{
    int data;
    struct st_node* next;
} node;

node *head, *tail;
void print_list()
{
    node* aux=head;
    FILE* fout=fopen("output.txt","a");
         if (fout==NULL)
    {
        printf("Error in opening the file.");
        exit(1);
    }
    while(aux!=NULL)
    {
        fprintf(fout,"%d ",aux->data);
        aux=aux->next;
    }
    fprintf(fout,"\n");
    fclose(fout);
}
void printfirstx(int x)
{
    int k=0;
    node* aux=head;
    FILE* fout=fopen("output.txt","a");
         if (fout==NULL)
    {
        printf("Error in opening the file.");
        exit(1);
    }
    while(aux!=NULL && k<x)
    {
        fprintf(fout,"%d ",aux->data);
        aux=aux->next;
        k++;
    }
    fprintf(fout,"\n");
    fclose(fout);
}
/*we have to print first x values from the list. We print them as long as the list is not null and in parallel we count them, and when
we reach x-1 we stop from printing*/


void addlast(int data)
{

    if(tail==NULL)
    {
        tail=(node*)malloc(sizeof(node));
        head=tail;
        tail->data=data;
        tail->next=NULL;
    }
    else
    {
        node* newnode=(node*)malloc(sizeof(node));
        newnode->data=data;
        newnode->next=NULL;
        tail->next=newnode;
        tail=newnode;
    }
}
void addfirst(int data)
{
    if(head==NULL)
    {
        head=(node*)malloc(sizeof(node));
        tail=head;
        head->data=data;
        head->next=NULL;
    }
    else
    {
        node* newnode=(node*)malloc(sizeof(node));
        newnode->data=data;
        newnode->next=head;
        head=newnode;
    }
}
void deletefirst()
{
    if(head==tail)
    {
        head=NULL;
        tail=NULL;
    }
    else
    {
        node *curr=(node*)malloc(sizeof(node));;

        curr=head->next;
        free(head);
        head=curr;
    }
}
/*We check if the list has only one element, if so we delete it(head=null, tail=null) else the current node(curr) receives the second
element in the list, the pointer that has the adress of the head becomes a null pointer and the list has a new head second element
of the list */
void deletelast()
{
    if(head==tail)
    {
        head=NULL;
        tail=NULL;
    }
    else
    {
        node *curr=(node*) malloc(sizeof(node));
        curr=head;
        while(curr!=NULL)
        {
            if(curr->next==tail)
            {
                tail=curr;
                tail->next=NULL;
                free(curr->next);
            }
            else
                curr=curr->next;
        }
    }
}

void DOOM()
{
    node *curr=(node*)malloc(sizeof(node));
    while(head!=NULL)
    {

        curr=head;
        head=curr->next;
        free(curr);
    }
    head=NULL;
    tail=NULL;
}
/* We delete the elements of the list one by one as long as the head is different from null pointer.When we reach the end of
the list the head and the tail receives the null pointer.*/

void deletex(int x)
{
    node* curr = (node*)malloc(sizeof(node));
    node* aux = (node*)malloc(sizeof(node));

    if(head->data == x)
        deletefirst();
    if(tail->data == x)
        deletelast();
    if(head == tail && head->data == x)
    {
        head = NULL;
        tail = NULL;
    }
    curr = head;

    while(curr->next != NULL)
    {
        aux = curr->next;
        if(aux->data == x)
        {
            curr->next = aux->next;
            free(aux);
        }

        curr = curr->next;
    }
}
/*If the element is in the head/tail of the list we delete te first/last element with the previous functions, else
we take each element of the list and check if it's equal with x, and if so the current pointer receives the next pointer of the
following element in the list, and the pointer to the element of the list where was x becomes 0 else we go to the next element of  the list*/
void printlastx(int x)
{
    int elements=0, nrcrt=0;
    node* aux = head;
    FILE* fout = fopen("output.txt", "a");
        if (fout==NULL)
    {
        printf("Error in opening the file.");
        exit(1);
    }
    while(aux != NULL)
    {
        elements++;
        aux = aux->next;
    }

    aux = head;
    while(aux != NULL)
    {
        nrcrt++;
        if(nrcrt > elements - x)
            fprintf(fout, "%d ", aux->data);
        aux = aux->next;
    }
    fprintf(fout,"\n");
    fclose(fout);
}
//It's complicated because at first we do not know how many elements are in the list, so first we have to count
//them. As long as the current position in the list is greater than the number of total elements minus x
//we pass over them and if not we print them in the file.

int main()
{

    FILE* fin = fopen("input.txt", "r");
    char caz[15];
    int n;
    if (fin==NULL)
    {
        printf("Error in opening the file.");
        exit(1);
    }

    while(fscanf(fin,"%s",caz)>0)
    {
        if (strcmp(caz,"AF")==0)
        {
            fscanf(fin,"%d",&n);
            addfirst(n);
        }
        else if (strcmp(caz,"AL")==0)
        {
            fscanf(fin,"%d",&n);
            addlast(n);
        }
        else if (strcmp(caz,"DF")==0)
            deletefirst();
        else if(strcmp(caz,"DL")==0)
            deletelast();
        else if(strcmp(caz,"DE")==0)
        {
            fscanf(fin,"%d",&n);
            deletex(n);
        }
        else if(strcmp(caz,"PRINT_ALL")==0)
            print_list();
        else if(strcmp(caz,"PRINT_F")==0)
        {
            fscanf(fin,"%d",&n);
            printfirstx(n);
        }
        else if(strcmp(caz,"PRINT_L")==0)
        {
            fscanf(fin,"%d",&n);
            printlastx(n);
        }
        else if(strcmp(caz,"DOOM_THE_LIST")==0)
            DOOM();
    }
    fclose(fin);
    return 0;
}
