//#include "header.h"
# include "hashTable.h"
//# include "io.h"

void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/4 of N)
    size = N * INITIAL_HT_SIZE_FACTOR;

    hashTable = (char**) malloc (sizeof(char*) * size);

}

void addToHashTable(int N)
{
    char **content = readFromFile(N);
    initHashTable(N);
    int k;
    float fill_factor;

    for(k=0; k<=N; k++)
    {
        fill_factor = getFillFactor();
            if(fill_factor >0.8)
                resizeHashTable();

        if(!insertElement(content[k], size, hashTable))
        {
            resizeHashTable();
            insertElement(content[k], size, hashTable);
        }
    }
}

float getFillFactor()
{
    //! return the fill factor of the hash table
    float fillFactor = -1;

    int nr, i;

    for(i=0; i<size; i++)
        if(hashTable[i] == NULL)
            nr+=1;

    fillFactor = nr / size;

    return fillFactor;
}

void deleteHashTable(char **hash, int hashSize)
{
    int i;

    for(i=0; i<hashSize; i++)
        free(hash[i]);

}


void resizeHashTable(int N)
{
    //! reconstruct the hash table by (usually) doubling its size
    //! only call this when the current fill factor of your hash table > MAX_FILL_FACTOR

    //! careful, when resizing, the 'size' variable should be changed as well such that the 'hashFunction's distribution will work
    //! be double careful! all the elements which are already in the hash table have to  be RE-hashed! (explanation @ lab)

    char ** newHash;
    int newSize = size * 2, i;

    newHash = (char**) malloc (newSize * sizeof(char*));

    for(i=0; i<newSize; i++)
    {
        newHash[i] = (char *) malloc (sizeof(char) * MAX_STRING_LENGTH);
    }

    // redistribute the elements of the old hash into the new hash

    for(i=0; i<size; i++)
    {
        if(hashTable[i] != NULL)
            insertElement(hashTable[i], newSize, newHash);
    }

    //delete the old hash
    deleteHashTable(hashTable, size);

    //continue adding new elements into the new hash

    hashTable = newHash;
}

int insertElement(char * element, int hashSize, char **hash)
{
    //! insert an element
    //! returns the number of collisions which occurred before the element was inserted

    int i =0, poz;

    do
    {
        poz = hashFunction(element, i, hashSize);
        if(hash[poz] == NULL)
        {
            hash[poz] = (char*) malloc (sizeof(char) * MAX_STRING_LENGTH);
            strcpy(hash[poz], element);
            return i;
        }
        i+=1;
    }while(i<=size);

    return 0;
}

int hashFunction(char * content, int i, int hashSize)
{
    int sum, k;

    for(k=0; k<strlen(content); k++)
        sum = sum+content[i] - 'A';

    return (sum + i) % hashSize;
}
