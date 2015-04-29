#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "stack.h"
#include "queue.h"
#include "matrix.h"

void readFromAdjMatrix(FILE * f)
{
    int n;
    fscanf(f,"%d",&n);
    nrOfVertices=n;
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
    for (i=0; i<nrOfVertices; i++)
    {
        printf("%c   ",65+i);
    }
    printf("\n");
    for (i=0; i<nrOfVertices; i++)
    {
        printf("%c ",65+i);
        for (j=0; j<nrOfVertices; j++)
            printf("%3d ",adjMatrix[i][j]);
        printf("\n");
    }
}

int getNumberOfNeighborsOfVertexFromMatrix(int v)
{
    int i;
    int nr=0;
    for (i=0; i<nrOfVertices; i++)
        nr+=adjMatrix[v][i];
    return nr;
}

int * getAllNeighborsOfVertexFromMatrix(int v)
{
    int * neighbours=(int*)malloc(getNumberOfNeighborsOfVertexFromMatrix(v)*sizeof(int));
    int i,m=0;
    for (i=0; i<=nrOfVertices; i++)
    {
        if (adjMatrix[v][i]==1)
        {
            neighbours[m]=i;
            m++;
        }
    }
    return neighbours;
}


void bfsMatrix(int searchNode)
{
    int* visited=(int*)malloc(nrOfVertices*sizeof(int));
    int i;
    for (i=0; i<nrOfVertices; i++)
    {
        visited[i]=UNVISITED;
    }
    visited[searchNode]=VISITED;
    enqueue(searchNode);
    printf("%d ",searchNode);
    while(!isEmptyQueue())
    {
        int v=peekQueue()->content;
        dequeue();
        int* aux=getAllNeighborsOfVertexFromMatrix(v);
        for (i=0; i<getNumberOfNeighborsOfVertexFromMatrix(v); i++)
        {
            int w=aux[i];
            if (visited[w]==UNVISITED)
            {
                visited[w]=VISITED;
                enqueue(w);
                printf("%d ",w);
            }
        }
    }
    printf("\n");
}




void dfsMatrix(int searchNode)
{
    int* visited=(int*)malloc(nrOfVertices*sizeof(int));
    int i;
    for (i=0; i<nrOfVertices; i++)
    {
        visited[i]=0;
    }
    push(searchNode);
    while(!isEmptyStack())
    {
        int v=peekStack()->content;
        pop();
        if (visited[v]==0)
        {
            visited[v]=1;
            int* aux=getAllNeighborsOfVertexFromMatrix(v);
            for (i=getNumberOfNeighborsOfVertexFromMatrix(v)-1; i>=0; i--)
            {

                int w=aux[i];
                if (visited[w]==0)
                    push(w);
            }
            printf("%d ",v);
        }
    }
    printf("\n");

}

