//#ifndef LISTFUNCTIONS_H_INCLUDED
//#define LISTFUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"


void addLast(int value);
void printAll(FILE *fileOutput);
void addCountry(char *countryName);
void addWaves(FILE *fileOutput,int value, listOfLists *countryWaves);
void deleteFirst(listOfLists *countryHead);
void readFromFile(FILE *file, FILE *fileOutput);
void sentinelsDown(FILE *fileOutput,int maxLife, char mostPowerfulCountry[100]);
void lastHit(FILE *fileOutput, int totalLifeOfSentinels );
char *getWeakestCountry(int lifeOfaCountry);

//#endif // LISTFUNCTIONS_H_INCLUDED
