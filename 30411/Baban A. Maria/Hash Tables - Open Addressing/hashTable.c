#include "hashTable.h"


void initHashTable(int N)
{
    int i;

    size=INITIAL_HT_SIZE_FACTOR * N;
    hashTable=(char**)malloc(sizeof(char*)*size);
    for(i=0;i<size;i++)
    {
        hashTable[i]=(char*)malloc(sizeof(char)*MAX_STRING_LENGTH);
        hashTable[i]=0;
    }

    for(i=0;i<n;i++)
    {
        printf("\n the number of collisions for element %s is %d ",content[i],insertElement(content[i], i));
    }
}
float getFillFactor(int nth_element)
{
    float fillFactor = -1;
    fillFactor= fillFactor - (nth_element/size);
    return fillFactor;
}

void resizeHashTable()
{
    initHashTable(2*N);
}

int insertElement(char *element, int nth_element)
{
    int i=hashFunction(element,0);
    while(hashTable[i]!=0)
        i++;
    if(getFillFactor(nth_element)>=MAX_FILL_FACTOR)
        resizeHashTable();
    else
        hashTable[i]=element;
    int nrOfCollisions=i-hashFunction(element,0);
    return nrOfCollisions;
    //return 0; why 0? it is a int function not a void!
}


int hashFunction(char * content, int i)
{
    int j;
    for(j=0;j<MAX_STRING_LENGTH;j++)
    {
        i= i+atoi(content[j]) + 65;
    }
    return i % size;
}
