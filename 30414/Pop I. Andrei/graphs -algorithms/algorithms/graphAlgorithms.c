#include "graph.h"
#include "graphRepresentation.h"
#include <limits.h>

//! Prim related stuff
edgeT getMinimumEdgeForCurrentlyVisitedNodes(int * visited)
{
    int min = 99999999, i, j;
    edgeT e;

    for(i=0; i<nrOfVerteces; i++)
        if(visited[i] == 1)
        {
            for(j=0; j<nrOfVerteces; j++)
                if(adjMatrix[i][j] != 0 && min > adjMatrix[i][j] && visited[j] == UNVISITED)
                {
                    min = adjMatrix[i][j];
                    e.source = i;
                    e.destination = j;
                    e.weight = adjMatrix[i][j];
                }
        }
    return e;
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

void prim(int start)
{
    printf("Prim started\n");
    int *visited = (int*) malloc (sizeof(int) * nrOfVerteces), i;
    for(i=0; i<nrOfVerteces; i++)
        visited[i] = UNVISITED;

    int nrOfSteps = 0, w = 0;
    edgeT *edges = (edgeT*) malloc (sizeof(edgeT) * (nrOfVerteces-1));

    visited[start] = VISITED;

    while(nrOfSteps < nrOfVerteces-1)
    {
        edgeT e = getMinimumEdgeForCurrentlyVisitedNodes(visited);
        visited[e.destination] = VISITED;
        edges[nrOfSteps++] = e;
        w+=e.weight;

    }

    printEdges(edges, nrOfVerteces-1);
    printf("Prim ended\n");
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

void kruskal()
{
    printf("\nKruskal's algorithm started\n");

    int **matrix = getCopyOfAdjecencyMatrix();
    int *tag  = (int*) malloc (sizeof(int) * nrOfVerteces);
    int nrOfEdges = 0, i, minTag, maxTag;
    edgeT minEdge;
    edgeT *edges = (edgeT*) malloc (sizeof(edgeT) * (nrOfVerteces-1));

    for(i=0; i<nrOfVerteces; i++)
        tag[i] = i;

    while(nrOfEdges < nrOfVerteces-1)
    {
        minEdge = getMinimumEdgeForAdjacencyMatrix(matrix);
        matrix[minEdge.source][minEdge.destination] = -10;
        matrix[minEdge.destination][minEdge.source] = -10;

        if(tag[minEdge.source] != tag[minEdge.destination])
        {
            edges[nrOfEdges] = minEdge;
            //keep the greater tag
            if(tag[minEdge.source] > tag[minEdge.destination])
            {
                minTag = tag[minEdge.destination];
                maxTag = tag[minEdge.source];
            }
            else
            {
                minTag = tag[minEdge.source];
                minTag = tag[minEdge.destination];
            }
            //everywhere I find the minTag I will replace it by maxTag
            for(i=0; i<nrOfVerteces; i++)
                if(tag[i] == minTag)
                    tag[i] = maxTag;

            nrOfEdges+=1; //increment the number of edges that I'have used
        }
    }

    printEdges(edges, nrOfEdges);

    printf("Kruskal's algorithm ended\n");

}

//! Dijsktra related stuff

int getMinDistanceVertex(int * dist, int * visited)
{
    int min, i, pozMin;
    min = INT_MAX;

    for(i=0; i<nrOfVerteces; i++)
    {
        if(min > dist[i] && visited[i] == 0)
        {
            min = dist[i];
            pozMin = i;
        }
    }

    return pozMin;

}

void dijkstra(int start)
{
    printf("\nDijkstra's algorithm started\n");

    int *dist = (int*) malloc (nrOfVerteces * sizeof(int));
    int *visited = (int*) malloc (nrOfVerteces * sizeof(int));
    int *parent = (int*) malloc (nrOfVerteces * sizeof(int));
    int *neigh = (int*) malloc (nrOfVerteces * sizeof(int));
    int i, u, nr = 0,w;

    for(i=0; i<nrOfVerteces; i++)
    {
        dist[i] = INT_MAX;
        parent[i] = UNDEFINED;
        visited[i] = UNVISITED;
    }

    dist[start] = 0;

    while(nr<nrOfVerteces)
    {
        u = getMinDistanceVertex(dist, visited);
        visited[u] = VISITED;
        neigh = getAllNeighborsOfVertex(u);
        for(i = 0; i<getNumberOfNeighborsOfVertex(u); i++)
        {
            w = neigh[i];
            if(dist[w] > dist[u] + adjMatrix[u][w])
            {
                dist[w] = dist[u] + adjMatrix[u][w];
                parent[w] = u;
            }
        }
        nr+=1;
    }

    printf("The minimum distances from vertex %d are: ", start);
    for(i=0; i<nrOfVerteces; i++)
        if(i!=start)
            printf("%d ", dist[i]);
    printf("\nDijkstra's algorithm ended\n");
}

// Bellman Ford related stuff

int getNumberOfEdges(int **adjMatrix)
{
    int i, j, nrEdges = 0;

    for(i=0; i<nrOfVerteces; i++)
        for(j=0; j<nrOfVerteces; j++)
            if(adjMatrix[i][j] != 0 && i<j)
                nrEdges+=1;

    return nrEdges;
}

edgeT *getTheEdges(int **adjMatrix)
{
    int i, j, nrEdges = 0;
    edgeT *edges = (edgeT *) malloc (getNumberOfEdges(adjMatrix) * sizeof(edgeT));

    for(i=0; i<nrOfVerteces; i++)
        for(j=0; j<nrOfVerteces; j++)
            if(adjMatrix[i][j] != 0 && i<j)
            {
                edges[nrEdges].source = i;
                edges[nrEdges].destination = j;
                edges[nrEdges].weight = adjMatrix[i][j];
                nrEdges +=1;
            }
    return edges;

}

void bellman(int start)
{
    printf("\nBellman's argorithm started\n");

    edgeT *edge = getTheEdges(adjMatrix);
    int nrEdges = getNumberOfEdges(adjMatrix);
    int *dist = (int*) malloc (nrOfVerteces * sizeof(int));
    int *parent = (int*) malloc (nrOfVerteces * sizeof(int));
    int i, j;

    for(i=0; i<nrOfVerteces; i++)
    {
        dist[i] = INT_MAX;
        parent[i] = UNDEFINED;
    }

    dist[start] = 0;

    for(i=0; i<nrOfVerteces; i++)
    {
        for(j=0; j<nrEdges; j++)
        {
            if(dist[edge[j].destination] > dist[edge[j].source] + edge[j].weight)
            {
                dist[edge[j].destination] = dist[edge[j].source] + edge[j].weight;
                parent[edge[j].destination] = edge[j].source;
            }
        }
    }

    int ok = 1;
    for(j=0; j<nrEdges; j++)
        if(dist[edge[i].destination] > dist[edge[i].source] + edge[i].weight)
            ok = 0;

    if(ok == 1)
    {
        printf("The distances from vertex %d are: ", start);
        for(i=0; i<nrOfVerteces; i++)
            if(i!=start)
                printf("%d ", dist[i]);
        printf("\n");
    }
    else
        printf("Found a negative cycle\n");

    printf("Bellman Ford algorithm ended\n");

}
