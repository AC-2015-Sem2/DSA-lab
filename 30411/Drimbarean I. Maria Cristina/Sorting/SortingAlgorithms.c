#include "SortingAlgorithms.h"

void initFunctions(){
    inPlaceSortingFunctions[BUBBLE] = bubbleSort;
    inPlaceSortingFunctions[INSERTION] = insertionSort;
    inPlaceSortingFunctions[SELECTION] = selectionSort;
    inPlaceSortingFunctions[QUICKSORT] = quicksort;

    outOfPlaceSortingFunctions[MERGESORT] = mergeSort;
    outOfPlaceSortingFunctions[RADIXSORT]=radixSort;
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

void resetCounters()
{
    comparisons=0;
    assignments=0;
}
/****************************************************
******************* RADIX Sort **********************
****************************************************/

int findMaxNrOfDigits(int *a,int n)
{
    int i,maxR=32.767;
    for (i=0;i<n;i++)
    {
        if (a[i]>maxR)
        {
           maxR=a[i];
           comparisons++;
        }
    }
    i=0;
    while (maxR>0)
    {
        i++;
        maxR=maxR/10;
    }
    return i;
}
nodeT * createNode(int content){
    nodeT * newN = (nodeT*)malloc(sizeof(nodeT));
    newN->key=content;
    newN->next=NULL;
    return newN;
}
void enqueue(queueT *queue, int content)
{
    if(queue->head == NULL){
        queue->head = createNode(content);
    }else{
        nodeT * aux = queue->head;
        while(aux->next!=NULL){
            aux=aux->next;
        }
        aux->next=createNode(content);
    }
}
void dequeue(queueT *queue){
    if(queue->head!=NULL){
        queue->head=queue->head->next;
    }
}
int isEmptyQueue(queueT queue){
    return queue.head == NULL;
}
void radixSort(int *a,int n, int *endResult)
{
    queueT *queue=(queueT*)malloc(sizeof(queueT)*10);
    int k;
    for(k=0;k<10;k++)
    {
        queue[k].head=NULL;
    }
    int d=findMaxNrOfDigits(a,n);
    int j,i=0;
    int m=10;
    int mm=1;
    endResult=a;
    assignments+=n;
    while (i<d)
    {
        for (j=0;j<n;j++)
        {
           int key=endResult[j] % m;
           key=key/mm;
           enqueue(&queue[key],endResult[j]);
           assignments++;
        }
          int c=0;
        for (j=0;j<10;j++)
        {
            while (isEmptyQueue(queue[j]))
            {
                endResult[c]=queue[j].head->key;
                c++;
                dequeue(&queue[j]);
            }
        }
       m=m*10;
       mm=mm*10;
       i++;
    }
    //printf("\n\n");
    //printToScreen(a,n);
}





