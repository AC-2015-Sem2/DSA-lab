#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SLL_Adding.h"
#include "SLL_Removing.h"
#include "SLL_Printing.h"
#include "SLL_Operations.h"

void ComProc(char* s){
    char* com = (char*)malloc(30);
    int value;
    sscanf(s, "%s", com);
    if (!strcmp(com, "AF")){
        sscanf(s, "%*s %d", &value);
        AddFirst(value);
        }
    else if(!strcmp(com, "AL")){
        sscanf(s, "%*s %d", &value);
        AddLast(value);
    }
    else if(!strcmp(com, "DF"))
        {DeleteFirst();}
    else if(!strcmp(com, "DL"))
        {DeleteLast();}
    else if(!strcmp(com, "DOOM_THE_LIST"))
        {DOOM();}
    else if(!strcmp(com, "DE")){
        sscanf(s, "%*s %d", &value);
        Del(value);
    }
    else if(!strcmp(com, "PRINT_ALL"))
        {PrintAll();}
    else if(!strcmp(com, "PRINT_F")){
        sscanf(s, "%*s %d", &value);
        PrintFirst(value);
    }
    else if(!strcmp(com, "PRINT_L")){
        sscanf(s, "%*s %d", &value);
        PrintLast(value);
    }
}
