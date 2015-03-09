#include <stdio.h>
#include <stdlib.h>
#include "listFunctions.h"
#include "lists.h"

listOfLists *head, *tail;
node *genericHead, *genericTail, *currWaveNode;

int main()
{
    FILE *file, *fileOutput;
    file= fopen("input.dat", "r");

    if(file== NULL)
    {
        perror("Cannot open file");
        return -100;
    }
    fileOutput= fopen("output.dat","w");

    readFromFile(file, fileOutput);

    fclose(fileOutput);
    return 0;
}
