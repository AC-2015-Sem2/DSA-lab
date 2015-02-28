/*This is the main part of the code
 which selects which function to use
 based on the read string
*/

#include<string.h>
#include "SLL_definition.h"
#include "SLL_io.h"
#include "SLL_operations.h"

enum
//all of the commands that can be in the file
//only TOTAL matters(for string comparison)
{
    AF = 0, AL, DF, DL, DOOM_THE_LIST, DE, PRINT_ALL, PRINT_F, PRINT_L,
    TOTAL
};
const char* const COMMAND[] = {"AF", "AL", "DF", "DL", "DOOM_THE_LIST", "DE", "PRINT_ALL", "PRINT_F", "PRINT_L"};

int Interpret(char* command, int parameter, Node** head, Node** tail, FILE* Out)
{
    int i;
    int found = -1;
    //searhing the command in the database
    for(i = 0; (i < TOTAL)&&(found == -1); i++)
        if(strcmp(command, COMMAND[i]) == 0)
            found = i;

    switch(found)
    {
        case 0:{AddFirst(head, tail, parameter);}break;
        case 1:{AddLast(head, tail, parameter);}break;
        case 2:{DeleteFirst(head, tail);}break;
        case 3:{DeleteLast(head, tail);}break;
        case 4:{Anihilate(head, tail);}break;
        case 5:{Delete(head, tail, parameter);}break;
        case 6:{PrintAll(Out, *head);}break;
        case 7:{PrintF(Out, *head, parameter);}break;
        case 8:{PrintL(Out, *head, parameter);}break;
        default:{return -1;}break;//not recognized
    }
    return 0;//successful
}
