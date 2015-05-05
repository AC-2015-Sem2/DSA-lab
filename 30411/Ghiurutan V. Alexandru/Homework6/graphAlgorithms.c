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
    while (parent[i] != UNDEFINED)
        i = parent[i];
    return i;
}

int uni(int * parent, int i, int j)
{
    int p1 = getParent(parent, i);
    int p2 = getParent(parent, j);
    if (p1 == p2 && p1 != UNDEFINED)
        return 0;
    return 1;
}

void kruskal()
{
    printf("Kruskal's Algorithm started\n");
    int minCost = 0;
    int** cpyAdjMatrix = getCopyOfAdjecencyMatrix();
    int* parent = (int*)malloc(nrOfVerteces*sizeof(int));
    int i;
    for ( i = 0; i < nrOfVerteces; i++)
        parent[i] = UNDEFINED;
    edgeT* edges = (edgeT*)malloc((nrOfVerteces-1)*sizeof(edgeT));
    int nrOfEdges = 0;
    while (getMinimumEdgeForAdjacencyMatrix(cpyAdjMatrix).weight != MAX && nrOfEdges < nrOfVerteces - 1) {
        edgeT u = getMinimumEdgeForAdjacencyMatrix(cpyAdjMatrix);
        cpyAdjMatrix[u.source][u.destination] = cpyAdjMatrix[u.destination][u.source] = 0;
        if (uni(parent, u.source, u.destination)) {
            edges[nrOfEdges] = u;
            nrOfEdges++;
            if (parent[u.destination] != -1)
                parent[u.source] = u.destination;
            else
                parent[u.destination] = u.source;
            minCost += u.weight;
        }
    }
    for (i = 0; i < nrOfVerteces; i++) {
        printf("%c:%d ", i+65, parent[i]);
    }
    printf("\n");
    for (i = 0; i < nrOfEdges; i++) {
        printf("%c -> %c\n", edges[i].source+65, edges[i].destination+65);
    }
    printf("Cost of MST by Kruskal's Algorithm: %d\n", minCost);
    printf("Kruskal's Algorithm ended\n\n");

}

//! Dijsktra related stuff

int getMinDistanceVertex(int * distances, int * visited){
    int min=MAX, i;
    int minV;
    for(i=0;i<nrOfVerteces;i++){
        if(distances[i] < min && visited[i] == UNVISITED){
            minV = i;
            min = distances[i];
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

    printf("Dijkstra's Algorithm ended\n\n");
}

//! Bellman Ford related stuff

int getNumberOfEdges() {
    int n = 0,i,j;
    for (i = 0; i < nrOfVerteces-1; i++)
        for (j = i + 1; j < nrOfVerteces; j++)
            if (adjMatrix[i][j] > 0)
                n++;
    return n;
}

edgeT* getAllEdges() {
    int nrEdges = getNumberOfEdges();
    edgeT* edges = (edgeT*)malloc(nrEdges*sizeof(edgeT));
    int k = 0,i,j;
    for (i = 0; i < nrOfVerteces-1; i++)
        for (j = i + 1; j < nrOfVerteces; j++)
            if (adjMatrix[i][j] > 0) {
                edges[k].source = i;
                edges[k].destination = j;
                edges[k].weight = adjMatrix[i][j];
                k++;
            }
    return edges;
}

int bellmanFord(int startNode) {
    printf("Bellman Ford's Algorithm started\n");
    int* parent = (int*)malloc(nrOfVerteces*sizeof(int));
    int* distance = (int*)malloc(nrOfVerteces*sizeof(int));
    int i,j;
    for (i = 0; i < nrOfVerteces; i++) {
        parent[i] = UNDEFINED;
        distance[i] = MAX;
    }
    distance[startNode] = 0;
    int nrEdges = getNumberOfEdges();
    edgeT* edges = getAllEdges();
    for (i = 0; i < nrOfVerteces; i++)
        for (j = 0; j < nrEdges; j++) {
            int s = edges[j].source;
            int d = edges[j].destination;
            int w = edges[j].weight;
            if (distance[s] + w < distance[d]) {
                distance[d] = distance[s] + w;
                parent[d] = s;
            }
            if (distance[d] + w < distance[s]) {
                distance[s] = distance[d] + w;
                parent[s] = d;
            }
        }
    for (j = 0; j < nrEdges; j++)
            if (distance[edges[j].source] + edges[j].weight < distance[edges[j].destination])
                return 0;

    for(i=0; i<nrOfVerteces; i++){
        int u=i;
        if(i!=startNode){
            while(parent[u] != UNDEFINED){
                push(u);
                u = parent[u];
            }

            printf("Path from %c to %c is: %c ",startNode + 65, i+65, startNode + 65);
            while(!isEmptyStack()){
                printf("-> %c ",peekStack()->content + 65);
                pop();
            }
            printf(" and distance is %d\n", distance[i]);
        }
    }
    printf("Bellman Ford's Algorithm ended\n\n");
    return 1;
}
