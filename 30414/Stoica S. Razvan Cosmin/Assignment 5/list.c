#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "graph.h"
#include "stack.h"
#include "queue.h"

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

void dfsRec(int v, int * mark)
{
   mark[v]=VISITED;
   int nrOfNeighbours=getNumberOfNeighborsOfVertex(v);
   int *neighbours=getAllNeighborsOfVertex(v);
   printf("%c ",v+65);
   int i;
   for (i=0;i<nrOfNeighbours;i++)
   {
       int w=neighbours[i];
       if (mark[w]==UNVISITED)
          dfsRec(w,mark);
   }
}

void dfsRecurs(int v)
{
    int *mark=(int*)malloc(sizeof(int)*nrOfVerteces);
    int i;
    for (i=0;i<nrOfVerteces;i++)
    {
        mark[i]=UNVISITED;
    }
    dfsRec(v,mark);
}



