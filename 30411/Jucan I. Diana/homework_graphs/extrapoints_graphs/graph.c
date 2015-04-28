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
    for (i=0; i<n; i++)
    {
        *(adjMatrix+i)=(int*)malloc(n*sizeof(int));
    }

    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            fscanf(f,"%d",&adjMatrix[i][j]);
    fclose(f);
}

void printAdjMatrix()
{
    int i,j;

    printf("\nThe matrix is:\n");
    printf("    ");
    for (i=0; i<nrOfVerteces; i++)
    {
        printf("%d   ",i);
    }
    printf("\n");
    for (i=0; i<nrOfVerteces; i++)
    {
        printf("%d ",i);
        for (j=0; j<nrOfVerteces; j++)
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
        for(i=0; i< nrOfVerteces; i++)
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
        for(i=0; i<nrOfVerteces; i++)
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
int dfs(int startNode,int stopNode)
{
    int * visited = (int*)malloc(nrOfVerteces * sizeof(int));
    int i, v;
    int path[100];
    int k=0;

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
            if(v!=stopNode)
            {
                //printf("%d ",v);
                path[k]=v;
                k++;
            }
            else
            {
                // printf("%d ",v);
                path[k]=v;
                for(i=k; i>0; i--)
                    if(adjMatrix[path[i]][path[i-1]]==0)
                        path[i-1]=path[i];
                for(i=0; i<=k; i++)
                    if(path[i]!=path[i+1])
                        printf("%d ",path[i]);

                return 0;
            }
        }

    }
    return 0;
}
