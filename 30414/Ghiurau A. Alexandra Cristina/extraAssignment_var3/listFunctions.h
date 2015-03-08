//#ifndef LISTFUNCTIONS_H_INCLUDED
//#define LISTFUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"


void addLast(int value);
void printAll(FILE *fileOutput);
void addCountry(char *countryName);
void addWaves(FILE *fileOutput,int value, node *countryWaves);
void deleteFirst(node *countryHead);


//#endif // LISTFUNCTIONS_H_INCLUDED
