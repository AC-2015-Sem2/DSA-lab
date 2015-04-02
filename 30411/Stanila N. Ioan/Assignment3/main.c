#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "functions.h"

int main()
{
    FILE* f = fopen("input.dat", "r");
    if (f == NULL) {
        perror("input,dat");
        exit(1);
    }

    BinTree* root = btCreateBinTree(f);
    LIST* l = getListFromTree(root);
    print_all(l, stdin);
    root = getTreeFromList(l);
    prettyPrint(root, 0, stdin);

    fclose(f);
    return 0;
}
