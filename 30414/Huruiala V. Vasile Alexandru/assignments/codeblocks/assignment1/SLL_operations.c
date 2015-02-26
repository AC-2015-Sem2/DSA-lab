/*This contains all the operations(functions) on the list
The double pointer stuff is the only way I managed to
get away without using any globals
*/
#include<stdio.h>
#include<stdlib.h>
#include "SLL_definition.h"

/*AF
allocates a new element and links it to head
then moves the head to the new element
*/
void AddFirst(Node** head, Node** tail, int val)
{
    Node* NewElement = (Node*)malloc(sizeof(Node));
    NewElement->value = val;
    if(*head == NULL)//if the list is empty
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
allocates a new element and links the tail to it
then moves the tail to the new element
*/
void AddLast(Node** head, Node** tail, int val)
{
    Node* NewElement = (Node*)malloc(sizeof(Node));
    NewElement->value = val;
    NewElement->next = NULL;
    if(*tail == NULL)//if empty
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
deletes the first element deallocating it
and moves the head one position forward
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
        Node* del = *head;
        Node* ndel = del->next;
        while(ndel->next != NULL)//second last element condition
        {
            del = del->next;
            ndel = del->next;
        }

        *tail = del;
        (*tail)->next = NULL;

        free(ndel);
    }
    return;
}

/*DOOM_THE_LIST
deallocates all the list
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
searches for the first occurrence of val in the list
deallocates it and relinks the list properly
*/
void Delete(Node** head, Node** tail, int val)
{
    Node* current = *head;
    Node* prev = NULL;
    while((current != NULL)&&(current->value != val))
    //stops at the end of the list or when finds its target
    {
        prev = current;
        current = current->next;
    }
    if(current != NULL)
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
            if(current == *tail)
                *tail = prev;
        }
        free(current);
    }
    return ;
}

/*PRINT_ALL
lists all from head to tail in Out
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
prints the first "count" elements in the list
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
prints the last "count" elements
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
