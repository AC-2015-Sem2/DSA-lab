# include "radix.h"

int main()
{
    FILE *in = fopen("input.data", "r");

    readInitArray(in);

    printf("The initial array is: ");
    printArray();

    radixSort();

    printf("\n");

    printf("The sorted array is: ");
    printArray();

    return 0;
}
