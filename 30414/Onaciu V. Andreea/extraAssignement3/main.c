#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
int main()
{
    FILE*f;
    char s[50];
    char *token;
    f=fopen("input.txt","r");
    if (f==NULL) perror("PROBLEM WITH THE FILE");
    fgets(s,50,f);
    token=strtok(s," ");
    while (token!=NULL)
    {
        addLast(token);
        if ((strcmp(token,"+")!=0)&&(strcmp(token,"-")!=0)&&(strcmp(token,"*")!=0)&&(strcmp(token,"/")!=0))
        {
            addLast("!");
            addLast("!");
        }
        token=strtok(NULL," ");
    }
    nodeT* root=createTreeFromList(head);
    prettyPrint(root,0);
    return 0;
}
