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
    printf("\nKruskal's Algorithm started\n\n");
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

//! Bellman Ford related stuff
void printPath(int i,int start,int parent[])
{
    if(i==start) printf("%c",start+65);
    else
        {
        printPath(parent[i],start,parent);
        printf(" -> %c",i+65);
        }
}

void printWeight(int *d,int *parent,int start,int **weight)
{
    int i;
    for(i=0; i<nrOfVerteces; i++)
        {
        printf("The weight from %c to %c was %d now is %d\n",start+65,i+65,weight[start][i],d[i]);
        printPath(i,start,parent);
        printf("\n");
        }
}

void bellmanFord(int start)
{
    printf("\nBellman-Ford's Algorithm started\n\n");
    int i,j,a,b;
    int *check=(int*)malloc(nrOfVerteces*sizeof(int));
    int *parent=(int*)malloc(nrOfVerteces*sizeof(int));
    int **weight=getCopyOfAdjecencyMatrix();
     for(i=0; i<nrOfVerteces; i++)
        for(j=0; j<nrOfVerteces; j++)
            {
            if(weight[i][j]==0 && i!=j) weight[i][j]=MAX;
            }
    for(i=0; i<nrOfVerteces; i++)
        {
        parent[i]=0;
        if(i==start) check[i]=0;
        else check[i]=MAX;
        }
    for (i=0; i<nrOfVerteces; i++)
    {
        for (a=0; a<nrOfVerteces; a++)
            for(b=0; b<nrOfVerteces; b++)
            {
                if(adjMatrix[a][b]>0 && check[a]+adjMatrix[a][b]<check[b])
                {
                        check[b]=check[a]+adjMatrix[a][b];
                        parent[b]=a;
                }
            }
    }
    printWeight(check,parent,start,weight);
    printf("\nBellman-Ford's Algorithm ended\n");
}
