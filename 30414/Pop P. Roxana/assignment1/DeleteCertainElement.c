#include <stdlib.h>
#include "definingStructure.h"

void deleteFirst();
void deleteLast();

void deleteCertainElement(int x)
{
    //the previous node to the one that has to be deleted will be memorized
    NODE *prevNode=NULL;
    if (head!=NULL)
    {
        NODE *currentNode;
        currentNode=head;
        //the list is traversed up to the node which has to be deleted
        while (currentNode!=NULL)
        {
            //the case in which the node to be deleted is a head or a tail are taken into consideration
            if (currentNode->data==x)
            {
                if (currentNode==head)
                    deleteFirst();
                else
                {
                    if (currentNode==tail)
                        deleteLast();
                    else
                    {
                        prevNode->next=currentNode->next;
                    }
                }
            }
            //the previous node is linked to the element following the one due to be deleted
            prevNode=currentNode;
            currentNode=currentNode->next;
        }

    }
}
