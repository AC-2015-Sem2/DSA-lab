#include "graph.h"
#include "graphRepresentation.h"

//! Prim related stuff
edgeT getMinimumEdgeForCurrentlyVisitedNodes(int * visited)
{

}

void printEdges(edgeT* edges, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%c -> %c\t",edges[i].source+65, edges[i].destination+65);
    }
    printf("\n");
}

void prim(int startNode)
{
    printf("Prim started\n");

    printf("\nPrim ended\n\n");
}

//! Kruskal related stuff

edgeT getMinimumEdgeForAdjacencyMatrix(int ** adjMat)
{
    int i,j;
    edgeT minEdge;
    minEdge.weight=MAX;
    for(i=0;i<nrOfVerteces;i++)
    {
        for(j=i;j<nrOfVerteces;j++)
        {
            if(adjMat[i][j]<minEdge.weight)
            {
                minEdge.weight=adjMat[i][j];
                minEdge.source=i;
                minEdge.destination=j;
            }
        }
    }
    return minEdge;
}

int ** getCopyOfAdjecencyMatrix()
{
    int i,j;
    int ** copyAdjMatrix =(int**)malloc(nrOfVerteces*sizeof(int*));
    for (i=0; i<nrOfVerteces; i++)
    {
        *(copyAdjMatrix+i)=(int*)malloc(nrOfVerteces*sizeof(int));
        for(j=0; j<nrOfVerteces; j++)
        {
            if (adjMatrix[i][j]==0)
                    copyAdjMatrix[i][j]=MAX;
                else
            copyAdjMatrix[i][j] = adjMatrix[i][j];
        }
    }
    return copyAdjMatrix;
}

int ** createEmptyMatrix()
{
    int i,j;
    int ** MATRIX =(int**)malloc(nrOfVerteces*sizeof(int*));
    for (i=0; i<nrOfVerteces; i++)
    {
        *(MATRIX+i)=(int*)malloc(nrOfVerteces*sizeof(int));
        for(j=0; j<nrOfVerteces; j++)
        {
            MATRIX[i][j] = 0;
        }
    }
    return MATRIX;
}

int **createAdjacencyMatrix(int **MATRIX) //Roy-Floyd
{
    int i,j,k;
    for(k=0;k<nrOfVerteces;k++)
    {
        for(i=0;i<nrOfVerteces;i++)
        {
            for(j=0;j<nrOfVerteces;j++)
            {
                if(MATRIX[k][j]==1 && MATRIX[i][k]==1)
                {
                    MATRIX[i][j]=1;
                    MATRIX[j][i]=1;
                }
            }
        }
    }
    return MATRIX;
}


void kruskal()
{
    int **adjMat=getCopyOfAdjecencyMatrix();
    int **MATRIX=createEmptyMatrix();
    int *mst=(int*)malloc(nrOfVerteces*sizeof(int));
    int i;
    int weight=0;
    for(i=0;i<nrOfVerteces;i++)
    {
        mst[i]=UNVISITED;
    }
    int nrOfCoveredEdges=0;
    printf("Kruskal started\n");
    printf("\n{");
    while(nrOfCoveredEdges<nrOfVerteces-1)
    {
        edgeT e=getMinimumEdgeForAdjacencyMatrix(adjMat);

        if(mst[e.destination]==UNVISITED || mst[e.source]==UNVISITED)
        {
            mst[e.destination]=VISITED;
            mst[e.source]=VISITED;
            MATRIX[e.source][e.destination]=1;
            MATRIX[e.destination][e.source]=1;
            weight+=e.weight;
            printf("(%c,%c) ",e.source+65,e.destination+65);
            adjMat[e.source][e.destination]=MAX;
            adjMat[e.destination][e.source]=MAX;
            nrOfCoveredEdges++;
        }
        else
        {
            int **adjacencyMATRIX=createAdjacencyMatrix(MATRIX);
            if (adjacencyMATRIX[e.source][e.destination]==0)
            {
                MATRIX[e.source][e.destination]=1;
                MATRIX[e.destination][e.source]=1;
                printf("(%c,%c) ",e.source+65,e.destination+65);
                nrOfCoveredEdges++;
            }
            adjMat[e.source][e.destination]=MAX;
            adjMat[e.destination][e.source]=MAX;
        }
    }

    printf("}");
    printf("\n The weight of the minimum spanning tree is %d",weight);
    printf("\nKruskal ended\n\n");
}

//! Dijsktra related stuff

int getMinDistanceVertex(int * distances, int * visited){

}

void dijkstra(int startNode)
{
    printf("Dijkstra started\n");


    /* UNCOMMENT FOR PRINTING DIJKSTRA PATHS
    for(i=0; i<nrOfVerteces; i++){
        int u=i;
        if(i!=startNode){
            while(previous[u] != UNDEFINED){
                push(u);
                u = previous[u];
            }
            printf("Path from %c to %c is: %c ",startNode + 65, i+65, startNode + 65);
            while(!isEmptyStack()){
                printf("-> %c ",peekStack()->content + 65);
                pop();
            }
            printf("\n");
        }
    }
    */

    printf("\nDijkstra ended\n\n");
}


//Bellman Ford -- finds the shorthest path form A to F in the oriented graph from the file matrixBF

void BellmanFord()
{
    printf("\nBellman-Ford algorithm started\n");
    int *d=(int*)malloc(sizeof(int)*nrOfBFVerteces);
    int *pi=(int*)malloc(sizeof(int)*nrOfBFVerteces);
    d[0]=0;
    pi[0]=0;
    int i,repeat,j;
    for(i=1;i<nrOfBFVerteces;i++)
    {
        d[i]=MAX;
        pi[0]=0;
    }
    for(repeat=0;repeat<nrOfBFVerteces-1;repeat++)
    {
        for(i=0;i<nrOfBFVerteces;i++)
        {
            for(j=0;j<nrOfBFVerteces;j++)
            {
                if(adjBFMatrix[i][j]!=0)
                    if(adjBFMatrix[i][j]+d[i]<d[j])
                {
                    d[j]=adjBFMatrix[i][j]+d[i];
                    pi[j]=i;
                }
            }
        }
    }
    int weight=0;
    for(i=0;i<nrOfBFVerteces;i++)
    {
        weight+=d[i];
    }
    printf("\n the cost of the shortest path is %d\n",weight);
    for(i=0;i<nrOfBFVerteces;i++)
    {
        printf("\nthe predecessor of node %c is %c ",pi[i]+65,i+65);
    }
    printf("\nBellman-Ford algorithm ended\n");
}

