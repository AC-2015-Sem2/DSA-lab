#include <stdio.h>
#include <stdlib.h>
#include "SLL_Operations.h"

int main()
{
    FILE* ifile = fopen("input.dat", "r");
    char* command = (char*)malloc(30);
    while (fgets(command, 30, ifile)){
        ComProc(command);
    }
    return 0;
}
