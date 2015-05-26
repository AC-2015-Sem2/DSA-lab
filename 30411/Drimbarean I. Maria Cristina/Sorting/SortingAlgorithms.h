#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "HelperFunctions.h"
typedef struct node
{
    int key;
    struct node* next;
}nodeT;
typedef struct queue
{
    nodeT *head;
}queueT;
enum inPlaceSortingFunctions{
    BUBBLE = 0,
    INSERTION = 1,
    SELECTION = 2,
    QUICKSORT = 3
};

enum outOfPlaceSortingFunctions{
    MERGESORT = 0,
    RADIXSORT=1
};

static const char* inPlaceSortingFunctionNames[] = { "Bubble Sort", "Insertion Sort", "Selection Sort", "Quicksort" };
static const char* outOfPlaceSortingFunctionNames[] = { "Merge Sort", "Radix Sort" };

//! counters which will be reset after each sorting execution
long comparisons;
long assignments;

//! 3 in-place sorting functions (bubble, insertion, selection, quicksort)
void (*inPlaceSortingFunctions[4])(int *x, int n);

//! 1 out-of-place sorting functions (merge,radixsort)
void (*outOfPlaceSortingFunctions[2])(int *a, int n, int *endResult);

void initFunctions();

void resetCounters();

//! in-place sorting functions
void bubbleSort(int *x, int n);
void insertionSort(int *x, int n);
void selectionSort(int *x, int n);
void quicksort(int *x, int n);

//! out-of-place sorting functions
void mergeSort(int *a, int n, int *endResult);
void radixSort(int *a,int n,int *endResult);
