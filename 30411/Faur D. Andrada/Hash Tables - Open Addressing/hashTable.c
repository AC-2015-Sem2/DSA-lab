#include "hashTable.h"
#include <stdio.h>
#include <stdlib.h>
#include "io.h"



void initHashTable(int N)
{

    char ** content=readFromFile(N);
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
    size=N*INITIAL_HT_SIZE_FACTOR;
    int i;
    hashTable=(char**)malloc(sizeof(char*)*size);

    for(i=0; i<size; i++)
    {
        hashTable[i]=(char*)malloc(sizeof(char)*MAX_STRING_LENGTH);
        hashTable[i]=NULL;
        int k=insertElement(content[i],N);
        //!printf("%s \n",content[i])
;        if (k>max_col)
        {
            max_col=k;
        }
        printf("the number of collisions at element %d is %d\n\n",i,k);
    }


    printf("the max number of collisions is %d \n",max_col);
    printf("the number of reinitialisations is %d \n",res);
}

float getFillFactor()
{
    //! return the fill factor of the hash table
    float fillFactor = -1;
    int filled=0, i;
    for(i=0;i<size;i++)
    {
        if(hashTable[i] != NULL)
            filled++;
    }
    fillFactor = filled/size;
    return fillFactor;
}

void resizeHashTable(int N)
{
    //! reconstruct the hash table by (usually) doubling its size

    //!if(getFillFactor()>MAX_FILL_FACTOR)
     free(hashTable);
    res++;
    initHashTable(2*N);

    //! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR

    //! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
    //! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)
}

int insertElement(char * element, int N)
{
    //! insert an element
    int e,col=0;
    e=hashFunction(element,col);
        if(hashTable[e]==NULL)
        {
            hashTable[e]=element;
        }
        else
        {
            while((col<size)&&(hashTable[e]!=NULL))
            {
                col++; e++;
            }
            hashTable[e]=element;
        }

    if(getFillFactor()>MAX_FILL_FACTOR)
        resizeHashTable(N);


    //! returns the number of collisions which occurred before the element was inserted

    return col;
}


int hashFunction(char * content, int i)
{
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
    return (sum+i) % size;

}
