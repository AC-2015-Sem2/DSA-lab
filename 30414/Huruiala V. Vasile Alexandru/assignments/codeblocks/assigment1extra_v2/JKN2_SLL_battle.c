#include "JKN2_SLL_definition.h"
#include <stdlib.h>
#include <string.h>

Country* StrongestCountry(JKN* J)
{
    Country* Strongest = NULL;
    int maxpower = 0;

    Country* temp = J->headCou;
    while(temp != NULL)
    {
        int strPower = 0;
        Army* atemp = temp->headArmy;
        while(atemp != NULL)
        {
            strPower += (int)atemp->data;
            atemp = atemp->next;
        }
        if(strPower > maxpower)
        {
            maxpower = strPower;
            Strongest = temp;
        }
        temp = temp->next;
    }

    return Strongest;
}

Country* WeakestCountry(JKN* J)
{
    Country* Weakest = NULL;
    int minpower = 0;

    Country* temp = J->headCou;
    while(temp != NULL)
    {
        int strPower = 0;
        Army* atemp = temp->headArmy;
        while(atemp != NULL)
        {
            strPower += (int)atemp->data;
            atemp = atemp->next;
        }
        if((strPower < minpower)||(temp == J->headCou))
        {
            minpower = strPower;
            Weakest = temp;
        }
        temp = temp->next;
    }

    return Weakest;
}

int SoloWin(JKN* J, int* SentinelsDown, int* SentinelDamage)
{
    *SentinelsDown = 0;
    *SentinelDamage = 0;
    //Find the sum of the hp of the strongest country
    int Power = 0;
    Army* temp = J->StrongestCountry(J)->headArmy;
    while(temp != NULL)
    {
        Power += (int)temp->data;
        temp = temp->next;
    }
    //then simulate a fight with the sentinels
    temp = J->sentinel->headArmy;
    while((temp != NULL)&&(Power > 0))
    {
        Power -= (int)temp->data;
        if(Power > 0)
        {
            (*SentinelsDown)++;
        }
        else
        {
            *SentinelDamage = (int)temp->data + Power;
        }
        temp = temp->next;
    }

    int SoloWinPossible = 0;
    if(temp == NULL)
        SoloWinPossible = 1;

    return SoloWinPossible;
}

int Battle(JKN* J, char** LastHitter)
{
    *LastHitter = NULL;

    Country* ctemp = NULL;
    int exitCond = -1;
    while(exitCond == -1)
    {
        if(ctemp == NULL)
            ctemp = J->headCou;
        //Chose the next valid wave
        Army* atemp = NULL;
        while((atemp = ctemp->headArmy) == NULL)
        {
            ctemp = ctemp->next;
            if(ctemp == NULL)
                ctemp = J->headCou;
        }
        (*J->SelectCountry)(J, ctemp);
        //Perform the fight
        int exitBattle = 0;
        while((exitBattle == 0)&&(J->sentinel->headArmy != NULL))
        {
            int hpdiff = (int)J->sentinel->headArmy->data - (int)atemp->data;
            if(hpdiff > 0)
            //The sentinel survived
            {
                exitBattle = 1;
                (*J->SetArmyDataS)(J, (void*)hpdiff);
                (*J->RemoveFirstArmyC)(J);
            }
            else if(hpdiff == 0)
            //Both are destroyed
            {
                exitBattle = 1;
                (*J->RemoveFirstArmyS)(J);
                (*J->RemoveFirstArmyC)(J);
            }
            else//if(hpdiff < 0)
            //The army survived, it fights the next sentinel(does not exit loop)
            {
                (*J->RemoveFirstArmyS)(J);
                (*J->SetArmyDataC)(J, (void*)-hpdiff);
            }
        }

        //Check if either won
        if(J->sentinel->headArmy == NULL)
        //The rebels won
        {
            exitCond = 0;
            *LastHitter = (char*)malloc(strlen((char*)ctemp->data));
            strcpy(*LastHitter, (char*)ctemp->data);
        }
        else
        {
            //If there is no wave left
            int noArmiesLeft = 1;
            Country* ct = J->headCou;
            while((ct != NULL)&&(noArmiesLeft == 1))
            {
                if(ct->headArmy != NULL)
                    noArmiesLeft = 0;
                ct = ct->next;
            }
            if(noArmiesLeft == 1)
            //then the sentinels won
            {
                exitCond = 1;
            }
        }
        ctemp = ctemp->next;
        (*J->DebugPrint)(J);//DEBUG
    }
    return exitCond;
}

void PrintResults(FILE* O, int victory, char* lasthit, char* strong, char* weak, int solopos, int sentsdown, int sentdamage)
{
    if(victory == 0)
    {
        fprintf(O, "The tyrant was killed!\nThe last hit was done by: %s.\n", lasthit);
    }
    else
    {
        fprintf(O, "The sentinels fended off the attack!\n");
    }
    fprintf(O, "The strongest country was: %s.\n", strong);
    fprintf(O, "The weakest country was: %s.\n", weak);
    if(solopos == 0)
    {
        fprintf(O, "No country could have defeated all the sentinels.\n");
        fprintf(O, "%s could have brought down the first %d sentinels and would have had chipped off %d life points from sentinel %d.", strong, sentsdown, sentdamage, sentsdown + 1);
    }
    else
    {
        fprintf(O, "%s could have defeated all the sentinels by themselves.\n", strong);
    }
}

void Solve(JKN* J, FILE* O)
{
    //Must first store values before altering the lists
    char *strongest = (char*)(*J->StrongestCountry)(J)->data;
    char *weakest = (char*)(*J->WeakestCountry)(J)->data;
    int SentsDown = 0;
    int SentsDamage = 0;
    int SoloPos = (J->SoloWin)(J, &SentsDown, &SentsDamage);
    char* LastHitter = NULL;
    //Then perform the simulation
    int Victory = (*J->Battle)(J, &LastHitter);
    //And finally print the result
    (*J->PrintResults)(O, Victory, LastHitter, strongest, weakest, SoloPos, SentsDown, SentsDamage);
}
