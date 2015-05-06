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
                //printf("%d \n", adjMatrix[i][j]);
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
    minEdge.weight = -1;
    // minEdge.weight=MAX;

    for (i=0; i<nrOfVerteces; i++)
    {
        for (j=0; j<nrOfVerteces; j++)
        {
            if(adjMat[i][j] > 0)
            {
                if(adjMat[i][j]<minEdge.weight || minEdge.weight == -1)
                {
                    minEdge.source = i;
                    minEdge.destination = j;
                    minEdge.weight = adjMat[i][j];
                }
            }
        }
    }
    adjMat[minEdge.source][minEdge.destination] = 0;
    adjMat[minEdge.destination][minEdge.source] = 0;

    return minEdge;
}
//function that returns a copy of the adjacency matrix
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

int adjMatrixIsEmpty(int **adjMat)
{
    int isEmpty = 1;
    int i, j;
    for(i = 0; i < nrOfVerteces && isEmpty == 1; i++)
        for(j = 0; j < nrOfVerteces && isEmpty == 1; j++)
            if(adjMat[i][j] > 0)
                isEmpty = 0;

    return isEmpty;
}

void kruskal()
{
    printf("Kruskal's Algorithm started\n");
    int i;
    int **adjMat = getCopyOfAdjecencyMatrix();

    int *treeComponent = (int*)malloc(sizeof(int) * nrOfVerteces);

    for(i=0; i < nrOfVerteces; i++)
        treeComponent[i]= i;

    int minCost =0;
    while(adjMatrixIsEmpty(adjMat) == 0)
    {
        edgeT minEdge = getMinimumEdgeForAdjacencyMatrix(adjMat);
        if(treeComponent[minEdge.source] != treeComponent[minEdge.destination])
        {
            int priorityComponent = 0;
            if(treeComponent[minEdge.source] < treeComponent[minEdge.destination])
                priorityComponent = treeComponent[minEdge.source];
            else if(treeComponent[minEdge.source] > treeComponent[minEdge.destination])
                priorityComponent = treeComponent[minEdge.destination];

            int targetComponent = 0;
            if(treeComponent[minEdge.source] == priorityComponent)
                targetComponent = treeComponent[minEdge.destination];
            else if(treeComponent[minEdge.destination] == priorityComponent)
                targetComponent = treeComponent[minEdge.source];

            for(i=0; i<nrOfVerteces; i++)
                if(treeComponent[i] ==targetComponent)
                    treeComponent[i] = priorityComponent;
           printf("%c -> %c\t",minEdge.source+65, minEdge.destination+65);
           minCost += minEdge.weight;
        }
    }
        printf("\nCost of MST by Kruskal's algorithm: %d\n", minCost);
        printf("Kruskal's Algorithm ended\n\n");
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

            printf("Path from %c to %c is: %c ",startNode + 65, i+65, startNode + 65);
            while(!isEmptyStack())
            {
                printf("-> %c ",peekStack()->content + 65);
                pop();
            }
            printf("\n");
        }
    }

    printf("Dijkstra's Algorithm ended\n");
}


void bellmanFord(int startingNode)
{
    printf("\nBellman Ford's algorithm starts here: \n");
    int i,j, minCost =0;
    int* weight = (int*)malloc(sizeof(int) * nrOfVerteces);
    int* parent = (int*)malloc(sizeof(int) * nrOfVerteces);
    for(i = 0; i < nrOfVerteces; i++)
    {
        weight[i] = 0;
        parent[i] = 0;
        if(i == startingNode)
        {
            weight[i] = -2;
        }
        else
        {
            weight[i] = 99999;
            parent[i] = -1;
        }
    }
    for(i = 0; i < nrOfVerteces - 1; i++)
    {
        int i1;
        int j1;
        for(i1 = 0; i1 < nrOfVerteces; i1++)
        {
            for(j1 = 0; j1 < nrOfVerteces; j1++)
            {
                if(adjMatrix[i1][j1] > 0)
                {
                    if(weight[i1] + adjMatrix[i1][j1] < weight[j1])
                    {
                        weight[j1] = weight[i1] + adjMatrix[i1][j1];
                        parent[j1] = i1;
                    }
                }
            }
        }
    }
    for(i=0; i<nrOfVerteces;i++)
    {
        for(j=0;j<nrOfVerteces; j++)
        {
            if(adjMatrix[i][j] > 0)
            {
                if(weight[i] + adjMatrix[i][j] < weight[j])
                {
                    printf("\n Error: graph contains a negative weight cycle\n");
                }
            }
        }
    }
    for(i=0;i<nrOfVerteces;i++)
    {
        if( i!= startingNode)
            minCost += adjMatrix[i][parent[i]];
    }
    for(i = 0; i < nrOfVerteces; i++)
    {
        printf("%c->%c\t", parent[i]+65 , i +65);
    }

    printf("\nCost of MST by BellmanFord's algorithm: %d\n", minCost);
    printf("Bellman Ford's ended\n\n");
}

