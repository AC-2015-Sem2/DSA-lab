#include "graph.h"
#include "graphRepresentation.h"

//! Prim related stuff
edgeT getMinimumEdgeForCurrentlyVisitedNodes(int * visited)
{
    int i,j;
    edgeT minEdge;
    minEdge.weight=MAX;

    for (i=0; i<nrOfVerteces; i++)
        for (j=0; j<nrOfVerteces; j++)
            if(visited[i] == VISITED && visited[j] != VISITED && adjMatrix[i][j] > 0)
                if(adjMatrix[i][j]<minEdge.weight)
                {
                    minEdge.source = i;
                    minEdge.destination = j;
                    minEdge.weight = adjMatrix[i][j];
                }
    return minEdge;
}

void printEdges(edgeT* edges, int n)
{
    int i;
    for(i=0; i<n; i++)
        printf("%c -> %c\t",edges[i].source+65, edges[i].destination+65);
    printf("\n");
}

void prim(int startNode)
{
    printf("Prim's Algorithm started\n");

    int nrVertecesVisited=0,i;
    int * visited = (int*)malloc(nrOfVerteces * sizeof(int));
    for(i=0; i<nrOfVerteces; i++)
        visited[i] = UNVISITED;
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
    printf("Cost of MST by Prim's Algorithm is : %d\n",minCost);
    printf("Prim's algorithm ended\n\n\n\n\n\n");
}

//! Kruskal related stuff
edgeT getMinimumEdgeForAdjacencyMatrix(int ** adjMat)
{
    int i,j;
    edgeT minEdge;
    minEdge.weight=MAX;
    for (i=0; i<nrOfVerteces; i++)
        for (j=0; j<nrOfVerteces; j++)
            if(adjMat[i][j] > 0)
                if(adjMat[i][j]<minEdge.weight)
                {
                    minEdge.source = i;
                    minEdge.destination = j;
                    minEdge.weight = adjMat[i][j];
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
            copyAdjMatrix[i][j] = adjMatrix[i][j];

    }
    return copyAdjMatrix;
}

int getParent(int* parent,int i)
{
    if(parent[i])
        i=parent[i];
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
    int i,j,a,b,mincost=0,u,v;
    int nrofedges=1;
    int**weight=getCopyOfAdjecencyMatrix();
    for(i=0; i<nrOfVerteces; i++)
        for(j=0; j<nrOfVerteces; j++)
            if(weight[i][j]==0)
                weight[i][j]=MAX;

    int * parent  = (int*)malloc(nrOfVerteces * sizeof(int));
    for(i=0; i<nrOfVerteces; i++)
        parent[i]=UNVISITED;
    while(nrofedges<=nrOfVerteces-1)
    {
        edgeT minEdge;
        minEdge=getMinimumEdgeForAdjacencyMatrix(weight);
        a=minEdge.source;
        b=minEdge.destination;
        u=getParent(parent,a);
        v=getParent(parent,b);
        if(uni(parent,u,v))
        {
            printf("%dth edge is:(%c->%c) with weight=%d\n",nrofedges++,a+65,b+65,minEdge.weight);
            mincost +=minEdge.weight;
        }
        weight[a][b]=weight[b][a]=MAX;

    }
    printf("Minimum cost = %d\n",mincost);
    printf("\nKRUSKAL's algorithm ended\n\n\n\n\n\n\n");
}

//! Dijsktra related stuff

int getMinDistanceVertex(int * distances, int * visited)
{
    int min=MAX, i;
    int minV;
    for(i=0; i<nrOfVerteces; i++)
        if(distances[i] < min && visited[i] == UNVISITED)
            minV = i;
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

    while(nrOfVertecesVisited < nrOfVerteces)
    {
        int u = getMinDistanceVertex(distances,visited);
        visited[u] = VISITED;

        int nrOfNeighbors = getNumberOfNeighborsOfVertex(u);
        int * neighbors = getAllNeighborsOfVertex(u);
        for(i=0; i<nrOfNeighbors; i++)
        {
            int w = neighbors[i];
            int alt = distances[u] + adjMatrix[u][w];
            if(alt<distances[w])
            {
                distances[w] = alt;
                previous[w] = u;
            }
        }
        nrOfVertecesVisited++;
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


    printf("\nDijkstra ended\n\n\n\n\n");
}

/// ////////////////////////////////////////BELLMAN-FORD////////////////////////////////////////////////
///Bellman-Ford Stuff

void printpaths(int i,int start,int parent[10])
{
    if(i==start)
        printf("%c",start+65);
    else
    {
        printpaths(parent[i],start,parent);
        printf("->%c",i+65);
    }
}
void bellman(int start)
{
    printf("Bellman's Algorithm started\n");
    int i,u,v,j;
    int * d= (int*)malloc(nrOfVerteces * sizeof(int));
    int * parent = (int*)malloc(nrOfVerteces * sizeof(int));
    int **dist=getCopyOfAdjecencyMatrix();
    for(i=0; i<nrOfVerteces; i++)
        for(j=0; j<nrOfVerteces; j++)
            if(dist[i][j]==0&& i!=j)
                dist[i][j]=MAX;
    for(i=0; i<nrOfVerteces; i++)
    {
        if(i==start)
            d[i]=0;
        else d[i]=MAX;
        parent[i]=0;
    }
    for (i = 0; i < nrOfVerteces; ++i)
        for (u = 0; u < nrOfVerteces; ++u)
            for(v=0; v<nrOfVerteces; v++)
                if(adjMatrix[u][v]>0&& u!=v)
                    if(d[u]+adjMatrix[u][v]<d[v])
                    {
                        d[v]=d[u]+adjMatrix[u][v];
                        parent[v]=u;
                    }
    for(i=0; i<nrOfVerteces; i++)
    {
        printpaths(i,start,parent);
        printf("     distance is : %d\n", d[i]);
    }
    printf("Bellman's Algorithm ended\n");
}
