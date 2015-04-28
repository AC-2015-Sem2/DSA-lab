#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "stack.h"
#include "queue.h"

//! representation

void readFromAdjMatrix(FILE * f)
{
    int n;
    fscanf(f,"%d",&n);
    nrOfVerteces=n;
    int i,j;
    adjMatrix=(int**)malloc(n*sizeof(int*));
    for (i=1; i<=n; i++)
    {
        *(adjMatrix+i)=(int*)malloc(n*sizeof(int));
    }

    for (i=1; i<=n; i++)
        for (j=1; j<=n; j++)
            fscanf(f,"%d",&adjMatrix[i][j]);
    fclose(f);
}

void printAdjMatrix()
{
    int i,j;

    printf("\nThe matrix is:\n");
    printf("    ");
    for (i=1; i<=nrOfVerteces; i++)
    {
        printf("%c   ",65+i);
    }
    printf("\n");
    for (i=1; i<=nrOfVerteces; i++)
    {
        printf("%c ",65+i);
        for (j=1; j<=nrOfVerteces; j++)
            printf("%3d ",adjMatrix[i][j]);
        printf("\n");
    }
}

int getNumberOfNeighborsOfVertex(int v)
{
    if(v<nrOfVerteces)
    {
        int nrOfNeighbors=0;
        int i;
        for(i=1; i<= nrOfVerteces; i++)
        {
            if(adjMatrix[v][i]>0 && i!=v)
            {
                nrOfNeighbors++;
            }
        }
        return nrOfNeighbors;
    }
    else
    {
        return 0;
    }
}

int * getAllNeighborsOfVertex(int v)
{
    if(v<nrOfVerteces)
    {
        int nrOfNeighbors = getNumberOfNeighborsOfVertex(v);
        int * neighbors = (int*)malloc(sizeof(int) * nrOfNeighbors);
        int i,j=0;
        for(i=1; i<=nrOfVerteces; i++)
        {
            if(adjMatrix[v][i]>0 && i!=v)
            {
                neighbors[j]=i;
                j++;
            }
        }
        return neighbors;
    }
    else
    {
        return NULL;
    }

}

//! traversals

void bfs(int startNode)
{
    printf("BFS started\n");
    int * visited = (int*)malloc(nrOfVerteces * sizeof(int));
    int i, v, w;

    for(i=0; i < nrOfVerteces; i++)
    {
        visited[i]=UNVISITED;
    }

    visited[startNode] = VISITED;
    printf("%c ", startNode+65);
    enqueue(startNode);

    while(!isEmptyQueue())
    {
        v = peekQueue()->content;
        dequeue();
        int nrOfNeighbors = getNumberOfNeighborsOfVertex(v);
        int * neighbors = getAllNeighborsOfVertex(v);
        for(i=0; i<nrOfNeighbors; i++)
        {
            w = neighbors[i];
            if(visited[w] == UNVISITED)
            {
                printf("%c ", w+65);
                enqueue(w);
                visited[w] = VISITED;
            }
        }
    }
    printf("\nBFS ended\n\n");
}

void dfs(int startNode)
{

    printf("DFS started\n");
    int * visited = (int*)malloc(nrOfVerteces * sizeof(int));
    int i, v;

    for(i=0; i < nrOfVerteces; i++)
    {
        visited[i]=UNVISITED;
    }

    push(startNode);

    while(!isEmptyStack())
    {
        v = peekStack()->content;
        pop();

        if(visited[v] == UNVISITED)
        {
            visited[v] = VISITED;
            int nrOfNeighbors = getNumberOfNeighborsOfVertex(v);
            int * neighbors = getAllNeighborsOfVertex(v);
            for(i=nrOfNeighbors-1; i>=0; i--)
            {
                int w = neighbors[i];
                if(visited[w] == UNVISITED)
                {
                    push(w);
                }
            }
            printf("%c ",v+65);
        }

    }
    printf("\nDFS ended\n\n");

}
void dfsRec(int v, int * visited)
{
    int i;
    visited[v] = VISITED;
    int nrOfNeighbors = getNumberOfNeighborsOfVertex(v);
    int * neighbors = getAllNeighborsOfVertex(v);
    printf("%c ",v+65);
    for(i=0; i<nrOfNeighbors; i++)
    {
        int w = neighbors[i];
        if(visited[w]==UNVISITED)
        {
            dfsRec(w, visited);
        }
    }
}

void dfsRecurs(int startNode)
{
    printf("DFS recursive started\n");
    int * visited = (int*)malloc(nrOfVerteces * sizeof(int));
    int i;
    for(i=0; i<nrOfVerteces; i++)
    {
        visited[i]=0;
    }
    dfsRec(startNode,visited);
    printf("\nDFS recursive ended\n\n");
}
void createAdjList(int** adjMatrix)
{
    adjListlength = (int*) malloc(nrOfVerteces * sizeof(int));
    adjList = (int**) malloc (nrOfVerteces * sizeof(int*));

    int i;
    for (i = 0; i < nrOfVerteces; i++)
    {
        adjListlength[i] = getNumberOfNeighborsOfVertex(i);
        adjList[i] = getAllNeighborsOfVertex(i);
    }
}
void printAdjList()
{
    int i, j;

    printf("\nadjList\n");
    for (i = 0; i < nrOfVerteces; i++)
    {
        printf("%c: ", i+65);
        for (j = 0; j < adjListlength[i]; j++)
        {
            printf("%c ", adjList[i][j] + 65);
        }
        printf("\n");
    }
    printf("\n");
}
int** ListToMatrix(int** adjList, int* adjListlength)
{
    int** newAdjMatr = (int**) malloc (nrOfVerteces * sizeof(int*));

    int i,j;
    for (i=0;i<nrOfVerteces;i++)
    {
        newAdjMatr[i]=(int*)calloc(nrOfVerteces,sizeof(int));
        for (j=0;j<adjListlength[i];j++)
        {
            newAdjMatr[i][adjList[i][j]]=1;
        }
    }
    return newAdjMatr;
}
