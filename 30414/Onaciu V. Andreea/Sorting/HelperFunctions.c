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

char * formFileName(const char * funct, char * type){
    char *filename = (char*) malloc(sizeof(char) * 75);
    strcpy(filename,"results/");
    strcat(filename,funct);
    strcat(filename,"-");
    strcat(filename,type);
    strcat(filename,".csv");
    return filename;
}

/**********Helper Functions for Radix Sort *************/



sentinel* initializeQueueArray(int n)
{
    int i;
    sentinel *array=(sentinel *)malloc(n*sizeof(sentinel));
    for (i=0;i<n;i++){
        array[i].head=NULL;
    array[i].tail=NULL;}
    return array;
}

void enqueue(sentinel* q,int x)
{
    if (q->head==NULL)
    {
        q->head=(nodQueue *)malloc(sizeof(nodQueue));
        q->head->next=NULL;
        q->head->data=x;
        q->tail=q->head;
    }
    else
    {
        nodQueue *newnode=(nodQueue *)malloc(sizeof(nodQueue));
        newnode->data=x;
        q->tail->next=newnode;
        newnode->next=NULL;
        q->tail=newnode;
    }
}

int dequeue(sentinel* q)
{
    if (q->head!=NULL)
    {
        nodQueue *first=q->head;
        q->head=q->head->next;
        int x=first->data;
        free(first);
        if (q->head==NULL)
            q->tail=NULL;
            return x;
    }
    return 0;
}
int maxNrOfDigits(int *x,int n)
{
    int max=0;
    int i;
    for (i=0;i<n;i++)
    {
        int aux=x[i];
        int nrOfDigits=0;
        while (aux>0)
            {
            aux=aux/10;
            nrOfDigits++;
            }
        if (nrOfDigits>max) max=nrOfDigits;
    }
    return max;
}
int itsEmpty(sentinel* x)
{
  return x->head==NULL;
}
