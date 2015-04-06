#include <stdio.h>
#include <stdlib.h>
#include "functionsForDelete.h"
int main()
{
    int value;
    FILE *f;
    f=fopen("input.txt","r");
    if (f==NULL)
    {
        perror("File with problems.");
        exit(1);
    }
    nodeT* root=createBinTree(f);
    prettyPrint(root,0);
    printf("insert a value=");
    scanf("%d",&value);
    root=deleteNode(root,value);
    printf("\n");
    prettyPrint(root,0);
    return 0;
}
