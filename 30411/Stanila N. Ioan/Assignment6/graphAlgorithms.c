#include "graph.h"
#include "graphRepresentation.h"

//! Prim related stuff
/*
int vis[v] -> UNVISITED
vis[startNode] = VISITED;
edgeT * edges = malloc((v-1)*sizeof(edgeT));
while (nrOfSteps < v - 1) {
   edgeT e = getMinEdge(vis);
   vis[e.destination] =  VISITED;
   edges[nrOfSteps] = e;
   nrOfSteps++;
}
*/
edgeT getMinimumEdgeForCurrentlyVisitedNodes(int * visited)
{
    edgeT minE;
    minE.weight = MAX;
    for (int i = 0; i < nrOfVerteces; i++)
        for (int j = 0; j < nrOfVerteces; j++)
            if (visited[i] == VISITED && visited[j] == UNVISITED && adjMatrix[i][j] < minE.weight && adjMatrix[i][j]) {
                minE.source = i;
                minE.destination = j;
                minE.weight = adjMatrix[i][j];
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
    int vis[nrOfVerteces];
    for (int i = 0; i < nrOfVerteces; i++)
        vis[i] = UNVISITED;
    vis[startNode] = VISITED;
    edgeT* edges = (edgeT*)malloc((nrOfVerteces-1)*sizeof(edgeT));
    for (int i = 0; i < nrOfVerteces - 1; i++) {
        edgeT e = getMinimumEdgeForCurrentlyVisitedNodes(vis);
        vis[e.destination] =  VISITED;
        edges[i] = e;
    }
    printEdges(edges, nrOfVerteces - 1);
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

}

int uni(int * parent, int i,int j)
{

}

void kruskal()
{

}

//! Dijsktra related stuff
int getMinDistanceVertex(int * distances, int * visited)
{
    int minDist = MAX;
    int u;
    for (int i = 0; i < nrOfVerteces; i++)
        if (distances[i] < minDist && !visited[i]) {
            u = i;
            minDist = distances[i];
        }
    return u;
}

void dijkstra(int startNode)
{
    int vis[nrOfVerteces];
    int distances[nrOfVerteces];
    int parent[nrOfVerteces];
    for (int i = 0; i < nrOfVerteces; i++) {
        vis[i] = UNVISITED;
        distances[i] = MAX;
        parent[i] = UNDEFINED;
    }
    vis[startNode] = VISITED;
    for (int i = 0; i < nrOfVerteces; i++) {
        int u = getMinDistanceVertex(distances, vis);
        vis[u] = VISITED;
        int* neighbors = getAllNeighborsOfVertex(u);
        int n = getNumberOfNeighborsOfVertex(u);
        for (int j = 0; j < n; j++) {
            if (distances[neighbors[i]] > distances[u] + adjMatrix[u][neighbors[i]]) {
                distances[neighbors[i]] = distances[u] + adjMatrix[u][neighbors[i]];
                parent[neighbors[i]] = u;
            }
        }
    }
    for (int i = 0; i < nrOfVerteces; i++)
        printf("%d ", parent[i]);
    for (int i = 0; i < nrOfVerteces; i++) {
        int u = i;
        if (i != startNode)
            while (parent[u] != UNDEFINED) {
                push(u);
                u = parent[u];
            }
        printf("Path from %c to %c is %c", startNode+65, i+65, startNode+65);
        while (!isEmptyStack()) {
            printf("->%c", peekStack()->content+65);
            pop();
        }
        printf("\n");
    }
}
