#include "hashTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void initHashTable(int N)
{
    size=INITIAL_HT_SIZE_FACTOR*N;
    ///allocate memory for the hash Table
    hashTable=(listT*)malloc(size*sizeof(listT));
    int i;
    for (i=0;i<size;i++)
    {
        hashTable[i].head=NULL;
        hashTable[i].tail=NULL;
        hashTable[i].size=0;
    }
}

void insertElement(char * element)
{
    static int i=0;
    i++;
    //! insert an element
    int k=hashFunction(element);
    addToList(&hashTable[k],element);
}

void computeDistributionsPerBucket()
{
    printf("\nDISTRIBUTION PER BUCKET STARTS\n");
    int max=0;
    int i;
    for (i=0;i<size;i++)
    {
        if (hashTable[i].size>max)
        {
            max=hashTable[i].size;
        }
    }
    int x=30;
    for (i=0;i<size;i++)
    {
        int y=(hashTable[i].size*x)/max;
        int j=0;
        while(j<y)
        {
            printf("* ");
            j++;
        }
        printf("\n");
    }
    printf("\nDISTRIBUTION PER BUCKET ENDED\n");
}

float getStandardDeviation()///not so sure it's correct... i've tried transposing some mathematical formulas in the code
{
    float miu;
    int i; float sum=0;
    for(i=0;i<size;i++)
    {
        sum+=hashTable[i].size;
    }
    miu=sum/size;

    float delta;
    sum=0;
    for(i=0;i<size;i++)
    {
        sum=+pow(hashTable[i].size-miu,2)/size;
    }
    delta=sqrt(sum);
    return delta;
}
/********* TERRITORY OF HASH FUNCTIONS *************************************/

int h0(char * content)
{
    return (content[1]%size);
}

int h1(char* content)
{
    int k;
    int sum=0;
    int length = strlen(content);
    for (k=0; k < length; k++)
    {
        sum += content[k];
    }
    return sum % size;

}
///h2 related stuff

char* convert(int n)///get the binary representation
{
    char*s=(char*)malloc(sizeof(char)*33);
    s[0]=0;
    int c, k;
    for (c = 31; c >= 0; c--)
    {
        k = n >> c;

        if (k & 1)
        strncat(s,"1",1);
            else
        strncat(s,"0",1);
    }
    return s;
}

int partitionsSum(char *s)
{
    int sum=0;
    int i;
    for (i=0;i<8;i++)
    {

        char * partition=malloc(sizeof(char)*5);
        partition[0]=0;
        strncat(partition,s+i*4,4);
        int nr;
        sscanf(partition,"%d",&nr);
        sum+=nr;
    }
    return sum;
}

int h2(char*element)///component sum... sort of :?
{
    int sum=0;
    int n=strlen(element);
    int i;
    for (i=0;i<n;i++)
    {
        char* s=convert(element[i]);
        int sum1=partitionsSum(s);
        sum+=sum1;
    }
    return sum%size;
}
int h3(char*element)
{
    return (h1(element)+h2(element))%size;
}
