#include <stdio.h>
#include <stdlib.h>

typedef struct st_node
{
    int data;
    struct st_node* next;
} node;
node *head, *tail;

void PRINT_ALL()
{
    FILE *f;
    f=fopen("text.txt","a");
    node* aux=head;
    while (aux!=NULL)
    {
        fprintf(f,"%d ",aux->data);
        aux=aux->next;
    }
    fprintf(f,"\n");
}

void AF(int data)
{
    if (head==NULL)
    {
        head=(node*)malloc(sizeof(node));
        tail=head;
        head->data=data;
        head->next=NULL;
    }
    else
    {
        node* newNode=(node*)malloc(sizeof(node));
        newNode->data=data;
        newNode->next=head;
        head=newNode;
    }
}


void DF()
{
    node* *rnode= (node*)malloc(sizeof(node));;
    if (head==NULL)
        return;
    else

        rnode=head;
    if (head==tail)
    {
        head=NULL;
        tail=NULL;
    }
    else
    {
        head=head->next;
    }
    rnode=NULL;
}



void DL()
{
    node* *rnode= (node*)malloc(sizeof(node));;
    if (head==NULL)
        return;
    else

        rnode=tail;
    if (head==tail)
    {
        head=NULL;
        tail=NULL;
    }
    else
    {
        node* *ptotail=head;
        while (head->next !=tail)
            head=head->next;
        tail=head;
        tail->next=NULL;
        head=ptotail;
    }
    rnode=NULL;
}




void AL(int data)
{
    if (tail==NULL)
    {
        tail=(node*)malloc(sizeof(node));
        head=tail;
        tail->data=data;
        tail->next=NULL;
    }
    else
    {
        node* newNode=(node*)malloc(sizeof(node));
        newNode->data=data;
        newNode->next=NULL;
        tail->next=newNode;
        tail=newNode;
    }
}

void DE(int x)
{
    node* newNode = (node*)malloc(sizeof(node));
    node* aux = (node*)malloc(sizeof(node));

    if(head->data == x)
        DF();
    if(tail->data == x)
        DL();

    newNode = head;

    while(newNode->next != NULL)
    {
        aux = newNode->next;
        if(aux->data == x)
        {
            newNode->next = aux->next;
        }

        newNode = newNode->next;
    }
}
void DOOM_THE_LIST()
{
    node* newNode = (node*)malloc(sizeof(node));
    node* aux = (node*)malloc(sizeof(node));

    newNode = head;

    while(newNode->next != NULL)
    {
        newNode=newNode->next;
        DF();
    }
    DF();
}
void PRINT_F(int data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode=head;
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
    newNode=head;
    FILE *f;
    f=fopen("text.txt","a");
    int c,b,a=0;
    b=0;
    c=0;
    while(newNode!=NULL)
    {
        a=a+1;
        newNode=newNode->next;
    }
    b=a-data;
    c=a;
    a=0;
    newNode=head;
    while(a!=c)
    {
        a=a+1;
        if(a>b) fprintf(f,"%d ",newNode->data);
        newNode=newNode->next;
    }
    fprintf(f,"\n");
}


 int main()
{
    FILE *g;
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
