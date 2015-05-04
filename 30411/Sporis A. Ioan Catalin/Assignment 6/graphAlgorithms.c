#include "graph.h"
#include "graphRepresentation.h"

//! Prim related stuff
edgeT getMinimumEdgeForCurrentlyVisitedNodes(int * visited)
{
    int i,j;
    edgeT minE;
    minE.weight=MAX ;
    for(i=0; i<nrOfVerteces; i++)

        for(j=0; j< nrOfVerteces; j++)
        {
            if(visited[i]==VISITED  && visited[j]==UNVISITED && adjMatrix[i][j] < minE.weight && adjMatrix[i][j])
            {
                minE.source=i;
                minE.destination=j;
                minE.weight=adjMatrix[i][j];
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
    int v=nrOfVerteces,i;
    int * vis = (int*)malloc(nrOfVerteces * sizeof(int));
    for(i=0; i < nrOfVerteces; i++)
    {
        vis[i]=UNVISITED;
    }

    vis[startNode]=VISITED;
    edgeT * edges=(edgeT*)malloc( (v-1)*sizeof(edgeT));
    int nrofsteps=0;
    while(nrofsteps < v-1)
    {
        edgeT e=getMinimumEdgeForCurrentlyVisitedNodes(vis);
        vis[e.destination]=VISITED;
        edges[nrofsteps]=e;
        nrofsteps++;
    }

    printEdges(edges,nrofsteps);
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
    int i,j, Costmin=0,u,v,x,y;
    int nrOfEdges=1;
    int *parent=(int*)malloc(sizeof(int)*nrOfVerteces);
    int **weight_matr=getCopyOfAdjecencyMatrix();
    for(i=0;i<nrOfVerteces;i++)
        for(j=0;j<nrOfVerteces;j++)
            if(weight_matr[i][j]==0)
                weight_matr[i][j]=MAX;

    for(i=0;i<nrOfVerteces;i++)
        parent[i]=UNVISITED;

    while(nrOfEdges<nrOfVerteces)
    {
        edgeT minE=getMinimumEdgeForAdjacencyMatrix(weight_matr);
        x=minE.source;
        y=minE.destination;
        u=x;
        v=y;
        u=getParent(parent,u);
        v=getParent(parent,v);

        if(uni(parent,u,v))
        {
            printf("%dth edge added is:(%c->%c) : weight=%d\n",nrOfEdges++,x+65,y+65,minE.weight);
            Costmin =Costmin+minE.weight;
        }
        weight_matr[x][y]=weight_matr[y][x]=MAX;
    }
    printf("The minimum cost is %d\n",Costmin);
}

//! Dijsktra related stuff

int getMinDistanceVertex(int * distances, int * visited)
{
    int i;
    int node, MIN=999;
    for( i=0; i<nrOfVerteces; i++)
        if(visited[i] != VISITED && distances[i] < MIN)
            node=i;

    return node;
}

void dijkstra(int startNode)
{
    int v=nrOfVerteces,i;
    int *dist=(int*)malloc((v*sizeof(int)));
    int * vis = (int*)malloc(nrOfVerteces * sizeof(int));
    for(i=0; i < nrOfVerteces; i++)
    {
        vis[i]=UNVISITED;
    }

    for(i=0; i < nrOfVerteces; i++)
    {
        dist[i]=MAX;
    }
    int *parent=(int*)malloc((v*sizeof(int)));
    for(i=0; i < nrOfVerteces; i++)
    {
        parent[i]=UNDEFINED;
    }

    dist[startNode]=0;
    int nrofsteps=0;



    while(nrofsteps< v)
    {
        int u=getMinDistanceVertex(dist,vis);
        vis[u]=VISITED;
        int *neighbors=getAllNeighborsOfVertex(u);
        int nrOfNeighbors = getNumberOfNeighborsOfVertex(u);

        for(i=0; i<nrOfNeighbors; i++)
        {
            int w = neighbors[i];
            int altDist= dist[u]+adjMatrix[u][w];
            if(altDist <dist[w])
            {
                dist[w]=altDist;
                parent[w]=u;
            }
        }
        nrofsteps++;

    }
    for(i=0; i<v; i++)
    {
        int u=i;
        if(i !=startNode)
        {
            while(parent[u] != UNDEFINED)
            {
                push(u);
                u=parent[u];
            }
        }
        printf("Path from %c to %c is %c\n",startNode+65,i+65,startNode+65);
        while(!isEmptyStack())
        {
            printf("->%c",peekStack()->content+65);
            pop();

        }
        printf("\n");
    }

}

//Bellman_Ford Algorithm

void Bellman_ford(int startNode)
{

    int i,j,v=nrOfVerteces;

    int * parent = (int*)malloc(v*sizeof(int));
    int * q= (int*)malloc(v*sizeof(int));
    int **weight=getCopyOfAdjecencyMatrix();

     for(i=0; i<v; i++)
        for(j=0; j<v; j++)
            if(weight[i][j]==0&& i!=j)
                weight[i][j]=MAX;
    for(i=0; i<v; i++)
    {
        if(i==startNode)
            q[i]=0;
        else
            q[i]=MAX;
        parent[i]=0;
    }
    int x,y;
    for (i=0;i<v;i++)
        for (x=0;x<v; x++)
            for(y=0; y<v;y++)
                if(adjMatrix[x][y]>0&& x!=y)
                    if(q[x]+adjMatrix[x][y]<q[y])
                    {
                        q[y]=q[x]+adjMatrix[x][y];
                        parent[y]=x;
                    }
    for(i = 0; i <v; i++)
    {
        printf("%c->%c\t", parent[i]+65 , i +65);
    }

}
