#include "definingStructure.h"
#include <stdlib.h>

void deleteLast()
{
    if (head!=NULL)
    {
        //The list is traversed up to the the penultimate element which will then become the tail
        NODE *currentNode;
        currentNode=head;
        while (currentNode->next!=tail)
        {
            currentNode=currentNode->next;
        }
        currentNode->next=NULL;
        tail=currentNode;
    }
}

/*method_2
void deleteLast()
{
    NODE *prev=NULL;
    if (head!=NULL)
    {
        NODE *currentNode;
        currentNode=head;
        while (currentNode!=tail)
        {
            prev=currentNode;
            currentNode=currentNode->next;
        }
        prev->next=NULL;
        tail=prev;
    }
}*/
