#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "DoubleList.h"

int main() {
    FILE *in = fopen("input.dat", "r");
    FILE *out = fopen("output.dat", "w");

    // use this
    DoubleList *l = newList();
    // don't use void initList(l)
    // safer, no warnings

    char line[50], *c1, *c2;
    while (fgets(line, 50, in)) {

        // printAll(l);
        // printf("%s", line);

        c1 = strtok(line, " \n");
        c2 = strtok(NULL, " \n");
        // c2 == NULL if no 2nd term is present

        if (!strcmp(c1, "AF")) {
            addFirst(l, atoi(c2));
        } else if (!strcmp(c1, "AL")) {
            addLast(l, atoi(c2));
        } else if (!strcmp(c1, "DF")) {
            delFirst(l);
        } else if (!strcmp(c1, "DL")) {
            delLast(l);
        } else if (!strcmp(c1, "DE")) {
            del(l, atoi(c2));
        } else if (!strcmp(c1, "DOOM_THE_LIST")) {
            doom(l);
        } else if (!strcmp(c1, "PRINT_ALL")) {
            printAll(out, l);
        } else if (!strcmp(c1, "PRINT_F")) {
            printFirst(out, l, atoi(c2));
        } else if (!strcmp(c1, "PRINT_L")) {
            printLast(out, l, atoi(c2));
        }

        // printAll(l);
        // printf("\n");
    }

    freeList(l);
    return 0;
}
