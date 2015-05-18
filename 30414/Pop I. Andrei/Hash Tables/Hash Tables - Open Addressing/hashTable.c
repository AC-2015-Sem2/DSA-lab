//#include "header.h"
# include "hashTable.h"
//# include "io.h"

void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
    size = N * INITIAL_HT_SIZE_FACTOR;
    int i;

    hashTable = (char**) malloc (sizeof(char*) * size);

    for(i=0; i<size; i++)
        hashTable[i] = NULL;

   // int i;
    for(i=0; i<N; i++)
        collisions[i] = 0;
}

void printHashTableToConsole()
{
    int i;

    for(i=0; i<size; i++)
    {
        printf("B%d: ", i);
        if(hashTable[i]!=NULL)
            puts(hashTable[i]);
        puts("\n");
    }
}

void addToHashTable(int N)
{
    char **content = readFromFile(N);
    collisions = (int*) malloc (sizeof(int) *N);
    initHashTable(N);
    int nr=0;
    int k;
    float fill_factor;

    for(k=0; k<N; k++)
    {
        fill_factor = getFillFactor();
        if(fill_factor >MAX_FILL_FACTOR)
            resizeHashTable();

        collisions[k] += insertElement(content[k], size, hashTable);
        nr+=1;
        //printContentToConsole(hashTable, size);
    }

    //printf("\n%d  end", nr);
}

float getFillFactor()
{
    //! return the fill factor of the hash table
    float fillFactor = -1;
    float m = size;

    int nr = 0, i;

    for(i=0; i<size; i++)
        if(hashTable[i] != NULL)
            nr+=1;

    fillFactor = nr / m;

    return fillFactor;
}

void deleteHashTable(char **hash, int hashSize)
{
    int i;
    for(i=0; i<hashSize; i++)
        if(hash != NULL)
            free(hash[i]);
    free(hash);
}


void resizeHashTable(int N)
{
    //! reconstruct the hash table by (usually) doubling its size
    //! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR

    //! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
    //! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)

    char ** newHash;
    int newSize = size * 2, i;

    nrOfResizes+=1;

    newHash = (char**) malloc (newSize * sizeof(char*));

    for(i=0; i<newSize; i++)
        newHash[i] = NULL;

    // redistribute the elements of the old hash into the new hash

    for(i=0; i<size; i++)
    {
        if(hashTable[i] != NULL)
            collisions[i] += insertElement(hashTable[i], newSize, newHash);
    }

    //delete the old hash
    deleteHashTable(hashTable, size);

    //continue adding new elements into the new hash

    hashTable = newHash;
    size = newSize;
}

int insertElement(char * element, int hashSize, char **hash)
{
    //! insert an element
    //! returns the number of collisions which occurred before the element was inserted

    int i =0, poz = hashFunction2(element, i, hashSize);

    while(hash[poz] != NULL)
    {
        i+=1;
        poz = hashFunction2(element, i, hashSize);
    }


    hash[poz] = (char*) malloc (sizeof(char) * (MAX_STRING_LENGTH+1));
    strcpy(hash[poz], element);
    return i;
}

int maxCollisions(int N)
{
    int max = 0, i;

    for(i=0; i<N; i++)
        if(max < collisions[i])
            max = collisions[i];

    return max;
}

int hashFunction2(char *str, int i, int hashSize) // cea mai buna
{
    unsigned long hash = 0;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return (hash+i) %hashSize;

}

int hashFunction1(char * content, int i, int hashSize) //acceptabila
{
    int sum=0, k, c1 = 17, c2 = 29;

    for(k=0; k<strlen(content); k++)
        sum = sum+content[k];

    return (sum + i*c1 + i*i*c2) % hashSize;
}

int hashFunction0(char * content, int i, int hashSize) //acceptabila
{
    int sum=0, k, c1 = 17, c2 = 29;

    for(k=0; k<strlen(content); k++)
        sum = sum+content[k];

    return (sum + c1*i) % hashSize;
}
