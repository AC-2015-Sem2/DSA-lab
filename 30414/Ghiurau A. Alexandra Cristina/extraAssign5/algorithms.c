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

//! enumerate all the paths in the graph using DFS, and record the longest
int getLongestRec(int startNode, int finishNode, int * visited)
{
    if(visited[startNode] == VISITED)
        return -100;
    if(startNode == finishNode)
    {
        printf("%c ", finishNode+65);
        return 0;
    }
    visited[startNode] = VISITED;
    int nrOfNeighbors = getNumberOfNeighborsOfVertex(startNode);
    int * neighbors = getAllNeighborsOfVertex(startNode);
    //int *recordPath = (int*)malloc(sizeof(int)*100);
    int maxLength = -100;
    int i;
//   printf("%c ",startNode+65);
    for(i=0; i<nrOfNeighbors; i++)
    {
        int w = getLongestRec(neighbors[i],finishNode, visited);
        if(w >= maxLength)
            maxLength = w;
    }
    if(maxLength > 0)
    {
        printf("%c ",startNode+65);
    }
    if(maxLength > -1)
        return maxLength+1;
    else return 0;
    // visited[startNode] = UNVISITED;
}

int getLongestRecurs(int startNode, int finishNode)
{
    int * visited = (int*)malloc(nrOfVerteces * sizeof(int));
    int i;
    for(i=0; i<nrOfVerteces; i++)
    {
        visited[i]=0;
    }
    return getLongestRec(startNode,finishNode,visited);
}
