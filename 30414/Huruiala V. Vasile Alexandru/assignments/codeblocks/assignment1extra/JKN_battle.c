#include<stdio.h>
#include<stdlib.h>
#include "SLL_definition.h"
#include "SLL_functions.h"
#include "JKN_io.h"

/*The main function
It produces stats and simulates the battle
then it prints them to the output file
*/
int Battle(Country** Sentinel, Country** Scourge, Country** tScourge, FILE* Out)
{
    //Gather stats
    //strongest/weakest
    Country* Strongest = NULL;
    int scP = 0;
    Country* Weakest = NULL;
    int wcP = 0;

    Country* Temp = *Scourge;
    while(Temp->nextCountry != *Scourge)
    {
        int Sum = 0;
        Army* aTemp = Temp->headArmy;
        while(aTemp != NULL)
        {
            Sum += aTemp->hitpoints;
            aTemp = aTemp->next;
        }

        if(Sum > scP)
        {
            scP = Sum;
            Strongest = Temp;
        }
        if((Temp == *Scourge)||((Temp != *Scourge)&&(wcP > Sum)))
        {
            wcP = Sum;
            Weakest = Temp;
        }

        Temp = Temp->nextCountry;
    }
    //last hit
    char* LastHitter;
    //solo win simulation
    int soloWinPossible = 0;
    int sentDown = 0;
    int sentDamage = 0;

    int SentTotalHP = 0;
    Army* aTemp = (*Sentinel)->headArmy;
    while(aTemp != NULL)
    {
        SentTotalHP += aTemp->hitpoints;
        aTemp = aTemp->next;
    }
    if(scP >= SentTotalHP)
    {
        soloWinPossible = 1;
    }
    else
    {
        //printf("%d\n", scP);//DEBUG
        Army* sentTemp = (*Sentinel)->headArmy;
        int scouPower = scP;
        while(scouPower > 0)
        {
            if(scouPower - sentTemp->hitpoints <= 0)
                sentDamage = scouPower;
            else
                sentDown++;
            scouPower -= sentTemp->hitpoints;
            sentTemp = sentTemp->next;
        }
    }

    //init
    Country* Sent = *Sentinel;
    //having these will simplify expressions
    //and are probably needed
    Army* aSent = Sent->headArmy;
    Army* atSent = Sent->tailArmy;
    //and this makes things easier
    Country* Scou = *Scourge;

    //Let the battle commence
    int exitCond = 0;
    while(exitCond == 0)
    {
        //Skip all countries that no longer have waves
        Army* aScou = NULL;
        Army* atScou = NULL;
        do
        {
            aScou = Scou->headArmy;
            atScou = Scou->tailArmy;
            if(aScou == NULL)
                Scou = Scou->nextCountry;
        }
        while(aScou == NULL);

        //will exit loop when a wave is destroyed, otherwise go for the next sentinel
        //or when all sentinels are down
        int exitFight = 0;
        while(exitFight == 0)
        {
            //this value represents who won
            int hpDiff = aSent->hitpoints - aScou->hitpoints;
            if(hpDiff > 0)
            //if a Sent is down
            {
                exitFight = 1;
                setHpArmy(aSent, hpDiff);
                removeLinkArmy(&aScou, &atScou);
            }
            else if(hpDiff == 0)
            //mutual assured destruction
            {
                exitFight = 2;
                removeLinkArmy(&aSent, &atSent);
                removeLinkArmy(&aScou, &atScou);
            }
            else
            //Sentinel down! go get the next one
            {
                removeLinkArmy(&aSent, &atSent);
                setHpArmy(aScou, -hpDiff);
            }
            //time to check if there are any sentinels left
            if(aSent == NULL)
            //if all sentinels are defeated
            {
                exitFight = 3;
                exitCond = 1;
                LastHitter = Scou->cname;
            }
        }
        //set the new list pointers(the parameters and temps)
        Scou->headArmy = aScou;
        Scou->tailArmy = atScou;
        (*Sentinel)->headArmy = aSent;
        (*Sentinel)->tailArmy = atSent;

        //test if there are any armies left
        Country* ScouTest = *Scourge;
        int ScouDefeated = 1;
        while((ScouDefeated == 1)&&(ScouTest->nextCountry != *Scourge))
        {
            if(ScouTest->headArmy != NULL)
            //if there is at least one left
            {
                ScouDefeated = 0;
            }
            ScouTest = ScouTest->nextCountry;
        }

        if(ScouDefeated == 1)
        {
            exitCond = 2;
        }
        else
        {
            //next country's turn to attack
            Scou = Scou->nextCountry;
        }
    }
    (*Sentinel)->headArmy = aSent;
    (*Sentinel)->tailArmy = atSent;

    //Display stats
    if(exitCond == 1)
    {
        fprintf(Out, "Sentinel has been defeated.\n%s has gotten the last hit.\n", LastHitter);
    }
    else
    {
        fprintf(Out, "Sentinel still reigns terror upon Earth.\nThanks Obama.\n");
    }
    fprintf(Out, "The strongest country was: %s\n", Strongest->cname);
    fprintf(Out, "The weakest  country  was: %s\n", Weakest->cname);
    if(soloWinPossible == 1)
    {
        fprintf(Out, "%s could have defeated the sentinels on their own.\n", Strongest->cname);
    }
    else
    {
        fprintf(Out, "No country could have defeated all of the sentinels.\n%s would have taken down %d sentinels and chipped off %d damage from sentinel %d.", Strongest->cname, sentDown, sentDamage, sentDown + 1);
    }

    return exitCond;
}
