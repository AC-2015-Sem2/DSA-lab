#include "list_h.h"

///FIRST OF ALL, FUNCTIONS FOR THE HEADER CELLS LIST

/********************** FUNCTION FOR CREATING A NODE IN THE LIST ****************************************************************/
headerCell* createHeaderCellNode(char* s)
{
    headerCell *newNode=(headerCell*)malloc(sizeof(headerCell));
    newNode->nextHeader=NULL;
    newNode->country=s;
    newNode->head=NULL;
    newNode->tail=NULL;
    newNode->lifePoints=0;
    return newNode;
}

/********************** FUNCTION FOR ADDING THE LAST HEADER CELL ***************************************************************/
void addLastHeader(char* s)
{
    headerCell* newNode=createHeaderCellNode(s);
    if (headerHead==NULL)
    {
        headerHead=newNode;
        headerTail=newNode;
    }
    else
    {
        headerTail->nextHeader=newNode;
        headerTail=newNode;
        headerTail->head=NULL;
        headerTail->tail=NULL;
    }
}

/********************** FUNCTION FOR DELETING THE FIRST HEADER CELL ***********************************************************/
void deleteFirstHeader()
{
    headerCell *aux;
    if (headerHead!=NULL)
    {
        if (headerHead==headerTail)
    {
        aux=headerHead;
        headerHead=NULL;
        headerTail=NULL;
        free(aux);
    }
        else
        {
            aux=headerHead;
            headerHead=headerHead->nextHeader;
            free(aux);
        }
}
}

/********************** FUNCTION FOR DELETING THE LAST HEADER CELL ***********************************************************/
void deleteLastHeader()
{
    headerCell * aux;
    if (headerHead!=NULL)
    {
        if (headerHead==headerTail)
    {
        aux=headerHead;
        headerHead=NULL;
        headerTail=NULL;
        free(aux);
    }
       else
        {

            headerCell *currentHeaderCell=headerHead;
            while(currentHeaderCell->nextHeader!=headerTail)
            {
                currentHeaderCell=currentHeaderCell->nextHeader;
            }
            aux=headerTail;
            currentHeaderCell->nextHeader=NULL;
            headerTail=currentHeaderCell;
            free(aux);
        }
    }
}

/********************** FUNCTION FOR DELETING A HEADER CELL FROM THE LIST AKA ELIMINATING A COUNTRY WITH NO MORE HITS LEFT*****/
/********************** THE FUNCTION ALSO RETURNS A POINTER TO THE NEW CURRENT COUNTRY ****************************************/
void deleteCertainHeader(headerCell* *headerToDelete)
{
    if ((*headerToDelete)==headerHead)
    {
        deleteFirstHeader();
        *headerToDelete=headerHead;
    }
    else
    {
        if ((*headerToDelete)==headerTail)
        {
            deleteLastHeader();
            *headerToDelete=headerTail;
        }
        else
        {
            headerCell * currentHeader=headerHead, *prev;
            while(currentHeader!=(*headerToDelete))
            {
                prev=currentHeader;
                currentHeader=currentHeader->nextHeader;
            }
            headerCell*aux;
            aux=currentHeader;
            prev->nextHeader=currentHeader->nextHeader;
            (*headerToDelete)=prev->nextHeader;
            free(aux);
        }
    }
}

/*************THIS FUNCTION ADS LIFE POINTS TO THE LIST CONTAINING INFORMATION ABOUT EACH COUNTRY, AKA THE HEADER CELL LIST****/

void addLifePoints(headerCell* * p, int data)
{
    (*p)->lifePoints+=data;
}
