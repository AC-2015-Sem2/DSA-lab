#include "graph.h"
#include "graphRepresentation.h"


//! Prim related stuff
edgeT getMinimumEdgeForCurrentlyVisitedNodes(int * visited)
{
    int i, j;
    edgeT minEdge;
    minEdge.weight=MAX;
    for (i=0; i<nrOfVerteces; i++)
    {
        for(j=0; j<nrOfVerteces; j++)
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

int **getCopyOfAdjecencyMatrix()
{
    int i,j;
    int **copyAdjMatrix =(int**)malloc(nrOfVerteces*sizeof(int*));
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
    while (parent[i])
    {
        i=parent[i];
    }
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
    printf("\nKruskal starts\n");
    int nrOfEdges=0, i, p, t;
    edgeT minEdge;
    int **matrix=getCopyOfAdjecencyMatrix();
    int *parent=(int*)malloc(nrOfVerteces*sizeof(int));
    edgeT *edges=(edgeT*)malloc(sizeof(edgeT)*(nrOfVerteces-1));
    for(i=0; i<nrOfVerteces; i++)
    {
        parent[i]=i;
    }
    while(nrOfEdges<nrOfVerteces-1)
    {
        minEdge=getMinimumEdgeForAdjacencyMatrix(matrix);
        matrix[minEdge.source][minEdge.destination]=0;
        matrix[minEdge.destination][minEdge.source]=0;
        if (parent[minEdge.source]!=parent[minEdge.destination])
        {
            edges[nrOfEdges]=minEdge;
            if(parent[minEdge.source]>parent[minEdge.destination])
            {
                p=parent[minEdge.destination];
                t=parent[minEdge.source];
            }
            else
            {
                p=parent[minEdge.source];
                t=parent[minEdge.destination];
            }
            for(i=0; i<nrOfVerteces; i++)
            {
                if(parent[i]==p)
                {
                    parent[i]=t;
                }
            }
            nrOfEdges++;
        }
    }
    printEdges(edges, nrOfEdges);
    printf("Kruskal stops\n");
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
void prim(int start)
{
    printf("\nPrim Starts\n");
    int nrOfVisitedVerteces=0, i;
    int *visited=(int*)malloc(nrOfVerteces*sizeof(int));
    for(i=0; i<nrOfVerteces; i++)
    {
        visited[i]=UNVISITED;
    }
    int minCost=0;
    edgeT *edges=(edgeT*)malloc((nrOfVerteces-1)*sizeof(edgeT));
    visited[start]=VISITED;

    while(nrOfVisitedVerteces<nrOfVerteces-1)
    {
        edgeT minEdge=getMinimumEdgeForCurrentlyVisitedNodes(visited);
        visited[minEdge.destination]=VISITED;
        edges[nrOfVisitedVerteces++]=minEdge;
        minCost+=minEdge.weight;
    }
    printEdges(edges, nrOfVisitedVerteces);
    printf("Cost of MST by Prim Algorithm is %d\n", minCost);
    printf("Prim Stops\n");
}
void dijkstra(int startNode)
{
    printf("\nDijkstra starts\n");
    int *distances= (int*)malloc(nrOfVerteces*sizeof(int));
    int *previous= (int*)malloc(nrOfVerteces*sizeof(int));
    int *visited= (int*)malloc(nrOfVerteces*sizeof(int));

    int nrOfVisitedVerteces=0, i;
    for(i=0; i<nrOfVerteces; i++)
    {
            distances[i]=MAX;
            previous[i]=UNDEFINED;
            visited[i]=UNVISITED;
    }
    distances[startNode]=0;

    while(nrOfVisitedVerteces<nrOfVerteces)
    {
        int aux=getMinDistanceVertex(distances, visited);
        visited[aux]= VISITED;
        int nrOfNeighbors=getNumberOfNeighborsOfVertex(aux);
        int *neighbors= getAllNeighborsOfVertex(aux);

        for(i=0; i<nrOfNeighbors; i++)
        {
            int w=neighbors[i];
            int x=distances[aux]+adjMatrix[aux][w];
            if (x<distances[w])
            {
                distances[w]=x;
                previous[w]=aux;
            }
        }
        nrOfVisitedVerteces++;
    }
    for(i=0; i<nrOfVerteces; i++)
    {
        int u=i;
        if(i!=startNode)
        {
            while(previous[u]!=UNDEFINED)
            {
                push(u);
                u=previous[u];
            }
            printf("Path from %c to %c is: %c", startNode+65, i+65, startNode+65);
            while(!isEmptyStack())
            {
                printf("-> %c", peekStack()->content + 65);
                pop();
            }
            printf("\n");
        }
    }
    printf("Dijkstra stops\n");
}
void printPath(int i, int startNode, int parent[])
{
    if(i==startNode)
    {
        printf("%c", startNode + 65);
    }
    else
    {
        printPath(parent[i], startNode, parent);
        printf("->%c", i + 65);
    }
}
void printDistance(int *dist, int *parent, int startNode, int **distance)
{
    int i;
    printf("\nDistances updated:\n");
    for(i=0; i<nrOfVerteces; i++)
    {
        printf("The initial distance from (%c->%c) was %d and now is %d\n", startNode+65, i+65, distance[startNode][i], dist[i]);
    }
    printf("The paths from start to the other verteces:\n");
    for(i=0; i<nrOfVerteces; i++)
    {
        printPath(i, startNode,parent);
        printf("\n");
    }
}
void BellmanFord(int startNode)
{
    printf("Bellman Ford starts\n");
    int i, j, p, t;
    int **distance=getCopyOfAdjecencyMatrix();
    int *parent=(int*)malloc(nrOfVerteces*sizeof(int));
    int *dist=(int*)malloc(nrOfVerteces*sizeof(int));
    for(i=0; i<nrOfVerteces; i++)
    {
        for(j=0; j<nrOfVerteces; j++)
        {
            if(distance[i][j]==0 && i!=j)
            {
                distance[i][j]=MAX;
            }

        }
    }
    for(i=0; i<nrOfVerteces; i++)
    {
        if(i==startNode)
        {
            dist[i]=0;
        }
        else
        {
            dist[i]=MAX;
        }
        parent[i]=0;
    }
    for(i=0; i<nrOfVerteces; i++)
    {
        for(p=0; p<nrOfVerteces; p++)
        {
            for(t=0; t<nrOfVerteces; t++)
            {
                if(adjMatrix[p][t]>0 && p!=t)
                {
                    if(dist[p]+adjMatrix[p][t]<dist[t])
                    {
                        dist[t]=dist[p]+adjMatrix[p][t];
                        parent[t]=p;
                    }
                }
            }
        }
    }
    printDistance(dist, parent, startNode, distance);
    printf("Bellman Ford ends\n");
}
