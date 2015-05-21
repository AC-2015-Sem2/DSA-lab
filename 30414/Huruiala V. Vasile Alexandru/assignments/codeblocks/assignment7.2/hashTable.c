#include "hashTable.h"
#include <math.h>

void initHashTable(listT** hashTable, int* size, int N)
{
    *size = N * INITIAL_HT_SIZE_FACTOR;
    *hashTable = (listT*)malloc(*size * sizeof(listT));
    int i;
    for(i = 0; i < *size; i++)
    {
        (*hashTable)[i].head = NULL;
        (*hashTable)[i].tail = NULL;
        (*hashTable)[i].size = 0;
    }
}

void insertAllElements(listT* hashTable, int size, int N, char** content)
{
    int i;
    for(i = 0; i < N; i++)
        insertElement(hashTable, size, content[i]);
}

void insertElement(listT* hashTable, int size, char* element)
{
    int Hash = hashFunction3(element, size);
    addToList(&hashTable[Hash], element);
}

double sqr(double x){return x * x;}

void computeDistributionsPerBucket(listT* hashTable, int size, int N, FILE* O)
{
    int i;
    //Find the maximum number of elements in a bucket to associate with the maximum amount of stars on a row
    int maxElements = -1;
    for(i = 0; i < size; i++)
        if(maxElements < hashTable[i].size || maxElements == -1)
            maxElements = hashTable[i].size;

    //128 works well in files
    //also printing in stdout is very slow
    int maxStars = 128;

    for(i = 0; i < size; i++)
    {
        fprintf(O, "B[%6d]: ", i);
        //The order matters since decimals can be lost
        int stars = (double)maxStars * ((double)hashTable[i].size / (double)maxElements);
        int j;
        for(j = 0; j < stars; j++)
            fprintf(O, "*");
        for(j = stars; j < maxStars; j++)
            fprintf(O, " ");

        fprintf(O, "| %10lf%%\n", 100 * (double)stars/maxStars);
    }
    fprintf(O, "Maximum Elements: %d\nMax stars per row: %d\n", maxElements, maxStars);

    //computing the standard deviation
    int sum = 0;
    for(i = 0; i < size; i++)
        sum += hashTable[i].size;

    double average = (double)sum/(double)N;

    double sumOfDeviations = 0.0;
    for(i = 0; i < size; i++)
        sumOfDeviations += sqr(hashTable[i].size - average);

    double variance = sumOfDeviations / (double)N;

    double standardDeviation = sqrt(variance);

    fprintf(O, "Standard Deviation: %lf\n", standardDeviation);
}

int sumOfChars(char* element)
{
    int sum = 0;
    int i;
    for(i = 0; element[i] != '\0'; i++)
        sum += element[i];
    return sum;
}

int reverseSumOfChars(char* element)
{
    int sum = 0;
    int i;
    for(i = 0; element[i] != '\0'; i++)
        sum += 255 - element[i];
    return sum;
}

int prodOfChars(char* element)
{
    int prod = 1;
    int i;
    for(i = 0; element[i] != '\0'; i++)
        prod *= element[i];
    return prod;
}

int function1OfChars(char* element)
{
    int x = 0;
    int i;
    for(i = 0; element[i] != '\0'; i++)
        x += element[i] % 2;
    return x;
}

int function2OfChars(char* element)
{
    int x = 0;
    int i;
    for(i = 0; element[i] != '\0'; i++)
        x += element[i] % 3;
    return x;
}

long double functionLogOfChars(char* element)
{
    long double x = 0;
    int i;
    for(i = 0; element[i] != '\0'; i++)
        x += log(element[i]);
    return x;
}

long double functionSinOfChars(char* element)
{
    long double x = 0;
    int i;
    for(i = 0; element[i] != '\0'; i++)
        x += sin(element[i]);
    return x;
}

long double functionCosOfChars(char* element)
{
    long double x = 0;
    int i;
    for(i = 0; element[i] != '\0'; i++)
        x += cos(element[i]);
    return x;
}

///Hash functions

int hashFunction0(char* content, int size)
{
    long double Sin = functionSinOfChars(content);
    long double Cos = functionCosOfChars(content);

    return (int)fabs(Sin * Cos) % size;
}

int hashFunction1(char* content, int size)
{
    int sum = sumOfChars(content);

    return (int)fabs(sum) % size;
}

int hashFunction2(char* content, int size)
{
    int sum = sumOfChars(content);
    int rum = reverseSumOfChars(content);
    int Prod = prodOfChars(content);
    long double Log = functionLogOfChars(content);

    return (int)fabs(sum * rum + Prod - Log) % size;
}

int hashFunction3(char* content, int size)
{
    int sum = sumOfChars(content);
    int rum = reverseSumOfChars(content);
    int f1 = function1OfChars(content);
    int f2 = function2OfChars(content);
    long double Log = functionLogOfChars(content);
    long double Sin = functionSinOfChars(content);
    long double Cos = functionCosOfChars(content);

    return (int)fabs(sum * f1 + rum * f2 + Log + Sin + Cos) % size;
}
