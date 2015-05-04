#include "graph.h"
#include "graphRepresentation.h"


//! Prim related stuff
edgeT getMinimumEdgeForCurrentlyVisitedNodes(int *mst)
{
    int i,j;
    edgeT minE;
    minE.weight=MAX;
    for(i=0; i<nrOfVerteces; i++)
        for(j=0; j<nrOfVerteces; j++)
        {
            if(i!=j)
            {

                if(mst[i]==VISITED && mst[j]==UNVISITED && minE.weight<adjMatrix[i][j] && adjMatrix[i][j]>0 && i!=j)
                {
                    minE.source=i;
                    minE.destination=j;
                    minE.weight=adjMatrix[i][j];
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
    printf("Prim\n");
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
    printf("\n");
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
     if (parent[i]==-1)
        return i;
    else
        return getParent(parent, parent[i]);
}

int uni(int * parent, int i,int j)
{
    int iParent = getParent(parent, i);
    int jParent = getParent(parent, j);
    if (iParent!=jParent)
    {
        parent[jParent] = iParent;
        return 1;
    }
    else
    {
        return 0;
    }
}
void kruskal()
{
    printf("Kruskal\n");
    int** adjCopy = getCopyOfAdjecencyMatrix();
    int* parentNodes = (int*)malloc(nrOfVerteces*sizeof(int));
    int i;
    for (i=0; i<nrOfVerteces; i++)
    {
        parentNodes[i] = -1;
    }
    edgeT edge = getMinimumEdgeForAdjacencyMatrix(adjCopy);
    while (edge.weight != MAX)
    {
        if (uni(parentNodes, edge.source, edge.destination))
        {
           printf("%c-%c(%d) ", 65+edge.source, 65+edge.destination, edge.weight);
        }
        adjCopy[edge.source][edge.destination] = adjCopy[edge.destination][edge.source] = MAX;
        edge = getMinimumEdgeForAdjacencyMatrix(adjCopy);
    }
    printf("\n");
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
    printf("Dijkstra\n");
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
    printf("\n");
}

//! Bellman-Ford related stuff

void printUtil(int ini, int* parent, int node)
{
    if (node == ini)
    {
        printf("%c", 65+ini);
    }
    else
    {
        printUtil(ini, parent, parent[node]);
        printf("-%c", 65+node);
    }
}

void bellmanFord (int initNode)
{
    printf("Bellman-Ford\n");
    int* distance = (int*)malloc(nrOfVerteces*sizeof(int));
    int* parentNodes = (int*)malloc(nrOfVerteces*sizeof(int));
    int i;
    for (i=0; i<nrOfVerteces; i++)
    {
        distance[i] = MAX;
        parentNodes[i] = -1;
    }
    distance[initNode] = 0;
    int r, p;
    for(i=0; i<nrOfVerteces-1; i++)
    {
        for(r=0; r<nrOfVerteces; r++)
        {
            for(p=0; p<nrOfVerteces; p++)
            {
                if(adjMatrix[r][p]>0 && r!=p && distance[r]+adjMatrix[r][p]<distance[p])
                {
                    distance[p] = distance[r]+adjMatrix[r][p];
                    parentNodes[p] = r;
                }
            }
        }
    }
    int Neg = 0; //to check if there is a negative cycle
    for(r=0; r<nrOfVerteces; r++)
    {
        for(p=0; p<nrOfVerteces; p++)
        {
            if (r!=p && adjMatrix[r][p]>0 && distance[r]+adjMatrix[r][p]<distance[p])
            {
                Neg = 1;
            }
        }
    }
    if (!Neg)
    {
        for (i=0; i<nrOfVerteces; i++)
        {
            printUtil(initNode, parentNodes, i);
            printf("\n");
        }
    }
    else
        printf("The graph has a \"-\" weight cycle\n");
    printf("\n");
}
