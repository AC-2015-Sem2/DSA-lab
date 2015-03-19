#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct st_node
{
    int data;
    struct st_node* next;
    struct st_node* prev;
} node;

typedef struct sentinel
{
    node* head;
    node* tail;
    int len;
} list;

list *sent;



void printList()
{
    node* curr =(node*)malloc(sizeof(node));
    curr=sent->head;

    FILE* fout = fopen("output.txt", "a");

    while(curr!= NULL)
    {
        fprintf(fout, "%d ", curr->data);
        curr = curr->next;
    }
    fprintf(fout, "\n");
    fclose(fout);
}
void printFirstX(int x)
{
    node* curr=(node*)malloc(sizeof(node));
    curr = sent->head;
    int contor=0;

    FILE* fout = fopen("output.txt", "a");

    while(curr!= NULL && x<contor)
    {
        fprintf(fout, "%d ", curr->data);
        curr = curr->next;
        contor++;
    }
    fprintf(fout, "\n");
    fclose(fout);
}
void printLastX(int x)
{
    node* curr =(node*)malloc(sizeof(node));
    curr = sent->tail;
    FILE* fout = fopen("output.txt", "a");
    int contor;
    for(contor = 1; contor < x; contor++)
        if(curr->prev != NULL)
            curr = curr->prev;

    while(curr != NULL)
    {
        fprintf(fout, "%d ", curr->data);
        curr = curr->next;
    }
    fprintf(fout, "\n");

    fclose(fout);
}
void addFirst(int data)
{
    if(sent->head==NULL)
    {
        sent->head=(node*)malloc(sizeof(node));
        sent->head->data=data;
        sent->tail=sent->head;
    }
    else
    {
        node *curr=(node*)malloc(sizeof(node));
        curr->data=data;
        curr->next=sent->head;
        sent->head->prev=curr;
        sent->head=curr;
    }
    sent->len++;
}
void addLast(int data)
{
    if(sent->tail==NULL)
    {
        sent->tail=(node*)malloc(sizeof(node));
        sent->tail->data=data;
        sent->head=sent->tail;

    }
    else
    {
        node *curr=(node*)malloc(sizeof(node));
        curr->data=data;
        sent->tail->next=curr;
        curr->prev=sent->tail;
        sent->tail=curr;
    }
    sent->len++;
}
void deleteFirst()
{
    if(sent->head==sent->tail)
    {
        free(sent->head);
        sent->head=NULL;
        sent->tail=NULL;
        sent->len=0;
    }
    else
    {
        node *curr=(node*)malloc(sizeof(node));
        curr=sent->head;
        sent->head=sent->head->next;
        free(curr);
        sent->len--;
    }
}
void deleteLast()
{
    if(sent->head==sent->tail)
    {
        free(sent->tail);
        sent->head=NULL;
        sent->tail=NULL;
        sent->len=0;
    }
    else
    {
        node* curr=(node*)malloc(sizeof(node));
        curr=sent->tail;
        sent->tail=sent->tail->prev;
        free(curr);
        sent->len--;
    }

}
void doomTheList()
{
    node* curr=(node*)malloc(sizeof(node));
    node* aux=(node*)malloc(sizeof(node));
    curr=sent->head;
    aux=curr;
    while(curr!=NULL)
    {
        curr=curr->next;
        free(aux);
        aux=curr;
    }
    sent->head=NULL;
    sent->tail=NULL;
    sent->len=0;
}
void deleteX(int x)
{
    node* curr=(node*)malloc(sizeof(node));
    if(sent->head->data==x)
        deleteFirst();
    if(sent->tail->data==x)
        deleteLast();
    if(sent->tail==sent->head && sent->head->data==x)
    {

        free(sent->head);
        sent->tail=NULL;
        sent->head=NULL;
    }
    curr=sent->head;
    int i;
    for(i=0; i<sent->len; i++)
    {
        curr=curr->next;
        if(curr->data==x)
        {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            node* aux = (node*)malloc(sizeof(node));
            aux= curr;
            curr = curr->next;
            free(aux);
            curr = curr->prev;
        }
    }

}

int main()
{

    sent = (list*)malloc(sizeof(list));
    sent->head = NULL;
    sent->tail = NULL;
    sent->len = 0;


    FILE*  fin= fopen("input.txt", "r");

    char caz[20];
    int n;

    while(fscanf(fin, "%s", caz)>0)
    {
        if(strcmp(caz, "AF")==0)
        {
            fscanf(fin, "%d", &n);
            addFirst(n);
        }
        else if(strcmp(caz, "AL")==0)
        {
            fscanf(fin, "%d", &n);
            addLast(n);
        }
        else if(strcmp(caz, "DF")==0)
            deleteFirst();
        else if(strcmp(caz, "DL")==0)
            deleteLast();
        else if(strcmp(caz, "DOOM_THE_LIST")==0)
            doomTheList();
        else if(strcmp(caz, "DE")==0)
        {
            fscanf(fin, "%d", &n);
            deleteX(n);
        }
        if(strcmp(caz, "PRINT_ALL")==0)
            printList();
        else if(strcmp(caz, "PRINT_F")==0)
        {
            fscanf(fin, "%d", &n);
            printFirstX(n);
        }
        else if(strcmp(caz, "PRINT_L")==0)
        {
            fscanf(fin, "%d", &n);
            printLastX(n);
        }
    }

    fclose(fin);
    return 0;
}

