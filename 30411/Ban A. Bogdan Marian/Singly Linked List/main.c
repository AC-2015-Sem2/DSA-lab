#include <stdio.h>
#include <stdlib.h>

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
    else if (tail==NULL)
    {
        NodeT* p=(NodeT*)malloc(sizeof(NodeT));
        p->code=code;
        p->next=NULL;
        tail=p;
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

NodeT* find(int x)
{
    NodeT* aux;
    aux=head;
    while(aux!=NULL&&aux->code!=x)
    {
        aux=aux->next;
    }
    return aux;

}


void printList()
{
    NodeT* aux=head;
    while(aux!=NULL)
    {
        printf("%d ",aux->code);
        aux=aux->next;
    }
}

void deleteFirst()
{
    NodeT* aux;
    aux=head;
    head=head->next;
    free(aux);
}

void deleteLast()
{
    NodeT* aux;
    if (head!=NULL)
    {
    aux=head;
    while(aux->next!=NULL)
    {
        aux=aux->next;
    }
    free(tail);
    aux->next=NULL;
}
}

void DOOM_THE_LIST()
{
    NodeT* aux,*p;
    aux=head;
    while (aux!=NULL)
    {
        p=aux;
        aux=aux->next;
        free(p);
    }
    head=NULL;
    tail=NULL;
}

void delX(int x)
{
    NodeT* aux,*p;
    aux=head;
    while(aux->next!=NULL&&aux->code!=x)
    {
        p=aux;
        aux=aux->next;
    }
    if (aux!=NULL)
    {
        if (aux==head)
        {
            deleteFirst();
            if (head==NULL) tail=NULL;
        }
        else
        {
            p->next=aux->next;
            if ( aux==tail )
            {
                deleteLast();
            }
            else
            {
                free(aux);
            }
        }
    }
}

void printF(FILE *pf,int x)
{
    NodeT* aux;
    int nr=0;
    aux=head;
    while(aux!=NULL)
    {
        if(nr==x)
        {
            break;
        }
        printf("%d ",aux->code);
        aux=aux->next;
        nr++;
    }
}

void printL(FILE *pf,int x)
{
    NodeT* aux;
    int nr=0;
    int l;
    int p=0;
    aux=head;
    if(aux!=NULL)
    {
        while(aux!=NULL)
        {
            aux=aux->next;
            nr++;
        }
        if(x>=nr)
        {
            printList();
        }
        else
        {
            l=nr-x;
            aux=head;
            while (p!=l)
            {
                aux=aux->next;
                p++;
            }
        }
    }
}

int main()
{
    FILE *pf;
    char s[100];
    int x;
    pf=fopen("input.txt","r");
    if(pf==NULL)
    {
        perror("Cannot open file");
    }
    FILE *fp;
    fp=fopen("output.txt","w");
    if(fp==NULL)
    {
        perror("Cannot open file");
    }
    fseek(pf,0,SEEK_SET);
    while (fscanf(pf,"%s",s)==1)
    {
        if(strcmp(s,"AF")==0)
        {
            fscanf(pf," %d",&x);
            addFirst(x);
        }
        if(strcmp(s,"AL")==0)
        {
            fscanf(pf," %d",&x);
            addLast(x);
        }
        if(strcmp(s,"DF")==0)
        {
            deleteFirst();
        }
        if(strcmp(s,"DL")==0)
        {
            deleteLast();
        }
        if(strcmp(s,"DOOM_THE_LIST")==0)
        {
            DOOM_THE_LIST();
        }
        if(strcmp(s,"DE")==0)
        {
            fscanf(pf," %d",&x);
            delX(x);
        }
        if(strcmp(s,"PRINT_ALL")==0)
        {
            printList(fp);
        }
        if(strcmp(s,"PRINT_F")==0)
        {
            fscanf(pf," %d",&x);
            printF(fp,x);
        }
        if(strcmp(s,"PRINT_L")==0)
        {
            fscanf(pf," %d",&x);
            printL(fp,x);
        }
    }

//addLast(5);
//addLast(6);
//addLast(7);
//printList();
//NodeT* p=find(6);
//deleteFirst();
//printList();
//deleteLast();
//printList();
//printf("%d",p->code);
//DOOM_THE_LIST();
//printList();
//delX(7);
//printList();
//printF(2);
//printL(1);
fclose(pf);
fclose(fp);
return 0;
}
