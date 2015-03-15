#include <stdio.h>
#include <stdlib.h>
typedef struct nod
{
    int data;
    struct nod *next;
    struct nod *prev;
} node;
typedef struct
{
    int length;
    node *head,*tail;
} sentinel;
sentinel * list;

void addFirst(int x)
{
    if (list->head==NULL) // Verify if the list is empty.
    {

        list->head=(node *)malloc(sizeof(node));
        list->head->data=x;
        list->head->next=NULL;
        list->head->prev=NULL;
        list->tail=list->head;// We will have a single node in the list, so the head and the tail will coincide.
    }
    else
    {
        node *newnode=(node*)malloc(sizeof(node)); // if the list is not empty,we create a new node.
        newnode->data=x;
        newnode->next=list->head;
        list->head->prev=newnode;
        list->head=newnode;
    }
    list->length++;
}

void addLast(int x)
{
    if (list->head==NULL)// Verify if the list is empty.
    {
        list->head=(node *)malloc(sizeof(node));
        list->head->next=NULL;
        list->head->prev=NULL;
        list->head->data=x;
        list->tail=list->head;// The list created here will have a single node, so the tail and the head will coincide.
    }
    else
    {
        node *newnode=(node *)malloc(sizeof(node));// If the list is not empty we create a new node.
        newnode->data=x;
        newnode->next=NULL;
        newnode->prev=list->tail;
        list->tail->next=newnode;
        list->tail=newnode;//We set the new node as a tail.
    }
    list->length++;
}

void deleteFirst()
{
    if (list->length>0)
    {
        if (list->head==list->tail)
        {
            free(list->head);
            list->head=NULL;
            list->tail=NULL;
        }
        else
        {
            node *p=list->head;
            list->head=list->head->next;
            list->head->prev=NULL;
            free(p);

        }
        list->length--;
    }
}

void deleteLast()
{
    if (list->length>0)
    {
        if (list->head==list->tail)
        {
            free(list->head);
            list->head=NULL;
            list->tail=NULL;
        }
        else
        {
            node *p=list->tail;
            list->tail=list->tail->prev;
            list->tail->next=NULL;
            free(p);

        }
        list->length--;
    }
}

void deleteElementX(int x)
{
    node *p=list->head;
    if (p->data==x) // If x is equal with the data in the first node we use the function deletefirst.
    {
        deleteFirst();
    }
    else
    {
        while  ((p!=NULL)&& (p!=list->tail))
        {
            p=p->next;
        }
        if (p->data==x)
        {
            if (p==list->tail)// if it coincide with the tail we use deleteLast.
                deleteLast();
            else
            {
                p->next->prev=p->prev;
                p->prev->next=p->next; // We reassemble the list.
                free(p);
                list->length--;
            }
        }
    }
}

void doomTheList() //Deletes the hole list.
{
    node *p;
    while (list->head!=list->tail)
    {
        p=list->head;
        list->head=list->head->next;
        free(p);
    }
    free(list->tail);
    list->tail=NULL;
    list->head=NULL;
    list->length=0;
}

void printAll(FILE *g)
{
    node *p=list->head;
    while (p!=NULL)
    {
        fprintf(g,"%d ",p->data);
        p=p->next;
    }
    fprintf(g," \n");
}

void printFirstX(FILE *g,int x)
{
    node *p=list->head;
    while ((p!=NULL) && (x>0))
    {
        fprintf(g,"%d ",p->data);
        p=p->next;
        x--;
    }
    fprintf(g,"\n");
}

void printLastX(FILE *g,int x)
{
    node *p=list->tail;
    while ((p!=list->head) && (x>1))
    {
        p=p->prev;
        x--;
    }
    while (p!=NULL)
    {
        fprintf(g,"%d ",p->data);
        p=p->next;

    }
    fprintf(g,"\n");
}
void initializeList()
{
    list=(sentinel*)malloc(sizeof(sentinel));
    list->head=NULL;
    list->tail=NULL;
    list->length=0;
}


