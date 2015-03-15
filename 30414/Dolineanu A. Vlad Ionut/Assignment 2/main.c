#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main()
{
    f = fopen("output.dat", "a");
    ourList = (list*)malloc(sizeof(list));
    ourList->head = NULL;
    ourList->tail = NULL;
    ourList->length = 0;

    FILE* g = fopen("input.dat", "r");

    char oper[20];
    int value;

    while(fscanf(g, "%s", oper)>0)
    {
        if(strcmp(oper, "AF")==0)
        {
            fscanf(g, "%d", &value);
            addFirst(value);
            printf("AF\n");
        }
        else if(strcmp(oper, "AL")==0)
        {
            fscanf(g, "%d", &value);
            addLast(value);
            printf("AL\n");
        }
        else if(strcmp(oper, "DF")==0)
        {
            deleteFirst();
            printf("DF\n");
        }
        else if(strcmp(oper, "DL")==0)
        {
            deleteLast();
            printf("DL\n");
        }
        else if(strcmp(oper, "DOOM_THE_LIST")==0)
        {
            doom();
            printf("DOOM\n");
        }
        else if(strcmp(oper, "DE")==0)
        {
            fscanf(g, "%d", &value);
            deleteX(value);
            printf("DE_X\n");
        }
        else if(strcmp(oper, "PRINT_ALL")==0)
        {
            printList();
            printf("PRINT_ALL\n");
        }
        else if(strcmp(oper, "PRINT_F")==0)
        {
            fscanf(g, "%d", &value);
            printFirst(value);
            printf("PRINT_F\n");
        }
        else if(strcmp(oper, "PRINT_L")==0)
        {
            fscanf(g, "%d", &value);
            printLast(value);
            printf("PRINT_L\n");
        }
    }

    fclose(g);

    return 0;
}
