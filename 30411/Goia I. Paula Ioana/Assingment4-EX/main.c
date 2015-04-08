#include <stdio.h>
#include <stdlib.h>
#include "avldel.h"

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
    int k,k1;
    printf("Insert 2 nodes: ");
    scanf("%d %d",&k,&k1);
    insert(root,k);
    insert(root,k1);
    prettyPrint(root,0);
    printf("\n");
    printf("Insert the key of the node you want to delete:\n");
    scanf("%d",&nr);
    deleteNODE(root,nr);
    prettyPrint(root,0);
    printf("\n");
    printf("\n");
    printf("Insert the key of the node you want to delete:\n");
    scanf("%d",&nr);
    deleteNODE(root,nr);
    printf("\n");
    printf("\n");
    prettyPrint(root,0);
    return 0;
}
