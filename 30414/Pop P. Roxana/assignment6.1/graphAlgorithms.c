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
    if (parent[i]==-1) return i;
    return getParent(parent,parent[i]);
}

int uni(int * parent, int i,int j)
{
    int parentOfi=getParent(parent,i);
    int parentOfj=getParent(parent,j);
    parent[parentOfj]=parentOfi;///the set of j is included in the set of i
    return parentOfi;///I did not know what else to return... i do not understand why its not void :?
}

void kruskal()
{
    printf("Kruskal algorithm\n");
    int* parent=(int*)malloc(nrOfVerteces*sizeof(int));
    int i;
    for (i=0;i<nrOfVerteces;i++)
        parent[i]=-1;///at first, each vertex forms a set
    edgeT * edges = (edgeT*) malloc((nrOfVerteces-1) * sizeof(edgeT));
    int nrOfEdgesInTheTree=0;
    int**graph=getCopyOfAdjecencyMatrix();///i will work on a copy as i delete the edges in the graph
    while(nrOfEdgesInTheTree<nrOfVerteces-1)
    {
        edgeT e=getMinimumEdgeForAdjacencyMatrix(graph);///take the minimum weighted edge in the graph: e
        int x=getParent(parent,e.source);
        int y=getParent(parent,e.destination);
        if (x!=y)///if e does not close a cycle
        {
            edges[nrOfEdgesInTheTree]=e;///e is added to the solution
            nrOfEdgesInTheTree++;
            ///perform the union
            int nr=uni(parent,x,y);
        }
        ///delete the edge from the graph
        graph[e.source][e.destination]=0;
        graph[e.destination][e.source]=0;///as it is an undirected graph, i don't want to take the same edge twice
    }
    printEdges(edges, nrOfEdgesInTheTree);
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

edgeT* createEdgesArray()
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
int BellmanFord(int source)
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
    distances[source]=0;
    edgeT* edges=createEdgesArray();
    int nrOfEdges=getNumberOfEdges();
    ///n-1 steps, where n is the nr of verteces
    for(i=1;i<nrOfVerteces;i++)
    {
        int j;
        ///for every edge u-v of the graph
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
    ///print paths
    for(i=0; i<nrOfVerteces; i++)
    {
        int u=i;
        if(i!=source)
            {
                while(previous[u] != UNDEFINED)
                    {
                        push(u);
                        u = previous[u];
                    }
                printf("Path from %c to %c is: %c ",source + 65, i+65, source + 65);
                while(!isEmptyStack())
                    {
                        printf("-> %c ",peekStack()->content + 65);
                        pop();
                    }
                printf("\n");
            }
    }
    ///check for negative weight cycle
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
    return 1;
}
