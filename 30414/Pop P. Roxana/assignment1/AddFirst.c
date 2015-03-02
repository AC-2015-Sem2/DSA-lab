#include <stdlib.h>
#include "definingStructure.h"


void addFirst(int x)
{
    //Verify if the list is empty
    if (head==NULL)
    {
        //Creates bew node and sets it as head
        head=(NODE*)malloc(sizeof(NODE));
        head->data=x;
        head->next=NULL;
        tail=head;
    }
    else
    {
        //Creates new node and links it to the list
        NODE* newNode;
        newNode=(NODE*)malloc(sizeof(NODE));
        newNode->data=x;
        newNode->next=head;
        //The new node is set as head
        head=newNode;
    }
}
