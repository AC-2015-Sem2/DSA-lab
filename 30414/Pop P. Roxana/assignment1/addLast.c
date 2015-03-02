#include "definingStructure.h"
#include <stdlib.h>

void addLast(int x)
{
    if (head==NULL)
    {
        head=(NODE*)malloc(sizeof(NODE));
        head->data=x;
        head->next=NULL;
        tail=head;
    }
    else
    {
        //Create a new node
        NODE* newNode=(NODE*)malloc(sizeof(NODE));
        newNode->data=x;
        newNode->next=NULL;
        //Link it at the end of the list
        tail->next=newNode;
        //Call it a tail
        tail=newNode;
    }
}
