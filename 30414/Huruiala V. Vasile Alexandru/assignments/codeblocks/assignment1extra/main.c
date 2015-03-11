#include <stdio.h>
#include <stdlib.h>
#include "JKN.h"

int main()
{
    FILE* I = fopen(INPUT_FILE, "r");
    if(I == NULL)
    {
        printf("Error. Could not open %s.\n", INPUT_FILE);
        exit(-1);
    }
    FILE* O = fopen(OUTPUT_FILE, "w");
    if(O == NULL)
    {
        printf("Error. Could not open %s.\n", OUTPUT_FILE);
        exit(-1);
    }


    int nSent;
    Country* Sent;
    int nCount;
    Country* hCount;
    Country* tCount;


    readFile(I, &nSent, &Sent, &nCount, &hCount, &tCount);

    listList(Sent, hCount, tCount);//DEBUG

    Battle(&Sent, &hCount, &tCount, O);

    return 0;
}
