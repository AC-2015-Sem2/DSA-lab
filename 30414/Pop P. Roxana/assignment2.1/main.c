#include <string.h>
#include "list_h.h"

int main()
{
    FILE * f, * g;
    f=fopen("input.dat","r");
    if (f==NULL) perror("File for reading could not be opened\n");
    g=fopen("output.dat","w");
    if (g==NULL) perror("data out file could not be opened\n");
    ///THE LIST IS INITIALIZED
    initList();
    ///THE DATA IS READ, LINE BY LINE
    char *s=(char*)malloc(10*sizeof(char));
    int x;
    while (fscanf(f,"%s%d",s,&x)!=-1)
    {
        ///THE OPERATIONS ARE DONE ON THE LISTS
        if (strcmp("AF",s)==0) addFirst(x);
        if (strcmp("AL",s)==0) addLast(x);
        if (strcmp("DF",s)==0) deleteFirst();
        if (strcmp("DL",s)==0) deleteLast();
        if (strcmp("DOOM_THE_LIST",s)==0) doomTheList();
        if (strcmp("DE",s)==0) deleteElementByKey(x);
        if (strcmp("PRINT_ALL",s)==0) printAll(g);
        if (strcmp("PRINT_F",s)==0) printFirst(g,x);
        if (strcmp("PRINT_L",s)==0) printLast(g,x);
    }
    fclose(f);
    fclose(g);
    return 0;
}
