#include "readAdjMatrix.h"
void readAdjMatrix()
{
    FILE *f=fopen("Matrix.txt","r");
    if(f==NULL)
    {
        fatalError();
    }
    int n,i,j;
    fscanf(f,"%d",&n);
    nrOfVertices=n;
    adjMatrix=(int **)malloc(sizeof(int *)*n);
    for(i=0; i<n; i++)
    {
        adjMatrix[i]=(int *)malloc(sizeof(int)*n);
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            fscanf(f,"%d",&adjMatrix[i][j]);
        }
    }
    fclose(f);
}

void printAdjMatrix()
{
    int i,j;

    printf("\nThe matrix is:\n");
    printf("    ");
    for (i=0; i<nrOfVertices; i++)
    {
        printf("%c   ",65+i);
    }
    printf("\n");
    for (i=0; i<nrOfVertices; i++)
    {
        printf("%c ",65+i);
        for (j=0; j<nrOfVertices; j++)
            printf("%3d ",adjMatrix[i][j]);
        printf("\n");
    }
}

void fatalError()
{
    perror("Can't open file \"adjMatrix.txt\"\n");
    exit(1);
}
