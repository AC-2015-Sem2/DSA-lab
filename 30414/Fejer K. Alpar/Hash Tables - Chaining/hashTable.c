#include "hashTable.h"


void addElements(char** content, int N)
{
    int i;

    for (i=0; i<N ; i++) insertElement((content+i));
}

void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/3 of N)
    //! also the size variable has to be initialized

    int i;
    size=N*INITIAL_HT_SIZE_FACTOR;
    hashTable=(listT*) malloc (size*sizeof(listT));
    for (i=0; i<size; i++)
    {
        hashTable[i].size=0;
    }
}

void insertElement(char * element)
{
    //! insert an element
    int hash;
    addToList(&hashTable[hashFunction3(element)],element);
}

int hashFunction1(char * content)
{
    //! keep in mind, size in this case simply means the number of buckets

    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
    return sum % size;
}

int hashFunction0(char * content)
{
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }

    return sum % 2;
}

int hashFunction2(char * content)
{
    int length=strlen(content);
    int k,sum=0;
    for (sum=0, k=length-1; k>=0; k--)
        sum+=content[k]*k;
    return sum % size;
}

int hashFunction3(char* content)
{
    int length=strlen(content);
    int j,k,pow,sum=0;
    for (sum=0, k=length-1; k>=0; k--)
    {
        for (pow=1,j=0; j<k; j++) pow=pow*content[k];
        sum+=pow;
    }
    return sum % size;
}

void computeDistributionsPerBucket()
{
    //! computes the distribution of elements for each bucket
    //! the output should look something like:
    /**
        MAX = 'x' * 20

        B0: ********** (~50%)
        B1: ************ (~60%)
        B2: ****** (~30%)
        B3: ******* (~35%)
        .....


        hint : the bigger you choose X, the better approximation
        hint2: choose it somewhere between 20-40 such that it fits in one row in the console nicely
    */

    int k=0,i,j,max=50,maxSize=0;
    float nr,percent;


    for(i=0; i<size; i++) if (hashTable[i].size>maxSize) maxSize=hashTable[i].size;

    printf("MAX = '*' x 50 \n \n");

    for(i=0; i<size; i++)
    {

        nr=(max*hashTable[i].size)/maxSize;
        percent=(100*hashTable[i].size)/maxSize;
        printf("B%3d: ",k);
        for (j=0; j<nr; j++) printf("*");
        printf("(%.1f \%%)\n",percent);
        k++;

    }
}
