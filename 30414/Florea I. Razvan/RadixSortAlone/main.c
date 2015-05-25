#include <stdio.h>

void print(int *x, int n)
{
	int i;
	for (i=0; i<n; i++)
	  printf("%d, ", x[i]);
}
void Radix_Sort(int *x, int n)
{
	int i, aux[10000], maxim=0, cut=1, step=0;

	for (i=0; i<n; i++)
    {
		if (x[i] > maxim)
		   maxim = x[i];
	}
	while (maxim/cut > 0)
	{
	    step++;
		int digit[10]={0};

		for (i=0; i<n; i++)
		   digit[(x[i]/cut) %10]++;

		for (i=1; i<10; i++)
		   digit[i]+=digit[i-1];

		for (i=n-1; i>=0; i--)
		   aux[--digit[(x[i]/cut) %10]] = x[i];

		for (i=0; i<n; i++)
		   x[i]=aux[i];

		cut*= 10;
//! the number of steps is given by the number of digits that compose the greatest element (=maxim) in the array to be sorted.
        printf("\n\nStep %d : ",step);
		print(x, n);

	}
}
int main()
{
	int a[10000];
	int i, na;

	printf("\nNumber of elements in the array to be sorted: ");
	scanf("%d", &na);

	printf("\nInput the elements:\n");
	for (i = 0; i < na; i++)
    {
      printf("a[%d]=",i);
      scanf("%d", &a[i]);
    }

	Radix_Sort(&a, na);
	printf("\n\nThe sorted array is: ");
	print(&a, na);
	return 0;
}
