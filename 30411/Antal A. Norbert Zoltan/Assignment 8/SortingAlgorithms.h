#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

enum inPlaceSortingFunctions{
    BUBBLE = 0,
    INSERTION = 1,
    SELECTION = 2,
    QUICKSORT = 3,
    RADIXSORT = 4
};

enum outOfPlaceSortingFunctions{
    MERGESORT = 0
};

static const char* inPlaceSortingFunctionNames[] = { "Bubble Sort", "Insertion Sort", "Selection Sort", "Quicksort", "Radix Sort" };
static const char* outOfPlaceSortingFunctionNames[] = { "Merge Sort" };

//! counters which will be reset after each sorting execution
long comparisons;
long assignments;

//! 3 in-place sorting functions (bubble, insertion, selection, quicksort)
void (*inPlaceSortingFunctions[5])(int *x, int n);

//! 1 out-of-place sorting functions (merge)
void (*outOfPlaceSortingFunctions[1])(int *a, int n, int *endResult);

void initFunctions();

void resetCounters();

//! in-place sorting functions
void bubbleSort(int *x, int n);
void insertionSort(int *x, int n);
void selectionSort(int *x, int n);
void quicksort(int *x, int n);
void radixSort(int*, int);

//! in-place sorting functions
void mergeSort(int *a, int n, int *endResult);


