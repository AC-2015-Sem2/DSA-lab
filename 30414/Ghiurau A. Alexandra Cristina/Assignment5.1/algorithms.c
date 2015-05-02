#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "stack.h"
#include "queue.h"
#include "list.h"
#include "algorithms.h"


//! traversals

void bfs(int searchNode)
{
    //allocate visited vector
    int *visited_v = (int*)malloc(sizeof(int)*nrOfVerteces);
    //fill with unvisited
    int i;
    for(i=0; i<nrOfVerteces; i++)
    {
        *(visited_v+i)=UNVISITED;
    }
    visited_v[searchNode] = VISITED;
    printf("\nstartNode: %d ", searchNode);
    enqueue(searchNode);

    int w;
    //int k = getNumberOfNeighborsOfVertex(v);

    while(!isEmptyQueue())
    {
        int  v = peekQueue()->content;
        dequeue();

        for(w=0; w<nrOfVerteces ; w++)
            if(adjMatrix[v][w]==1)
            {
                if(visited_v[w]==UNVISITED)
                {
                    visited_v[w] = VISITED;
                    printf("%d ", w);
                    enqueue(w);
                }
            }
    }
}

void dfs(int searchNode)
{
    int *visited_v = (int*)malloc(sizeof(int)*nrOfVerteces);
    //fill with unvisited
    int i;
    for(i=0; i<nrOfVerteces; i++)
    {
        *(visited_v+i)=UNVISITED;
    }
    push(searchNode);
    printf("\n");
    while(!isEmptyStack())
    {
        int  v = peekStack()->content;

        int k = getNumberOfNeighborsOfVertex(v);
        int * neighbors = getAllNeighborsOfVertex(v);

        pop();
        if(visited_v[v]==UNVISITED)
        {
            visited_v[v] = VISITED;
            for(i=k-1; i>=0; i--)
            {
                int w = neighbors[i];
                if(visited_v[w] == UNVISITED)
                {
                    push(w);

                }

            }
            printf("%d ", v);
        }
    }
}

//! copy-pasted
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
    int * visited = (int*)malloc(nrOfVerteces * sizeof(int));
    int i;
    for(i=0; i<nrOfVerteces; i++)
    {
        visited[i]=0;
    }
    dfsRec(startNode,visited);
}
