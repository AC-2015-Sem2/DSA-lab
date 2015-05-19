#include "hashTable.h"
#include "io.h"
#include <string.h>

void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
    char ** content = readFromFile(N);
    size= N*INITIAL_HT_SIZE_FACTOR; //!printf("size %d \n" ,size);
    int i;
    hashTable=(char**)malloc(sizeof(char*)*size);
    for(i=0; i<size; i++)
    {
        hashTable[i]=(char*)malloc(sizeof(char)*MAX_STRING_LENGTH);
        hashTable[i]=NULL;
        int k=insertElement(content[i],N);
        //!printf("the number of collisions at element %d is %d\n\n",i,k);
    }
    printf("\nthe max number of collisions is %d\n",max_col);
     printf("\nthe  number of resets is %d\n",res);

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
    fillFactor = filled /size;
    return fillFactor;


}

void resizeHashTable(int N)
{
    //! reconstruct the hash table by (usually) doubling its size
    //! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR
    int i;
    for(i=0; i<size; i++)
        free(hashTable[i]);
    initHashTable(2*N);
    //! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
    //! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)
}

int insertElement(char * element,int N)
{
    //! insert an element
    //! returns the number of collisions which occurred before the element was inserted
int key,collision=0;
    key=hashFunction(element,0);


        if(hashTable[key]==NULL)
        {
            hashTable[key]=element;
        }
        else
            while((collision<size)&&(hashTable[key]!=NULL))
        {

        collision++;
        key++;
        if(collision>max_col)
            max_col=collision;
    }
    if(getFillFactor(N)>MAX_FILL_FACTOR)
    {
        resizeHashTable(N);
        res++;
        printf("!\n");
    }

    return collision;
}


/*
   int hashFunction(char * content, int i)
{
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
    return (sum+i) % size;

} */

/*
int hashFunction(char * content, int i) //!hashfunction 2
{
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += (content[k]*content[k])/4;
    }
    return (sum+i) % size;

} */

int hashFunction(char * content, int i) //!hashfunction 3
{
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
    sum=sum/length;
    return (sum+i) % size;

}
