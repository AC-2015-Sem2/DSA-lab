# include "header.h"

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

edgeT *findEdge(int ind)
{
    edgeT *p = firstEdge;

    while(ind!=0)
    {
        p = p->next;
        ind-=1;
    }
    return p;
}

void getTheEdges(int **adjMatrix)
{
    int i, j, nr = 0;

    for(i=0; i<nrOfVerteces; i++)
        for(j=0; j<nrOfVerteces; j++)
        {
            if(i<j && adjMatrix[i][j] != 0)
            {
                addAnEdge(i, j);
            }
        }
}

void vertexCover()
{
    getTheEdges(adjMatrix);
    //printEdges();
    edgeT *edge;
    int nrEdges = getNrOfEdges();
    int i, ind;
    int *vSet = (int*) malloc (nrOfVerteces * sizeof(int)), nrV = 0;

    while(nrEdges != 0)
    {
        if(nrEdges > 1)
        {
            srand(time(NULL));
            ind = rand()%(nrEdges - 1);
        }
        else
            ind = 0;


        edge = findEdge(ind);
        int src = edge->source, dst = edge->dest;

        //printf("%d %d       ", edge->source, edge->dest);

        vSet[nrV++] = src;

        if(hasOtherAdjacentEdges(edge->dest))// add it to the set only if it has more than 1 adjacent edges
        vSet[nrV++] = dst;

        removeEdges(src); //remove the edges adjacent to the nodes of the selected edge
        nrEdges = getNrOfEdges();

        if(nrEdges != 0)
        {
            removeEdges(dst);
            nrEdges = getNrOfEdges();
        }

        //printEdges();

    }

    printf("%d", nrV-1);
    /*
    printf("The verteces from the set are: ");
    for(i=0; i<nrV; i++)
        printf("%d ", vSet[i]);
    */
}
