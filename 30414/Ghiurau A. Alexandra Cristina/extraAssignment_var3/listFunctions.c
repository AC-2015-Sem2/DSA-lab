#include "listFunctions.h"
#include "lists.h"


void addLast(int value)
{
    if(genericHead==NULL)
    {
        genericHead = (listOfLists*)malloc(sizeof(listOfLists));
        genericTail = genericHead;
        genericHead->next = NULL;
        genericHead->value = value;
    }
    else
    {
        listOfLists *newNode = (listOfLists*)malloc(sizeof(listOfLists));
        newNode->value = value;
        newNode->next =  NULL;
        genericTail->next = newNode;
        genericTail= newNode;
    }
}
void printAll(FILE *fileOutput)
{
    listOfLists *aux = genericHead; //we store the head in the variable aux
    while(aux!=NULL)
    {
        fprintf(fileOutput,"%d ", aux->value);
        aux = aux->next;
    }
    fprintf(fileOutput," \n");
}

void addCountry(char *countryName)
{
    node *newNode, *currentNode;
    newNode = (node*) malloc(sizeof(node)); // allocate memory
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

void addWaves(FILE *fileOutput, int value, node *countryWaves)
{
    listOfLists *currentWaveNode, *newWaveNode;
    newWaveNode = (listOfLists *) malloc(sizeof(listOfLists)); // allocate memory
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

void deleteFirst(node *countryHead)
{
    listOfLists *auxNode;
    auxNode = countryHead->nextWave;    //aux takes the value of the head
    countryHead->nextWave =  countryHead->nextWave->next;    // head is "right shifted" with "one bit" => "new" head
    free(auxNode);      // "old" head deleted

}

