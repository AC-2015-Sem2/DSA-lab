#include "graph.h"
#include "graphRepresentation.h"

/* ********************************************************************************************************************************/
//! Prim related stuff

edgeT getMinimumEdgeForCurrentlyVisitedNodes(int * visited)
{
    int i,j;
    edgeT minE;
    minE.weight = MAX;
    for (i=0; i<nrOfVerteces; i++)
        for (j=0; j<nrOfVerteces; j++)
        {
            if (i != j)
            {
                if (visited[i] ==VISITED && visited[j] ==UNVISITED && adjMatrix[i][j]<minE.weight && adjMatrix[i][j]>0)
                {
                    minE.source = i;
                    minE.destination=j;
                    minE.weight = adjMatrix[i][j];
                }
            }
        }
    return minE;
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
    int *mst;
    int nrofCoveredEdges, weight;
    edgeT *edges;

    mst = (int *)calloc(nrOfVerteces,sizeof(int));
    edges = (edgeT *)calloc((nrOfVerteces - 1), sizeof(edgeT));
    mst[startNode] = 1;
    nrofCoveredEdges = 0;
    weight = 0;

    while (nrofCoveredEdges < nrOfVerteces-1)
    {
        edgeT e = getMinimumEdgeForCurrentlyVisitedNodes(mst);
        mst [e.destination] = 1;
        edges[nrofCoveredEdges]=e;
        weight+=e.weight;
        nrofCoveredEdges++;
    }
    printEdges(edges, nrofCoveredEdges);
    printf("%d ", weight);
}
/* ********************************************************************************************************************************/

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
    if (parent[i]!=0)
    {
        i=parent[i];
    }
    return(i);
}

int uni(int * parent, int i,int j)
{

}

void kruskal()
{

}

/* ********************************************************************************************************************************/

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
    printf("Dijkstra's Algorithm started\n\n");
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

    printf("Dijkstra's Algorithm ended\n\n");
}
/* ********************************************************************************************************************************/
//! Bellman Ford algorithm

int getNumberofEdges()
{
    int i,j,nr;

    nr = 0;
    for (i=0; i< nrOfVerteces; i++)
        for (j=0; j<nrOfVerteces; j++)              //find the number of edges
           // if (i<j)                             //it works fine only if I comment this line
                if (adjMatrix[i][j] != 0)
                    nr++;
    return(nr);
}

edgeT *getAllEdges()
{
    int i,j,k,nr;
    edgeT *alledges;

    nr = getNumberofEdges();
    alledges = (edgeT *)calloc(nr, sizeof(edgeT));   //allocate the memory for the array of edges
    k = 0;
    for (i=0; i< nrOfVerteces; i++)
        for (j=0; j<nrOfVerteces; j++)    //find the edges
           // if (i<j)                    //it works fine only if I comment this line
                if (adjMatrix[i][j] != 0)
                {
                    alledges[k].source=i;
                    alledges[k].destination=j;
                    alledges[k].weight=adjMatrix[i][j];
                    k++;
                }
    return (alledges);
}
void printSolution(int *dist, int source)
{
    int i;
    printf("Vertex:   Distance from Source:\n");
    for (i = 0; i < nrOfVerteces; ++i)
        if (i!= source)
            printf("%d \t\t %d\n", i, dist[i]);
}

void BellmanFord(int src)
{
    edgeT *edges;
    int nrofedges;
    int *dist;
    int i,j;

    dist = (int*)malloc(nrOfVerteces * sizeof(int));
    nrofedges = getNumberofEdges();
    edges = (edgeT *)calloc(nrofedges, sizeof(edgeT));
    edges = getAllEdges();

    printf("Bellman Ford algorithm started ! \n\n");
    // Step 1: Initialize distances from src to all other vertices as INFINITE
    for (i = 0; i < nrOfVerteces; i++)
        dist[i]= MAX;
    dist[src] = 0;

    // Step 2: Relax all edges |V| - 1 times. A simple shortest path from src
    // to any other vertex can have at-most |V| - 1 edges
    for (i = 0; i < nrOfVerteces; i++)
    {
        for (j = 0; j < nrofedges; j++)
        {
            edgeT aux;
            aux = edges[j];
            int u = aux.source;
            int v = aux.destination;
            int weight = aux.weight;
            if (dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // Step 3: check for negative-weight cycles.  The above step guarantees shortest distances if graph doesn't contain negative weight cycle.
    // If we get a shorter path, then there is a cycle.
    for (i = 0; i < nrofedges; i++)
    {
        int u = edges[i].source;
        int v = edges[i].destination;
        int weight = edges[i].weight;
        if (dist[u] != MAX && dist[u] + weight < dist[v])
            printf("Graph contains negative weight cycle between %d and %d", u, v);
    }
    printSolution(dist, src);
    printf("Bellman ford algorithm ended ! \n\n");
}
