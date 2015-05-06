#include "graph.h"
#include "graphRepresentation.h"

//! Prim related stuff
edgeT getMinimumEdgeForCurrentlyVisitedNodes(int * visited)
{
int i,j;
edgeT minEdge;
minEdge.weight=MAX;
for (i=0;i<nrOfVerteces;i++)
{
    for (j=0;j<nrOfVerteces;j++)
    {
        if (visited[i]==VISITED && visited[j]!=VISITED && adjMatrix[i][j]>0)
        {
            if (adjMatrix[i][j]<minEdge.weight)
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
    printf("Prim's Algorithm started\n");
    int i,nrOfVV=0;
    int*visited=(int*) malloc (nrOfVerteces*sizeof(int));
    for (i=0;i<nrOfVerteces;i++)
    {
        visited[i]=UNVISITED;
    }
    int minCost=0;
    edgeT*edges=(edgeT*) malloc ((nrOfVerteces-1)*sizeof(edgeT));
    visited[startNode]=VISITED;
    while(nrOfVV<nrOfVerteces-1)
          {
          edgeT minEdge=getMinimumEdgeForCurrentlyVisitedNodes(visited);
          visited[minEdge.destination]=VISITED;
          edges[nrOfVV++]=minEdge;
          minCost+=minEdge.weight;
          }
          printEdges(edges,nrOfVV);
          printf("%d",minCost);

    printf("Prim's algorithm ended\n\n");
}

//! Kruskal related stuff
edgeT getMinimumEdgeForAdjacencyMatrix(int ** adjMat)
{
 int i,j;
 edgeT minEdge;
 minEdge.weight=MAX;
 for (i=0;i<nrOfVerteces;i++)
 {
     for (j=0;j<nrOfVerteces;j++)
     {
         if (adjMat[i][j]>0)
         {
             if (adjMat[i][j]<minEdge.weight)
             {
                 minEdge.source=i;
                 minEdge.destination=j;
                 minEdge.weight=adjMat[i][j];
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
 printf("Kruskal Algorithm started\n");
 edgeT*edges=(edgeT*) malloc ((nrOfVerteces-1)* sizeof(int));
 int **matrix=getCopyOfAdjecencyMatrix();
 int*parent=(int*) malloc (nrOfVerteces*sizeof(int));
 int i,maxim,minim,nrOfEdges=0;
 edgeT minEdge;
 for (i=0;i<nrOfVerteces;i++)
 {
     parent[i]=i;
 }
 while (nrOfEdges<nrOfVerteces-1)
 {
     minEdge=getMinimumEdgeForAdjacencyMatrix(matrix);
     matrix[minEdge.source][minEdge.destination]=-10000000;
     matrix[minEdge.destination][minEdge.source]=100000;

     if (parent[minEdge.source]!=parent[minEdge.destination])
     {
         edges[nrOfEdges]=minEdge;
         if (parent[minEdge.source]>parent[minEdge.destination])
         {
             maxim=parent[minEdge.source];
             minim=parent[minEdge.destination];
         }
              else
              {
                  minim=parent[minEdge.source];
                  maxim=parent[minEdge.destination];
              }
         }
         for (i=0;i<nrOfVerteces;i++)
         {
             if (parent[i]==minim) parent[i]=maxim;
         }
         nrOfEdges++;
 }
     printEdges(edges,nrOfEdges);
printf("Kruskal's algorithm ended\n");
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
    printf("\nDijkstra's Algorithm started\n");
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


void bellmanFord(int startNode)
{
    printf("\nBellman Ford started\n");
    int i;
    int* weight = (int*)malloc(sizeof(int) * nrOfVerteces);
    int* parent = (int*)malloc(sizeof(int) * nrOfVerteces);
    for(i = 0; i < nrOfVerteces; i++)
    {
        weight[i] = 0;
    }
    for(i = 0; i < nrOfVerteces; i++)
    {
        parent[i] = 0;
    }
    for(i = 0; i < nrOfVerteces; i++)
    {
        if(i == startNode)
        {
            weight[i] = 0;
        }
        else
        {
            weight[i] = 10000;
            parent[i] = 0;
        }
    }
    for(i = 0; i < nrOfVerteces - 1; i++)
    {
        int a;
        int b;
        for(a = 0; a < nrOfVerteces; a++)
        {
            for(b = 0; b < nrOfVerteces; b++)
            {
                if(adjMatrix[a][b] > 0)
                {
                    if(weight[a] + adjMatrix[a][b] < weight[b])
                    {
                        weight[b] = weight[a] + adjMatrix[a][b];
                        parent[b] = a;
                    }
                }
            }
        }
    }
    for(i = 0; i < nrOfVerteces; i++)
    {
        printf("%c->%c\n", parent[i]+65 , i +65);
    }
    printf("\n\nBellman Ford's ended\n");
}

