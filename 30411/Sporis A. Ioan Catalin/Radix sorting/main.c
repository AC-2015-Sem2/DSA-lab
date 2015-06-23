#include <stdio.h>
#include <stdlib.h>
#define High -999999
//Get maximum nr from array

int getMax(int *a,int n)
{
    int i,max=High;
    for (i=0;i<n;i++)
        if(a[i]>max)
            max=a[i];
    return max;
}

void Countsort(int *a, int n, int exp)
{
    int output[n];
    int i;
    for(i=0;i<n;i++)
        output[i]=0;
    int count[10];
    for(i=0;i<10;i++)
        count[i]=0;

    //Nr of occurences
    for(i=0;i<10;i++)
        count[(a[i]/exp)%10]++;
    for(i=1;i<10;i++)
        count[i]=count[i]+count[i-1];
    for(i=n-1;i>=0;i--)
    {
        output[count[(a[i]/exp)%10]-1]=a[i];
        count[(a[i]/exp)%10]--;
    }
    for(i=0;i<n;i++)
        a[i]=output[i];
}

void radixsort(int *a,int n)
{
    int max=getMax(a,n);
    int exp;
    for(exp=1;max/exp>0;exp*=10)
        Countsort(a,n,exp);
}

void print(int *a,int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}

int main()
{
    FILE *p=fopen("Input.txt","r");
    int n;
    fscanf(p,"%d\n",&n);
    int i,a[n];
    for(i=0;i<n;i++)
        fscanf(p,"%d ",&a[i]);

    radixsort(a,n);
    print(a,n);
    return 0;
}
