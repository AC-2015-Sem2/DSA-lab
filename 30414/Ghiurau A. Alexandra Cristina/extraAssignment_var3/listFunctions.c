#include "listFunctions.h"
#include "lists.h"


void addLast(int value)
{
    if(genericHead==NULL)
    {
        genericHead = (node*)malloc(sizeof(node));
        genericTail = genericHead;
        genericHead->next = NULL;
        genericHead->value = value;
    }
    else
    {
        node *newNode = (node*)malloc(sizeof(node));
        newNode->value = value;
        newNode->next =  NULL;
        genericTail->next = newNode;
        genericTail= newNode;
    }
}
void printAll(FILE *fileOutput)
{
    node *aux = genericHead; //we store the head in the variable aux
    while(aux!=NULL)
    {
        fprintf(fileOutput,"%d ", aux->value);
        aux = aux->next;
    }
    fprintf(fileOutput," \n");
}

void addCountry(char *countryName)
{
    listOfLists *newNode, *currentNode;
    newNode = (listOfLists*) malloc(sizeof(listOfLists)); // allocate memory
    newNode->countryName=(char*) malloc(sizeof(char));
    newNode->next = NULL;  // put new data inside
    newNode->nextWave = NULL;   //for each "individual new" line I have to initialize the first value-element to null, in order to add the first element correctly
    strcpy(newNode->countryName, countryName);

    if(head==NULL)
    {
        head = newNode;
        currentNode = newNode;
    }
    else
    {
        currentNode = head;
        while (currentNode->next != NULL)
        {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}

void addWaves(FILE *fileOutput, int value, listOfLists *countryWaves)
{
    node *currentWaveNode, *newWaveNode;
    newWaveNode = (node *) malloc(sizeof(node)); // allocate memory
    newWaveNode->value = value; // put new data inside
    newWaveNode->next = NULL;

    if(countryWaves->nextWave == NULL)
    {
        countryWaves->nextWave = newWaveNode;
        currentWaveNode = newWaveNode;
    }
    else
    {
        currentWaveNode = countryWaves->nextWave;
        while (currentWaveNode->next != NULL)
        {
            currentWaveNode = currentWaveNode->next;
        }
        currentWaveNode->next = newWaveNode;
    }
    fprintf(fileOutput,"%d ", newWaveNode->value);
}

void deleteFirst(listOfLists *countryHead)
{
    node *auxNode;
    auxNode = countryHead->nextWave;    //aux takes the value of the head
    countryHead->nextWave =  countryHead->nextWave->next;    // head is "right shifted" with "one bit" => "new" head
    free(auxNode);      // "old" head deleted

}
void sentinelsDown(FILE *fileOutput,int maxLife, char mostPowerfulCountry[100])
{
    node *sentinels = genericHead;

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
}

void lastHit(FILE *fileOutput, int totalLifeOfSentinels )
{
    listOfLists *country = (listOfLists *) malloc(sizeof(listOfLists));
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

void readFromFile(FILE *file, FILE *fileOutput)
{
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
    node *strongestCountry; //
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

        listOfLists *currentCountry = head; // move pointer to current country

        while (currentCountry->next != NULL)
        {
            currentCountry = currentCountry->next;
        }

        while((tok = strtok(NULL, " ")) != NULL) //I skip the counties, and tok will be first - the first value-element of China and so on
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
        fprintf(fileOutput, "%s could have defeated all the sentinels.\n",thePowerfulOfThemAll);
    }

    else
    {
        fprintf(fileOutput, "No country could have defeated all the sentinels\n");
        sentinelsDown(fileOutput, maxLife, mostPowerfulCountry);
    }

    if(totalLifeOfSentinels<totalLifeOfCountries)
    {
        fprintf(fileOutput,"The tyrant was killed!\n");
        lastHit(fileOutput, totalLifeOfSentinels );
    }

    else
    {
        fprintf(fileOutput,"The tyrant was not killed!\n");
    }
}


