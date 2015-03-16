#include <stdio.h>
#include <stdlib.h>
#include "DLL_Def.h"
#include "DLL_Operations.h"

int main()
{
    dll = (sentT*)malloc(sizeof(sentT));
    dll->head = NULL;
    dll->tail = NULL;
    dll->length = 0;
    FILE* ifile = fopen("input.dat", "r");
    char* command = (char*)malloc(30);
    while (fgets(command, 30, ifile))
    {
        ComProc(command);
    }
    return 0;
}
