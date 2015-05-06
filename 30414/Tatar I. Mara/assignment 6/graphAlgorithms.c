#include "graph.h"
#include "graphRepresentation.h"
#include <limits.h>

//! Prim related stuff
edgeT getMinimumEdgeForCurrentlyVisitedNodes(int * visited)
{
    edgeT e;
    int i,j;
int minimum= INT_MAX;
for(i=0;i<nrOfVerteces;i++)
{
    if (visited[i]==VISITED)
    {
        for (j=0;j<nrOfVerteces;j++)
        {
            if (adjMatrix[i][j]!=0 && visited[j]==UNVISITED)
              if (adjMatrix[i][j]<minimum)
              {
                  minimum=adjMatrix[i][j];
                  e.weight=adjMatrix[i][j];
                  e.source=i;
                  e.destination=j;
              }
        }
    }
}
return e;
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
    ///pornesti dintr-un nod
    ///pana cand nu ai vizitat toate nodurile
        ///cauti muchia minima de la un nod vizitat la unul nevizitat
        int w,i;
        int* visited=(int*)malloc(sizeof(int)*nrOfVerteces);
        w=0;
        for (i=0;i<nrOfVerteces;i++)
        {
            visited[i]=UNVISITED;
        }

         edgeT* edges=(edgeT*)malloc(sizeof(edgeT)*(nrOfVerteces-1));
         visited[startNode]=VISITED;

         for (i=0;i<nrOfVerteces-1;i++)
         {   edgeT e;
            e=getMinimumEdgeForCurrentlyVisitedNodes(visited);
            w=w+e.weight;
            visited[e.destination]=VISITED;
            edges[i]=e;


         }
    printEdges(edges,nrOfVerteces-1);
    printf("\nMinimum weight=%d",w);
    printf("\nPrim ended\n\n");
}

//! Kruskal related stuff
edgeT getMinimumEdgeForAdjacencyMatrix(int ** adjMat)
{  edgeT e;
int i,j,minimum;
    minimum=INT_MAX;
    for (i=0;i<nrOfVerteces-1;i++)
        for (j=i+1;j<nrOfVerteces;j++)
            if (adjMat[i][j]<minimum && adjMat[i][j] != 0)
            {
                     minimum=adjMat[i][j];
                     e.source=i;
                     e.destination=j;
                     e.weight=minimum;
            }
            return e;
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
    if (parent[i]==i)
        return i;
    parent[i]=getParent(parent,parent[i]);
        return parent[i];
    }
/*
int uni(int * parent, int i,int j)
{

}
*/
void kruskal()
{
    printf("Kruskal started\n");
    int i;
    int *parents=(int*)malloc(sizeof(int)*nrOfVerteces);
    for (i=0;i<nrOfVerteces;i++)
        parents[i]=i;
    edgeT*  edges=(edgeT*)malloc(sizeof(edgeT)*(nrOfVerteces-1));
    int ** copy;
    copy=getCopyOfAdjecencyMatrix(adjMatrix);
    for (i=0;i<nrOfVerteces-1;)
    {
        edgeT e;
        e=getMinimumEdgeForAdjacencyMatrix(copy);
        //printf("%d\n", i);
        copy[e.source][e.destination]=0;
        copy[e.destination][e.source]=0;
        if (getParent(parents, e.source)!=getParent(parents, e.destination))
        {
            edges[i]=e;
            parents[e.source] = getParent(parents, e.destination);
            i++;
        }

    }
   printEdges(edges,nrOfVerteces-1);
    printf("\nKruskal ended\n\n");
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
        {        distances[i] = MAX;
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

 /*   printf("\nDijkstra ended\n\n");
}*/
void bellmanFord(int startNode)
{
    printf("\nBellman Ford:");

    int i;
 int *dist = (int*)malloc(sizeof(int)*(nrOfVerteces));
    int *prev = (int*)malloc(sizeof(int)*(nrOfVerteces));

   for(i=0; i<nrOfVerteces; i++)
        {
                   dist[i] = MAX;
                    prev[i]=i;
        }
    dist[startNode] = 0;




    int a, b;

    for(i=0; i < nrOfVerteces-1; i++)

        for(a=0; a<nrOfVerteces; a++)

            for(b=0; b<nrOfVerteces; b++)

                if(a != b && adjMatrix[a][b] != 0)
                    if(dist[a] + adjMatrix[a][b] < dist[b])
                    {
                        prev[b] = a;
                        dist[b] = dist[a] + adjMatrix[a][b];

                    }

    printPaths(prev, dist,startNode);
}


