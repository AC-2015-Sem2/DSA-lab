#include "hashTable.h"
#include "io.h"
#include<string.h>

void initHashTable(int N)
{
    int i;

    nrOfCollisions = (int*) malloc(sizeof(int) * N);
    for(i=0;i<N;i++)
        nrOfCollisions[i]=0;
    size=INITIAL_HT_SIZE_FACTOR * N;

    hashTable=(char**)malloc(sizeof(char*)*size);

    for(i=0;i<size;i++)
    {
        hashTable[i]=(char*)malloc(sizeof(char)*MAX_STRING_LENGTH);
        hashTable[i]=NULL;
    }

    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
}

float getFillFactor()
{
    //! return the fill factor of the hash table
    float fillFactor = -1;
    int i;
    int nrOfComponents=0;
    for(i=0;i<size;i++)
    {
        if(hashTable[i] != NULL)
            nrOfComponents++;
    }

    fillFactor =(float) nrOfComponents / size;
    return fillFactor;
}

void resizeHashTable()
{
    int i;
   // for(i=0;i<size;i++)
    //{
      //  free(hashTable[i]);
    //}

   /* for(i=size; i<2*size; i++)
    {
         hashTable[i]=(char*)malloc(sizeof(char)*MAX_STRING_LENGTH);

    }*/

    size=size*2;

    for(i=0;i<size;i++)
    {
        hashTable[i]=NULL;
    }



    //! reconstruct the hash table by (usually) doubling its size
    //! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR

    //! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
    //! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)
}

int insertElement(char *element, int i)
{
    int nrOfCollisions=0;

    if(getFillFactor()>=MAX_FILL_FACTOR)
    {
        resizeHashTable();
        return -1;
    }
    else
    {
        if(hashTable[i] == NULL)
        {
            hashTable[i]=element;
        }
        else
        {
            nrOfCollisions++;
            i++;
        }
    }


    //! insert an element
    //! returns the number of collisions which occurred before the element was inserted

    return nrOfCollisions;
}


int hashFunction(char * content, int i)
{

    //! H1

    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }

    return (sum+i) % size;


    //! H2

   /* unsigned int x = 1315423911;
    unsigned int j    = 0;

    int len = strlen(content);

    for(j = 0; j < len; content++, j++)
    {
        x ^= ((x << 5) + (*content) + (x >> 2));
    }
    return x;
    */

    //!  H3

    /*unsigned int x = 0;
    unsigned int y    = 0;
    unsigned int j    = 0;

    int len = strlen(content);

    for(j = 0; j < len; content++, j++)
    {
        x = (x << 4) + (*content);
        if((y = x & 0xF0000000L) != 0)
        {
            x ^= (y >> 24);
        }
        x &= ~y;
    }
*/

    //return y;
}
