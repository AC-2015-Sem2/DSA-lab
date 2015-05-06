#include <stdlib.h>
#include "graphRepresentation.h"

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
    printf("\n");
}


int getNumberOfNeighborsOfVertex(int v)
{
    if(v<nrOfVerteces)
    {
        int nrOfNeighbors=0;
        int i;
        for(i=0; i< nrOfVerteces; i++)
        {
            if(adjMatrix[v][i]>0 && i!=v)
            {
                nrOfNeighbors++;
            }
        }
        return nrOfNeighbors;
    }
    else
    {
        return 0;
    }
}

int * getAllNeighborsOfVertex(int v)
{
    if(v<nrOfVerteces)
    {
        int nrOfNeighbors = getNumberOfNeighborsOfVertex(v);
        int * neighbors = (int*)malloc(sizeof(int) * nrOfNeighbors);
        int i,j=0;
        for(i=0; i<nrOfVerteces; i++)
        {
            if(adjMatrix[v][i]>0 && i!=v)
            {
                neighbors[j]=i;
                j++;
            }
        }
        return neighbors;
    }
    else
    {
        return NULL;
    }
}
