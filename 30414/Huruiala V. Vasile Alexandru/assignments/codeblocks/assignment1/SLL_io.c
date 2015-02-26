/*This contains the reading function
it always reads a string
and it reads an int where necessary, indicated in the enum
*/

#include<stdio.h>

enum
//the ops which have a parameter, used only to get TOTAL
{
    AF = 0,
    AL,
    DE,
    PRINT_F,
    PRINT_L,
    TOTAL
};
const char* const CMD_W_PARAM[] = {"AF", "AL", "DE", "PRINT_F", "PRINT_L"};

int readLine(FILE* In, char* command, int* param)
{
    fscanf(In, "%s", command);

    if(command[0] == 0)
        //the exit(eof) condition
        return -1;

    int i;
    int found = 0;
    for(i = 0; (i < TOTAL)&&(found == 0); i++)
        if(strcmp(command, CMD_W_PARAM[i]) == 0)
            found = 1;

    if(found == 1)
        fscanf(In, "%d", param);

    return 0;
}
