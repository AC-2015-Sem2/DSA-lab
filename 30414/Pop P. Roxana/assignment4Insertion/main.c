#include "tree.h"

int main()
{
    f=fopen("input.dat","r");
    if (f==NULL) perror ("input file could not be opened");
    g=fopen("output.dat","w");
    if (g==NULL) perror ("output file could not be opened");
    nodeT * root=createBinTree();
    printf("Input data to be inserted in the tree\n");
    int data;
    scanf("%d",&data);
    insertNew(root,data);
    prettyPrint(root,0);
    return 0;
}
