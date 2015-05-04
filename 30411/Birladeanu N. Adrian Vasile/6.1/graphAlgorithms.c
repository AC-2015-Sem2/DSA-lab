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


int getParent(int * parent, int i)
{
    while(parent[i]!=-1)
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
    printf("Kruskal: \n");
    int** matrix=getCopyOfAdjecencyMatrix(adjMatrix);
    int* parent=(int*)malloc(nrOfVerteces*sizeof(int));
    int i, weight=0;
    for(i=0; i<nrOfVerteces; i++)
    {
        parent[i]=-1;
    }
    int nrOfEdgesCovered=0;
    edgeT* edges=(edgeT*)malloc(sizeof(nrOfVerteces-1));
    while(nrOfEdgesCovered<nrOfVerteces-1)
    {
        edgeT e=getMinimumEdgeForAdjacencyMatrix(matrix);
        matrix[e.source][e.destination]=0;
        matrix[e.destination][e.source]=0;
        int u=getParent(parent, e.source);
        int v=getParent(parent, e.destination);
        if(uni(parent, u, v))
        {
            edges[nrOfEdgesCovered]=e;
            nrOfEdgesCovered++;
            weight+=e.weight;
        }
    }
    printEdges(edges, nrOfEdgesCovered);
    printf("\n%d\n", weight);
}


void bellmanFord()
{
    int n=nrOfVerteces, source, i, j, a;
    printf("Bellman-Ford\nsource: ");
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
