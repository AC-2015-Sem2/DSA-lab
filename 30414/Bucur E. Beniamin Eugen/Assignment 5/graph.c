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

void printAdjList()
{
    int     i;
    NodeT   *aux;

    printf ("\nThe list is:");
    for (i = 0; i < nrOfVertices; i++)
    {
        aux = adjList[i];
        printf ("\n%d: ", i);
        while (aux != NULL)
        {
            printf ("%d ", aux->content);
            aux = aux->next;
        }
    }
}

void matrixToList()
{
    NodeT   *aux;
    int     i, j, nr;

    adjList = (NodeT**)malloc(sizeof(NodeT*)*nrOfVertices);
    for (i = 0; i < nrOfVertices; i++)
    {
        adjList[i] = (NodeT*)calloc(1, sizeof(NodeT));
        aux = adjList[i];
        nr = 0;
        for (j = 0; j < nrOfVertices; j++)
            if (adjMatrix[i][j])
            {
                if (nr == 0)
                {
                    aux->content = j;
                    nr++;
                }
                else
                {
                    aux->next = createNode(j);
                    aux = aux->next;
                }
            }
        if (!nr)
            aux->content = -1;
    }
}

void listToMatrix()
{
    int i;
    NodeT *aux;

    for (i = 0; i < nrOfVertices; i++)
    {
        aux = adjList[i];
        while (aux != NULL)
        {
            if (aux->content >= 0)
                adjMatrix[i][aux->content] = 1;
            aux = aux->next;
        }

    }
}

int getNumberOfNeighborsOfVertex(int v)
{
    int nr, i;

    nr = 0;
    for (i = 0; i < nrOfVertices; i++)
        nr += adjMatrix[v][i];
    return nr;
}

int * getAllNeighborsOfVertex(int v)
{
    int *neighbors, i, j;

    neighbors = (int*)malloc(getNumberOfNeighborsOfVertex(v)*sizeof(int));
    i = 0;
    for (j = 0; j < nrOfVertices; j++)
    {
        if (adjMatrix[v][j] == 1)
        {
            *(neighbors + i) = j;
            i++;
        }
    }
    return neighbors;
}

//! traversals

void bfs(int startNode)
{
    int *visited = (int*)malloc(nrOfVertices*sizeof(int));
    int i, v, w;

    for (i = 0; i < nrOfVertices; i++)
        visited[i] = UNVISITED;
    visited[startNode] = VISITED;
    printf("\n%d", startNode);
    enqueue(startNode);
    while(!isEmptyQueue())
    {
        v = peekQueue();
        dequeue();
        for (i = 0; i < getNumberOfNeighborsOfVertex(v); i++)
        {
            w = *(getAllNeighborsOfVertex(v) + i);
            if (visited[w] == UNVISITED)
            {
                visited[w] = VISITED;
                printf("\n%d", w);
                enqueue(w);
            }
        }
    }
}

void dfs(int startNode)
{
    int *visited = (int*)malloc(nrOfVertices*sizeof(int));
    int i, v, w;

    for (i = 0; i < nrOfVertices; i++)
        visited[i] = UNVISITED;
    push(startNode);
    while(!isEmptyStack())
    {
        v = peekStack();
        pop();
        if(visited[v] == UNVISITED)
        {
            visited[v] = VISITED;
            for (i = (getNumberOfNeighborsOfVertex(v) - 1); i >= 0; i--)
            {
                w = *(getAllNeighborsOfVertex(v) + i);
                if (visited[w] == UNVISITED)
                    push(w);
            }
            printf("\n%d", v);
        }
    }
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
    int * visited = (int*)malloc(nrOfVertices * sizeof(int));
    int i;
    for(i=0; i<nrOfVertices; i++)
    {
        visited[i]=0;
    }
    dfsRec(startNode,visited);
    printf("\nDFS recursive ended\n\n");
}

int lGetNumberOfNeighborsOfVertex(int v)
{
    int nr;
    NodeT  *aux;

    aux = adjList[v];
    nr = 0;
    while (aux != NULL)
    {
        if (aux->content >= 0)
            nr++;
        aux = aux->next;
    }
    return nr;
}

int * lGetAllNeighborsOfVertex(int v)
{
    int *neighbors, i;
    NodeT  *aux;

    aux = adjList[v];
    neighbors = (int*)malloc(lGetNumberOfNeighborsOfVertex(v)*sizeof(int));
    i = 0;
    while (aux != NULL)
    {
        if (aux->content >= 0)
            *(neighbors + i) = aux->content;
        i++;
        aux = aux->next;
    }
    return neighbors;
}

void lBfs(int startNode)
{
    int *visited = (int*)malloc(nrOfVertices*sizeof(int));
    int i, v, w;

    for (i = 0; i < nrOfVertices; i++)
        visited[i] = UNVISITED;
    visited[startNode] = VISITED;
    printf("\n%d", startNode);
    enqueue(startNode);
    while(!isEmptyQueue())
    {
        v = peekQueue();
        dequeue();
        for (i = 0; i < getNumberOfNeighborsOfVertex(v); i++)
        {
            w = *(getAllNeighborsOfVertex(v) + i);
            if (visited[w] == UNVISITED)
            {
                visited[w] = VISITED;
                printf("\n%d", w);
                enqueue(w);
            }
        }
    }
}

void lDfs(int startNode)
{
    int *visited = (int*)malloc(nrOfVertices*sizeof(int));
    int i, v, w;

    for (i = 0; i < nrOfVertices; i++)
        visited[i] = UNVISITED;
    push(startNode);
    while(!isEmptyStack())
    {
        v = peekStack();
        pop();
        if(visited[v] == UNVISITED)
        {
            visited[v] = VISITED;
            for (i = (getNumberOfNeighborsOfVertex(v) - 1); i >= 0; i--)
            {
                w = *(getAllNeighborsOfVertex(v) + i);
                if (visited[w] == UNVISITED)
                    push(w);
            }
            printf("\n%d", v);
        }
    }
}
