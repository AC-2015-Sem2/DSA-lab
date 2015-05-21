#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const float INITIAL_HT_SIZE_FACTOR = .25;
static const float MAX_FILL_FACTOR = .60;

int size;
int nrOfResizes;


int (*hashFunction)(char *, int);

char** initHashTable(int N);
float getFillFactor();
char ** resizeHashTable(char ** hashTable);
int insertElement(char *** hashTable,char * element);

///prototypes of hash functions
int h1(char * content, int i);
int h2(char * content, int i);
int h3(char * content, int i);

