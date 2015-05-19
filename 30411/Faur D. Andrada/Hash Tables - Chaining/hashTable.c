#include "hashTable.h"
#include "io.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void initHashTable(int N)
{
    //! initialize hash table with length "INITIAL_HT_SIZE_FACTOR" of N (1/3 of N)
    //! also the size variable has to be initialized
    size=N*INITIAL_HT_SIZE_FACTOR;
    hashTable=(listT*) malloc(sizeof(listT)*size);
    int i;
    for (i=0;i<size;i++)
    {
        hashTable[i].head=NULL;
        hashTable[i].tail=NULL;
        hashTable[i].size=0;
    }
    char ** content = readFromFile(N);
    for (i=0;i<size;i++)
    {
        insertElement(content[i]);
    }


}

void insertElement(char * element)
{
    //! insert an element
    int pos=hashFunction(element,0);
addToList(&hashTable[pos],element);
}

/*int hashFunction(char * content, int i)
{
    //! keep in mind, size in this case simply means the number of buckets
    int length = strlen(content);//!hashfunction 0
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k];
    }
    return sum % size;

}
*/
/*
int hashFunction(char * content, int i) //!hashfunction 1
{
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += (content[k]*content[k])/4;
    }
    return (sum+i) % size;

}
*/
/*
int hashFunction(char * content, int i) //!hashfunction 2
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
*/
int hashFunction(char * content, int i) //!hashfunction 3
{
    int length = strlen(content);
    int k, sum;
    for (sum=0, k=0; k < length; k++)
    {
        sum += content[k]*content[k];
    }
    sum=sum/length;
    return (sum+i) % size;

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

int i;int contor,lengthstar;
   int maxsize=0;
   for (i=0;i<size;i++)
   {
     if (maxsize<hashTable[i].size)
     {
        maxsize=hashTable[i].size;
     }
   }
   printf("maxsize: %d \n",maxsize);

   for (i=0;i<size;i++)
   {
       lengthstar=(float)hashTable[i].size /maxsize*20.00;
       printf("\n B%d :",i);
       for(contor=0;contor<lengthstar;contor++)
       {
           printf("*");
       }
       printf("(%d %%) " ,hashTable[i].size*100/maxsize);
   }

}


void computeStandardDeviation(int N)
{
    int i,dev;
    for(i=0;i<size;i++)
    {
        dev+=(hashTable[i].size)*i;
    }
    printf("Standard deviation is: %d",dev/N );
}
