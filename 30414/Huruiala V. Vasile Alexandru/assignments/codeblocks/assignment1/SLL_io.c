/*This contains the reading function
 it reads an entire line of the file
 then it reads the string and parameter from that line
A string will always be present but in the case
 a number is not param will get a random dump value
 but it is not a problem since param would not be used
*/

#include<stdio.h>
#define OUTPUT_FILE "output.dat"
#define INPUT_FILE "input.dat"
#define MAX_LENGTH 100


int openFiles(FILE** I, FILE** O)
{
    if((*I = fopen(INPUT_FILE, "r")) == NULL)
    {
        printf("%s could not be open.\n", INPUT_FILE);
        return -1;
    }
    if((*O = fopen(OUTPUT_FILE, "w")) == NULL)
    {
        printf("%s could not be open.\n", OUTPUT_FILE);
        return -2;
    }
    return 0;
}

int closeFiles(FILE** I, FILE** O)
{
    fclose(*I);
    *I = NULL;
    fclose(*O);
    *O = NULL;

    return 0;
}

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
