#include "Q.h"
#include <stdio.h>

int main()
{
    Sentinel* S;
    initSent(&S);

    FILE* I = NULL;
    FILE* O = NULL;
    if(openFiles(&I, &O) != 0)
    {
        fprintf(stderr, "File errer.");
        exit(-1);
    }

    (*S->solve)(S, I, O);

    closeFiles(&I, &O);
    DestroySent(&S);
    return 0;
}
