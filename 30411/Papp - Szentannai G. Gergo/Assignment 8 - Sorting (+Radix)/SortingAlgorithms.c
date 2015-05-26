#include "SortingAlgorithms.h"

void initFunctions(){
    inPlaceSortingFunctions[BUBBLE] = bubbleSort;
    inPlaceSortingFunctions[INSERTION] = insertionSort;
    inPlaceSortingFunctions[SELECTION] = selectionSort;
    inPlaceSortingFunctions[QUICKSORT] = quicksort;

    outOfPlaceSortingFunctions[MERGESORT] = mergeSort;
    outOfPlaceSortingFunctions[RADIX] = radixSort;
}


/****************************************************
******************* Bubble Sort *********************
****************************************************/
void bubbleSort(int *x, int n)
{
    int i,j=0;
    for(i=0; i<n; i++)
        for(j=0; j<n-i-1; j++)
        {
            comparisons++;
            if(x[j] > x[j+1])
            {
                int aux = x[j];
                x[j] = x[j+1];
                x[j+1]=aux;
                assignments+=3;
            }
        }
}


/****************************************************
******************* Insertion Sort ******************
****************************************************/
void insertionSort(int *x, int n)
{
    int i,j,tmp;
    for(i=1; i<n; i++)
    {
        j=i;
        comparisons+=2;
        while(j>0 && x[j-1]>x[j])
        {
            tmp=x[j];
            x[j]=x[j-1];
            x[j-1]=tmp;
            j--;
            assignments+=3;
        }
    }
}


/****************************************************
******************* Selection Sort ******************
****************************************************/
void selectionSort(int *x, int n)
{
    int i,j;
    int minI=0;

    for(i=0; i<n-1; i++)
    {
        minI=i;
        for(j=i+1; j<n; j++)
        {
            comparisons++;
            if(x[j] < x[minI])
            {
                minI = j;
            }

        }
        comparisons++;
        if(minI != i)
        {
            int aux=x[i];
            x[i]=x[minI];
            x[minI]=aux;
            assignments+=3;
        }
    }
}


/****************************************************
******************* Merge Sort **********************
****************************************************/
void merge(int *a, int low, int high, int mid, int *endResult)
{
    int h,i,j,k;
    h=low;
    i=0;
    j=mid+1;
    k=low;

    while((h<=mid)&&(j<=high))
    {
        comparisons++;
        if(a[h]<=a[j])
        {
            endResult[i]=a[h];
            assignments++;
            h++;
        }
        else
        {
            endResult[i]=a[j];
            assignments++;
            j++;
        }
        i++;
    }

    if(h>mid)
    {
        for(k=j; k<=high; k++)
        {
            endResult[i]=a[k];
            i++;
            assignments++;
        }
    }
    else
    {
        for(k=h; k<=mid; k++)
        {
            endResult[i]=a[k];
            i++;
            assignments++;
        }
    }

    for(k=0; k<=high-low; k++)
    {
        a[k+low]=endResult[k];
        assignments++;
    }
}

void mergeSortRecur(int *a, int low, int high, int *endResult)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergeSortRecur(a,low,mid,endResult);
        mergeSortRecur(a,mid+1,high,endResult);
        merge(a,low,high,mid,endResult);
    }
}

void mergeSort(int *a, int n, int *endResult){
    mergeSortRecur(a, 0, n-1, endResult);
}


/****************************************************
******************* Quick Sort **********************
****************************************************/
void swap(int *x,int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
    assignments+=3;
}

int choose_pivot(int i,int j )
{
    return((i+j) /2);
}

void qSort(int *x, int m, int n)
{
    int key,i,j,k;
    if( m < n)
    {
        k = choose_pivot(m,n);
        swap(&x[m],&x[k]);
        key = x[m];
        i = m+1;
        j = n;
        while(i <= j)
        {

            while((i <= n) && (x[i] <= key))
            {
                comparisons++;
                i++;
            }
            while((j >= m) && (x[j] > key))
            {
                comparisons++;
                j--;
            }
            if( i < j)
                swap(&x[i],&x[j]);
        }
        // swap two elements
        swap(&x[m],&x[j]);
        // recursively sort the lesser x
        qSort(x,m,j-1);
        qSort(x,j+1,n);
    }
}

void quicksort(int *x, int n){
    qSort(x, 0, n-1);
}


/****************************************************
******************* Radix Sort **********************
****************************************************/

void copyArray(int *a, int n, int *endResult)
{
    int i;
    for (i=0; i<n; i++)
    {
        *(a+i) = *(endResult+i);
        assignments++;
    }

}

int getLenghtOfMax(int *a, int n) // only for positive integers!
{
    int aux = *a;
    int i;
    for (i=1; i<n; i++)
    {
        if (*(a+i)>aux)
        {
            aux = *(a+i);
            comparisons++;
            assignments++;
        }

    }
    i = 1;
    while(aux>9)
    {
        i++;
        aux = aux/10;
        assignments = assignments+2;
    }
    return i;
}

void radixSort(int *a, int n, int *endResult)  //! LSD (Least Significant Digit) radix sort
{

    int Radix = 10;
    int level = 1;  // number of digit to compare (tens, hundreds, etc.)
    int nrOfLevels = getLenghtOfMax(a, n);
    int k;

    for (k = 0; k < nrOfLevels; k++)
    {
        int pos = 0;
        int i = 0;
        int j;

        for (i=0; i<Radix; i++)
        {
            for (j=0; j<n; j++)
            {
                if ((a[j]/level)%Radix == i)
                {
                    comparisons++;
                    *(endResult+pos) = *(a+j); // arranging in new array
                    pos++;
                    assignments = assignments+2;
                }
            }
        }
        copyArray(a, n, endResult); // partially sorted array becomes the next one to be sorted
        level = level*10; // increase level
        assignments++;
    }
}


/***************** Other Functions *****************/

void resetCounters()
{
    comparisons=0;
    assignments=0;
}







