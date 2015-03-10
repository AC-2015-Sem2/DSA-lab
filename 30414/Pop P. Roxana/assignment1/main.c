#include <stdlib.h>
#include <string.h>
#include "definingStructure.h"
#include "functions.h"

FILE *f,*g;

int main()
{
    //the two data files are opened
    f=fopen("input.dat","r");
    if (f==0) printf("error1");
    g=fopen("output.dat","w");
    if (g==0) printf("error2");
    char s[9];
    int x;
    //the data is read from the file input.data, line by line
    while (fscanf(f,"%s%d",s,&x)!=-1)
    {
        //The type of operation to be done on the list is identified
        if (strcmp("AF",s)==0) addFirst(x);
        if (strcmp("AL",s)==0) addLast(x);
        if (strcmp("DF",s)==0) deleteFirst();
        if (strcmp("DL",s)==0) deleteLast();
        if (strcmp("DOOM_THE_LIST",s)==0) doomTheList();
        if (strcmp("DE",s)==0) deleteElementByKey(x);
        if (strcmp("PRINT_ALL",s)==0) printAll(g);
        if (strcmp("PRINT_F",s)==0) printFirstElements(g,x);
        if (strcmp("PRINT_L",s)==0) printLastElements(g,x);
    }
    fclose(f);
    fclose(g);
    return 0;
}
