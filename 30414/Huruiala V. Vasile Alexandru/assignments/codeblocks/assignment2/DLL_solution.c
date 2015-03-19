
#include "DLL_definition.h"
#include "DLL_io.h"
#include "DLL_methods.h"
#include <stdio.h>
#include <string.h>

#define MAX_CMD_LENGTH 14
//DOOM_THE_LIST is the longest with 13 characters

enum
//all of the commands that can be in the file
//only TOTAL matters(for string comparison)
{
    AF = 0, AL, DF, DL, DOOM_THE_LIST, DE, PRINT_ALL, PRINT_F, PRINT_L,
    TOTAL
};
const char* const COMMAND[] = {"AF", "AL", "DF", "DL", "DOOM_THE_LIST", "DE", "PRINT_ALL", "PRINT_F", "PRINT_L"};

int Interpret(List* L, char* cmd, void* data, FILE* Out)
{
    int found = -1;
    //searhing the command in the database
    for(int i = 0; (i < TOTAL)&&(found == -1); i++)
        if(strcmp(cmd, COMMAND[i]) == 0)
            found = i;

    switch(found)
    {
        case 0:{(*L->AddFirst)(L, data);}break;
        case 1:{(*L->AddLast)(L, data);}break;
        case 2:{(*L->DeleteFirst)(L);}break;
        case 3:{(*L->DeleteLast)(L);}break;
        case 4:{(*L->Anihilate)(L);}break;
        case 5:{(*L->Delete)(L, data);}break;
        case 6:{(*L->PrintAll)(L, Out);}break;
        case 7:{(*L->PrintF)(L, Out, (int)data);}break;
        case 8:{(*L->PrintL)(L, Out, (int)data);}break;
        default:{return -1;}break;//not recognized
    }
    return 0;//successful
}

void Solve(List* L, FILE* In, FILE* Out)
{
    char cmd[MAX_CMD_LENGTH];
    int param;
    while(readLine(In, cmd, &param) != -1)
    {
        //the operation selector, the main component
        if(((*L->Interpret)(L, cmd, (void*)param, Out)) != 0)
        {
            fprintf(stderr, "Invalid command detected: %s not recognized.\n", cmd);
        }
    }
}
