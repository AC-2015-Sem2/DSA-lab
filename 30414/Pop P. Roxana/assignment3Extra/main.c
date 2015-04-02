#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
    f=fopen("input.dat","r");
    if (f==NULL) perror("input file could not be opened");
    g=fopen("output.dat","w");
    if (g==NULL) perror("output file could not be opened");
    nodeT * root=NULL;
    root=createBinTree();
    prettyPrint(root,0);
    return 0;
}
