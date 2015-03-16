#include <stdio.h>
#include <stdlib.h>
#include "queuesFunctionsh.h"

int main()
{
    FILE *f;
    FILE *g;
    int t,x,y;
    char name[30];
    f=fopen("input.txt","r");
    if (f==NULL)
    {
        perror("Error while opening the input file.");
    }
    g=fopen("output.txt","w");
    if (g==NULL)
    {
        perror("Error while opening the input file.");
    }
    while (fscanf(f,"%d ",&t)>0)
    {
        enqueueT(f,t);

    }

    while (fscanf(f,"%s %d %d\n",name,&x,&y)>0)
    {
        enqueue(f,x,y);
    }
    problemSol(g);

    return 0;

}
