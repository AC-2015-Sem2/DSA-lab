#include "SLL_definition.h"
#include<stdlib.h>
#include<string.h>

void addLinkArmy(Army** head, Army** tail, int hp)
{
    Army* New = (Army*)malloc(sizeof(Army));
    New->hitpoints = hp;
    New->next = NULL;
    if(*head == NULL)
    {
        *head = New;
        *tail = New;
    }
    else
    {
        (*tail)->next = New;
        *tail = New;
    }
}

void removeLinkArmy(Army** head, Army** tail)
{
    if(*head == *tail)
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        Army* del = *head;
        *head = (*head)->next;
        free(del);
    }
}

void setHpArmy(Army* node, int newHp)
{
    node->hitpoints = newHp;
}

void addLinkCountry(Country** head, Country** tail, char* name)
{
    Country* New = (Country*)malloc(sizeof(Country));//New element
    char* cname = (char*)malloc(strlen(name));//Must allocate for the name
    strcpy(cname, name);//Put the string in the new allocated memory
    New->cname = cname;//Give it the pointer to that string
    New->headArmy = NULL;
    New->tailArmy = NULL;
    New->nextCountry = NULL;
    if(*head == NULL)
    {
        *head = New;
        *tail = New;
    }
    else
    {
        (*tail)->nextCountry = New;
        *tail = New;
        //and now to make it circular
        (*tail)->nextCountry = *head;
    }
}
