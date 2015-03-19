#include <stdlib.h>
#include <stdio.h>

typedef struct sentinel
{
    struct node *head, *tail;
} sentinel;

typedef struct node
{
    int data;
    struct node *next, *prev;
} node;

sentinel *sent;

void AL(int data)
{
    node *a;
    a=(node*)malloc(sizeof(node));
    a->prev=sent->tail;
    a->data=data;
    sent->tail->next=a;
    a->next=NULL;
    sent->tail=a;
}

void AF(int data)
{
    node *a;
    if (sent->head==NULL)
    {
        sent->head=(node*)malloc(sizeof(node));
        sent->tail=sent->head;
        sent->head->data=data;
        sent->head->prev=NULL;
        sent->head->next=NULL;
    }
    else
    {
        a=(node*)malloc(sizeof(node));
        a->data=data;
        a->prev=NULL;
        a->next=sent->head;
        sent->head->prev=a;
        sent->head=a;
    }
}

void DF()
{
    if(sent->head==sent->tail)
    {
        sent->head=NULL;
        sent->tail=NULL;
    }
    else
    {
        node* a;
        a=sent->head;
        sent->head=sent->head->next;
        sent->head->prev=NULL;
        free(a);
    }
}

void DL()
{
    if(sent->head==sent->tail)
    {
        sent->head=NULL;
        sent->tail=NULL;
    }
    else
    {
        node* a;
        a=sent->tail;
        sent->tail=sent->tail->prev;
        sent->tail->next=NULL;
        free(a);
    }
}

void DOOM()
{
    node* a;   node* b;
    a=sent->head;
    b=a;
    while(a!= NULL)
    {
        a=a->next;
        free(b);
        b=a;
    }
    sent->head=NULL;
    sent->tail=NULL;

}

void DELX(int x)
{
    node *a;
    if(sent->head->data==x)
        DF();
    else
    {
        a=sent->head;
        while((a->data!=x) && (a!=sent->tail))
            a=a->next;
        if (a!=sent->tail)
        {
            a->prev->next=a->next;
            a->next->prev=a->prev;
            free(a);
        }
        else if(sent->tail->data==x)
        {
            a=sent->tail;
            sent->tail=sent->tail->prev;
            sent->tail->next=NULL;
            a=NULL;
            free(a);
        }
    }
}

void PrALL()
{
    node* a=sent->head;
    FILE* f=fopen("output.dat", "a");
    while(a!= NULL)
    {
        fprintf(f, "%d ", a->data);
        a=a->next;
    }
    fprintf(f, "\n");
    fclose(f);

}

void PrFx(int x)
{
        int c=1;
    node* a=sent->head;
    FILE* f=fopen("output.dat", "a");
    while(a!=NULL && c<=x)
    {
        fprintf(f, "%d ", a->data);
        a=a->next;
        c++;
    }
    fprintf(f, "\n");
    fclose(f);

}

void PrLx(int x)
{
        int c=0, n=0;
    node* a=sent->tail;
    FILE* f=fopen("output.dat", "a");
    while(a!=NULL)
    {
        n++;
        a=a->prev;
    }
    while (a!=NULL)
    fprintf(f, "\n");
    fclose(f);

}
int main()
{
    FILE* g=fopen("input.dat", "r");

    char t[20];
    int value;
    sent=(sentinel*)malloc(sizeof(sentinel));
    sent->head=NULL;
    sent->tail=NULL;

    while(fscanf(g, "%s", &t)==1)
    {
        if(strcmp(t, "AF")==0)
        {
            fscanf(g, "%d", &value);
            AF(value);
        }
        else if(strcmp(t, "AL")==0)
        {
            fscanf(g, "%d", &value);
            AL(value);
        }
        else if(strcmp(t, "DF")==0)
            DF();
        else if(strcmp(t, "DL")==0)
            DL();
        else if(strcmp(t, "DOOM_THE_LIST")==0)
            DOOM();
        else if(strcmp(t, "DE")==0)
        {
            fscanf(g, "%d", &value);
            DELX(value);
        }
        else if(strcmp(t, "PRINT_ALL")==0)
            PrALL();
        else if(strcmp(t, "PRINT_F")==0)
        {
            fscanf(g, "%d", &value);
            PrFx(value);
        }
        else if(strcmp(t, "PRINT_L")==0)
        {
            fscanf(g, "%d", &value);
            PrLx(value);
        }
    }

    fclose(g);
    return 0;
}


