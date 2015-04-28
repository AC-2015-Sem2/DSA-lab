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
        printf("%c   ",65+i);
    }
    printf("\n");
    for (i=0; i<nrOfVerteces; i++)
    {
        printf("%c ",65+i);
        for (j=0; j<nrOfVerteces; j++)
            printf("%3d ",adjMatrix[i][j]);
        printf("\n");
    }
}

int getNumberOfNeighborsOfVertex(int v)
{
    int i,ct=0;
    for (i=0; i<nrOfVerteces; i++)
        if (adjMatrix[v][i]==1)
            ct++;
    return ct;
}

int * getAllNeighborsOfVertex(int v)
{
    int *a=(int*)malloc(sizeof(int)*nrOfVerteces);
    int i;
    int ct=0;
    for (i=0; i<nrOfVerteces; i++)
        if (adjMatrix[v][i]==1)
        {
            a[ct]=i;
            ct++;
        }
    return a;
}

//! traversals

void bfs(int searchNode)
{
    int mark[100];
    int i;
    for (i=0; i<100; i++)
        mark[i]=0;
    mark[searchNode]=1;
    printf("%d ",searchNode);
    enqueue(searchNode);
    while (!isEmptyQueue())
    {
        int v=peekQueue()->content;
        dequeue();
        int ct=getNumberOfNeighborsOfVertex(v);
        int *a=getAllNeighborsOfVertex(v);
        for (i=0; i<ct; i++)
            if (mark[a[i]]==0)
            {
                mark[a[i]]=1;
                enqueue(a[i]);
                printf("%d ",a[i]);
            }
    }
}

void dfs(int searchNode)
{
    printf("\n");
    int mark[100];
    int i;
    for (i=0; i<100; i++)
        mark[i]=0;
    push(searchNode);
    while (!isEmptyStack())
    {
        int v=peekStack()->content;
        pop();
        if (mark[v]==0)
        {
            mark[v]=1;
            int ct=getNumberOfNeighborsOfVertex(v);
            int *a=getAllNeighborsOfVertex(v);
            for (i=ct-1; i>=0; i--)
            {
                if (mark[a[i]]!=1)
                {
                    push(a[i]);
                }
            }
            printf("%d ",v);
        }
    }
}

void dfsRec(int v, int * mark)
{

}

void dfsRecurs(int v)
{

}
