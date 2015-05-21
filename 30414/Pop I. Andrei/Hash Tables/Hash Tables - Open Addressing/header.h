#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const float INITIAL_HT_SIZE_FACTOR = .25;
const float MAX_FILL_FACTOR = .80;

char ** hashTable;
int size;

int hashFunction(char *, int , int);

void addToHashTbale(int);
void initHashTable(int );
float getFillFactor();
void resizeHashTable();
int insertElement(char * element, int, char **);


static const int MAX_STRING_LENGTH = 64;

char * randString();

void writeToFile(int N);

char ** readFromFile(int N);

FILE * getFileForInt(int N);

void printContentToConsole(char ** contents, int N);

#endif // HEADER_H_INCLUDED
