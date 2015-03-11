#include "definingStructure.h"

///THIS MODULE CONTAINS FUNCTIONS THAT DELETE CERETAIN ELEMENTS OF THE LIST, OR EVEN ALL
void deleteLast()
{
    if (head!=NULL)
    {
        //The list is traversed up to the the penultimate element which will then become the tail
        NODE *currentNode,*aux;
        currentNode=head;
        while (currentNode->next!=tail)
        {
            currentNode=currentNode->next;
        }
        currentNode->next=NULL;
        aux=tail;
        tail=currentNode;
        free(aux);
        if (tail==NULL) head=NULL;
    }
}

//the head is set to point to the second element of the list
void deleteFirst()
{
    if (head!=NULL)
    {
        NODE * aux=head;
        head=head->next;
        free(aux);
        if (head==NULL) tail=NULL;
    }
}

void deleteElementByKey(int x)
{
    //the previous node to the one that has to be deleted will be memorized
    NODE *prevNode=NULL;
    int found=0;
    if (head!=NULL)
    {
        NODE *currentNode,*aux;
        currentNode=head;
        //the list is traversed up to the node which has to be deleted
        while ((!found)&&(currentNode!=NULL))
        {
            //the case in which the node to be deleted is a head or a tail are taken into consideration
            if (currentNode->data==x)
            {
                if (currentNode==head)
                    {
                        deleteFirst();
                        found=1;
                    }
                else
                {
                    if (currentNode==tail)
                        {
                        deleteLast();
                        found=1;
                        }
                    else
                    {
                        aux=currentNode;
                        prevNode->next=currentNode->next;
                        currentNode=prevNode->next;
                        free(aux);
                        found=1;
                    }
                }
            }
            else
            {
                //the previous node is linked to the element following the one due to be deleted
                prevNode=currentNode;
                currentNode=currentNode->next;
            }
        }

    }
}

void doomTheList()
{
    NODE* current=head;
    NODE *aux;
    while(current!=NULL)
    {
        aux=current;
        current=current->next;
        free(aux);
    }
    tail=NULL;head=NULL;
}

