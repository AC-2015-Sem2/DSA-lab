#include "graph.h"
#include "graphRepresentation.h"
#include "graphTraversals.h"
//FILE *f;
//! Prim related stuff
edgeT getMinimumEdgeForCurrentlyVisitedNodes(int * visited)
{
    int i,j;
    edgeT minE;
    minE.weight = MAX;
    for (i=0; i<nrOfVerteces; i++)
        for (j=0; j<nrOfVerteces; j++)
        {
            if (i != j)
            {
                if (visited[i] ==VISITED && visited[j] ==UNVISITED && adjMatrix[i][j]<minE.weight && adjMatrix[i][j]>0)
                {
                    minE.source = i;
                    minE.destination=j;
                    minE.weight = adjMatrix[i][j];
                }
            }
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
    int *mst;
    int nrofCoveredEdges, weight;
    edgeT *edges;

    mst = (int *)calloc(nrOfVerteces,sizeof(int));
    edges = (edgeT *)calloc((nrOfVerteces - 1), sizeof(edgeT));
    mst[startNode] = 1;
    nrofCoveredEdges = 0;
    weight = 0;

    while (nrofCoveredEdges < nrOfVerteces-1)
    {
        edgeT e = getMinimumEdgeForCurrentlyVisitedNodes(mst);
        mst [e.destination] = 1;
        edges[nrofCoveredEdges]=e;
        weight+=e.weight;
        nrofCoveredEdges++;
    }
    printEdges(edges, nrofCoveredEdges);
    printf("%d ", weight);
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

int checkTree(int start, int toFind, int* visited, edgeT* edges, int n)
{
    if(start==toFind)
    {
        return 1;
    }
    int i, a=0;
    visited[start]=1;
    for(i=0; i<n; i++)
    {
        if(edges[i].destination==start)
            if(visited[edges[i].source]==0)
            {
                a+=checkTree(edges[i].source, toFind, visited, edges, n);
            }
        if(edges[i].source==start)
            if(visited[edges[i].destination]==0)
            {
                a+=checkTree(edges[i].destination, toFind, visited, edges, n);
            }
    }
    return a;
}

int startCheck(int start, int toFind, edgeT* edges, int n)
{
    int i, a=0;
    if(n==0 || n==1)
    {
        return 0;
    }
    int* visited=(int*)calloc(n+1, sizeof(int));
    visited[start]=1;
    for(i=0; i<n; i++)
    {
        if(edges[i].source==start)
        {
            a+=checkTree(edges[i].destination, toFind, visited, edges, n);
        }
        if(edges[i].destination==start)
        {
            a+=checkTree(edges[i].source, toFind, visited, edges, n);
        }
    }
    return a;
}

void printEdge(edgeT e)
{
    printf("%c->%c ", e.source+65, e.destination+65);
}

void kruskal()
{
    int** matrix=getCopyOfAdjecencyMatrix();
    int nrOfEdgesCovered=0;
    int weight=0;
    edgeT* edges=(edgeT*)calloc(nrOfVerteces-1, sizeof(edgeT));
    while(nrOfEdgesCovered<nrOfVerteces-1)
    {
        edgeT e=getMinimumEdgeForAdjacencyMatrix(matrix);
        if(e.weight==MAX)
        {
            break;
        }
        matrix[e.source][e.destination]=0;
        matrix[e.destination][e.source]=0;
        if(startCheck(e.source, e.destination, edges, nrOfEdgesCovered)==0)
        {
            edges[nrOfEdgesCovered]=e;
            nrOfEdgesCovered++;
            weight+=e.weight;
            printEdge(e);
        }
    }
    printf("\n%d\n", weight);
}


void bellmanFord()
{
    int n=nrOfVerteces, source, i, j, a;
    printf("source: ");
    scanf("%d", &source);
    int* distance=(int*)calloc(n, sizeof(int));
    for(i=0; i<n; i++)
    {
        if(i!=source)
        {
            distance[i]=MAX;
        }
    }
    int* parent=(int*)malloc(n*sizeof(int));
    for(i=0; i<n; i++)
    {
        parent[i]=(int)NULL;
    }
    for(a=0; a<2; a++)
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
            {
                if(adjMatrix[i][j]!=0)
                {
                    if(distance[i]+adjMatrix[i][j]<distance[j])
                    {
                        distance[j]=distance[i]+adjMatrix[i][j];
                        parent[j]=i;
                    }
                }
            }
    edgeT* edges=(edgeT*)calloc(n-1, sizeof(edgeT));
    int nrOfEdgesCovered=0;
    int weight=0;
    for(i=0; i<n; i++)
    {
        if(i!=source)
        {
            edges[nrOfEdgesCovered].source=parent[i];
            edges[nrOfEdgesCovered].destination=i;
            edges[nrOfEdgesCovered].weight=distance[i]-distance[parent[i]];
            weight+=edges[nrOfEdgesCovered].weight;
            nrOfEdgesCovered++;
        }
    }
    printf("%d\n", weight);
    printEdges(edges, nrOfEdgesCovered);

}
