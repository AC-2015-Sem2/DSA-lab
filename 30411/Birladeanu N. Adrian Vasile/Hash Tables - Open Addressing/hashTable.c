#include "hashTable.h"
#include "io.h"
#include <math.h>

void initHashTable(int N)        
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
    size=INITIAL_HT_SIZE_FACTOR*N;
    hashTable=(char**)malloc(size * sizeof(char*));
    int i;
    for(i=0; i<size; i++)
    {
        hashTable[i]=NULL;
    }
    //HT_SIZE_FACTOR=INITIAL_HT_SIZE_FACTOR;
}

float getFillFactor()
{
    //! return the fill factor of the hash table
    float fillFactor = -1;
    float occupied=0;
    int i;
    for(i=0; i<size; i++)
    {
        if(hashTable[i]!=NULL)
        {
            occupied++;
        }
    }
    fillFactor=occupied/size;
    return fillFactor;
}

void resizeHashTable(int N)
{
    //! reconstruct the hash table by (usually) doubling its size
    //! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR

    //! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
    //! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)


    if(size*2<=N)
    {
        size*=2;
    }
    else
    {
        size=N;
    }
    //char** temporaryHT=hashTable;
    //int old_size=size;
    free(hashTable);
    hashTable=(char**)malloc(size * sizeof(char*));
    int i;
    for(i=0; i<size; i++)
    {
        hashTable[i]=NULL;
    }
}

int insertElement(char * element)
{
    //! insert an element
    //! returns the number of collisions which occurred before the element was inserted
    int noOfCollisions=0;
    int key=hashFunction(element, 0);
    if(hashTable[key]==NULL)
    {
        hashTable[key]=element;
    }
    else
    {
        int i=1;
        while(hashTable[key]!=NULL)
        {
            noOfCollisions++;
            key=hashFunction(element, i);
            i++;
        }
        hashTable[key]=element;
    }

    return noOfCollisions;
    return 0;
}

int hashFunction(char * content, int i)     //!H3
{
    int length = strlen(content);
    int k, sum;
    double a;
    for (sum=0, k=0; k < length; k++)
    {
        a=content[k];
        a=cos(a);
        sum += a;
    }
    return (sum+i) % size;
}

/*
int hashFunction(char * content, int i)     //!H2
{
    int length = strlen(content);
    int k, sum;
    int a;
    for (sum=0, k=0; k < length; k++)
    {
        a=content[k];
        sum += (a*a)%153 ;
    }
    return (sum+i) % size;
}
*/
/*
int hashFunction(char * content, int i)     //!H1
{
    int length = strlen(content);
    int k, sum=0;
    for (k=0; k < length; k++)
    {
        sum+=content[k];
    }
    return (sum+i) % size;
}
*/
void fillHashTable(char** content, int N)
{
    int noCollisions=0;
    int noResize=0;
    initHashTable(N);
    int i;
    float factor;
    for(i=0; i<N; i++)
    {
        noCollisions += insertElement(content[i]);
        factor= getFillFactor();
        if(factor>MAX_FILL_FACTOR && size<N)
        {
            noResize++;
            resizeHashTable(N);
            i=0;
        }
    }
    printf("Number of Collisions: %d \nNumber of Resizes: %d \n", noCollisions, noResize);
}
