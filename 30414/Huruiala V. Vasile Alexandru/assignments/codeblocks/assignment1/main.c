/****************/
/**ASSIGNMENT 1**/
/****************/
/*see SLL_io.h for file paths*/

#include <stdio.h>
#include <stdlib.h>
#include "SLL.h"

int main()
{
    //IO init
    FILE* In = fopen(INPUT_FILE, "r");
    FILE* Out = fopen(OUTPUT_FILE, "w");

    //List pointers init
    Node* Head = NULL;
    Node* Tail = NULL;

    //Input loop
    char cmd[MAX_LENGTH];
    int param;
    while(readLine(In, cmd, &param) != -1)
    {
        Interpret(cmd, param, &Head, &Tail, Out);
        //the operation selector, the main component
    }

    return 0;
}
