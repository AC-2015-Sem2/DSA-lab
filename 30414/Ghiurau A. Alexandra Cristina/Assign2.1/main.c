#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


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

    s = (list_sentinel*)malloc(sizeof(list_sentinel));
    s->head = 0;
    s->tail = 0;
    char line[1000];
    int value;
    while(fscanf(file,"%s", line)!=EOF)
    {
        if(strcmp(line, "AF")==0)
        {
            fscanf(file, " %d", &value);
            addFirst(value);
        }
        else if(strcmp(line, "AL")==0)
        {
            fscanf(file, " %d", &value);
            addLast(value);
        }
        else if(strcmp(line, "DF")==0)
        {
            deleteFirst();
        }
        else if(strcmp(line, "DL")==0)
        {
            deleteLast();
        }
        else if(strcmp(line, "DOOM_THE_LIST")==0)
        {
            deleteAll();
        }
        else if(strcmp(line, "DE")==0)
        {
            fscanf(file, " %d", &value);
            deleteX(value);
        }
        else if(strcmp(line, "PRINT_ALL")==0)
        {
            printAll(fileOutput);
        }
        else if(strcmp(line, "PRINT_F")==0)
        {
            fscanf(file, " %d", &value);
            printFirstX(value, fileOutput);
        }
        else if(strcmp(line, "PRINT_L")==0)
        {
            fscanf(file, " %d", &value);
            printLastX(value, fileOutput);
        }
    }
    fclose(fileOutput);
    return 0;

}


