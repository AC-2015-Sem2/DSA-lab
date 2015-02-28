/*This contains the reading function
 it reads an entire line of the file
 then it reads the string and parameter from that line
A string will always be present but in the case
 a number is not param will get a random dump value
 but it is not a problem since param would not be used
*/

#include<stdio.h>
#define MAX_LENGTH 14


int readLine(FILE* In, char* command, int* param)
{
    char line[MAX_LENGTH];
    if(fgets(line, MAX_LENGTH, In) == 0)
    {
        //the exit(eof) condition
        return -1;
    }
    sscanf(line, "%s %d", command, param);

    return 0;
}
