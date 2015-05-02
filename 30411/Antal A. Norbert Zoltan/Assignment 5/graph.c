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
    adjHolder=(int**)malloc(n*sizeof(int*));
    for (i=0; i<n; i++)
    {
        *(adjHolder+i)=(int*)malloc(n*sizeof(int));
    }

    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            fscanf(f,"%d",&adjHolder[i][j]);
    fclose(f);
    isM = 1;
}

void printAdjMatrix()
{
    int i,j;

    printf("\nThe matrix is:\n");
    printf("    ");
    for (i=0; i<nrOfVerteces; i++)
    {
        printf("%c   ",65+i);
    }
    printf("\n");
    for (i=0; i<nrOfVerteces; i++)
    {
        printf("%c ",65+i);
        for (j=0; j<nrOfVerteces; j++)
            printf("%3d ",adjHolder[i][j]);
        printf("\n");
    }
    printf("\n");
}

int getNumberOfNeighborsOfVertex(int v)
{
    if(v<nrOfVerteces)
    {
        if (isM)
        {
            int nrOfNeighbors=0;
            int i;
            for(i=0; i< nrOfVerteces; i++)
            {
                if(adjHolder[v][i]>0 && i!=v)
                {
                    nrOfNeighbors++;
                }
            }
            return nrOfNeighbors;
        }
        else
        {
            return nrNeighbors[v];
        }
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
        if (isM)
        {
            int nrOfNeighbors = getNumberOfNeighborsOfVertex(v);
            int * neighbors = (int*)malloc(sizeof(int) * nrOfNeighbors);
            int i,j=0;
            for(i=0; i<nrOfVerteces; i++)
            {
                if(adjHolder[v][i]>0 && i!=v)
                {
                    neighbors[j]=i;
                    j++;
                }
            }
            return neighbors;
        }
        else
        {
            return adjHolder[v];
        }
    }
    else
    {
        return NULL;
    }
}

//! traversals

void bfs(int searchNode)
{
    printf("BFS started\n");
    int * mark = (int*)malloc(nrOfVerteces * sizeof(int));
    int i, v, w;

    for(i=0; i < nrOfVerteces; i++)
    {
        mark[i]=UNVISITED;
    }

    mark[searchNode] = VISITED;
    printf("%d ", searchNode);
    enqueue(searchNode);

    while(!isEmptyQueue())
    {
        v = peekQueue()->content;
        dequeue();
        int nrOfNeighbors = getNumberOfNeighborsOfVertex(v);
        int * neighbors = getAllNeighborsOfVertex(v);
        for(i=0; i<nrOfNeighbors; i++)
        {
            w = neighbors[i];
            if(mark[w] == UNVISITED)
            {
                printf("%d ", w);
                enqueue(w);
                mark[w] = VISITED;
            }
        }
    }
    printf("\nBFS ended\n\n");
}

void dfs(int searchNode)
{
    printf("DFS started\n");
    int * mark = (int*)malloc(nrOfVerteces * sizeof(int));
    int i, v;

    for(i=0; i < nrOfVerteces; i++)
    {
        mark[i]=UNVISITED;
    }

    push(searchNode);

    while(!isEmptyStack())
    {
        v = peekStack()->content;
        pop();

        if(mark[v] == UNVISITED)
        {
            mark[v] = VISITED;
            int nrOfNeighbors = getNumberOfNeighborsOfVertex(v);
            int * neighbors = getAllNeighborsOfVertex(v);
            for(i=nrOfNeighbors-1; i>=0; i--)
            {
                int w = neighbors[i];
                if(mark[w] == UNVISITED)
                {
                    push(w);
                }
            }
            printf("%d ",v);
        }

    }
    printf("\nDFS ended\n\n");
}

void dfsRec(int v, int * mark)
{
    int i;
    mark[v] = VISITED;
    int nrOfNeighbors = getNumberOfNeighborsOfVertex(v);
    int * neighbors = getAllNeighborsOfVertex(v);
    printf("%d ",v);
    for(i=0; i<nrOfNeighbors; i++)
    {
        int w = neighbors[i];
        if(mark[w]==UNVISITED)
        {
            dfsRec(w, mark);
        }
    }
}

void dfsRecurs(int v)
{
    printf("DFS recursive started\n");
    int * mark = (int*)malloc(nrOfVerteces * sizeof(int));
    int i;
    for(i=0; i<nrOfVerteces; i++)
    {
        mark[i]=0;
    }
    dfsRec(0,mark);
    printf("\nDFS recursive ended\n\n");
}

void toList()
{
    if (adjHolder == NULL) return;
    int i;
    free(nrNeighbors);
    nrNeighbors = (int*)malloc(nrOfVerteces*sizeof(int));
    for (i=0; i<nrOfVerteces; i++)
    {
        int nrOfNeighbors = getNumberOfNeighborsOfVertex(i);
        int* adjVerteces = (int*)malloc(nrOfNeighbors*sizeof(int));
        int r, s = 0;
        for (r=0; r<nrOfVerteces; r++)
        {
            if (adjHolder[i][r]==1)
            {
                adjVerteces[s] = r;
                s++;
            }
        }
        nrNeighbors[i] = s;
        free(adjHolder[i]);
        adjHolder[i] = adjVerteces;
    }
    printf("Converted to list.\n\n");
    isM = 0;
}

void toMatrix()
{
    if (adjHolder == NULL) return;
    int i;
    for (i=0; i<nrOfVerteces; i++)
    {
        int* adjMRow = (int*)malloc(nrOfVerteces*sizeof(int));
        int r;
        for (r=0; r < nrOfVerteces; r++)
        {
            adjMRow[r] = 0;
        }
        for(r=0; r < nrNeighbors[i]; r++)
        {
            adjMRow[adjHolder[i][r]]++;
        }
        free(adjHolder[i]);
        adjHolder[i] = adjMRow;
    }
    printf("Converted to matrix.\n\n");
    isM = 1;
}
