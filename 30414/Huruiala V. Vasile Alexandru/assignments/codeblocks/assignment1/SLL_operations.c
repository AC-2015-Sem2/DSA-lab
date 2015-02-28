/*This contains all the operations(functions) on the list
The double pointer stuff is the only way I managed to
 get away without using any globals
*/
#include<stdio.h>
#include<stdlib.h>
#include "SLL_definition.h"

/*AF
Allocates a new element and links it to head
then moves the head to the new element
*/
void AddFirst(Node** head, Node** tail, int val)
{
    Node* NewElement = (Node*)malloc(sizeof(Node));
    NewElement->value = val;
    if(*head == NULL)//if the list is empty create the list
    {
        NewElement->next = NULL;
        *head = NewElement;
        *tail = *head;
    }
    else
    {
        NewElement->next = *head;
        *head = NewElement;
    }
    return;
}

/*AL
Allocates a new element and links the tail to it
then moves the tail to the new element
*/
void AddLast(Node** head, Node** tail, int val)
{
    Node* NewElement = (Node*)malloc(sizeof(Node));
    NewElement->value = val;
    NewElement->next = NULL;
    if(*tail == NULL)//if empty initialize it
    {
        *tail = NewElement;
        *head = *tail;
    }
    else
    {
        (*tail)->next = NewElement;
        *tail = NewElement;
    }
    return;
}

/*DF
Deletes the first element deallocating it
and moves the head one position forward
Deletes the entire list if there is only 1 element
*/
void DeleteFirst(Node** head, Node** tail)
{
    if(*head == *tail)//if there is only one element in the list nulls tail as well
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        Node* del = *head;
        *head = (*head)->next;
        free(del);
    }
    return;
}

/*DL
Deletes the last element in the list
moving the tail one position towards the head
Deletes the entire list if there is only 1 element
*/
void DeleteLast(Node** head, Node** tail)
{
    if(*head == *tail)//single element list
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
    }
    else
    //we must get to the second last element(the new tail)
    //only then can we delete the tail
    {
        Node* del = *head;//one position behind ndel, it will become the new tail
        Node* ndel = del->next;
        while(ndel->next != NULL)
        {
            del = del->next;
            ndel = del->next;
        }

        //at this point, ndel point to the last element
        //and del at the second lat
        *tail = del;
        (*tail)->next = NULL;

        free(ndel);
    }
    return;
}

/*DOOM_THE_LIST
Deallocates all the list,
nulls head and tail
*/
void Anihilate(Node** head, Node** tail)
{
    while(*head != NULL)
    {
        Node* del = *head;
        *head = (*head)->next;
        free(del);
    }
    *tail = NULL;
    return;
}

/*DE
Searches for the first occurrence of val in the list
deallocates it and relinks the list properly
*/
void Delete(Node** head, Node** tail, int val)
{
    Node* current = *head;
    Node* prev = NULL;
    int found = 0;
    while((current != NULL)&&(found == 0))
    //stops at the end of the list or when finds its target
    {
        if(current->value != val)
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
        if(*head == *tail)
        //this implies there is a single element in the list
        //whose value matched for destruction
        {
            *tail = NULL;
            *head = NULL;
        }
        else if(current == *head)
        //the found key is the first element of the list
        //it is an exception since prev is null here
        {
            *head = (*head)->next;
        }
        else
        {
            prev->next = current->next;//fills the gap
            if(current == *tail)//if it is the last the tail is also relocated
                *tail = prev;
        }
        free(current);
    }
    return;
}

/*PRINT_ALL
Lists all from head to tail in Out
*/
void PrintAll(FILE* Out, Node* head)
{
    Node* current = head;
    while(current != NULL)
    {
        fprintf(Out, "%d", current->value);
        if(current->next != NULL)
        //no space after the last element in the list
        {
            fprintf(Out, " ");
        }
        current = current->next;
    }
    fprintf(Out, "\n");
    return;
}

/*PRINT_F
Prints the first "count" elements in the list
*/
void PrintF(FILE* Out, Node* head, int count)
{
    Node* current = head;
    int listPrinted = 0;
    while((current != NULL)&&(listPrinted < count))
    //stops at the end of the list or when count elements have been printed
    {
        fprintf(Out, "%d", current->value);
        if((current->next != NULL)&&(listPrinted + 1 < count))
        //no space after the last one
        {
            fprintf(Out, " ");
        }
        current = current->next;
        listPrinted++;
    }
    fprintf(Out, "\n");
    return;
}

/*PRINT_L
Prints the last "count" elements
this is tricky because the length is needed if you
do not store the elements somewhere else
*/
void PrintL(FILE* Out, Node* head, int count)
{
    //Find the number of elements
    Node* current = head;
    int elementCount = 0;
    while(current != NULL)
    {
        current = current->next;
        elementCount++;
    }

    //go to element (elementCount - count)
    //to print the last count elements
    current = head;
    int i;
    for(i = 0; i < elementCount - count; i++)
    {
        current = current->next;
    }

    //finally we can print them
    //knowing that there are "count" elements left
    //(or all if count > elementCount)
    while(current != NULL)
    {
        fprintf(Out, "%d", current->value);
        if(current->next != NULL)
        //no reason for a space after the last
        {
            fprintf(Out, " ");
        }
        current = current->next;
    }
    fprintf(Out, "\n");
    return;
}
