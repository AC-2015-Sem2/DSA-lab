#include <stdio.h>
#include <stdlib.h>
#include "JKN2_SLL.h"

int main()
{
    JKN* J = NULL;
    InitJKN(&J);

    FILE* In = NULL;
    FILE* Out = NULL;
    openFiles(&In, &Out);
    (*J->readFile)(J, In);
    (*J->DebugPrint)(J);//DEBUG

    (*J->Solve)(J, Out);

    closeFiles(&In, &Out);
    Destroy(&J);
    return 0;
}
