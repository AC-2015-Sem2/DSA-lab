#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>
#include"def.h"
#include"Treefunctions.h"


int main()
{
    char s[50];
    FILE *f=fopen("input.txt","r");
    if (!f)
    {
        printf("Error! opening file");
        exit(1);
    }
    NodeT* root=createBinTree(f);
    prettyPrint(root,0);
    return 0;
}
