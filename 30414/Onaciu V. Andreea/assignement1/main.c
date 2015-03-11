#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SLLfunctionsh.h"

int main()
{
    FILE *f,*g;
    int  x;
    char operation[10];
    f=fopen("input.dat","r");
    if (f==NULL)
    {
        perror("Error while opening the input file.");
    }

    g=fopen("output.dat","w");
    if (g==NULL)
    {
        perror("Eroor while opening the output file.");
    }

    while (fscanf(f,"%s %d \n",operation,&x)>0)
    {
        if (strcmp("AF",operation)==0) addFirst(x);
        else if (strcmp("AL",operation)==0) addLast(x);
        else if (strcmp("DF",operation)==0) deleteFirst();
        else if (strcmp("DL",operation)==0) deleteLast();
        else if (strcmp("DOOM_THE_LIST",operation)==0) doomTheList();
        else if (strcmp("DE",operation)==0) deleteElementX(x);
        else if (strcmp("PRINT_ALL",operation)==0) printAll(g);
        else if (strcmp("PRINT_F",operation)==0) printFirstX(g,x);
        else if (strcmp("PRINT_L",operation)==0) printLastX(g,x);
    }
    fclose(f);
    fclose(g);
    return 0;
}
