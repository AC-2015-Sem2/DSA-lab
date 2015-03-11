#include <stdlib.h>
#include "definingStructure.h"
//function which calculates the number of elements in the list
int numberOfElements()
{
    //the list is traversed and each node is counted
    int k=0;
    NODE *currentNode;
    currentNode=head;
    while (currentNode!=NULL)
        {
         k++;
         currentNode=currentNode->next;
        }
    return k;
}

