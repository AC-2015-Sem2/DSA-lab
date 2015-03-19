#include <stdio.h>
#define INPUT_FILE "input.dat"
#define OUTPUT_FILE "output.dat"

int openFiles(FILE** I, FILE** O)
{
    if((*I = fopen(INPUT_FILE, "r")) == NULL)
    {
        fprintf(stderr, "Error. Could not open file %s", INPUT_FILE);
        return -1;
    }
    if((*O = fopen(OUTPUT_FILE, "w")) == NULL)
    {
        fprintf(stderr, "Error. Could not open file %s", OUTPUT_FILE);
        return -2;
    }
    return 0;
}

void closeFiles(FILE** I, FILE** O)
{
    fclose(*I);
    *I = NULL;
    fclose(*O);
    *O = NULL;
}
