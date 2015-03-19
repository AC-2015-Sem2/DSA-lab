#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int code;
    struct node* next,*prev;
} NodeT;

typedef struct sent
{
    NodeT *head,*tail;
    int length;
}santinel ;
santinel *L;

void addfirst (int code)
{
    if(L->head==NULL)
    {
        NodeT*p=(NodeT*)malloc(sizeof(NodeT*));
        L=(santinel*)malloc(sizeof(santinel*));
        L->head->code=code;
        L->head=L->tail=p;
        p->next=p->prev=NULL;
        L->tail=L->head;
    }
    else
    {
        NodeT*p=(NodeT*)malloc(sizeof(NodeT*));
        p->code=code;
        p->next=L->head;
        p->prev=NULL;
        L->head->prev=p;
        L->head=p;
    }
}
void addlast(int code)
{
    L=(santinel*)malloc(sizeof(santinel));
    NodeT* p=(NodeT*)malloc(sizeof(NodeT));
    p->code=code;
    if(L->head==NULL)
    {
         L->head=(NodeT*)malloc(sizeof(NodeT));
        L->head=L->tail=p;
        p->next=p->prev=NULL;
    }
    else if(L->tail!=NULL)
    {
        p->next=NULL;
        p->prev=L->tail;
        L->tail->next=p;
        L->tail=p;

    }
}
void deletefirst()
{
    NodeT *p;
    p=L->head;
    L->head=L->head->next; //nonempty list assumed
    free(p);  //release memory taken by node
    if(L->head==NULL)
        L->tail=NULL; //list become empty
    else
        L->head->prev=NULL;
}
void deletelast()
{
    NodeT *p;
    p=L->tail;
    L->tail=L->tail->prev; //nonempty list assumed
    if(L->tail==NULL)
    L->head=NULL; //list become empty
    else
        L->tail->next=NULL;
    free(p); //release memory taken by node
}
void delete_a_node(int code)
{
    NodeT* p=(NodeT*)malloc(sizeof(NodeT));
    if(L->head==p && L->tail==p)
    {
        //list has a single node
        L->head=NULL;
        L->tail=NULL;  //list become empty
        free(p);
    }
    else
        if(p==L->head)
    {  //deletion of first node
        L->head=L->head->next;
        L->head->prev=NULL;
        free(p);
    }
    else
    { //deletion ofan inner node
        p->next->prev=p->prev;
        p->prev->next=p->next;
        free(p);
    }
}
void delete_the_list ()
{
    NodeT*p;
    while(L->head!=NULL)
    {
        p=L->head;
        L->head=L->head->next;
        free(p);
    }
    L->tail=NULL;
}
void printlist(FILE *f)
{
    NodeT* aux=L->head;
    while(aux!=NULL)  // aux!=NULL    {
    {
        fprintf(f,"%d ",aux->code );
        aux=aux->next;
    }
    fprintf(f,"\n");
}
void print_the_first_nodes (FILE *pf,int x)
{
    NodeT* aux=L->head;
    int k=0;
    while(aux!=NULL && k<=x)
    {
        k++;
        fprintf(pf,"%d ",aux->code);
        aux=aux->next;
    }
    fprintf(pf,"\n");
}
void print_the_last_nodes(FILE* pf,int x)
{
    NodeT* aux=L->head;
    int k=0;
    while(aux!=NULL)
    {
        k++;
        aux=aux->next;
    }
    aux=L->head;
    int j=0;
    while(aux!=NULL )
    {
        j++;
        if(j>k-x)
            fprintf(pf,"%d ",aux->code);
            aux=aux->next;
    }
    fprintf(pf,"\n");
}
int main()
{
    FILE *f;
    f=fopen("input.dat","r");
    if(f==NULL)
    {
        perror("cannot create file!");
        return -1;
    }
    char s[20];
    int code;
    FILE *ff;
    ff=fopen("output.dat","w");
    if(ff==NULL)
    {
        perror("cannot create file!");
        return -1;
    }
    while(fscanf(f,"%s ",s)==1)
    {
        if((strcmp(s,"AF")==0)||(strcmp(s,"AL")==0)||(strcmp(s,"DE")==0)||(strcmp(s,"PRINTF_F")==0)||(strcmp(s,"PRINT_L")==0))
           {

            fscanf(f,"%d ",&code);
            printf("%s %d\n",s,code);
           }
        else
            printf("%s\n",s);
            if(strcmp(s,"AL")==0)
            addlast(code);
            if(strcmp(s,"AF")==0)
            addfirst(code);
            if(strcmp(s,"DE")==0)
            delete_a_node(code);
            if(strcmp(s,"PRINT_F")==0)
            print_the_first_nodes(ff,code);
            if(strcmp(s,"PRINT_L")==0)
            print_the_last_nodes(ff,code);
            if(strcmp(s,"DF")==0)
            deletefirst();
            if(strcmp(s,"DL")==0)
            deletelast();
            if(strcmp(s,"DOOM_THE_LIST")==0)
            delete_the_list();
            if(strcmp(s,"PRINT_ALL")==0)
            printlist(ff);

    }
    fclose(f);
    return 0;
}
