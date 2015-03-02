#include <stdlib.h>
#include "definingStructure.h"
//The prototype for the function giving the number of elements in the list is needed
int numberOfElements();

void printLastElements(FILE*g,int x)
{
    int k=0;
    //n gives the number of elements in the list which are not to be printed
    int n=numberOfElements()-x;
    //currentNode is a pointer to the current node
    NODE *currentNode;
    currentNode=head;
    //the list is traversed up to the node starting from which the elements will be printed
    while (k<n)
    {
        currentNode=currentNode->next;
        k++;
    }
    //the last x elements are being printed
    while (currentNode!=NULL)
    {
        fprintf(g,"%d ",currentNode->data);
        currentNode=currentNode->next;
    }
    fprintf(g,"\n");
}
