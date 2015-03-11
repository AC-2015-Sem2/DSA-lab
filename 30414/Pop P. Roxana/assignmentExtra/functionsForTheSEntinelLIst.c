#include "list_h.h"

///FUNCTIONS FOR THE SENTINEL LIST

/********************** FUNCTION FOR CREATING A NODE IN THE LIST ***************************************************************/
sentinels* createSentinel(int data)
{
    sentinels *newNode=(sentinels*)malloc(sizeof(sentinels));
    newNode->damage=data;
    newNode->nextSentinel=NULL;
    return newNode;
}

/********************** FUNCTION FOR ADDING THE LAST SENTINEL TO THE LIST ******************************************************/
void addLastSentinel(int data)
{
    sentinels* newNode=createSentinel(data);
    if (sentinelHead==NULL)
    {
        sentinelHead=newNode;
        sentinelTail=newNode;
    }
    else
    {
        sentinelTail->nextSentinel=newNode;
        sentinelTail=newNode;
    }
}

int totalSentinelForce()
{
    int s=0;
    sentinels * current=sentinelHead;
    while(current!=NULL)
    {
        s+=current->damage;
        current=current->nextSentinel;
    }
    return s;
}
