#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <stdbool.h>

typedef struct node
{
    char name[30];
    int time;
    int money;
    struct node *next;
} node;
node *head;
FILE *f;
FILE *g;

void queue(char n[30],int r,int s)
{
    if(head==NULL)
    {
        head=(node*)malloc(sizeof(node));
        strcpy(head->name,n);
        head->time=s;
        head->money=r;
        head->next=NULL;
    }
    else
    {
        node *aux;
        node *temp=head;
        aux=(node*)malloc(sizeof(node));
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=aux;
        strcpy(aux->name,n);
        aux->time=s;
        aux->money=r;
        aux->next=NULL;
    }
}

void cashier(int x)
{
    node *temp=head;
    int sec=0;
    int mon=0;
    while(temp!=NULL)
    {
        if(temp->time+sec<=x)
        {
            sec=sec+temp->time;
            mon=mon+temp->money;
        }
        else
        {
            break;
        }
        temp=temp->next;
    }
    fprintf(f,"After %d seconds: %d\n",x,mon);
}

bool isNumeric(const char *str)
{
    while(*str != '\0')
    {
        if(*str < '0' || *str > '9')
            return false;
        str++;
    }
    return true;
}

void read()
{
    char line[100];
    int a[100],n=0;
    int money;
    int time;
    g=fopen("input.dat","r");
    if(g==NULL)
    {
        printf("Error! Could not open file!\n");
    }
    else
    {
        while(fscanf(g,"%s",line)!=EOF)
        {

            if(isNumeric(line)==true)
            {
                a[n]=atoi(line);
                n++;
            }
            else
            {
                fscanf(g,"%d",&money);
                fscanf(g,"%d",&time);
                queue(line,money,time);
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        cashier(a[i]);
    }
}

int main()
{
    f=fopen("output.dat","w");
    head=NULL;
    read();
    return 0;
}
