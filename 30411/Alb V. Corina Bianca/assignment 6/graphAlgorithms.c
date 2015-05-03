#include "graph.h"
#include "graphRepresentation.h"

//! Prim related stuff
edgeT getMinimumEdgeForCurrentlyVisitedNodes(int * visited)
{

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

    printf("\nPrim ended\n\n");
}

//! Kruskal related stuff
edgeT getMinimumEdgeForAdjacencyMatrix(int ** adjMat)
{
    int i,j;
    edgeT minEdge;
    minEdge.weight=MAX;
    for(i=0;i<nrOfVerteces;i++)
    {
        for(j=i;j<nrOfVerteces;j++)
        {
            if(adjMat[i][j]<minEdge.weight)
            {
                minEdge.weight=adjMat[i][j];
                minEdge.source=i;
                minEdge.destination=j;
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

struct subset
{
    int parent;
    int rank;
};

int getParent(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = getParent(subsets, subsets[i].parent);

    return subsets[i].parent;
}


void uni(struct subset subsets[], int x,int y)
{
    int xroot = getParent(subsets, x);
    int yroot = getParent(subsets, y);

    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;

    // If ranks are same, then make one as root and increment
    // its rank by one
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int getNrOfEdges(int **adjMat)
{
    int x=0,j,i;
    for(i=0;i<nrOfVerteces;i++)
    {
        for(j=i+1;j<nrOfVerteces;j++)
        {
            if(adjMat[i][j]!=0)
            {
                x++;
            }
        }
    }
    return x;
}

edgeT *sortEdges(edgeT *edges, int nrOfEdges, int** adjMat)
{
    int p=0,j,i;
    for(i=0;i<nrOfVerteces;i++)
    {
        for(j=i+1;j<nrOfVerteces;j++)
        {
            if(adjMat[i][j]!=0)
            {
               edges[p].source=i;
               edges[p].destination=j;
               edges[p].weight=adjMat[i][j];
               p++;
            }
        }
    }
    edgeT aux;
    for(i=0;i<nrOfEdges;i++)
        for(j=i;j<nrOfEdges;j++)
    {
        if(edges[i].weight>edges[j].weight)
        {
            aux=edges[i];
            edges[i]=edges[j];
            edges[j]=aux;
        }
    }
    return edges;
}

void kruskal()
{
    printf("Kruskal started\n");
    int **adjMat=getCopyOfAdjecencyMatrix();
    int nrOfCoveredEdges=0;
    edgeT result[nrOfVerteces];
    int nrOfEdges=getNrOfEdges(adjMat);
    edgeT *edges=(edgeT*)malloc(sizeof(edgeT)*nrOfEdges);
    edges=sortEdges(edges,nrOfEdges,adjMat);
    int i=0;
    int v;
    struct subset *subsets =(struct subset*) malloc( nrOfVerteces * sizeof(struct subset) );
    for (v = 0; v < nrOfVerteces; ++v)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    while(nrOfCoveredEdges<nrOfVerteces-1)
    {
        int x = getParent(subsets, edges[i].source);
        int y = getParent(subsets, edges[i].destination);

        // If including this edge does't cause cycle, include it
        // in result and increment the index of result for next edge
        if (x != y)
        {
            result[nrOfCoveredEdges++] = edges[i];
            uni(subsets, x, y);
        }
        i++;
        // Else discard the next_edge
    }
    int w=0;
    for (i = 0; i < nrOfCoveredEdges; ++i)
    {
        printf("%c -- %c == %d\n", result[i].source+65, result[i].destination+65,result[i].weight);
        w+=result[i].weight;
    }
    printf("\n the weight of the MST is %d ",w);
    printf("\nKruskal ended\n\n");
}


//! Dijsktra related stuff

int getMinDistanceVertex(int * distances, int * visited){

}

void dijkstra(int startNode)
{
    printf("Dijkstra started\n");


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

    printf("\nDijkstra ended\n\n");
}


//Bellman Ford -- finds the shorthest path form A to F in the oriented graph from the file matrixBF

void BellmanFord()
{
    printf("\nBellman-Ford algorithm started\n");
    int *d=(int*)malloc(sizeof(int)*nrOfBFVerteces);
    int *pi=(int*)malloc(sizeof(int)*nrOfBFVerteces);
    d[0]=0;
    pi[0]=0;
    int i,repeat,j;
    for(i=1;i<nrOfBFVerteces;i++)
    {
        d[i]=MAX;
        pi[0]=0;
    }
    for(repeat=0;repeat<nrOfBFVerteces-1;repeat++)
    {
        for(i=0;i<nrOfBFVerteces;i++)
        {
            for(j=0;j<nrOfBFVerteces;j++)
            {
                if(adjBFMatrix[i][j]!=0)
                    if(adjBFMatrix[i][j]+d[i]<d[j])
                {
                    d[j]=adjBFMatrix[i][j]+d[i];
                    pi[j]=i;
                }
            }
        }
    }
    int weight=0;
    for(i=0;i<nrOfBFVerteces;i++)
    {
        weight+=d[i];
    }
    printf("\n the cost of the shortest path is %d\n",weight);
    for(i=0;i<nrOfBFVerteces;i++)
    {
        printf("\nthe predecessor of node %c is %c ",pi[i]+65,i+65);
    }
    printf("\nBellman-Ford algorithm ended\n");
}

