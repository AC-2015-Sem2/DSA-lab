#include "DLL_definition.h"
#include "DLL_methods.h"
#include "DLL_solution.h"
#include <stdlib.h>
#include <stdio.h>

/*
Initialization of sentinel
*/
void ListInit(List** L)
{
    *L = (List*)malloc(sizeof(List));

    (*L)->head = NULL;
    (*L)->tail = NULL;

    (*L)->AddFirst = &AddFirst;
    (*L)->AddLast = &AddLast;
    (*L)->DeleteFirst = &DeleteFirst;
    (*L)->DeleteLast = &DeleteLast;
    (*L)->Anihilate = &Anihilate;
    (*L)->Delete = &Delete;
    (*L)->PrintAll = &PrintAll;
    (*L)->PrintF = &PrintF;
    (*L)->PrintL = &PrintL;
    (*L)->Interpret = &Interpret;
    (*L)->Solve = &Solve;
}

/*
Allocates memory for a new node,
sets the fields and returns the address
*/
Node* CreateNode(void* data)
{
    Node* NewElement = (Node*)malloc(sizeof(Node));
    NewElement->next = NULL;
    NewElement->prev = NULL;
    NewElement->data = data;

    return NewElement;
}

/*
AF

Allocates a new element and links it to head
then moves the head to the new element
*/
void AddFirst(List* L, void* data)
{
    Node* NewElement = CreateNode(data);
    if(L->head == NULL)//if the list is empty create the list
    {
        L->head = NewElement;
        L->tail = NewElement;
    }
    else
    {
        NewElement->next = L->head;
        L->head->prev = NewElement;
        L->head = NewElement;
    }
    //L->length++;//Not required, DLL makes this simpler
}

/*
AL

Allocates a new element and links the tail to it
then moves the tail to the new element
*/
void AddLast(List* L, void* data)
{
    Node* NewElement = CreateNode(data);
    if(L->tail == NULL)//if the list is empty create the list
    {
        L->tail = NewElement;
        L->head = NewElement;
    }
    else
    {
        L->tail->next = NewElement;
        NewElement->prev = L->tail;
        L->tail = NewElement;
    }
    //L->length++;//Not required, DLL makes this simpler
}

/*
DF

Deletes the first element deallocating it
and moves the head one position forward
Deletes the entire list if there is only 1 element
*/
void DeleteFirst(List* L)
{
    if(L->head != NULL)
    {
        if(L->head == L->tail)//if there is only one element in the list nulls tail as well
        {
            free(L->head);
            L->head = NULL;
            L->tail = NULL;
        }
        else
        {
            Node* del = L->head;
            L->head = L->head->next;
            L->head->prev = NULL;
            free(del);
        }
    }
    //if(L->length > 0)//Not required, DLL makes this simpler
        //L->length--;
}

/*
DL

Deletes the last element in the list
moving the tail one position towards the head
Deletes the entire list if there is only 1 element
*/
void DeleteLast(List* L)
{
    if(L->head != NULL)
    {
        if(L->head == L->tail)//single element list
        {
            free(L->head);
            L->head = NULL;
            L->tail = NULL;
        }
        else
        //DLL comes in handy here since we can go one position ti the previous
        //instead of n-1 positions to the next using 2 pointer
        {
            Node* del = L->tail;
            L->tail = L->tail->prev;
            L->tail->next = NULL;
            free(del);
        }
    }
    //if(L->length > 0)//Not required, DLL makes this simpler
        //L->length--;
}

/*
DOOM_THE_LIST

Deallocates all the list,
nulls head and tail
*/
void Anihilate(List* L)
{
    while(L->head != NULL)
    {
        Node* del = L->head;
        L->head = L->head->next;
        free(del);
    }
    L->tail = NULL;
    //L->length = 0;//Not required, DLL makes this simpler
}

/*
DE

Searches for the first occurrence of val in the list,
deallocates it and re-links the list properly
*/
void Delete(List* L, void* data)
{
    Node* current = L->head;
    int found = 0;
    while((current != NULL)&&(found == 0))
    //stops at the end of the list or when finds its target
    {
        if(current->data == data)
        {
            found = 1;
        }
        else
        {
            current = current->next;
        }
    }
    if(found == 1)
    //an element to be destroyed has been found
    {
        if(L->head == L->tail)
        //this implies there is a single element in the list
        {
            L->tail = NULL;
            L->head = NULL;
        }
        else
        {
            //fills the gap
            if(current->prev != NULL)
                current->prev->next = current->next;
            else
                L->head = current->next;
            if(current->next != NULL)
                current->next->prev = current->prev;
            else
                L->tail = current->prev;
        }
        free(current);
    }
    //if(L->length > 0)//Not required, DLL makes this simpler
        //L->length--;
}

/*
PRINT_ALL

Lists all from head to tail in Out
*/
void PrintAll(List* L, FILE* Out)
{
    Node* current = L->head;
    while(current != NULL)
    {
        fprintf(Out, "%d", (int)current->data);
        if(current->next != NULL)
        //no space after the last element in the list
        {
            fprintf(Out, " ");
        }
        current = current->next;
    }
    fprintf(Out, "\n");
}

/*
PRINT_F

Prints the first "count" elements in the list
*/
void PrintF(List* L, FILE* Out, int count)
{
    Node* current = L->head;
    int listPrinted = 0;
    while((current != NULL)&&(listPrinted < count))
    //stops at the end of the list or when count elements have been printed
    {
        fprintf(Out, "%d", (int)current->data);
        if((current->next != NULL)&&(listPrinted + 1 < count))
        //no space after the last one
        {
            fprintf(Out, " ");
        }
        current = current->next;
        listPrinted++;
    }
    fprintf(Out, "\n");
}

/*
PRINT_L

Prints the last "count" elements
no longer as tricky since the DLL update
*/
void PrintL(List* L, FILE* Out, int count)
{
    //go to the n - count element
    Node* current = L->tail;
    for(int i = 0; i < count - 1; i++)//-1 because we start from the tail
    {
        current = current->prev;
    }
    //print the rest of them
    while(current != NULL)
    {
        fprintf(Out, "%d", (int)current->data);
        if(current->next != NULL)
        //no reason for a space after the last
        {
            fprintf(Out, " ");
        }
        current = current->next;
    }
    fprintf(Out, "\n");
}
