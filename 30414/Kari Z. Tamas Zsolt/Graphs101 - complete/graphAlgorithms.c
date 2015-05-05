#include "graph.h"
#include "graphRepresentation.h"
#include <limits.h>

//! Prim related stuff
edgeT getMinimumEdgeForCurrentlyVisitedNodes(int * visited)
{
    int i,j;
    edgeT minEdge;
    minEdge.weight=MAX;
    for (i=0; i<nrOfVerteces; i++)    {
        for (j=0; j<nrOfVerteces; j++)
        {
            if(visited[i]==VISITED && visited[j]!=VISITED && adjMatrix[i][j]>0)
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

void prim(int startNode)
{
    printf("Prim started\n");
    int nrVertecesVisited=0,i, mincost=0;
    int * visited = (int*)malloc(nrOfVerteces * sizeof(int));
    for(i=0; i<nrOfVerteces; i++)
        visited[i] = UNVISITED;

    edgeT * edges = (edgeT*) malloc((nrOfVerteces-1)*sizeof(edgeT));
    visited[startNode]=VISITED;
    while(nrVertecesVisited<nrOfVerteces-1)
    {
        edgeT minEdge=getMinimumEdgeForCurrentlyVisitedNodes(visited);
        visited[minEdge.destination]=VISITED;
        edges[nrVertecesVisited++]=minEdge;
        mincost+=minEdge.weight;
    }
    printEdges(edges, nrVertecesVisited);
    printf("MST %d\n",mincost);
    printf("Prim ended\n\n");
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
    while(parent[i]!=0) i=parent[i];
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

void kruskal()
{
    printf("\n Kruskal's Algorithm started\n \n");
    int i,j,minCost=0,numOfEdges=1;
    int **weight=getCopyOfAdjecencyMatrix();
    int *parent=(int*)malloc(nrOfVerteces*sizeof(int));
    for(i=0; i<nrOfVerteces; i++)
        {
         parent[i]=UNVISITED;
        }
    for(i=0; i<nrOfVerteces; i++)
        for(j=0; j<nrOfVerteces; j++)
            {
            if(weight[i][j]==0) weight[i][j]=MAX;
            }
    while(numOfEdges<nrOfVerteces)
        {
        edgeT minEdge;
        minEdge=getMinimumEdgeForAdjacencyMatrix(weight);
        if(uni(parent,getParent(parent,minEdge.source),getParent(parent,minEdge.destination))!=0)
            {
            printf("Edge %d added from %c to %c with weight %d\n",numOfEdges++,minEdge.source+65,minEdge.destination+65,minEdge.weight);
            minCost=minCost+minEdge.weight;
            }
        weight[minEdge.source][minEdge.destination]=weight[minEdge.destination][minEdge.source]=MAX;
        }
    printf("Minimum cost = %d\n",minCost);
    printf("\nKruskal's algorithm ended\n\n");
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

///bellman Ford related stuff

int getNumberOfEdges()
{
    int i,j,k=0;
    for (i=0;i<nrOfVerteces;i++)
        for (j=0;j<nrOfVerteces;j++)
            if (adjMatrix[i][j]!=0)
            k++;
    return k;
}

edgeT* getAllEdges()
{
   int nr=getNumberOfEdges();
   edgeT* edges=(edgeT*)malloc(nr*sizeof(edgeT));
   int i,j,k=0;
   for (i=0;i<nrOfVerteces;i++)
    for(j=0;j<nrOfVerteces;j++)
    if (adjMatrix[i][j]!=0)
   {
       edges[k].source=i;
       edges[k].destination=j;
       edges[k].weight=adjMatrix[i][j];
       k++;
   }
   return edges;

}
int bellman(int startNode)
{
    printf("\nBellman Ford Algorithm started\n");
    int i;
    int * distances = (int*)malloc(nrOfVerteces * sizeof(int));
    int * previous  = (int*)malloc(nrOfVerteces * sizeof(int));
    for(i=0; i<nrOfVerteces; i++)
    {
        distances[i] = MAX;
        previous[i]=UNDEFINED;
    }
    distances[startNode]=0;
    edgeT* edges=getAllEdges();
    int nrOfEdges=getNumberOfEdges();
    for(i=1;i<nrOfVerteces;i++)
    {
        int j;
        for(j=0;j<nrOfEdges;j++)
        {
            int u=edges[j].source;
            int v=edges[j].destination;
            ///relax the edge
            if (distances[v]>distances[u]+edges[j].weight)
            {
                distances[v]=distances[u]+edges[j].weight;
                previous[v]=u;
            }
        }
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
    for(i=0;i<nrOfEdges;i++)
        {
            int u=edges[i].source;
            int v=edges[i].destination;
            ///relax the edge
            if (distances[v]>distances[u]+edges[i].weight)
            {
                printf("Bellman Ford Algorithm ended\n");
                return 0;
            }
        }
    printf("Bellman Ford Algorithm ended\n");
}


