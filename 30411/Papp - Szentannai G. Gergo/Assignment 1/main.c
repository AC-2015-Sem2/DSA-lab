#include <stdio.h>
#include <stdlib.h>
#include "SLL.h"
#include <string.h>

// Singly Linked List

typedef struct node
{
    int code;
    struct node* next;
} NodeT;

NodeT *head, *tail;

int main()
{
    FILE *f;
    f=fopen("output.dat","w");
    fclose(f);
    FILE *pf;
    pf=fopen("input.dat","r");
    if (pf==NULL)
    {
        perror("Cannot open file");
        return(-1);
    }
    int q;
    char ch[14];
    while(fscanf(pf,"%s %d",ch,&q)>0)
    {
        if(strcmp(ch,"AL")==0)
            AL(q);
        else if(strcmp(ch,"AF")==0)
            AF(q);
        else if(strcmp(ch,"DF")==0)
            DF();
        else if(strcmp(ch,"DL")==0)
            DL();
        else if(strcmp(ch,"DOOM_THE_LIST")==0)
            DOOM_THE_LIST();
        else if(strcmp(ch,"DE")==0)
            DE(q);
        else if(strcmp(ch,"PRINT_ALL")==0)
            PRINT_ALL();
        else if(strcmp(ch,"PRINT_F")==0)
            PRINT_F(q);
        else if(strcmp(ch,"PRINT_L")==0)
            PRINT_L(q);
    }

    return 0;
}
