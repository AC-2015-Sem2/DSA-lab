#include "tree.h"

int main()
{
    FILE *f;
    f=fopen("input.dat","r");
    if (f==NULL) perror ("input file could not be opened");
    g=fopen("output.dat","w");
    if (g==NULL) perror ("output file could not be opened");
    nodeT * root=createBalancedBST(f);
    printf("Introduce node to be deleted\n");
    int del;
    scanf("%d",&del);
    root=deleteNode(root,del);
    prettyPrint(root,0);
    return 0;
}
