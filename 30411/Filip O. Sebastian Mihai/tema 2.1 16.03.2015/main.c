#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int code;
    struct node* next;
    struct node* prev;
} NodeT;
struct node *head,*tail;

void addfirst(int code)
{

    if(head==NULL)
    {
        head=(NodeT*)(malloc(sizeof(NodeT*)));
        head->code=code;
        head->next=head->prev=NULL;
        tail=head;
    }
    else
    {
        NodeT* p;
        p=(NodeT*)(malloc(sizeof(NodeT*)));
        p->code=code;
        p->next=head;
        p->prev=NULL;
        //head->prev=p;
        head=p;
    }
}
void addlast(int code)
{
    if(head==NULL)
    {
        head=(NodeT*)(malloc(sizeof(NodeT*)));
        head->code=code;
        head->next=head->prev=NULL;
        tail=head;
    }
    else
    {
        NodeT*p;
        p=(struct node*)malloc(sizeof(struct node));
        p->code=code;
        p->next=NULL;
        p->prev=tail;
        tail->next=p;
        tail=p;

    }
}
void deletefirst()
{
    if (head!=NULL)
    {
        struct node *p;
        p=head;
        head=head->next;
        head->prev=NULL;
        free(p);
    }
}
void deletelast()
{
    if(head!=NULL)
    {
        NodeT* p;
        p=tail->prev;
        free(tail);
        p->next=NULL;
        tail=p;
    }
}

void doom_the_list()
{
    NodeT* p,*q;
    p=head;
    while(p!=NULL)
    {
        q=p->next;
        free(p);
        p=q;
    }
    head=tail=NULL;
}

void printlist(FILE *file)
{
    NodeT*p=head;
    while (p!=NULL)
    {
        fprintf(file,"%d ",p->code);
        p=p->next;
    }
    fprintf(file,"\n");
}
void deletenod(int x)
{
    NodeT*p=head,*q;
    while(p->code!=x)
    {
        p=p->next;
    }
    q=p->prev;
    p=p->next;
    q->next=p;
    p->prev=q;
}
void printleft(int x,FILE *file)
{
    int i=0;
    NodeT* p;
    p=head;
    while(i!=x)
    {
        fprintf(file,"%d ",p->code);
        p=p->next;
        i++;
    }
    fprintf(file,"\n");
}
void printright(int x,FILE *file)
{
    int i=0;
    NodeT* p;
    p=head;
    int n=0;
    while (p!=NULL)
    {
        p=p->next;
        n++;
    }

    p=head;
    while(i!=n-x)
    {
        p=p->next;
        i++;
    }
    while(i!=n)
    {
        fprintf(file,"%d ",p->code);
        p=p->next;
        i++;
    }
     fprintf(file,"\n");
}
int main()
{
    FILE *file,*file2;
    file= fopen("input.dat","r");
    file2=fopen("output.dat","w");
    if (file==NULL)
    {
        perror("Cannot read file");
        return -200;
    }
    char line[1000];
    int number;
    while(fscanf(file,"%s",line)!=EOF)
    {

        printf("\n%s",line);
        if(strcmp(line,"AF")==0)
        {
            fscanf(file,"%s",line);
            number=atoi(line);
            addfirst(number);
        }
        if(strcmp(line,"AL")==0)
        {
            fscanf(file,"%s",line);
            number=atoi(line);
            addlast(number);
        }
        if(strcmp(line,"DF")==0)
        {
            deletefirst();
        }
        if(strcmp(line,"DL")==0)
        {
            deletelast();
        }
        if(strcmp(line,"PRINT_ALL")==0)
        {
            printlist(file2);
        }
        if(strcmp(line,"PRINT_F")==0)
        {
            fscanf(file,"%s",line);
            number=atoi(line);
            printleft(number,file2);
        }
        if(strcmp(line,"PRINT_L")==0)
        {
            fscanf(file,"%s",line);
            number=atoi(line);
            printright(number,file2);
        }
        if(strcmp(line,"DE")==0)
        {
            fscanf(file,"%s",line);
            number=atoi(line);
            deletenod(number);
        }
        if(strcmp(line,"DOOM_THE_LIST")==0)
        {
            doom_the_list();
        }
    }

    fclose(file);

    return 0;
}
