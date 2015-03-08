#include <stdio.h>
#include <stdlib.h>
#include "listFunctions.h"
#include "lists.h"

node *head, *tail;
listOfLists *genericHead, *genericTail, *currWaveNode;

int main()
{
    FILE *file, *fileOutput;
    file= fopen("input.dat", "r");

    if(file== NULL)
    {
        perror("Cannot open file");
        return -100;
    }
    fileOutput= fopen("output.dat","w");

    int N;
    fscanf (file, "%d", &N);
    printf ("N=%d\n", N);

    int totalLifeOfSentinels = 0;
    int value;
    int i;
    for(i=0; i<N; i++)
    {
        fscanf(file, "%d", &value);
        totalLifeOfSentinels = totalLifeOfSentinels + value;
        addLast(value);
    }

    printf("%d\n", totalLifeOfSentinels);
    printAll(fileOutput);

    int countryNumber;
    fscanf(file, "%d", &countryNumber);
    printf ("countryNumber=%d\n", countryNumber);

    /*!*****************************************************************************
    *                             DECLARATION ZONE
    ********************************************************************************/
    char line[1000]; //for each line
    value = 0;
    int ok = 0;
    int lifeOfaCountry = 0;
    int totalLifeOfCountries = 0;
    int maxLife = 0, minLife = 9999;
    char mostPowerfulCountry[100], weakestCountry[100],  thePowerfulOfThemAll[100];
    listOfLists *strongestCountry; //
    /*!*****************************************************************************+
    *                           END OF THE DECLARATION ZONE
    ********************************************************************************/

    fgets(line, sizeof(line), file);
    int k;
    for(k=0; k<countryNumber; k++)
    {
        fgets(line, sizeof(line), file);
        char *tok = strtok(line,  " \n");
        printf("\n%s: ", tok);
        addCountry(tok);

        node *currentCountry = head; // move pointer to current country
        while (currentCountry->next != NULL)
        {
            currentCountry = currentCountry->next;
        }
        while((tok = strtok(NULL, " \n")) != NULL) //I skip the counties, and tok will be first - the first value-element of China and so on
        {
            printf("%s ", tok);
            value = atoi(tok);
            lifeOfaCountry = lifeOfaCountry + value;
            addWaves(fileOutput,value,currentCountry);
        }


        totalLifeOfCountries = totalLifeOfCountries + lifeOfaCountry;
        if(maxLife<lifeOfaCountry)
        {
            maxLife=lifeOfaCountry;
            strcpy(mostPowerfulCountry,currentCountry->countryName);
            strongestCountry = currentCountry->nextWave;
        }

        if(minLife>lifeOfaCountry)
        {
            minLife=lifeOfaCountry;
            strcpy(weakestCountry,currentCountry->countryName);
        }

        if(lifeOfaCountry>totalLifeOfSentinels)
        {
            ok = 1;
            strcpy(thePowerfulOfThemAll, head->countryName);

        }
        lifeOfaCountry=0;
    }

    fprintf(fileOutput, "\nThe strongest country was: %s\n", mostPowerfulCountry);
    fprintf(fileOutput, "The weakest country was: %s\n", weakestCountry);

    if(ok==1)
    {
        fprintf(fileOutput, "The strongest of them all country was: %s\n",thePowerfulOfThemAll );

    }

    else
    {
        listOfLists *sentinels = genericHead;

        int destroyed = 0, left = 0;
        while ((maxLife - sentinels->value) > 0)
        {
            maxLife = maxLife - sentinels->value;
            destroyed++;
            sentinels = sentinels->next;
        }
        left = sentinels->value - maxLife;
        fprintf(fileOutput, "%s could have brought down the first %d sentinels and would have had chipped off %d life points from sentinel %d.\n",
                mostPowerfulCountry, destroyed, left+destroyed, destroyed+1);

        fprintf(fileOutput, "No country could have defeated all the sentinels\n");

    }

    if(totalLifeOfSentinels<totalLifeOfCountries)
    {


        fprintf(fileOutput,"The tyrant was killed!\n");
        node *country = (node *) malloc(sizeof(node));
        country = head;

        while(totalLifeOfSentinels>0)
        {
            if(country->nextWave!= NULL)
            {
                totalLifeOfSentinels=totalLifeOfSentinels-(country->nextWave->value);
                deleteFirst(country);
            }
            if (country->next != NULL)
            {
                if(totalLifeOfSentinels>0)
                    country=country->next;
            }
            else
            {
                country = head;
            }
        }
        fprintf(fileOutput,"The last hit was done by: %s", country->countryName);

    }

    else
    {
        fprintf(fileOutput,"The tyrant was not killed!\n");
    }

    fclose(fileOutput);
    return 0;
}
