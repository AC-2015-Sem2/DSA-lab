#include "list_h.h"
#include <limits.h>

/**************** FUNCTION WHICH COMPUTES WHICH ONE IS THE WEAKEST COUNTRY OF ALL *****************************************/
char* weakestCountry()
{

    char *s=(char*)malloc(20*sizeof(char));
    int min=INT_MAX;
    headerCell* current=headerHead;
    while(current->nextHeader!=NULL)
    {
        if (current->head==NULL)
        {
            min=0;///A COUNTRY MIGHT HAVE NO WAVES... NOT THAT IT WOULD HAVE MUCH SENSE INVOLVING IN THE WAR. ANYWAY, JUST TESTING
            s=current->country;
        }
        else
        {
            if(current->lifePoints<min)
            {
                min=current->lifePoints;
                s=current->country;
            }
        }
        current=current->nextHeader;
    }
    return s;
}

char* strongestCountry()
{

    char *s=(char*)malloc(20*sizeof(char));
    int max=0;
    headerCell* current=headerHead;
    while(current->nextHeader!=NULL)
    {
        if(current->lifePoints>max)
        {
                max=current->lifePoints;
                s=current->country;
        }
        current=current->nextHeader;
    }
    return s;
}

/*************** A FUNCTION WHICH COMPUTES WHICH FUNCTION COULD HAVE BROUGHT DOWN THE MOST SENTINELS ***********************/

int mostSentinelsKilled(char*s,int *killedSentinels, int *pointsLeft)///s INDICATES THE STRONGEST COUNTRY
{
    int ok=1;///TESTS IF THE COUNTRY WAS ABLE TO BRING DOWN ALL THE SENTINELS. AT FIRST IT IS ASSUMED IT CAN
    headerCell* current=headerHead;
    while (current->nextHeader!=NULL)
    {
        if (strcmp(current->country,s)==0)///THE STRONGEST COUNTRY WAS FOUND
        {
            (*killedSentinels)=0;///NO SENTINEL KILLED YET
            (*pointsLeft)=current->lifePoints;/// THE POINTS LEFT OF THE COUNTRY ARE AT FIRST ALL ITS LIFEPOINTS
            ///NOW I WILL TRANSVERSE THE SENTINEL LIST UNTIL THEY ARE ALL DEAD OR THE STRONGEST COUNTRY HAS NO MORE WAVES(AKA LIFEPOINTS)
            sentinels * sentinel=sentinelHead;
            while((sentinel!=NULL)&&(ok))
            {
                if((*pointsLeft)>sentinel->damage)
                {
                    (*pointsLeft)-=sentinel->damage;
                    (*killedSentinels)++;
                    sentinel=sentinel->nextSentinel;
                }
                else
                {
                    ok=0;
                }
            }
        break;///THE NEEDED VALUES WERE COMPUTED
        }
        else
        {
            current=current->nextHeader;
        }

    }
    return ok;
}

/*******THIS FUNCTION SOMEHOW SIMULATES THE WAR.****************************************************************************
********IT RETURNS BY VALUE A POSITIVE NUMBER IF THE ENEMY WAS DEFEATED AND THROUGH A PARAMETER THE COUNTRY THAT HIT LAST***/

int simulatingTheWar(char* *lastCountry)
{
    int ok=0;///IT IS SUPPOSED THE ENEMY WAS
    ///I WILL INITIALIZE IT TO MAKE IT FASTER. HAVE TO CHANGE IT AND ACTUALLY COMPUTE IT !!!!!!!!!!!!
    int forceNeeded=totalSentinelForce();
    /// THE WAR STOPS WHEN EITHER THE ENEMY WAS DEFEATED OR NO COUNTRY HAS SURVIVED
    while((forceNeeded>0)&&(headerHead!=NULL))
    {
        headerCell * currentHeader=headerHead;
        while ((currentHeader!=NULL)&&(forceNeeded>0))
        {
            int out=0;
            /// TESTING IF THE COUNTRY HAS ANY WAVES LEFT
            while ((out==0)&&(currentHeader->head==NULL))
            {
                if (currentHeader==headerTail)
                {
                    deleteCertainHeader(&currentHeader);
                    out=1;
                }
                else
                {
                    deleteCertainHeader(&currentHeader);
                }
            }
            if (out==0) ///THE TAIL WAS NOT DELETED. IF IT WAS, THE CURRENT HEADER CELL WILL MOVE BACWARDS, WHICH IS UNWANTED
            {
                forceNeeded-=(currentHeader->head)->force;
                deleteFirstNode(&currentHeader->head,&currentHeader->tail);
                (*lastCountry)=currentHeader->country;
                currentHeader=currentHeader->nextHeader;
            }
            else
            {
               currentHeader=NULL;
            }
        }
    }
    if (forceNeeded<=0) ok=1;
    return ok;
}

