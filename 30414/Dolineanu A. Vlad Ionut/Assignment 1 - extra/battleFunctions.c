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

void computeBest(country** auxCountry, char** bestName, char** worstName, int *totalDamage, int *maxDamage)
{
    int minDamage = 99999;
    while(*auxCountry != NULL)
    {
        int thisDamage = 0;
        node* search = (*auxCountry)->waves->head;
        while(search != NULL)
        {
            thisDamage += search->data;
            search = search->next;
        }

        *totalDamage = *totalDamage + thisDamage;
        if(thisDamage > *maxDamage)
        {
            *maxDamage = thisDamage;
            *bestName = (*auxCountry)->name;
        }
        else if(thisDamage < minDamage)
        {
            minDamage = thisDamage;
            *worstName = (*auxCountry)->name;
        }

        *auxCountry = (*auxCountry)->next;
    }

}

void computeLast(int currentHealth, country** auxCountry, country* first, FILE* g)
{
    int wave = 1;
    while(currentHealth > 0)
    {
        *auxCountry = first;
        while(*auxCountry != NULL)
        {
            int j;
            node* src = (*auxCountry)->waves->head;
            for(j=1; j<wave; j++)
                if(src->next != NULL)
                    src = src->next;
                else
                    break;
            if(currentHealth - src->data < 0)
            {
                fprintf(g, "Last hit was done by: %s\n", (*auxCountry)->name);
                currentHealth -= src->data;
                break;
            }
            else
            {
                currentHealth -= src->data;
            }
            *auxCountry = (*auxCountry)->next;
        }
        wave++;
    }
}

void computeSingleCountry(country** auxCountry, waveList *sentinels, int totalDefense, int maxDamage, FILE* g)
{
    int turrets = 0;
    int chipped = 0;
    int nr=0;
    char *name;

    while(*auxCountry != NULL)
    {
        int thisDamage = 0;
        node* search = (*auxCountry)->waves->head;
        while(search != NULL)
        {
            thisDamage += search->data;
            search = search->next;
        }

        if(thisDamage >= totalDefense)
        {
            fprintf(g,"%s ", (*auxCountry)->name);
            nr++;
        }

        if(thisDamage == maxDamage && maxDamage < totalDefense)
        {
            int hp;
            name = (*auxCountry)->name;
            search = (*auxCountry)->waves->head;
            node* currentSent = sentinels->head;
            hp = currentSent->data;
            while(search != NULL)
            {
                if(hp - search->data <= 0)
                {
                    turrets++;
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
            chipped = currentSent->data - hp;
        }
        *auxCountry = (*auxCountry)->next;
    }

        if(nr==0)
        fprintf(g,"No country ");
    fprintf(g, "could have defeated all the sentinels\n");
    if(nr==0)
        fprintf(g, "%s could have brought down the first %d sentinels and would have chipped off %d life points from sentinel %d\n", name, turrets, chipped, turrets+1);
}

