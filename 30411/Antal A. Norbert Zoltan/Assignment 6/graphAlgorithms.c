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
    edgeT edge;
    edge.weight = MAX;
    int i, r;
    for (i=0; i<nrOfVerteces; i++)
    {
        for (r=0; r<nrOfVerteces; r++)
        {
            if (adjMat[i][r]>0 && adjMat[i][r]<edge.weight)
            {
                edge.source = i;
                edge.destination = r;
                edge.weight = adjMat[i][r];
            }
        }
    }
    return edge;
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
    {
        return i;
    }
    else
    {
        return getParent(parent, parent[i]);
    }
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
    printf("Kruskal started\n");
    int** adjCopy = getCopyOfAdjecencyMatrix();
    int* parentNodes = (int*)malloc(nrOfVerteces*sizeof(int));
    int i;
    for (i=0; i<nrOfVerteces; i++)
    {
        parentNodes[i] = -1;
    }
    edgeT edge = getMinimumEdgeForAdjacencyMatrix(adjCopy);
    printf("Edges: ");
    while (edge.weight != MAX)
    {
        if (uni(parentNodes, edge.source, edge.destination))
        {
            printf("%c-%c(%d) ", 65+edge.source, 65+edge.destination, edge.weight);
        }
        adjCopy[edge.source][edge.destination] = adjCopy[edge.destination][edge.source] = MAX;
        edge = getMinimumEdgeForAdjacencyMatrix(adjCopy);
    }
    printf("\nKruskal ended\n\n");
}

//! Dijsktra related stuff

int getMinDistanceVertex(int * distances, int * visited)
{

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

//! Bellman-Ford related stuff

void printUTIL(int init, int* parent, int node)
{
    if (node == init)
    {
        printf("%c", 65+init);
    }
    else
    {
        printUTIL(init, parent, parent[node]);
        printf("-%c", 65+node);
    }
}

void bellmanFord (int initNode)
{
    printf("Bellman-Ford started\n");
    int* distances = (int*)malloc(nrOfVerteces*sizeof(int));
    int* parentNodes = (int*)malloc(nrOfVerteces*sizeof(int));
    int i;
    for (i=0; i<nrOfVerteces; i++)
    {
        distances[i] = MAX;
        parentNodes[i] = -1;
    }
    distances[initNode] = 0;
    int r, p;
    for(i=0; i<nrOfVerteces-1; i++)
    {
        for(r=0; r<nrOfVerteces; r++)
        {
            for(p=0; p<nrOfVerteces; p++)
            {
                if(adjMatrix[r][p]>0 && r!=p && distances[r]+adjMatrix[r][p]<distances[p])
                {
                    distances[p] = distances[r]+adjMatrix[r][p];
                    parentNodes[p] = r;
                }
            }
        }
    }
    int negFlag = 0;
    for(r=0; r<nrOfVerteces; r++)
    {
        for(p=0; p<nrOfVerteces; p++)
        {
            if (r!=p && adjMatrix[r][p]>0 && distances[r]+adjMatrix[r][p]<distances[p])
            {
                negFlag = 1;
            }
        }
    }
    if (!negFlag)
    {
        printf("Paths:\n");
        for (i=0; i<nrOfVerteces; i++)
        {
            printUTIL(initNode, parentNodes, i);
            printf("\n");
        }
    }
    else
    {
        printf("Graph contains a negative-weight cycle\n");
    }
    printf("\nBellman-Ford ended\n");
}
