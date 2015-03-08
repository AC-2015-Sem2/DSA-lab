/****************/
/**ASSIGNMENT 1**/
/****************/
/*see SLL_io.c for file paths*/

#include <stdio.h>
#include <stdlib.h>
#include "SLL.h"

int main()
{
    //IO init
    FILE* In = NULL;
    FILE* Out = NULL;
    if(openFiles(&In, &Out) != 0)
    {
        printf("Error. File could not be open.\n");
        exit(-1);
    }

    //List pointers init
    List* L = NULL;
    ListInit(&L);

    //Input loop
    char cmd[MAX_LENGTH];
    int param;
    while(readLine(In, cmd, &param) != -1)
    {
        //the operation selector, the main component
        if(((*L->Interpret)(L, cmd, (void*)param, Out)) != 0)
        {
            printf("Invalid command detected: %s not recognized.\n", cmd);
        }
    }
    closeFiles(&In, &Out);

    return 0;
}
