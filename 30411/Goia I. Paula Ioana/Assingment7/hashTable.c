#include "hashTable.h"
#include "io.h"
#include <string.h>
void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
    char ** content = readFromFile(N);
    if(res==1)size=N*INITIAL_HT_SIZE_FACTOR;
    else size=N*getFillFactor();
    int i;
    hashTable=(char**)malloc(sizeof(char*)*size);

    for(i=0; i<size; i++)
    {
        hashTable[i]=(char*)malloc(sizeof(char)*MAX_STRING_LENGTH);
        hashTable[i]=NULL;
        int k=insertElement(content[i],N);
        printf("the number of collisions at element %d is %d\n\n",i,k);
    }
    printf("\nthe max number of collisions is %d\n",maxboom);
}

float getFillFactor()
{
    //! return the fill factor of the hash table
    float fillFactor = -1;
    int nr=0, i=0;
    while(i<size)
    {
        if(hashTable[i] == NULL)
            nr++;
        i++;
    }
    fillFactor = nr / size;
    return fillFactor;
}

void resizeHashTable(int N)
{
    //! reconstruct the hash table by (usually) doubling its size
    //! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR
    maxboom=0;
    int i;
    for(i=0; i<size; i++)
        free(hashTable[i]);
    int doubleN=N*2;
    res++;
    initHashTable(doubleN);
    //! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
    //! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)
}

int insertElement(char * element,int N)
{
    //! insert an element
    int bucket,boom=0;//here boom represents the number of collisions
    bucket=hashFunction(element,boom);
    while(boom<size)
    {
        if(hashTable[bucket]==NULL)
        {
            hashTable[bucket]=element;
            return boom;
        }
        boom++;
        bucket++;
        if(boom>maxboom)
            maxboom=boom;
    }
    if(getFillFactor()>MAX_FILL_FACTOR)
        resizeHashTable(N);
    return 0;
}




int hashFunction(char * content, int i)
{
   ///I don't think this is the best function.I kind of found it on the internet.
   ///Anyway,the max number of collisions  was reduced a bit so I guess it's still good XD
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k]+65;
    }
    return sum % size;
}


