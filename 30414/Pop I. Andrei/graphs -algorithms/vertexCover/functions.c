# include "functions.h"

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

int getNumberOfEdges(int **adjMatrix)
{
    int i, j, nrEdges = 0;

    for(i=0; i<nrOfVerteces; i++)
        for(j=0; j<nrOfVerteces; j++)
            if(adjMatrix[i][j] != 0 && i<j)
                nrEdges+=1;

    return nrEdges;
}

edgeT findAnEdge(int **adjMatrix)
{
    int i, j;
    edgeT e;
    for(i=0; i<nrOfVerteces; i++)
        for(j=0; j<nrOfVerteces; j++)
            if(adjMatrix[i][j] > 0)
            {
                e.source = i;
                e.dest = j;
            }
    return e;
}

void removeEdges(int nod, int *nrEdges)
{
    int i;

    for(i=0; i<nrOfVerteces; i++)
        if(adjMatrix[nod][i] > 0)
        {
            adjMatrix[nod][i] = -1;
            adjMatrix[i][nod] = -1;
            *nrEdges-=1;
        }
}

int hasOtherAdjacentEdges(int nod)
{
    int i, nr = 0;
    for(i=0; i<nrOfVerteces; i++)
        if(adjMatrix[nod][i] !=0)
            nr+=1;

    if(nr>1)
        return 1;
    else
        return 0;
}

void vertexCover()
{
    int nrEdges = getNumberOfEdges(adjMatrix), i;
    edgeT edge;
    int *vSet = (int*) malloc (nrOfVerteces * sizeof(int)), nrV = 0;

    while(nrEdges != 0)
    {
        edge = findAnEdge(adjMatrix);

        if(hasOtherAdjacentEdges(edge.source)) // add it to the set only if it has more than 1 adjacent edges
            vSet[nrV++] = edge.source;

        if(hasOtherAdjacentEdges(edge.dest))
            vSet[nrV++] = edge.dest;

        removeEdges(edge.source, &nrEdges); //remove the edges adjacent to the nodes of the selected edge
        if(nrEdges != 0)
            removeEdges(edge.dest, &nrEdges);
    }

    printf("The verteces from the st are: ");
    for(i=0; i<nrV; i++)
        printf("%d ", vSet[i]);
}
