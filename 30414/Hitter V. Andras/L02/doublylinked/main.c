#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct node
{
    int data;
    struct node *next,*prev;
}node;

typedef struct sent
{
    struct node *head,*tail;
}sent;

sent *S;
FILE *f,*g;

void addFirst(int data)
{
    node *a;
    if(S->head==NULL)
    {
        S->head=(node*)malloc(sizeof(node));
        S->tail=S->head;
        S->head->data=data;
        S->head->next=NULL;
        S->head->prev=NULL;
    }
    else
    {
        a=(node*)malloc(sizeof(node));
        a->prev=NULL;
        a->data=data;
        a->next=S->head;
        S->head->prev=a;
        S->head=a;
    }
}

void addLast(int data)
{
   node *a;
    if(S->head==NULL)
    {
        S->head=(node*)malloc(sizeof(node));
        S->tail=S->head;
        S->head->data=data;
        S->head->next=NULL;
        S->head->prev=NULL;
    }
    else
    {
    a=(node*)malloc(sizeof(node));
    a->data=data;
    a->next=NULL;
    a->prev=S->tail;
    S->tail->next=a;
    S->tail=a;
    }

}

void deleteFirst()
{
    node *aux;
    if(S->head==NULL) return;
    else
    {
        aux=S->head;
        if(S->head==S->tail) {S->tail->next=NULL; S->tail->prev=NULL;}
        S->head=S->head->next;
        S->head->prev=NULL;
        free(aux);
    }
}

void deleteLast()
{
    if(S->tail==NULL) return;
    else
    {
    node *aux;
    aux=S->tail;
    if(S->tail==S->head) {S->head->next=NULL; S->head->prev=NULL;}
    S->tail=S->tail->prev;
    S->tail->next=NULL;
    free(aux);
    }
}

void deleteElement(int x)
{
    node *aux;
    if (S->head->data==x) deleteFirst();
    else
    {
        aux=S->head;
        while ((aux->data!=x) && (aux!=S->tail))
        {
            aux=aux->next;
        }
        if (aux!=S->tail)
        {
            aux->prev->next=aux->next;
            aux->next->prev=aux->prev;
            free(aux);
        }
        else if (S->tail->data==x)
        {
            deleteLast();
        }
    }
}

void doomTheList()
{
    node *p,*q;
    p=S->head;
    do
    {
        q=p;
        p=p->next;
        free(q);
    }
    while (p!=S->tail);
    //free(S->tail);
    S->head=NULL;
    S->tail=NULL;
}
void printAll()
{
    g=fopen("output.dat", "a");
    node *aux;
    {
    aux=S->head;
    while (aux!=NULL)
    {
        fprintf(g,"%d ",aux->data);
        aux=aux->next;
    }
    fprintf(g,"\n");}
    fclose(g);
}

void print()
{
    node *aux;
    {
    aux=S->head;
    while (aux!=NULL)
    {
        printf("%d ",aux->data);
        aux=aux->next;
    }
    printf("\n");}
}

void printFirst(int x)
{
    g=fopen("output.dat", "a");
    int i=1;
    node *aux;
    aux=S->head;
    while ((aux!=NULL) && (i<=x))
    {
        fprintf(g,"%d ",aux->data);
        i++;
        aux=aux->next;
    }
    fprintf(g,"\n");
    fclose(g);
}

/*void printLast(int data)
{
    g=fopen("output.dat", "a");
    node *a,*aux;
    a=S->head;
    aux=S->head;
    int c=0;
    while (aux!=NULL)
    {
        c=c+1;
        aux=aux->next;
    }
    if (c<=data) printAll();
    else
    {
        while(a!=NULL)
        {
        if (c>data) {c=c-1;a=a->next;}
            else
                if (c<=data) {c=c-1;fprintf(g,"%d ",a->data);a=a->next;}
    }
    fprintf(g,"\n");
    }
}*/
void printLast(int data)
{
    g=fopen("output.dat","a");
    node *aux;
    aux=S->tail;
    int c=1;
    while ((c<data)&&(aux->prev!=NULL))
    {
        c=c+1;
        aux=aux->prev;
    }
    if (aux->prev==NULL) printAll();
    else
    {
        while(aux!=NULL)
        {   printf("%d",aux->data);
            fprintf(g,"%d ",aux->data);aux=aux->next;
        }
    fprintf(g,"\n");
    }
}


int main()
{
    f=fopen("input.dat","r");
    g=fopen("output.dat","w");
    if(f==NULL)
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    S=(sent*)malloc(sizeof(sent));
    S->head=NULL;
    S->tail=NULL;
    char s[20];int k=1;int x;
    while (k==1)
    {
        fscanf(f,"%s%d",s,&x);
        if (s[0]=='\0') k=0;
        if (strcmp(s, "AF")==0) {addFirst(x);}
        if (strcmp(s, "AL")==0) {addLast(x);}
        if (strcmp(s, "DF")==0) {deleteFirst();}
        if (strcmp(s, "DL")==0) {deleteLast();}
        if (strcmp(s, "DE")==0) {deleteElement(x);}
        if (strcmp(s, "DOOM_THE_LIST")==0) {doomTheList();}
        if (strcmp(s, "PRINT_ALL")==0) {printAll();print();}
        if (strcmp(s, "PRINT_F")==0) {printFirst(x);}
        if (strcmp(s, "PRINT_L")==0) {printLast(x);}
        s[0]='\0';
    }
    return 0;
}
