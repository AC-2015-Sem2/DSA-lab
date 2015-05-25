#include "SortingAlgorithms.h"
#include "HelperFunctions.h"

int MAX = 1000;
int MIN = 100;
int STEP = 100;

void changeConstants();

void inPlaceSort(void (*funct)(int *, int), int which);
void outOfPlaceSort(void (*funct)(int *a, int n, int *endResult), int which);

int main()
{
    printf("A - Bubble Sort\nB - Insertion Sort\nC - Selection Sort\nD - Merge Sort\nE - QuickSort\nF - All Sorting Algorithms\nX - Remove Files\nN - Change constants\nQ - Quit\n");
    initFunctions();

    char choice;
    while(1)
    {
        printf("Choice: ");
        choice = getch();
        printf("\n");
        switch(choice)
        {
        case 'A':
            inPlaceSort(inPlaceSortingFunctions[BUBBLE], BUBBLE);
            break;

        case 'B':
            inPlaceSort(inPlaceSortingFunctions[INSERTION], INSERTION);
            break;

        case 'C':
            inPlaceSort(inPlaceSortingFunctions[SELECTION], SELECTION);
            break;

        case 'D':
            outOfPlaceSort(outOfPlaceSortingFunctions[MERGESORT], MERGESORT);
            break;

        case 'E':
            inPlaceSort(inPlaceSortingFunctions[QUICKSORT], QUICKSORT);
            break;

        case 'F':
            inPlaceSort(inPlaceSortingFunctions[BUBBLE], BUBBLE);
            inPlaceSort(inPlaceSortingFunctions[INSERTION], INSERTION);
            inPlaceSort(inPlaceSortingFunctions[SELECTION], SELECTION);
            outOfPlaceSort(outOfPlaceSortingFunctions[MERGESORT], MERGESORT);
            inPlaceSort(inPlaceSortingFunctions[QUICKSORT], QUICKSORT);
            break;
        case 'X':
            removeFiles();
            break;

        case 'N':
            changeConstants();
            break;

        case 'Q':
            exit(0);
            break;

        default:
            printf("Bad Operation!\n");
            break;
        }
    }

    return 0;
}

void inPlaceSort(void (*funct)(int *, int), int which){
    printf("Performing %s with MIN = %d, MAX = %d and STEP = %d\n\n",inPlaceSortingFunctionNames[which],MIN,MAX,STEP);
    FILE *fpBest,*fpWorst,*fpAverage;
    int currentCount;
    //! Bubble Sort
    fpBest = fopen(formFileName(inPlaceSortingFunctionNames[which],"Best"),"w");
    fpAverage = fopen(formFileName(inPlaceSortingFunctionNames[which],"Average"),"w");
    fpWorst = fopen(formFileName(inPlaceSortingFunctionNames[which],"Worst"),"w");
    for(currentCount=MIN; currentCount<=MAX; currentCount+=STEP)
    {
        int *a;
        generateBest(&a,currentCount);
        (*funct)(a,currentCount);
        fprintf(fpBest,"%d,%lu,%lu,%lu\n",currentCount,assignments,comparisons,assignments+comparisons);
        resetCounters();


        generateAverage(&a,currentCount);
        (*funct)(a,currentCount);
        fprintf(fpAverage,"%d,%lu,%lu,%lu\n",currentCount,assignments,comparisons,assignments+comparisons);
        resetCounters();

        generateWorst(&a,currentCount);
        (*funct)(a,currentCount);
        fprintf(fpWorst,"%d,%lu,%lu,%lu\n",currentCount,assignments,comparisons,assignments+comparisons);
        resetCounters();
        printf("N: %d\n",currentCount);
    }
    fclose(fpBest);
    fclose(fpAverage);
    fclose(fpWorst);
    printf("Finished %s with MIN = %d, MAX = %d and STEP = %d\n\n",inPlaceSortingFunctionNames[which],MIN,MAX,STEP);
}

void outOfPlaceSort(void (*funct)(int *a, int n, int *endResult), int which){
    printf("Performing %s with MIN = %d, MAX = %d and STEP = %d\n\n",outOfPlaceSortingFunctionNames[which],MIN,MAX,STEP);
    FILE *fpBest,*fpWorst,*fpAverage;
    int currentCount;
    //! Insertion Sort
    fpBest = fopen(formFileName(outOfPlaceSortingFunctionNames[which],"Best"),"w");
    fpAverage = fopen(formFileName(outOfPlaceSortingFunctionNames[which],"Average"),"w");
    fpWorst = fopen(formFileName(outOfPlaceSortingFunctionNames[which],"Worst"),"w");
    for(currentCount=MIN; currentCount<=MAX; currentCount+=STEP)
    {
        int *a, *b=NULL;
        resetArray(&b,currentCount);
        generateBest(&a,currentCount);
        (*funct)(a, currentCount,b);
        fprintf(fpBest,"%d,%lu,%lu,%lu\n",currentCount,assignments,comparisons,assignments+comparisons);
        resetCounters();

        resetArray(&b,currentCount);
        generateAverage(&a,currentCount);
        (*funct)(a, currentCount,b);
        fprintf(fpAverage,"%d,%lu,%lu,%lu\n",currentCount,assignments,comparisons,assignments+comparisons);
        resetCounters();

        resetArray(&b,currentCount);
        generateWorst(&a,currentCount);
        (*funct)(a, currentCount,b);
        fprintf(fpWorst,"%d,%lu,%lu,%lu\n",currentCount,assignments,comparisons,assignments+comparisons);
        resetCounters();

        printf("N: %d\n",currentCount);
    }
    fclose(fpBest);
    fclose(fpAverage);
    fclose(fpWorst);
    printf("Finished %s with MIN = %d, MAX = %d and STEP = %d\n\n",outOfPlaceSortingFunctionNames[which],MIN,MAX,STEP);
}

void changeConstants()
{

    printf("New MIN: ");
    scanf("%d",&MIN);
    printf("\n");

    printf("New MAX: ");
    scanf("%d",&MAX);
    printf("\n");

    printf("New STEP: ");
    scanf("%d",&STEP);
    printf("\n");

}
