#include <stdio.h>
#include <stdlib.h>
#include "funstionsTree.h"
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
    printf("insert a value=");
    scanf("%d",&value);
    prettyPrint(root,0);
    root=insertNode(root,value);
    printf("\n");
    prettyPrint(root,0);
    return 0;
}
