#include <stdlib.h>
#include "definingStructure.h"

void printFirstElements(FILE*g,int x)
{
    NODE *currentNode;
    currentNode=head;
    int k=0;
    //the list is traversed up to the xth node, the elements being printed
    while ((k<x)&&(currentNode!=NULL))
    {
        fprintf(g,"%d ",currentNode->data);
        currentNode=currentNode->next;
        k++;
    }
    fprintf(g,"\n");
}
