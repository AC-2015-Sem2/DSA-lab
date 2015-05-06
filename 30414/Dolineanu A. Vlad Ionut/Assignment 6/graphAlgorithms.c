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
    return parent[i];
}

int uni(int * parent, int i,int j)
{
    int parentI = getParent(parent, i), parentJ = getParent(parent, j);

    if(parentI != parentJ)
    {
        parent[parentI] = parentJ;
        return 1;
    }
    else
        return 0;
}

void removeEdge(int** matrix, edgeT edge)
{
    matrix[edge.source][edge.destination] = 0;
    matrix[edge.destination][edge.source] = 0;
}

void kruskal()
{
    int* parent = (int*)malloc(sizeof(int)*nrOfVerteces);

    int i, trees = nrOfVerteces, nrEdges = 0;

    for(i=0; i<nrOfVerteces; i++)
        parent[i] = i;

    edgeT minEdge;
    edgeT *edges = (edgeT*) malloc(sizeof(edgeT)*(nrOfVerteces-1));

    int** copyOfAdjMatrix = getCopyOfAdjecencyMatrix(adjMatrix);

    while(trees > 1)
    {
        minEdge = getMinimumEdgeForAdjacencyMatrix(copyOfAdjMatrix);

        removeEdge(copyOfAdjMatrix, minEdge);

        if(uni(parent, minEdge.source, minEdge.destination) != 0)
        {
            trees--;
            edges[nrEdges] = minEdge;
            nrEdges++;
        }
    }

    printf("\nKruskal:\n");
    printEdges(edges, nrOfVerteces-1);
    printf("\n");

}

//! Dijsktra related stuff

int getMinDistanceVertex(int * distances, int * visited){
    int min=MAX, i;
    int minV;
    for(i=0;i<nrOfVerteces;i++){
        if(distances[i] < min && visited[i] == UNVISITED){
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

    while(nrOfVertecesVisited < nrOfVerteces){
        int u = getMinDistanceVertex(distances,visited);
        visited[u] = VISITED;

        int nrOfNeighbors = getNumberOfNeighborsOfVertex(u);
        int * neighbors = getAllNeighborsOfVertex(u);
        for(i=0; i<nrOfNeighbors; i++)
        {
            int w = neighbors[i];
            int alt = distances[u] + adjMatrix[u][w];
            if(alt<distances[w]){
                distances[w] = alt;
                previous[w] = u;
            }
        }
        nrOfVertecesVisited++;
    }

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

    printf("Dijkstra's Algorithm ended\n");
}

void printPaths(int* parents, int* distance, int startNode)
{
    int* path = (int*)malloc(sizeof(int) * (nrOfVerteces - 1));

    int i, lengthOfPath = 0, auxVert;
    printf("\n\n");

    for(auxVert=0; auxVert < nrOfVerteces; auxVert++)
    {
        if(startNode != auxVert)
        {
            printf("Distance from start to %d is %d\n", auxVert, distance[auxVert]);
            lengthOfPath = 0;
            path[lengthOfPath] = auxVert;
            lengthOfPath++;

            int pathVert = auxVert;

            while(pathVert != parents[pathVert])
            {
                pathVert = parents[pathVert];
                path[lengthOfPath] = pathVert;
                lengthOfPath++;
            }
            printf("Path to node %d is: ", auxVert);
            for(i=lengthOfPath-1; i>= 0; i--)
                printf("%d ", path[i]);
            printf("\n");
        }
    }
}

void bellmanFord(int startNode)
{
    printf("\nBellman Ford:");
    int *distance = (int*)malloc(sizeof(int)*nrOfVerteces);
    int *parents = (int*)malloc(sizeof(int)*nrOfVerteces);

    int i;

    for(i=0; i<nrOfVerteces; i++)
    {
        if(i == startNode)
        {
            distance[i] = 0;
            parents[i] = i;
        }
        else
        {
            distance[i] = MAX;
            parents[i] = i;
        }

    }

    int x, y;

    for(i=0; i < nrOfVerteces-1; i++)
        for(x=0; x<nrOfVerteces; x++)
            for(y=0; y<nrOfVerteces; y++)
                if(x != y && adjMatrix[x][y] != 0)
                    if(distance[x] + adjMatrix[x][y] < distance[y])
                    {
                        distance[y] = distance[x] + adjMatrix[x][y];
                        parents[y] = x;
                    }

    printPaths(parents, distance, startNode);
}

