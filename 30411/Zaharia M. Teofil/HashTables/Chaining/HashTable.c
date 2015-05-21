#include "HashTable.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

HashTable* newHashTable(int size, int (*hashFunction)(char*)) {
    HashTable* ht = (HashTable*) malloc (sizeof(HashTable));
    ht->size = size;
    ht->hashFunction = hashFunction;

    ht->listArray = (ListT**) malloc (size * sizeof(ListT*));

    int i;
    for (i = 0; i < size; i++) {
        ht->listArray[i] = newList();
    }

    return ht;
}

HashTable* delHashTable(HashTable* ht) {
    int i;
    for (i = 0; i < ht->size; i++) {
        ht->listArray[i] = delList(ht->listArray[i]);
    }
    free(ht);
    return NULL;
}

void setHashFunction(HashTable* ht, int (*newHashFunction)(char*)) {
    if (ht == NULL)
        return;

    ht->hashFunction = newHashFunction;
}

void insertElement(HashTable* ht, char* element) {
    int (*hf)(char*) = ht->hashFunction;
    int j = (*hf)(element) % ht->size;

    addToList(ht->listArray[j], element);
}

void computeDistributionsPerBucket(HashTable* ht, int scale) {
    int i, j, x = scale;
    for (i = 0; i < ht->size; i++) {
        printf("B%2d: ", i);
        for (j = 0; j < ht->listArray[i]->size / x; j++) {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
}

// bad hash function = maps many different elements
// to the same key
// word length, number of alphanumerics, ...

// counts number of letters
int hashFunction0(char* element) {
    int sum = 0, i = 0;
    char c;

    while (element[i] != '\0') {
        c = element[i];

        if ((c > 96 && c < 123) || (c > 64 && c < 91)) {
            sum += 1;
        }
        i++;
    }
    return sum;
}

// char sum
int hashFunction1(char* element) {
    int sum = 0;

    int i = 0;
    while (element[i] != '\0') {
        sum += element[i];
        i++;
    }

    return sum;
}

// hash with bit-shifts
int hashFunction2(char* element) {
    int key = 0;

    int i = 0;
    while (element[i] != '\0') {
        key = element[i] + (key << 6) + (key << 16) - key;
        i++;
    }

    return abs(key);
}

// sum 4 chars at a time, fold on the string
int hashFunction3(char* element) {
    int quarterLength = strlen(element) / 4;
    int sum = 0, mult = 1;

    int i, j;
    char substr[5];


    // take the string 4 characters at a time
    // interpret this chunk as a word
    for (i = 0; i < quarterLength; i++) {
        strncpy(substr, element + 4*(i + 1), 4);

        mult = 1;
        for (j = 0; j < 4; j++) {
            sum += substr[j] * mult;
            mult *= 256;
        }
    }

    // add them over again
    mult = 1;
    i = 0;
    while (element[i] != '\0') {
        sum += element[i] * mult;
        mult *= 256;
        i++;
    }

    // need abs for int OVERFLOW
    // not a bug, but a feature
    return abs(sum);
}

// Ideas for future hash functions : bit-wise XOR
// XOR : good for pseudo-random number generators

