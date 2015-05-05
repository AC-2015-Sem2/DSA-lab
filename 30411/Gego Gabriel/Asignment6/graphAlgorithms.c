#include "graph.h"
#include "graphRepresentation.h"

//! Prim related stuff
edgeT getMinimumEdgeForCurrentlyVisitedNodes(int * visited)
{
    int i,j;
    edgeT minEdge;
    minEdge.weight=MAX;

    for (i=0; i<nrOfVerteces; i++)
    {
        for (j=0; j<nrOfVerteces; j++)
        {
            if(visited[i] == VISITED && visited[j] != VISITED && adjMatrix[i][j] > 0)
            {
                if(adjMatrix[i][j]<minEdge.weight)
                {
                    minEdge.source = i;
                    minEdge.destination = j;
                    minEdge.weight = adjMatrix[i][j];
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

void prim(int startNode)
{
    printf("Prim's Algorithm started\n");

    int nrVertecesVisited=0,i;
    int * visited = (int*)malloc(nrOfVerteces * sizeof(int));
    for(i=0; i<nrOfVerteces; i++)
    {
        visited[i] = UNVISITED;
    }
    int minCost = 0;

    edgeT * edges = (edgeT*) malloc((nrOfVerteces-1) * sizeof(edgeT));

    visited[startNode] = VISITED;

    while(nrVertecesVisited<nrOfVerteces-1)
    {
        edgeT minEdge = getMinimumEdgeForCurrentlyVisitedNodes(visited);
        visited[minEdge.destination]=VISITED;
        edges[nrVertecesVisited++] = minEdge;
        minCost+=minEdge.weight;
    }

    printEdges(edges, nrVertecesVisited);
    printf("Cost of MST by Prim's Algorithm: %d\n",minCost);
    printf("Prim's algorithm ended\n\n");
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
    int z = i;
    while(parent[z] != -1)
    {
        z = parent[z];
    }
    return z;
}

int uni(int * parent, int i,int j)
{

    int u = getParent(parent, i);
    int v = getParent(parent, j);
    if(u!=v)
        return 1;
    else
        return 0;
}

void kruskal()
{
    printf("Kruskal\n");
    int** adjCopy = getCopyOfAdjecencyMatrix();
    int* parents = (int*)malloc(nrOfVerteces*sizeof(int));
    int i;
    for (i=0; i<nrOfVerteces; i++)parents[i] = -1;
    edgeT edge = getMinimumEdgeForAdjacencyMatrix(adjCopy);
    while (edge.weight != MAX)
    {
        if (uni(parents, edge.source, edge.destination))
            printf("%c-%c(%d) ", 65+edge.source, 65+edge.destination, edge.weight);

        adjCopy[edge.source][edge.destination] = adjCopy[edge.destination][edge.source] = MAX;
        edge = getMinimumEdgeForAdjacencyMatrix(adjCopy);
    }
    printf("\n Kruscall Ended \n");
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

void dijkstra(int startNode)
{
    printf("Dijkstra's Algorithm started\n");
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

            printf("Path from %c to %c is: %c ",startNode +65, i+65, startNode +65);
            while(!isEmptyStack())
            {
                printf("-> %c ",peekStack()->content +65);
                pop();
            }
            printf("\n");
        }
    }

    printf("Dijkstra's Algorithm ended\n");
}

void bellmanFord(int startingNode)
{
    printf("\nBellman Ford's algorithm started: \n");
    int i;
    int* weights = (int*)malloc(nrOfVerteces*sizeof(int));
    int* parents = (int*)malloc( nrOfVerteces* sizeof(int));
    for(i = 0; i < nrOfVerteces; i++)
    {
        weights[i] = 0;
        parents[i] = 0;
    }

    for(i = 0; i < nrOfVerteces; i++)
    {
        if(i == startingNode)
        {
            weights[i] = -2;
        }
        else
        {
            weights[i] = INFINITY;
            parents[i] = -1;
        }
    }
    for(i = 0; i < nrOfVerteces-1; i++)
    {
        int u,v;
        for(u = 0; u < nrOfVerteces; u++)
        {
            for(v = 0; v < nrOfVerteces; v++)
            {
                if(adjMatrix[u][v] > 0)
                    if(weights[u] + adjMatrix[u][v] < weights[v])
                    {
                        parents[v] = u;
                        weights[v] = weights[u] + adjMatrix[u][v];
                    }
            }
        }
    }
    for(i = 0; i < nrOfVerteces; i++)
    {
        printf("%c->%c\n", parents[i]+65,i+65);
    }
    printf("Bellman Ford's ended\n\n");
}

