#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "stack.h"
#include "queue.h"

void readFromAdjMatrix(FILE * f)
{
    int n;
    fscanf(f,"%d",&n);
    nrOfVerteces=n;
    int i,j;
    adjMatrix=(int**)malloc(n*sizeof(int*));
    for (i=0; i<n; i++)
    {
        *(adjMatrix+i)=(int*)malloc(n*sizeof(int));
    }

    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            fscanf(f,"%d",&adjMatrix[i][j]);
    fclose(f);
}

void printAdjMatrix()
{
    int i,j;

    printf("\nThe matrix is:\n");
    printf("    ");
    for (i=0; i<nrOfVerteces; i++)
    {
        printf("%c   ",65+i);
    }
    printf("\n");
    for (i=0; i<nrOfVerteces; i++)
    {
        printf("%c ",65+i);
        for (j=0; j<nrOfVerteces; j++)
            printf("%3d ",adjMatrix[i][j]);
        printf("\n");
    }
}

int getNumberOfNeighborsOfVertexM(int v)
{
    int i;
    int s=0;
    for (i=0;i<nrOfVerteces;i++)
        s+=adjMatrix[v][i];
    return s;
}

int * getAllNeighborsOfVertexM(int v)
{
    int * a=(int*)malloc(getNumberOfNeighborsOfVertexM(v)*sizeof(int));
    int i;
    int k=-1;
    for (i=0;i<=nrOfVerteces;i++)
    {
        if (adjMatrix[v][i]==1)
        {
           k++;
           a[k]=i;
        }
    }
    return a;
}
