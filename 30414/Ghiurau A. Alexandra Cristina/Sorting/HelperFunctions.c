#include "HelperFunctions.h"
#include "SortingAlgorithms.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void allocateMem(int **x, int n){
    *x = (int*)malloc(sizeof(int)*n);
}

void generateWorst(int **x, int n)
{
    allocateMem(x,n);
    int i=0;
    for(i=n-1; i>=0; i--)
    {
        *(*x+i)=n-i;
    }
}

void generateBest(int **x, int n)
{
    allocateMem(x,n);
    int i=0;
    for(i=0; i<n; i++)
    {
        *(*x+i)=i;
    }
}

void generateAverage(int **x, int n)
{
    allocateMem(x,n);
    int i=0;
    for(i=0; i<n; i++)
        *(*x+i)=rand();
}

void printToScreen(int *x, int n)
{
    int i=0;
    for(i=0; i<n; i++)
        printf("%d ",x[i]);
}

void resetArray(int **x, int n)
{
    if(*x==NULL)
        *x = (int*)malloc(sizeof(int)*n);
    memset(*x, 0, n * sizeof(int));
}

void removeFiles()
{
    printf("Removing files...\n");

    int rows=(sizeof(inPlaceSortingFunctionNames)/sizeof(inPlaceSortingFunctionNames[0]));
    int i;

    for(i=0;i<rows;i++){
        remove(formFileName(inPlaceSortingFunctionNames[i],"Best"));
        remove(formFileName(inPlaceSortingFunctionNames[i],"Average"));
        remove(formFileName(inPlaceSortingFunctionNames[i],"Worst"));
    }

    rows=(sizeof(outOfPlaceSortingFunctionNames)/sizeof(outOfPlaceSortingFunctionNames[0]));
    for(i=0;i<rows;i++){
        remove(formFileName(outOfPlaceSortingFunctionNames[i],"Best"));
        remove(formFileName(outOfPlaceSortingFunctionNames[i],"Average"));
        remove(formFileName(outOfPlaceSortingFunctionNames[i],"Worst"));
    }

    printf("Done!\n");
}
int getMax(int *x, int n)
{
    int max = x[0];
    int i;
    for(i=0; i<n; i++)

        if(x[i] > max)
            max = x[i];
        return max;

}
//! A function to do counting sort of *x according to the digit represented by exp
void countSort(int *x, int n, int exp, int *endResult)
{
    //int *output = (int*)malloc(n* sizeof(int));
    int i;

    int count[10] = {0};

    for(i=0; i<n; i++)
    {
        count[(x[i]/exp)%10]++;
    }

    for(i=1; i<10; i++)
    {
        count[i]+= count[i-1];
    }

    for(i=n-1; i>=0; i--)
    {
        endResult[count[(x[i]/exp)%10]-1] = x[i];
        count[(x[i]/exp)%10]--;
    }

    for(i=0; i<n ;i++)
        x[i] = endResult[i];
}
char * formFileName(const char * funct, char * type){
    char *filename = (char*) malloc(sizeof(char) * 75);
    strcpy(filename,"results/");
    strcat(filename,funct);
    strcat(filename,"-");
    strcat(filename,type);
    strcat(filename,".csv");
    return filename;
}

