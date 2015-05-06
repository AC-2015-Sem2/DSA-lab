#include "graph.h"
#include "graphRepresentation.h"
///////////////Prim/////////////////////////////////////////////
//! Prim related stuff
edgeT getMinimumEdgeForCurrentlyVisitedNodes(int * visited)
{
    int i,j;
    edgeT minE;
    minE.weight=MAX;
    for (i=0; i<nrOfVerteces; i++)
        for (j=0; j<nrOfVerteces; j++)
            if (adjMatrix[i][j]<minE.weight && visited[i]==1 && visited[j]==0 && adjMatrix[i][j]>0 && i!=j)
            {
                minE.source=i;
                minE.destination=j;
                minE.weight=adjMatrix[i][j];
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
    printf("Prim started\n");
    int *mst=(int*)malloc(nrOfVerteces*sizeof(int));
    int nrOfCoveredEdeges=0;
    int i;
    int weights=0;
    for (i=0; i<nrOfVerteces; i++)
        mst[i]=0;
    mst[startNode]=1;
    edgeT *edges=(edgeT*)malloc (sizeof(edgeT)*(nrOfVerteces-1));
    while (nrOfCoveredEdeges<nrOfVerteces-1)
    {
        edgeT e=getMinimumEdgeForCurrentlyVisitedNodes(mst);
        mst[e.destination]=1;
        edges[nrOfCoveredEdeges]=e;
        weights+=e.weight;
        nrOfCoveredEdeges++;
    }
    printEdges(edges,nrOfVerteces-1);
    printf("minimum cost is:%d",weights);
    printf("\nPrim ended\n\n");
}
////////////////////////////Kruskal//////////////////////////////////////////////
//! Kruskal related stuff
edgeT getMinimumEdgeForAdjacencyMatrix(int ** adjMat)
{
    int i,j,minDistance=MAX;
    edgeT minE;
    for (i=0; i<nrOfVerteces; i++)
        for (j=0; j<nrOfVerteces; j++)
            if (minDistance>adjMat[i][j] && adjMat[i][j]>0)
            {
                minDistance=adjMat[i][j];
                minE.source=i;
                minE.destination=j;
                minE.weight=minDistance;
            }
    return minE;
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
    if (parent[i]!=UNDEFINED)
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
    printf("Kruskal started\n");
    int i,j;
    edgeT *mst=(edgeT*)malloc(sizeof(edgeT)*nrOfVerteces);
    int **ad=getCopyOfAdjecencyMatrix();
    for(i=0; i<nrOfVerteces; i++)
        for(j=0; j<nrOfVerteces; j++)
            if(ad[i][j]==0)
                ad[i][j]=MAX;

    int EdgesVisited=0;
    int weights=0;

    int a,b,u,v;

    int *parent=(int*)malloc(sizeof(int)*nrOfVerteces);
    for(i=0; i<nrOfVerteces; i++)
        parent[i]=UNDEFINED;
    while (EdgesVisited<nrOfVerteces-1)
    {
        edgeT minE=getMinimumEdgeForAdjacencyMatrix(ad);
        a=minE.source;
        b=minE.destination;
        u=getParent(parent,a);
        v=getParent(parent,b);
        if (uni(parent,u,v))
        {
            mst[EdgesVisited]=minE;
            weights+=minE.weight;
            EdgesVisited++;
        }
        ad[a][b]=ad[b][a]=MAX;
    }
    printEdges(mst,EdgesVisited);
    printf("the min cost is:%d",weights);
    printf("\nKruskal ended\n\n");
}
//////////////////////////////////////Dijsktra//////////////////////////////////////////////////
//! Dijsktra related stuff

int getMinDistanceVertex(int * distances, int * visited)
{
    int i,minDistance=MAX+1,minVertex=0;
    for(i=0; i<nrOfVerteces; i++)
    {
        if (distances[i]<minDistance && visited[i]==UNVISITED)
        {
            minVertex=i;
            minDistance=distances[i];
        }
    }
    return minVertex;
}

void dijkstra(int startNode)
{
    printf("Dijkstra started\n");
    int *distances=(int*)malloc(sizeof(int)*nrOfVerteces);
    int i;
    for(i=0; i<nrOfVerteces; i++)
        distances[i]=MAX;
    int *parent=(int*)malloc(sizeof(int)*nrOfVerteces);
    for(i=0; i<nrOfVerteces; i++)
        parent[i]=UNDEFINED;
    int *visited=(int*)malloc(sizeof(int)*nrOfVerteces);
    for(i=0; i<nrOfVerteces; i++)
        visited[i]=UNVISITED;
    int nrVisited=0;
    distances[startNode]=0;
    while (nrVisited < nrOfVerteces)
    {
        int u=getMinDistanceVertex(distances,visited);
        visited[u]=VISITED;
        int nr=getNumberOfNeighborsOfVertex(u);
        int *neighbours=getAllNeighborsOfVertex(u);
        for (i=0; i<nr; i++)
        {
            int w=neighbours[i];
            int alt=distances[u]+adjMatrix[u][w];
            if (alt<distances[w])
            {
                distances[w]=alt;
                parent[w]=u;
            }
        }
        nrVisited++;
    }
    // UNCOMMENT FOR PRINTING DIJKSTRA PATHS
    for(i=0; i<nrOfVerteces; i++)
    {
        int u=i;
        if(i!=startNode)
        {
            while(parent[u] != UNDEFINED)
            {
                push(u);
                u = parent[u];
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
    //

    printf("\nDijkstra ended\n\n");
}
//////////////////////////Bellman-Ford///////////////////////

void Ford(int startNode)
{
    printf("Bellman-Ford started:\n");
    int *distances=(int*)malloc(sizeof(int)*nrOfVerteces);
    int *parent=(int*)malloc(sizeof(int)*nrOfVerteces);
    int i,j;
    for (i=0; i<nrOfVerteces; i++)
    {
        distances[i]=MAX;
        parent[i]=UNDEFINED;
    }
    parent[startNode]=startNode;
    distances[startNode]=0;
        int intineration=0;
    while (intineration<nrOfVerteces)
    {
        for(i=0;i<nrOfVerteces;i++)
        {
            int nrNeighbours=getNumberOfNeighborsOfVertex(i);
            int *neighbours=getAllNeighborsOfVertex(i);
            for ( j=0;j<nrNeighbours;j++)
            {
               int w=neighbours[j];
               if (distances[w]>adjMatrix[i][w]+distances[i] && adjMatrix[i][w]>0&& i!=w)
               {
                   distances[w]=adjMatrix[i][w]+distances[i];
                   parent[w]=i;
               }
            }
        }
        intineration++;
    }
        for(i=0; i<nrOfVerteces; i++)
    {
        int u=i;
        if(i!=startNode)
        {
            while(parent[u] != 0)
            {
                push(u);
                u = parent[u];
            }
                push(u);
                u = parent[u];
            printf("Path from %c to %c is: %c ",startNode + 65, i+65, startNode + 65);
            while(!isEmptyStack())
            {
                printf("-> %c ",peekStack()->content + 65);
                pop();
            }
            printf("\n");
        }
    }
       for (i=0;i<nrOfVerteces;i++)
        if (distances[i]<0)
          {printf("we have a negative weight");
          break;}
        printf("Bellman-Ford ended:\n");
    }
