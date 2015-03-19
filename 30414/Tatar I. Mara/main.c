#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nod
{
    int data;
    struct Nod *next;
    struct Nod *prev;
}Node;

 typedef struct Sentinel
 {
     Node *head;
     Node *tail;
     int count;
 }sentinel;
 sentinel *s;

 void add_first(int data)
 { Node *newnode;
     if (s->head==NULL)
     {
         s->head=(Node*)malloc(sizeof(Node));
         s->head->data=data;
         s->head->next=NULL;
         s->head->prev=NULL;
         s->head=s->tail;
     }
     else
     {   newnode=(Node*)malloc(sizeof(Node));
         newnode->data=data;
        newnode->next=s->head;
        newnode->prev=NULL;
        s->head->prev=newnode;
        s->head-=newnode;
     }
     }
     void add_last(int data)
    {   Node *newnode;

        if (s->head==NULL)
        {
            s->head=(Node*)malloc(sizeof(Node));
            s->head->data=data;
            s->head->next=NULL;
            s->head->prev=NULL;
            s->head=s->tail;

        }
        else
        {
            newnode=(Node*)malloc(sizeof(Node));
            newnode->data=data;
            newnode->next=NULL;
            newnode->prev=s->tail;
            s->tail->next=newnode;
            s->tail=newnode;
        }
    }

    void delete_first()
    { Node* temp;
        if (s->head==NULL)
            return;
        else if (s->head==s->tail)
        {    free(s->head);
             s->head=NULL;
             s->tail=NULL;
        }
        else
        {
            temp=s->head;
            s->head=s->head->next;
            s->head->prev=NULL;
            free(temp);
        }

    }

 void delete_last()
    { Node* temp;
        if (s->head==NULL)
            return;
        else if (s->head==s->tail)
        {    free(s->head);
             s->head=NULL;
             s->tail=NULL;
        }
        else
        {
            temp=s->tail;
            s->tail=s->tail->prev;
            s->tail->next=NULL;
            free(temp);

        }}
void DOOM_THE_LIST()
{
    Node *temp;
    while (s->head!=NULL)
    { temp=s->head;
    s->head=s->head->next;
    free(temp);
    }
    s->head=NULL;
    s->tail=NULL;
}
void DE_x(int data)
{  Node *temp;
    temp=s->head;
    while (temp!=NULL)
    {
        if (temp->data==data)
        {
                if (temp==s->head)
                    delete_first();
                else if (temp==s->tail)
                    delete_last;
                else
                { temp->prev->next=temp->next;
                  temp->next->prev=temp->prev;
                  free(temp);
                }
          }
        else
            temp=temp->next;
    }
}

void print_all(FILE *f2)
    {
        Node *temp;
        temp=s->head;
        while(temp!=NULL)
        {
             fprintf(f2,"%d",temp->data);
             temp=temp->next;
        }
          fprintf(f2,"\n");
    }

void print_x(FILE *f2,int x)
{Node *temp;
int i;
i=1;
 temp=s->head;
 while ((temp!=NULL)&&(i<=x))
 {
     fprintf(f2,"%d",temp->data);
     temp=temp->next;
     i++;
 }
 fprintf(f2,"\n");
}
void print_last_x(FILE *f2,int  x)
{Node *temp;
int i;
i=1;
 temp=s->tail;
 while ((temp!=NULL)&&(i<=x))
 {
     fprintf(f2,"%d",temp->data);
     temp=temp->prev;
     i++;
 }
 fprintf(f2,"\n");
}

     int main()
     {
    FILE *f1;
    FILE *f2;
    int data;
    f1=fopen("input.txt","r");
    f2=fopen("output.txt","w");

   s=(sentinel*)malloc(sizeof(sentinel));
   s->head=NULL;
   s->tail=NULL;
    f1=fopen("input.txt","r");
    if (f1==NULL) perror("File for reading could not be opened\n");
    f2=fopen("output.txt","w");
    if (f2==NULL) perror("data out file could not be opened\n");
    char *str=(char*)malloc(10*sizeof(char));
    int x;
    while (fscanf(f1,"%s%d",s,&x)!=-1)
    {
        if (strcmp("AF",str)==0) add_first(x);
        if (strcmp("AL",str)==0) add_last(x);
        if (strcmp("DF",str)==0) delete_first();
        if (strcmp("DL",str)==0) delete_last();
        if (strcmp("DOOM_THE_LIST",str)==0) DOOM_THE_LIST();
        if (strcmp("DE",str)==0) DE_x(x);
        if (strcmp("PRINT_ALL",str)==0) print_all(f2);
        if (strcmp("PRINT_F",str)==0) print_x(f2,x);
        if (strcmp("PRINT_L",str)==0) print_last_x(f2,x);
    }
    fclose(f1);
    fclose(f2);
    return 0;
}



