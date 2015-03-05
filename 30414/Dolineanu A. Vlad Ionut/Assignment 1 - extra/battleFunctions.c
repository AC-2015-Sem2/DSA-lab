#include "battleFunctions.h"

int calculateDefense(waveList *sentinels)
{
    int totalDefense=0;
    node* newNode = sentinels->head;
    while(newNode != NULL)
    {
        totalDefense += newNode->data;
        newNode = newNode->next;
    }
    return totalDefense;
}

void computeBest(country** newCountry, char** bestName, char** worstName, int *totalDamage, int *maxDamage)
{
    int minDamage = 99999;
    while(*newCountry != NULL)
    {
        int thisDamage = 0;
        node* search = (*newCountry)->waves->head;
        while(search != NULL)
        {
            thisDamage += search->data;
            search = search->next;
        }

        *totalDamage = *totalDamage + thisDamage;
        if(thisDamage > *maxDamage)
        {
            *maxDamage = thisDamage;
            *bestName = (*newCountry)->name;
        }
        else if(thisDamage < minDamage)
        {
            minDamage = thisDamage;
            *worstName = (*newCountry)->name;
        }

        *newCountry = (*newCountry)->next;
    }

}

void computeLast(int currentHealth, country** newCountry, country* first, FILE* g)
{
    int wave = 1;
    while(currentHealth > 0)
    {
        *newCountry = first;
        while(*newCountry != NULL)
        {
            int j;
            node* src = (*newCountry)->waves->head;
            for(j=1; j<wave; j++)
                if(src->next != NULL)
                    src = src->next;
                else
                    break;
            if(currentHealth - src->data < 0)
            {
                fprintf(g, "Last hit was done by: %s\n", (*newCountry)->name);
                currentHealth -= src->data;
                break;
            }
            else
            {
                currentHealth -= src->data;
            }
            *newCountry = (*newCountry)->next;
        }
        wave++;
    }
}

void computeSingleCountry(country** newCountry, waveList *sentinels, int totalDefense, int maxDamage, int *turrets, int *chipped, int *nr, FILE* g)
{
    while(*newCountry != NULL)
    {
        int thisDamage = 0;
        node* search = (*newCountry)->waves->head;
        while(search != NULL)
        {
            thisDamage += search->data;
            search = search->next;
        }

        if(thisDamage >= totalDefense)
        {
            fprintf(g,"%s ", (*newCountry)->name);
            *nr = *nr + 1;
        }

        if(thisDamage == maxDamage && maxDamage < totalDefense)
        {
            int hp;
            search = (*newCountry)->waves->head;
            node* currentSent = sentinels->head;
            hp = currentSent->data;
            while(search != NULL)
            {
                if(hp - search->data <= 0)
                {
                    *turrets = *turrets + 1;
                    int diff = search->data - hp;
                    currentSent = currentSent->next;
                    hp = currentSent->data;
                    hp -= diff ;
                }
                else
                {
                    hp -= search->data;
                }
                search = search->next;
            }
            *chipped = currentSent->data - hp;
        }
        *newCountry = (*newCountry)->next;
    }
}

