#include <stdio.h>
#include <stdlib.h>

typedef struct NodeT{
        int code;
        struct NodeT* next;
    }NodeT;


int stringCompare(char[],char[]);

NodeT *head, *tail;
FILE *pf,*pff;
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
        head->next=tail;
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

void delFirst()
{
    NodeT *aux;
    if(head!=NULL)
    {
        aux=head ;
        head=head->next ;
        free(aux);
        if(head==NULL)
            tail=NULL;
    }
}
void delLast()
{
    NodeT *aux,*aux2;
    aux2 = NULL;
    aux=head;
    if(aux!=NULL)
    {
        while (aux!=tail)
        {
            aux2=aux;
            aux=aux->next ;
        }
        if (aux==head)
            head= tail=NULL;
        else
            aux2->next=NULL;
        tail=aux2;
    }
    free(aux);
}

void delElem(int code)
{
    NodeT *aux, *aux2;
    aux2=NULL;
    aux=head;
    while (aux!=NULL)
    {
        if (aux->code==code)
            break;
        aux2=aux;
        aux=aux->next ;
    }
    if (aux!=NULL)
    {
        if (aux==head)
        {
            head=head->next ;
            free(aux);
            if (head==NULL)
                tail=NULL;
        }
        else
        {
            aux2->next=aux->next ;
            if (aux==tail)
                tail=aux2;
            free(aux);
        }
    }
}

void delList()
{
    NodeT *aux;
    while(head!=NULL)
    {
        aux=head;
        head=head->next ;
        free(aux);
    }
    tail=NULL;
}
void printlist()
{
    NodeT* aux=head;
    while(aux!=NULL)
    {
        fprintf(pff, "%d ",aux->code);
        aux=aux->next;
    }
    fprintf(pff,"\n");
}

void printF(int x)
{
    NodeT* aux=head;
    int i;
    for(i=0; i<x; i++)
    {
        fprintf(pff, "%d ",aux->code);
        aux=aux->next;
    }
    fprintf(pff,"\n");

}

void printL(int x)
{
    NodeT* aux=head;
    int n=0,i;
    while(aux!=NULL)
    {
        n++;
        aux=aux->next;
    }
    aux=head;
    for(i=1;i<=n-x;i++)
        aux=aux->next;

    while(aux!=NULL)
        {
            fprintf(pff,"%d ",aux->code);
            aux=aux->next;
        }
    fprintf(pff,"\n");
}
int main()
{

    pf=fopen("input.dat","r");
    pff=fopen("output.dat","w");


    char command[2];
    char useless[11];
    int x,c;
    char ch = getc(pf);
    char AF[2] = "AF", AL[2] = "AL", DF[2] = "DF", DL[2] = "DL", DO[2] = "DO", DE[2] = "DE",PR[2] = "PR";


    while(ch != EOF)
    {
        command[0] = ch;
        fscanf(pf,"%c",&command[1]);

        c = stringCompare(command,AF);
        if(c == 1)
        {
            fscanf(pf,"%d",&x);
            addFirst(x);

        }
        c = stringCompare(command,AL);
        if(c == 1)
        {
            fscanf(pf,"%d",&x);
            addLast(x);

        }
        c = stringCompare(command,DF);
        if(c == 1)
          {
              delFirst();

          }

        c = stringCompare(command,DL);
        if(c == 1)
          {
              delLast();

          }
        c = stringCompare(command,DO);
        if(c == 1)
            {
                fscanf(pf,"%s",useless);
                delList();

            }
        c = stringCompare(command,DE);
        if(c == 1)
        {
            fscanf(pf,"%d",&x);
            delElem(x);
        }
        c = stringCompare(command,PR);
        if(c == 1)
        {
            fscanf(pf,"%s",useless);
            if(useless[4]=='A')
                printlist();
            if(useless[4]=='F')
            {
                fscanf(pf,"%d",&x);
                printF(x);
            }
            if(useless[4]=='L')
            {
                fscanf(pf,"%d",&x);
                printL(x);
            }
        }



        ch = getc(pf);
        ch = getc(pf);

    }

    fclose(pf);
    fclose(pff);
    return 0;
}

int stringCompare(char str1[],char str2[])
{
    int i=0,flag=0;

    while(str1[i]!='\0' && str2[i]!='\0' && i<2)
    {
         if(str1[i]!=str2[i])
         {
             flag=1;
             break;
         }
         i++;
    }

    if (flag==0)
         return 1;
    else
         return 0;

}
