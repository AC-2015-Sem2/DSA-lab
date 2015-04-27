#include <stdio.h>
#include <stdlib.h>
#include "AdjList.h"
#include "graph.h"
#include "stack.h"
#include "queue.h"

///For Adj List
int getNumberOfNeighborsOfVertex(int v)
{
    int m=0;
       edge *e;
        e=graph[v].edgePointer;
        while(e)
        {
            m++;
            e=e->edgePointer;
        }
    return m;
}
int * getAllNeighborsOfVertex(int v)
{
    int z=0;
    int *w=(int*)malloc(sizeof(int)*n);
    edge *e;
    e=graph[v].edgePointer;
    while(e!=NULL)
        {
            w[z]=graph[e->vertexIndex].vertexKey;
            z++;

            e=e->edgePointer;
        }
    return w;
}
///for Adj Matrix
/*int getNumberOfNeighborsOfVertex(int v)
{
    int j,n=0;

    for(j=0; j<nrOfVerteces; j++)
        if(adjMatrix[v][j]==1)n++;
    return n;
}

int * getAllNeighborsOfVertex(int v)
{
    int z=0,j;
    int n=getNumberOfNeighborsOfVertex(v);
    int *w=(int*)malloc(sizeof(int)*n);
    for(j=0; j<nrOfVerteces; j++)
        if(adjMatrix[v][j]==1)
        {
            w[z]=j;
            z++;
        }
    return w;
}*/

//! traversals

void bfs(int searchNode)
{

    int *mark=(int*)malloc(sizeof(int)*nrOfVerteces);
    int i,j,w;
    NodeT *v;
    for(i=0; i<nrOfVerteces; i++)
        mark[i]=UNVISITED;
    mark[searchNode]=VISITED;
    printf("%d ",searchNode);
    enqueue(searchNode);
    while(!isEmptyQueue())
    {
        v=peekQueue();
        dequeue();
        int s=getNumberOfNeighborsOfVertex(v->content);
        int *neighbours=getAllNeighborsOfVertex(v->content);
        for (j=0; j<s; j++)
        {
            w=neighbours[j];
            if(mark[w]==UNVISITED)
            {
                enqueue(w);
                mark[w]=VISITED;
                printf("%d ",w);
            }
        }
    }
}

void dfs(int searchNode)
{
    int *mark=(int*)malloc(sizeof(int)*nrOfVerteces);
    int i,j,v,w;
    for(i=0; i<nrOfVerteces; i++)
        mark[i]=UNVISITED;
    push(searchNode);
    while(!isEmptyStack())
    {
        v=peekStack()->content;
        pop();
        if(mark[v]==UNVISITED)
        {
            mark[v]=VISITED;
            int *neighbours=getAllNeighborsOfVertex(v);
            int s=getNumberOfNeighborsOfVertex(v);
            for(j=s-1; j>=0; j--)
            {
                w=neighbours[j];
                if(mark[w]==UNVISITED)
                    push(w);
            }
            printf("%d ",v);
        }
    }
}

void dfsRec(int v, int * mark)
{
    int i;
    mark[v]=VISITED;
    int n=getNumberOfNeighborsOfVertex(v);
    int *neighbours=getAllNeighborsOfVertex(v);
    printf("%d ",v);
    for(i=0;i<n;i++)
    {
        int w=neighbours[i];
        if(mark[w]==UNVISITED)dfsRec(w,mark);
    }

}

void dfsRecurs(int v)
{
    int i;
    int *mark=(int*)malloc(sizeof(int)*nrOfVerteces);
    for(i=0; i<nrOfVerteces; i++)
        mark[i]=UNVISITED;
    dfsRec(v,mark);
}

