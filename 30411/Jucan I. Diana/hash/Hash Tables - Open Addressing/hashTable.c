#include "hashTable.h"
#include "io.h"
# include <string.h>


void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
   char ** content = readFromFile(N);
    int j;
    if(res==1)
        size=N*INITIAL_HT_SIZE_FACTOR;
    else
     size=N*getFillFactor();
    int i;
    hashTable=(char**)malloc(sizeof(char*)*size);

    for(i=0; i<size; i++)
    {
        hashTable[i]=(char*)malloc(sizeof(char)*MAX_STRING_LENGTH);
        hashTable[i]=NULL;
        j=insertElement(content[i],N);
        printf("the number of collisions at element %d is %d\n\n",i,j);
    }
    printf("\nthe max number of collisions is %d\n",nrmax);
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

    //! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
    //! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)

    nrmax=0;
    int i;
    for(i=0; i<size; i++)
        free(hashTable[i]);
    int doublesize=N*2;
    res++;
    initHashTable(doublesize);
}

int insertElement(char * element,int N)
{
    //! insert an element
    //! returns the number of collisions which occurred before the element was inserted

    int bucket,nrofcol=0;
    bucket=hashFunction(element,nrofcol);
    while(nrofcol<size)
    {
        if(hashTable[bucket]==NULL)
        {
            hashTable[bucket]=element;
            return nrofcol;
        }
        nrofcol++;
        bucket++;
        if(nrofcol>nrmax)
            nrmax=nrofcol;
    }
    if(getFillFactor()>MAX_FILL_FACTOR)
        resizeHashTable(N);
    return 0;
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

int hashFunction1(char * content, int i)
{
	int	my_hash, length, j;

	length = strlen(content);
	my_hash = 0;
	for (j = 0 ; j < length ; ++j)
	{
		my_hash += content[j];
	}
	my_hash -= length;
	my_hash %= (length / 2 + 11);
	my_hash *= length;
    return (my_hash + i) % size;
}
int hashFunction2(char * content, int i)
{
	int	my_hash, length, j;

	length = strlen(content);
	my_hash = 0;
	for (j = 0 ; j < length ; ++j)
	{
		my_hash += content[j]-1;
	}
	my_hash -= length-1;
	my_hash %= (length / 2 +8);
	my_hash *= length-2;
    return (my_hash + i) % size;
}

int hashFunction3(char* content) {
    long hash = 5381;
    char* str = content;

    while (*str) {
        hash = ((hash << 5) + hash) + (int)(*str); /* hash * 33 + c */
        str++;
    }
    return abs(hash)%size;
}
