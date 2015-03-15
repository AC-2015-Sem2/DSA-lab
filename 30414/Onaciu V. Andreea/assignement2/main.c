#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DLLfunctionsh.h"

int main()
{
    FILE* f;
    FILE* g;
    char operation[20];
    int x;

    f=fopen("input.txt","r");
    if (f==NULL)
    {
        perror("The file does not open.");
    }

    g=fopen("output.txt","w");
    if (g==NULL)
    {
        perror("The file does not open.");
    }

    initializeList(); // function that initialize the list.
    while (fscanf(f,"%s %d\n",operation,&x)>0)
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
    return 0;
}
