#include "list_h.h"

///FUNCTIONS FOR THE LIST OF WAVES

/********************** FUNCTION FOR CREATING A NODE IN THE LIST ***************************************************************/
node* createNode(int data)
{
    node* newNode=(node*)malloc(sizeof(node));
    newNode->force=data;
    newNode->next=NULL;
    return newNode;
}

/********************** FUNCTION FOR ADDING THE LAST WAVE TO THE LIST **********************************************************/
void addLastNode (node* *head, node* *tail, int data)
{
    node* newNode=createNode(data);
    if ((*head)==NULL)
    {
        (*head)=newNode;
        (*tail)=newNode;
    }
    else
    {
        (*tail)->next=newNode;
        (*tail)=newNode;
    }
}

/******************** THE FUNCTION WHICH DELETES THE FIRST WAVE OF A COUNTRY ***************************************************/

void deleteFirstNode(node* *head, node* *tail)
{
    if((*head)!=NULL)
       {
        node * aux;
        if ((*head)==(*tail))
    {
        aux=(*head);
        (*head)=NULL;
        (*tail)=NULL;
        free(aux);
    }
        else
    {
        aux=(*head);
        (*head)=(*head)->next;
        free(aux);
    }
       }
}
