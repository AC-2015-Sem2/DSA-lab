#include "functions.h"

node* createNode(int data)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->next = NULL;
    newNode->data = data;
    return newNode;
}

void addLast(waveList* list, int data)
{
    if(list->tail == NULL)
    {
        list->tail = createNode(data);
        list->head = list->tail;
    }
    else
    {
        node* newNode = createNode(data);
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

void printList(waveList* list)
{
    node* aux = list->head;
    while(aux!=NULL)
    {
        printf("%d ", aux->data);
        aux=aux->next;
    }
}

country* createCountry()
{
    country* newCountry = (country*)malloc(sizeof(country));
    newCountry->next = NULL;
    newCountry->waves = createList();
    return newCountry;
}

waveList* createList()
{
    waveList* newList = (waveList*)malloc(sizeof(waveList));
    newList->head = NULL;
    newList->tail = NULL;
    return newList;
}

void readElements(int *sentinelNumber ,int *countryNumber, waveList *sentinels, country** first, country** last){
    int i, aux;

    FILE* f = fopen("input.dat", "r");
    if(f == NULL)
        printf("ERROR OPENING FILE");

    fscanf(f, "%d", sentinelNumber);

    //Reading the health of the sentries
    for(i=0; i<*(sentinelNumber); i++)
    {
        int tmp;
        fscanf(f, "%d", &tmp);
        addLast(sentinels, tmp);
    }

    fscanf(f, "%d", countryNumber);

    //Reading the countries and their respective damage per wave
    for(i=0; i<*(countryNumber); i++)
    {
        if(*last == NULL)
        {
            *last = createCountry();
            *first = *last;
        }
        else
        {
            country* newCountry = createCountry();
            (*last)->next = newCountry;
            *last = newCountry;
        }
        fscanf(f, "%s", (*last)->name);

        while(fscanf(f, "%d", &aux)>0)
            addLast((*last)->waves, aux);
    }

    fclose(f);
}

