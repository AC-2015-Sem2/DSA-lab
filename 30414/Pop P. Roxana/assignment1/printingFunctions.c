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

