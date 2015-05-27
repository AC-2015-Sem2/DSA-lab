# include "radix.h"
# include "list.h"

void initialize(int n)
{
    initArray = (int*) malloc (sizeof(int) *n);
    head = (NodeT**) malloc (sizeof(NodeT*) * 9);
    tail = (NodeT**) malloc (sizeof(NodeT*) * 9);

    int i;

    for(i=0; i<=9; i++)
        head[i] = NULL;

}

void readInitArray(FILE *in)
{
    fscanf(in, "%d", &n);
    initialize(n);

    int i;

    for(i=0; i<n; i++)
        fscanf(in, "%d", &initArray[i]);
}

int findMaxNrOfDigits()
{
    int max = 0, i, nrMax = 0;

    for(i=0; i<n; i++)
        if(max < initArray[i])
            max = initArray[i];

    while(max != 0)
    {
        nrMax += 1;
        max /= 10;
    }

    return nrMax;
}

void compareByDigit(int power)
{
    int i, digit;

    for(i=0; i<n; i++)
    {
        digit = (initArray[i] / power) % 10;
        addToList(initArray[i], digit);
    }
}

void reBuildArray()
{
    int i = 0, ind = 0;
    NodeT *p;

    for(i=0; i<=9; i++)
    {
        p = head[i];

        while(p != NULL)
        {
            initArray[ind] = p->data;
            ind +=1;
            p = p->next;
        }

        deleteList(i);
    }
}

void radixSort()
{
    int i, maxDigits = findMaxNrOfDigits(), power = 1;

    for(i=0; i<maxDigits; i++)
    {
        compareByDigit(power);
        reBuildArray();
        power *= 10;
    }
}

void printArray()
{
    int i;

    for(i=0; i<n; i++)
        printf("%d ", initArray[i]);

}


