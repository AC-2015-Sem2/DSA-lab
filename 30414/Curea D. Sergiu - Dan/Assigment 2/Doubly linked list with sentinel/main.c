#include <stdio.h>
#include <stdlib.h>

typedef struct st_node
{
    struct st_node* prev;
    int data;
    struct st_node* next;
} node;

typedef struct Sant
{
    node *head;
    node *tail;
    int l;
}ST;
ST* s1;

void PRINT_ALL()
{
    FILE *f;
    f=fopen("text.txt","a");
    node* aux;

    aux=s1->head;
    while (aux!=NULL)
    {
        fprintf(f,"%d ",aux->data);
        aux=aux->next;
    }
    fprintf(f,"\n");
}
void AF(int data)
{
    if (s1->head==NULL)
    {
        s1->head=(node*)malloc(sizeof(node));
        s1->tail=s1->head;
        s1->head->data=data;
        s1->head->next=NULL;
        s1->head->prev=NULL;
        s1->l++;
    }
    else
    {
        node* newNode=(node*)malloc(sizeof(node));
        newNode->data=data;
        newNode->next=s1->head;
        s1->head->prev=newNode;
        s1->head=newNode;
        s1->l++;
    }
}

void DF()
{
    node* *rnode= (node*)malloc(sizeof(node));;
    if (s1->head==NULL)
        return;
    else

    {
        rnode=s1->head;
        s1->l--;
        if (s1->head==s1->tail)
        {
            s1->head=NULL;
            s1->tail=NULL;
            s1->l--;
        }
        else
        {
            s1->head=s1->head->next;
            s1->head->prev=NULL;
            s1->l--;
        }
        rnode=NULL;
    }
}

void DL()
{
    node* *rnode=(node*)malloc(sizeof(node));;
    if (s1->head==NULL)
        return;
    else
    {

        s1->l--;
        rnode=s1->tail;
    }
    if (s1->head==s1->tail)
    {
        s1->head=NULL;
        s1->tail=NULL;
        s1->l--;

    }
    else
    {
        s1->tail=s1->tail->prev;
        s1->tail->next=NULL;
        s1->l--;
    }

    rnode=NULL;
}
void AL(int data)
{
    if (s1->tail==NULL)
    {
        s1->tail=(node*)malloc(sizeof(node));
        s1->tail->data=data;
        s1->tail->next=NULL;
        s1->tail->prev=NULL;
        s1->head=s1->tail;
        s1->l++;
    }
    else
    {
        node* newNode=(node*)malloc(sizeof(node));
        newNode->data=data;
        newNode->next=NULL;
        newNode->prev=s1->tail;
        s1->tail->next=newNode;
        s1->tail=newNode;
        s1->l++;
    }
}
void DE(int x)
{
    node* newNode = (node*)malloc(sizeof(node));
    node* aux = (node*)malloc(sizeof(node));

    if(s1->head->data == x)
    {
        s1->l--;
        DF();
    }
    if(s1->tail->data == x)
    {
        DL();
        s1->l--;
    }
    newNode = s1->head;

    while(newNode->next != NULL)
    {
        aux = newNode->next;
        if(aux->data == x)
        {
            newNode->next = aux->next;
            aux->next->prev=newNode;
            s1->l--;
        }

        newNode = newNode->next;
    }
}
void DOOM_THE_LIST()
{
    node* newNode = (node*)malloc(sizeof(node));
    node* aux = (node*)malloc(sizeof(node));

    newNode = s1->head;

    while(newNode->next != NULL)
    {
        newNode=newNode->next;
        DF();
    }
    DF();
    s1->l=0;
}
void PRINT_F(int data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode=s1->head;
    FILE *f;
    f=fopen("text.txt","a");
    while(data!=0)
    {
        data=data-1;
        fprintf(f,"%d ", newNode->data);
        newNode=newNode->next;

    }
    fprintf(f,"\n");
}
void PRINT_L(int data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode=s1->tail;
    FILE *f;
    f=fopen("text.txt","a");
    while(data!=0)
    {
        data=data-1;
        newNode=newNode->prev;
    }
    newNode=newNode->next;
    while(newNode!=NULL)
    {
        fprintf(f,"%d ", newNode->data);
        newNode=newNode->next;
    }


    fprintf(f,"\n");
}
int main()
{
    FILE *g;
    s1->l=0;
    s1->head=NULL;
    s1->tail=NULL;
    g=fopen("input.txt", "r");
    char cuvant[15];
    int n;
    if (g==NULL)
    {
        printf("Error in opening the file.");
        exit(1);
    }

    while(fscanf(g,"%s",cuvant)>0)
    {
        if (strcmp(cuvant,"AF")==0)
        {
            fscanf(g,"%d",&n);
            AF(n);
        }
        else if (strcmp(cuvant,"AL")==0)
        {
            fscanf(g,"%d",&n);
            AL(n);
        }
        else if (strcmp(cuvant,"DF")==0)
            DF();
        else if(strcmp(cuvant,"DL")==0)
            DL();
        else if(strcmp(cuvant,"DE")==0)
        {
            fscanf(g,"%d",&n);
            DE(n);
        }
        else if(strcmp(cuvant,"PRINT_ALL")==0)
            PRINT_ALL();
        else if(strcmp(cuvant,"PRINT_F")==0)
        {
            fscanf(g,"%d",&n);
            PRINT_F(n);
        }
        else if(strcmp(cuvant,"PRINT_L")==0)
        {
            fscanf(g,"%d",&n);
            PRINT_L(n);
        }
        else if(strcmp(cuvant,"DOOM_THE_LIST")==0)
            DOOM_THE_LIST();
    }
    fclose(g);
    printf("%d",s1->l);
    return 0;
}
/* int main(){
AF(5);
AF(6);
AF(21);
AL(12);
DF();
DL();
DE(3);
DE(6);
AF(2);
AL(200);
PRINT_ALL();
AF(1);
PRINT_F(2);
PRINT_L(3);
DOOM_THE_LIST();
DL();
AF(42);
AL(24);
AF(9);
PRINT_ALL();
PRINT_L(2);
return(0);
} */


