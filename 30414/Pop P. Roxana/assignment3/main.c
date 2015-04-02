#include <stdio.h>
#include <stdlib.h>
#include "header.h"


int main()
{
    f=fopen("input.dat","r");
    if (f==NULL) perror ("input file could not be opened");
    g=fopen("output.dat","w");
    if (g==NULL) perror ("output file could not be opened");
    nodeT * root=createBinTree();
    nodeL * head=getListFromTree(root);
    traverseList(head);
    root=getTreeFromList(head);
    prettyPrint(root,0);
    return 0;
}
