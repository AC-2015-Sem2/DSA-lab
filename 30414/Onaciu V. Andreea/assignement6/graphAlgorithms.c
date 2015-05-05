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
  return parent[i];// I know this function doesn't really do something,but that the only way I know how to use it.
}

int uni(int * parent, int i,int j)
{
    int t;
if (i!=j){
     if (i<j){
        for (t=0;t<nrOfVerteces;t++)
        if (parent[t]==j) parent[t]=i;
        }
    else {
         for (t=0;t<nrOfVerteces;t++)
          if (parent[t]==i) parent[t]=j;
          }
    return 1;}
    return 0;
}

void kruskal()
{
int nrOfEdges=0,i,a,b;
int minCost=0;
int **cpyAdjMatrix;
cpyAdjMatrix=getCopyOfAdjecencyMatrix();
edgeT minEdge;
int *parent=(int *)malloc(nrOfVerteces*sizeof(int));
for (i=0;i<nrOfVerteces;i++)
    parent[i]=i;
printf("Kruskal's algorithm started\n");
    while (nrOfEdges<nrOfVerteces-1)
    {
     minEdge=getMinimumEdgeForAdjacencyMatrix(cpyAdjMatrix);
     int source=minEdge.source;
     int destination=minEdge.destination;
     cpyAdjMatrix[source][destination]=0;
     cpyAdjMatrix[destination][source]=0;
     a=getParent(parent,source);
     b=getParent(parent,destination);
     if (uni(parent,a,b))
     {
         printf("%c->%c ",source+65,destination+65);
         nrOfEdges++;
         minCost+=minEdge.weight;
     }
    }
    printf("\nCost of MST by Kruskal's Algorithm: %d\n",minCost);
    printf("Kruskal's algorithm ended\n\n");
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
//! BellmanFord related stuff
int getNumberOfEdges(int** adjMatrix)
{
    int i,j,nr=0;
    for (i=0;i<nrOfVerteces;i++)
        for (j=0;j<nrOfVerteces;j++)
        if (adjMatrix[i][j]!=0) nr++;
        return nr;
}
edgeT *getAllEdges(int** adjMatrix)
{
    int i,j,k=0;
    edgeT* AllEdges=(edgeT*)malloc(getNumberOfEdges(adjMatrix)*sizeof(edgeT));
    for(i=0;i<nrOfVerteces;i++)
        for (j=0;j<nrOfVerteces;j++)
        if (adjMatrix[i][j]!=0)
    {
        AllEdges[k].source=i;
        AllEdges[k].destination=j;
        AllEdges[k].weight=adjMatrix[i][j];
        k++;
    }
    return AllEdges;
}

void BellmanFord(int startNode)
{
    printf("Bellman-Ford's Algorithm started\n");
   int i,k,u,v;
   int weight;
   int* distance=(int*)malloc(nrOfVerteces*sizeof(int));
   int* predecessor=(int*) malloc(nrOfVerteces*sizeof(int));
   int nrOfEdges=getNumberOfEdges(adjMatrix);
   edgeT* allEdges=(edgeT*)malloc(nrOfEdges*sizeof(edgeT));
   allEdges=getAllEdges(adjMatrix);
   for (i=0;i<nrOfVerteces;i++)
   {
   distance[i]=MAX;
   predecessor[i]=0;
   }
   distance[startNode]=0;
   for ( k = 1; k <= nrOfVerteces-1; k++)
    {
        for (i=0;i<nrOfEdges;i++)
        {

             u = allEdges[i].source;
             v = allEdges[i].destination;
             weight= allEdges[i].weight;
            if (distance[u] != MAX && distance[u] + weight < distance[v])
                distance[v] = distance[u] + weight;
                predecessor[v]=u;
        }
    }


    for (i=0;i<nrOfEdges;i++)
    {
             u = allEdges[i].source;
             v = allEdges[i].destination;
         weight = allEdges[i].weight;
        if (distance[u] != MAX && distance[u] + weight < distance[v])
            printf("Graph contains negative weight cycle");

    }
   printf("The distance from %c to:\n",startNode+65);
    for (i=0;i<nrOfVerteces;i++)
        printf("  %c is %d \n",i+65,distance[i]);
    printf("Bellman-Ford's algorithm ended.\n");


}
