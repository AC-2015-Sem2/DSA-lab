#include <stdlib.h>
#include "definingStructure.h"
//the list is traversed and each element is printed in the output data file
void printAll(FILE*g)
{
    NODE *currentNode;
    currentNode=head;
    while (currentNode!=NULL)
    {
        fprintf(g,"%d ",currentNode->data);
        currentNode=currentNode->next;
    }
    fprintf(g,"\n");
}
