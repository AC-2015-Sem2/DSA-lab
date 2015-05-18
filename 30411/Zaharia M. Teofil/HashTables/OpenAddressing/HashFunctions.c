#include "HashFunctions.h"

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
