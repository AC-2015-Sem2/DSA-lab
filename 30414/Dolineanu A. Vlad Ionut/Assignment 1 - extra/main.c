#include "functions.h"



int main()
{
    int sentryNumber, countryNumber, i, aux;
    lst *sentries = createList();
    country* first =NULL;
    country* last = NULL;

    FILE* f = fopen("input.dat", "r");
    if(f == NULL)
        printf("ERROR OPENING FILE");

    fscanf(f, "%d", &sentryNumber);

    //Reading the health of the sentries
    for(i=0; i<sentryNumber; i++)
    {
        int aux;
        fscanf(f, "%d", &aux);
        addLast(sentries, aux);
    }

    fscanf(f, "%d", &countryNumber);

    //Reading the countries and their respective damage per wave
    for(i=0; i<countryNumber; i++)
    {
        if(last == NULL)
        {
            last = createCountry();
            first = last;
        }
        else
        {
            country* newCountry = createCountry();
            last->next = newCountry;
            last = newCountry;
        }
        fscanf(f, "%s", last->name);

        while(fscanf(f, "%d", &aux)>0)
            addLast(last->waves, aux);
    }
    fclose(f);

    //Calculating the total defense of the sentries
    int totalDefense = 1;
    node* newNode = sentries->head;
    while(newNode != NULL)
    {
        totalDefense += newNode->data;
        newNode = newNode->next;
    }


    int maxDamage = 0;
    int minDamage = 99999;
    int totalDamage = 0;
    char *bestName;
    char *worstName;
    country* newCountry = first;

    //Finding the best and weakest countries
    while(newCountry != NULL)
    {
        int thisDamage = 0;
        node* search = newCountry->waves->head;
        while(search != NULL)
        {
            thisDamage += search->data;
            search = search->next;
        }
        totalDamage += thisDamage;
        if(thisDamage > maxDamage)
        {
            maxDamage = thisDamage;
            bestName = newCountry->name;
        }
        else if(thisDamage < minDamage)
        {
            minDamage = thisDamage;
            worstName = newCountry->name;
        }

        newCountry = newCountry->next;
    }

    FILE* g = fopen("output.dat", "w");

    //Checking for victory
    if(totalDamage > totalDefense)
        fprintf(g, "The tyrant was killed!\n");
    else
        fprintf(g, "The tyrant was not killed!\n");


    newCountry = first;
    int currentHealth = totalDefense;

    //Calculating the last hit
    if(totalDamage >= totalDefense)
        while(currentHealth >= 0)
        {
            int wave = 1;
            newCountry = first;
            while(newCountry != NULL)
            {
                int j;
                node* src = newCountry->waves->head;
                for(j=1; j<wave; j++)
                    src = src->next;
                if(currentHealth - src->data <= 0)
                {
                    fprintf(g, "Last hit was done by: %s\n", newCountry->name);
                    currentHealth -= src->data;
                    break;
                }
                else
                {
                    currentHealth -= src->data;
                }
                newCountry = newCountry->next;
            }
            wave++;
        }


    newCountry = first;
    int nr=0;

    fprintf(g,"The strongest country was: %s\n", bestName);
    fprintf(g,"The weakest country was: %s\n", worstName);

    //Checking if there are countries which can kill all sentries, and if not we will calculate how much the best country could do
    int turrets = 0, chipped = 0;
    while(newCountry != NULL)
    {
        int thisDamage = 0;
        node* search = newCountry->waves->head;
        while(search != NULL)
        {
            thisDamage += search->data;
            search = search->next;
        }

        if(thisDamage >= totalDefense)
        {
            fprintf(g,"%s ", newCountry->name);
            nr++;
        }

        if(thisDamage == maxDamage && maxDamage < totalDefense)
        {
            int hp;
            search = newCountry->waves->head;
            node* currentSent = sentries->head;
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
        newCountry = newCountry->next;
    }

    if(nr==0)
        fprintf(g,"No country ");
    fprintf(g, "could have defeated all the sentinels\n");
    if(nr==0)
        fprintf(g, "%s could have brought down the first %d sentinels and would have chipped off %d life points from sentinel %d\n", bestName, turrets, chipped, turrets+1);
    fclose(g);
    return 0;
}
