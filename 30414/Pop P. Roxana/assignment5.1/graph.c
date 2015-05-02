#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "stack.h"
#include "queue.h"

void bfs(int searchNode)
{
    int n=nrOfVerteces;
    int* visited=(int*)malloc(n*sizeof(int));
    int i;
    for (i=0;i<n;i++)
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
        int* aux=getAllNeighborsOfVertex(v);
        for (i=0;i<getNumberOfNeighborsOfVertex(v);i++)
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

void dfs(int searchNode)
{
    int n=nrOfVerteces;
    int* visited=(int*)malloc(n*sizeof(int));
    int i;
    for (i=0;i<n;i++)
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
            int* aux=getAllNeighborsOfVertex(v);
            for (i=getNumberOfNeighborsOfVertex(v)-1;i>=0;i--)
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

void dfsRec(int v, int * mark)
{
   if (mark[v]==VISITED) return;
   printf("%d ",v);
   mark[v]=VISITED;
   int i;
   int* neighbours=getAllNeighborsOfVertex(v);
   for (i=0;i<getNumberOfNeighborsOfVertex(v);i++)
    dfsRec(neighbours[i],mark);
}

void dfsRecurs(int v)
{
    int * mark=(int*)malloc(nrOfVerteces*sizeof(int));
    int i;
    for (i=0;i<nrOfVerteces;i++)
        mark[i]=UNVISITED;
    dfsRec(v,mark);
}
