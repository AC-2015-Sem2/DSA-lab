#include <stdlib.h>
#include <stdio.h>

typedef struct nod
{
    int data;
    struct nod *next;
} node;
node *head,*tail;

void addFirst(int x)
{
    if (head==NULL) // Verify if the list is empty.
    {
        head=(node *)malloc(sizeof(node));
        head->data=x;
        head->next=NULL;
        tail=head;// We will have a single node in the list, so the head and the tail will coincide.
    }
    else
    {
        node *newnode=(node*)malloc(sizeof(node)); // if the list is not empty,we create a new node.
        newnode->data=x;
        newnode->next=head;//  Links the newnode in front of our list.
        head=newnode;// Sets the new node as the head of our list.
    }
}

void addLast(int x)
{
    if (head==NULL)// Verify if the list is empty.
    {
        head=(node *)malloc(sizeof(node));
        head->next=NULL;
        head->data=x;
        tail=head;// The list created here will have a single node, so the tail and the head will coincide.
    }
    else
    {
        node *newnode=(node *)malloc(sizeof(node));// If the list is not empty we create a new node.
        newnode->data=x;
        tail->next=newnode; // We link the node at the back of the list.
        newnode->next=NULL;
        tail=newnode; //We set the new node as a tail.
    }
}

void deleteFirst()
{
    if (head!=NULL)// Verify that the list is not empty.
    {
        node *first=head;// Creates a copy of the head.
        head=head->next;// Move the head to the second node.
        free(first);// Deletes the first node.
        if (head==NULL)
            tail=NULL; // if the list has only one element,the tail should be NULL as well.
    }
}

void deleteLast()
{
    if (head!=NULL) // Verify that the list is not empty.
    {
        if (head==tail) // single element list.
        {
            free(head);
            head=NULL;
            tail=NULL;
        }
        else
        {
            node *p=head;
            while (p->next!=tail)// We traverse the list till the last but one node.
                p=p->next;
            tail=p;// Set it as the new tail.
            tail->next=NULL;
            free(p->next);
        }
    }
}

void doomTheList() //Deletes the hole list.
{
    node *p;
    while (head!=NULL)
    {
        p=head;
        head=head->next;
        free(p);
    }
    tail=NULL;
}

void deleteElementX(int x)
{
    node *p=head;
    if (p->data==x) // If x is equal with the data in the first node we use the function deletefirst.
        deleteFirst();
    else
    {
        node *q=p->next; // we create a copy that goes one step forward.
        while ((q->data!=x)&&(q!=tail)) // traverse the list until we find x or until we reach the tail.
        {
            q=q->next;
            p=p->next;
        }

        if (q->data==x)
        {
            if (q==tail)// if it coincide with the tail we use deleteLast.
                deleteLast();
            else
            {
                p->next=q->next; // We reassemble the list.
                free(q);
            }
        }
    }
}

void printAll(FILE *g)
{
    node *p=head;
    while (p!=NULL)
    {
        fprintf(g,"%d ",p->data);
        p=p->next;
    }
    fprintf(g,"\n");
}

void printFirstX(FILE *g,int x)
{
    node *p=head;
    int nr=0;// Variable to count the number of printed elements.
    while ((p!=NULL) && (nr<x))
    {
        fprintf(g,"%d ",p->data);
        p=p->next;
        nr++;
    }
    fprintf(g,"\n");
}

void printLastX(FILE *g,int x)
{
    int i;
    node *p=head;
    int nr=0; // Variable to count the number of elements of the list.
    while (p!=NULL) // Find the number of elements.
    {
        nr++;
        p=p->next;
    }
    p=head;
    for (i=1; i<=nr; i++) // Traverse the list and prints the last x elements.
    {
        if (i>=nr-x+1) fprintf(g,"%d ",p->data);
        p=p->next;
    }
    fprintf(g,"\n");
}



