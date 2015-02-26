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
    char cmd[14];
    int param;
    while(readLine(In, cmd, &param) != -1)
    {
        //printf("%s %d\n", cmd, param);//DEBUG
        //scanf("%c", &c);//DEBUG
        Interpret(cmd, param, &Head, &Tail, Out);//the operation selector, the main component
        cmd[0] = 0;//reset the string to signal the exit
                   //if the input file reached eof
        //PrintAll(stdout, Head);//DEBUG
    }

    return 0;
}
