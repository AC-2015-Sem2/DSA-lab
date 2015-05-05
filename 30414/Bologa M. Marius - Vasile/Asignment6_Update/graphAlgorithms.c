#include "graph.h"
#include "graphRepresentation.h"

//! Prim related stuff
edgeT getMinimumEdgeForCurrentlyVisitedNodes(int * visited)
{
    int i,j;
    edgeT minEdge;
    minEdge.weight=MAX;
    for(i=0; i<nrOfVerteces; i++)
    {
        for(j=0; j<nrOfVerteces; j++)
        {
            if(visited[i]==VISITED && visited[j]!=VISITED &&adjMatrix[i][j]>0)
            {
                if(adjMatrix[i][j]<minEdge.weight)
                {
                    minEdge.source=i;
                    minEdge.destination=j;
                    minEdge.weight=adjMatrix[i][j];
                }
            }
        }
    }
    return minEdge;
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

void Prim(int startNode)
{
    printf("Prim's Algorithm started:\n");
    printf("\n");
    int *visited=(int*)malloc(sizeof(int)*nrOfVerteces);
    int i, visitedVertices=0,minCost=0;
    for(i=0; i<nrOfVerteces; i++)
        visited[i]=UNVISITED;
    edgeT *edges=(edgeT*)malloc(sizeof(edgeT)*nrOfVerteces-1);
    visited[startNode]=VISITED;
    while(visitedVertices<nrOfVerteces-1)
    {
        edgeT minEdge=getMinimumEdgeForCurrentlyVisitedNodes(visited);
        visited[minEdge.destination]=VISITED;
        edges[visitedVertices++]=minEdge;
        minCost+=minEdge.weight;
    }
    printEdges(edges,visitedVertices);
    printf("\n");
    printf("Minimum cost is:");
    printf("%d", minCost);
    printf("\n");
    printf("Prim's Algorithm ended!\n");
    printf("\n");
}

//! Kruskal related stuff
edgeT getMinimumEdgeForAdjacencyMatrix(int ** adjMat)
{
    int i,j;
    edgeT minEdge;
    minEdge.weight=MAX;

    for (i=0; i<nrOfVerteces; i++)
    {
        for (j=0; j<nrOfVerteces; j++)
        {
            if(adjMat[i][j] > 0)
            {
                if(adjMat[i][j]<minEdge.weight)
                {
                    minEdge.source = i;
                    minEdge.destination = j;
                    minEdge.weight = adjMat[i][j];
                }
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
            copyAdjMatrix[i][j] = adjMatrix[i][j];
        }
    }
    return copyAdjMatrix;
}

int getParent(int * parent, int i)
{
    while(parent[i]!=i)
        i=parent[i];
    return i;
}

int uni(int * parent, int i,int j)
{
    if(i!=j)
    {
        parent[j]=i;
        return 1;
    }
    return 0;
}


void Kruskal()
{

    printf("Kruskal's Algorithm started:\n");
    printf("\n");
    int totalEdges=0,i;
    int nrVerteces=nrOfVerteces;
    edgeT minEdge;
    int **auxMatrix=getCopyOfAdjecencyMatrix();
    int *parent=(int*)malloc(nrOfVerteces*sizeof(int));
    edgeT *edges=(edgeT*)malloc(sizeof(edgeT)*(nrOfVerteces-1));

    for(i=0; i<nrVerteces; i++)
    {
        parent[i]=i;
    }
     while (nrVerteces > 1) {
        minEdge = getMinimumEdgeForAdjacencyMatrix(auxMatrix);


        auxMatrix[minEdge.source][minEdge.destination] = 0;
        auxMatrix[minEdge.destination][minEdge.source] = 0;
        if (uni(parent, minEdge.destination, minEdge.source)) {
            edges[totalEdges++] = minEdge;
            nrVerteces--;
        }
    }
    printf("Minimum Spanning Tree :\n");
    printEdges(edges, nrOfVerteces-1);
     printf("Kruskal's Algorithm ended!\n");
}


//! Dijsktra related stuff

int getMinDistanceVertex(int * distances, int * visited)
{
    int min=MAX, i;
    int minV;
    for(i=0; i<nrOfVerteces; i++)
    {
        if(distances[i] < min && visited[i] == UNVISITED)
        {
            minV = i;
        }
    }
    return minV;
}
void Dijkstra(int startNode)
{
    printf("Dijkstra's Algorithm started:\n");
    printf("\n");
    int * distances = (int*)malloc(nrOfVerteces * sizeof(int));
    int * previous  = (int*)malloc(nrOfVerteces * sizeof(int));
    int * visited   = (int*)malloc(nrOfVerteces * sizeof(int));
    int nrOfVertecesVisited=0,i;
    for(i=0; i<nrOfVerteces; i++)
    {
        distances[i] = MAX;
        previous[i]  = UNDEFINED;
        visited[i] = UNVISITED;
    }
    distances[startNode] = 0;

    while(nrOfVertecesVisited < nrOfVerteces)
    {
        int u = getMinDistanceVertex(distances,visited);
        visited[u] = VISITED;

        int nrOfNeighbors = getNumberOfNeighborsOfVertex(u);
        int * neighbors = getAllNeighborsOfVertex(u);
        for(i=0; i<nrOfNeighbors; i++)
        {
            int w = neighbors[i];
            int alt = distances[u] + adjMatrix[u][w];
            if(alt<distances[w])
            {
                distances[w] = alt;
                previous[w] = u;
            }
        }
        nrOfVertecesVisited++;
    }

    for(i=0; i<nrOfVerteces; i++)
    {
        int u=i;
        if(i!=startNode)
        {
            while(previous[u] != UNDEFINED)
            {
                push(u);
                u = previous[u];
            }

            printf("Path from %c to %c is: %c ",startNode + 65, i+65, startNode + 65);
            while(!isEmptyStack())
            {
                printf("-> %c ",peekStack()->content + 65);
                pop();
            }
            printf("\n");
        }
    }
    printf("\n");
    printf("Dijkstra's Algorithm ended!\n");

}
void BellmanFord(int source)
{
    printf("\nBellman-Ford's algorithm started:\n");


    int *predecessor=(int*)malloc(sizeof(int)*nrOfVerteces);
    int *distance=(int*)malloc(sizeof(int)*nrOfVerteces);
    predecessor[source]=0;
    distance[source]=0;
    int i,k,j;
    // Step 1: Initiate the vectors
    for(i=1; i<nrOfVerteces; i++)
    {
        predecessor[0]=0;
        distance[i]=MAX;
    }
    // Step 2: A simple shortest path from source
    // to any other vertex can have at-most |V| - 1 edges
    for(k=0; k<nrOfVerteces-1; k++)
    {
        for(i=0; i<nrOfVerteces; i++)
        {
            for(j=0; j<nrOfVerteces; j++)
            {
                if(adjMatrix[i][j]!=0)
                    if(adjMatrix[i][j]+distance[i]<distance[j])
                    {
                        distance[j]=adjMatrix[i][j]+distance[i];
                        predecessor[j]=i;
                    }
            }
        }
    }
    // Step 3: check for negative-weight cycles.  The above step guarantees
    // shortest distances if graph doesn't contain negative weight cycle.

    for ( i= 0; i < nrOfVerteces; i++)
    {
        for (j = 0; j < nrOfVerteces; j++)
        {
            if (i != j && adjMatrix[i][j])
            {
                if (adjMatrix[i][j]+distance[i]<distance[j])
                {
                    printf("Graph contains negative weight cycle");

                }
            }
        }
    }
    int cost=0;
    for(i=0; i<nrOfVerteces; i++)
    {
        cost=cost+predecessor[i];
    }
    printf("\nThe cost of the shortest path is: %d",cost);
    printf("\n");
    printf("\nBellman-Ford's algorithm ended!\n");
}
