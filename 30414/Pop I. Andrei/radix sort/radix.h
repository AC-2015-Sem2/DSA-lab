#include <stdio.h>
#include <stdlib.h>

#ifndef RADIX_H_INCLUDED
#define RADIX_H_INCLUDED

int n, *initArray;

void readInitArray(FILE *in);
void printArray();
void radixSort();


#endif // RADIX_H_INCLUDED
