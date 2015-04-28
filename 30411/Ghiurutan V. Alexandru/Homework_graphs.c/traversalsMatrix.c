#include "traversalsMatrix.h"

int getNumberOfNeighborsOfVertex(int v)
{
    int i,nr;
    nr=0;
    for(i=0; i<nrOfVertices; i++)
    {
        if(adjMatrix[v][i]==1)
        {
            nr++;
        }
    }
    return nr;
}

int *getAllNeighborsOfVertex(int v)
{
    int i,j,nr;
    nr=getNumberOfNeighborsOfVertex(v);
    int *c=(int *)malloc(sizeof(int)*nr);
    for(i=0,j=0; i<nrOfVertices; i++)
    {
        if(adjMatrix[v][i]==1)
        {
            c[j]=i;
            j++;
        }
    }
    return c;
}

void bfs(int searchNode)
{
    printf("BFS started:\n");
    int *visited=(int *)malloc(sizeof(int)*nrOfVertices);
    int i,v;
    for(i=0; i<nrOfVertices; i++)
    {
        visited[i]=UNVISITED;
    }
    visited[searchNode]=VISITED;
    enqueue(searchNode);
    printf("%c ",searchNode+65);
    while(!isEmptyQueue())
    {
        v=peekQueue()->content;
        dequeue();
        int nrOfNeighbours=getNumberOfNeighborsOfVertex(v);
        int *neighbors=getAllNeighborsOfVertex(v);
        for(i=0; i<nrOfNeighbours; i++)
        {
            int w=neighbors[i];
            if(visited[w]==UNVISITED)
            {
                visited[w]=VISITED;
                printf("%c ",w+65);
                enqueue(w);
            }
        }
    }
    printf("\nBFS ended:\n");
}

void dfs(int searchNode)
{
    printf("\nDFS started:\n");
    int *visited=(int *)malloc(sizeof(int)*nrOfVertices);
    int i,v;
    for(i=0; i<nrOfVertices; i++)
    {
        visited[i]=UNVISITED;
    }
    push(searchNode);
    while(!isEmptyStack())
    {
        v=peekStack()->content;
        pop();
        if(visited[v]==UNVISITED)
        {
            visited[v]=VISITED;
            printf("%c ",v+65);
            int nrOfNeighbors=getNumberOfNeighborsOfVertex(v);
            int *neighbors=getAllNeighborsOfVertex(v);
            for(i=nrOfNeighbors-1; i>=0; i--)
            {
                int w=neighbors[i];
                if(visited[w]==UNVISITED)
                {
                    push(w);
                }
            }
        }
    }
    printf("\nDFS ended:\n");
}

void dfsRec(int v,int *visited)
{
    int i;
    visited[v]=VISITED;
    printf("%c ",v+65);
    int nrOfNeighbors=getNumberOfNeighborsOfVertex(v);
    int *neighbors=getAllNeighborsOfVertex(v);
    for(i=0; i<nrOfNeighbors; i++)
    {
        int w=neighbors[i];
        if(visited[w]==UNVISITED)
        {
            dfsRec(w,visited);
        }
    }
}

void dfsRecurs(int searchNode)
{
    printf("DFS Recursive:\n");
    int *visited=(int *)calloc(sizeof(int),nrOfVertices);
    int i;
    for(i=0; i<nrOfVertices; i++)
    {
        visited[i]=UNVISITED;
    }
    dfsRec(searchNode,visited);
    printf("\nDFS Recursive ended.\n");
}
