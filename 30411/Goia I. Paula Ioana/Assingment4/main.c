#include <stdio.h>
#include <stdlib.h>
#include "avlins.h"

int main()
{
    FILE *fin;
    fin=fopen("in.txt","r");
    if (fin==NULL)
    {
        perror("Error\n");
        exit(1);
    }
    int nr;
    NodeT *root=NULL;

    while((fscanf(fin,"%d",&nr))==1)
    {
        root=insert(root,nr);
    }
    prettyPrint(root,0);
    printf("\n\n\n");
    int k,k1,k2;
    printf("Insert the following 3 nodes:");
    scanf("%d %d %d",&k,&k1,&k2);
    insert(root,k);
    insert(root,k1);
    insert(root,k2);
    prettyPrint(root,0);
    return 0;
}
