#include "DLL.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    List* L = NULL;
    ListInit(&L);

    FILE* In = NULL;
    FILE* Out = NULL;

    if(openFiles(&In, &Out) != 0)
    {
        printf("Error. File could not be open.\n");
        exit(-1);
    }

    (*L->Solve)(L, In, Out);

    return 0;
}
