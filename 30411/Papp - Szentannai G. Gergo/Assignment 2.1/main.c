#include <stdio.h>
#include <stdlib.h>
#include "DLL.h"
#include <string.h>
#include "DLL_TYPES.h"



int main()
{
    FILE *f;
    f=fopen("output.dat","w"); // Clearing output file
    fclose(f);

    FILE *pf;
    pf=fopen("input.dat","r"); // Opening input.dat for reading
    if (pf==NULL)
    {
        perror("Cannot open file");
        return(-1);
    }
    sentinel s; // Sentinel for storing head & tail
    s.length=(int*)malloc(sizeof(int*));
    s.head=(NodeT*)malloc(sizeof(NodeT*));
    s.tail=(NodeT*)malloc(sizeof(NodeT*));

    *(s.length)=0;
    s.head->code=s.tail->code=0; // Setting initial head & tail values

    int q; // Input value
    char ch[14]; // Input command

    while(fscanf(pf,"%s %d",ch,&q)>0)
    {
        if(strcmp(ch,"AL")==0)
            AL(s,q);
        else if(strcmp(ch,"AF")==0)
            AF(s,q);
        else if(strcmp(ch,"DF")==0)
            DF(s);
        else if(strcmp(ch,"DL")==0)
            DL(s);
        else if(strcmp(ch,"DOOM_THE_LIST")==0)
            DOOM_THE_LIST(s);
        else if(strcmp(ch,"DE")==0)
            DE(s,q);
        else if(strcmp(ch,"PRINT_ALL")==0)
            PRINT_ALL(s);
        else if(strcmp(ch,"PRINT_F")==0)
            PRINT_F(s,q);
        else if(strcmp(ch,"PRINT_L")==0)
            PRINT_L(s,q);
    }
    return 0;
}
