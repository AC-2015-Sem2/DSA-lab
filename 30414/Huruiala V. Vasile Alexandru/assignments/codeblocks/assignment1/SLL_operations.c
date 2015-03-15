/*This contains all the operations(functions) on the list
The double pointer stuff is the only way I managed to
 get away without using any globals
*/
#include<stdio.h>
#include<stdlib.h>
#include "SLL_definition.h"
#include "SLL_operations.h"
#include "SLL_interpret.h"

/*
Initialization of the object-like structure
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
}

/*
Allocates memory for a new node
returns the address
*/
Node* CreateNode(void* data)
{
    Node* NewElement = (Node*)malloc(sizeof(Node));
    NewElement->next = NULL;
    NewElement->data = data;

    return NewElement;
}

/*AF
Allocates a new element and links it to head
then moves the head to the new element
*/
void AddFirst(List* L, void* data)
{
    Node* NewElement = CreateNode(data);
    if(L->head == NULL)//if the list is empty create the list
    {
        L->head = NewElement;
        L->tail = L->head;
    }
    else
    {
        NewElement->next = L->head;
        L->head = NewElement;
    }
    L->length++;
}

/*AL
Allocates a new element and links the tail to it
then moves the tail to the new element
*/
void AddLast(List* L, void* data)
{
    Node* NewElement = CreateNode(data);
    if(L->tail == NULL)//if empty initialize it
    {
        L->tail = NewElement;
        L->head = L->tail;
    }
    else
    {
        L->tail->next = NewElement;
        L->tail = NewElement;
    }
    L->length++;
}

/*DF
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
            free(del);
        }
    }
    if(L->length > 0)
        L->length--;
}

/*DL
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
        //we must get to the second last element(the new tail)
        //only then can we delete the tail
        {
            Node* del = L->head;//one position behind ndel, it will become the new tail
            Node* ndel = del->next;
            while(ndel->next != NULL)
            {
                del = del->next;
                ndel = del->next;
            }

            //at this point, ndel point to the last element
            //and del at the second lat
            L->tail = del;
            L->tail->next = NULL;

            free(ndel);
        }
    }
    if(L->length > 0)
        L->length--;
}

/*DOOM_THE_LIST
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
    L->length = 0;
}

/*DE
Searches for the first occurrence of val in the list
deallocates it and relinks the list properly
*/
void Delete(List* L, void* data)
{
    Node* current = L->head;
    Node* prev = NULL;
    int found = 0;
    while((current != NULL)&&(found == 0))
    //stops at the end of the list or when finds its target
    {
        if(current->data != data)
        {
            prev = current;
            current = current->next;
        }
        else
        {
            found = 1;
        }
    }
    if(found == 1)
    //an element to be destroyed has been found
    {
        if(L->head == L->tail)
        //this implies there is a single element in the list
        //whose value matched for destruction
        {
            L->tail = NULL;
            L->head = NULL;
        }
        else if(current == L->head)
        //the found key is the first element of the list
        //it is an exception since prev is null here
        {
            L->head = L->head->next;
        }
        else
        {
            prev->next = current->next;//fills the gap
            if(current == L->tail)//if it is the last the tail is also relocated
                L->tail = prev;
        }
        free(current);
    }
    if(L->length > 0)
        L->length--;
}

/*PRINT_ALL
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

/*PRINT_F
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

/*PRINT_L
Prints the last "count" elements
this is tricky because the length is needed if you
do not store the elements somewhere else
*/
void PrintL(List* L, FILE* Out, int count)
{
    //go to element (elementCount - count)
    //to print the last count elements
    Node* current = L->head;
    int i;
    for(i = 0; i < L->length - count; i++)
    {
        current = current->next;
    }

    //finally we can print them
    //knowing that there are "count" elements left
    //(or all if count > elementCount)
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
