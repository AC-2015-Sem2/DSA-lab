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

void prim(int startNode)
{
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
    printf("%d", minCost);
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
    if(parent[i]) i=parent[i];
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
    printf("\n\nKRUSKAL's Algorithm started\n\n");
    int i,j,a,b,minc=0,u,v;
    int nrofedges=1;
    int**weight= getCopyOfAdjecencyMatrix();
    for(i=0; i<nrOfVerteces; i++)
        for(j=0; j<nrOfVerteces; j++)
            if(weight[i][j]==0) weight[i][j]=999;
    int * parent  = (int*)malloc(nrOfVerteces * sizeof(int));
    for(i=0; i<nrOfVerteces; i++)
        parent[i]=UNVISITED;
    while(nrofedges<=nrOfVerteces-1)
    {
        edgeT minEdge;
        minEdge=getMinimumEdgeForAdjacencyMatrix(weight);
        a=u=minEdge.source;
        b=v=minEdge.destination;
        u=getParent(parent,u);
        v=getParent(parent,v);
        if(uni(parent,u,v))
        {
            printf("%dth edge added is:(%c->%c) with weight=%d\n",nrofedges++,a+65,b+65,minEdge.weight);
            minc +=minEdge.weight;
        }
        weight[a][b]=weight[b][a]=999;

    }
    printf("cost min.: %d\n",minc);
    printf("\nKRUSKAL's algorithm ended\n\n");
}

//! Dijsktra related stuff

int getMinDistanceVertex(int * distances, int * visited)
{
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
    int * dist = (int*)malloc(nrOfVerteces * sizeof(int));
    int * prev  = (int*)malloc(nrOfVerteces * sizeof(int));
    int * visited   = (int*)malloc(nrOfVerteces * sizeof(int));
    int nrOfVertecesVisited=0,i;
    for(i=0; i<nrOfVerteces; i++)
        {
            dist[i] = MAX;
            prev[i]  = UNDEFINED;
            visited[i] = UNVISITED;
        }
    dist[startNode] = 0;

    while(nrOfVertecesVisited < nrOfVerteces)
        {
            int u = getMinDistanceVertex(dist,visited);
            visited[u] = VISITED;
            int nrOfNeighbors = getNumberOfNeighborsOfVertex(u);
            int * neighbors = getAllNeighborsOfVertex(u);
            for(i=0; i<nrOfNeighbors; i++)
        {
            int w = neighbors[i];
            int alt = dist[u] + adjMatrix[u][w];
            if(alt<dist[w])
                {
                    dist[w] = alt;
                    prev[w] = u;
                }
        }
            nrOfVertecesVisited++;
        }
    for(i=0; i<nrOfVerteces; i++)
    {
        int u=i;
        if(i!=startNode)
        {
            while(prev[u] != UNDEFINED)
                {
                    push(u);
                    u=prev[u];
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



void BFord(int startingNode)
{
    printf("\nBFord's algorithm starts here: \n");
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
                    printf("\n graph contains a negative weight cycle\n");
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

    printf("\nCost-BFord's algorithm: %d\n", minCost);
    printf("BFord's ended\n\n");
}
