#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "stack.h"
#include "queue.h"
#include "myHW.h"

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
    int n = 0;
    for (int i = 0; i < nrOfVerteces; i++)
        if (adjMatrix[v][i] == 1)
            n++;
    return n;
}

int * getAllNeighborsOfVertex(int v)
{
    int n = getNumberOfNeighborsOfVertex(v);
    int* neighbors = (int*)malloc((n + 1)*sizeof(int));
    int k = 0;
    for (int i = 0; i < nrOfVerteces; i++)
        if (adjMatrix[v][i] == 1) {
            neighbors[k] = i;
            k++;
        }
    return neighbors;
}

//! traversals

void bfs(int searchNode) {
    /*
    allocate "mark" vector
    fill with UNVISITED
    mark[startNode] = VISITED
    print startNode
    enqueue(startNode)
    while(!isEmptyQueue())
        v = peekQueue()->content;
        dequeue();
        for all neihbors w of v
            if (mark[w] == UNVISITED) {
                mark[w] = VISITED;
                enqueue(w);
                printf w;
            }
    */
    int* mark = (int*)malloc(nrOfVerteces*sizeof(int));
    for (int i = 0; i < nrOfVerteces; i++)
        mark[i] = UNVISITED;
    mark[searchNode] = VISITED;
    printf("%d ", searchNode);
    enqueue(searchNode);
    while (!isEmptyQueue()) {
        int v = peekQueue()->content;
        dequeue();
        int* w = LISTgetAllNeighborsOfVertex(v);
        int n = LISTgetNumberOfNeighborsOfVertex(v);
        for (int i = 0; i < n; i++)
            if (mark[w[i]] == UNVISITED) {
                mark[w[i]] = VISITED;
                enqueue(w[i]);
                printf("%d ", w[i]);
            }
        free(w);
    }
}

void dfs(int searchNode) {
    /*
    allocate and fill mark vector
    push(searchNode)
    while(!isEmptyStack()) {
        v = peekStack()->content;
        pop();
        if mark[v] == UNVISITED {
            mark[v] = visited
            for each neighbor w of v
                push w
            print v
    }
    */
    int* mark = (int*)malloc(nrOfVerteces*sizeof(int));
    for (int i = 0; i < nrOfVerteces; i++)
        mark[i] = UNVISITED;
    push(searchNode);
    while (!isEmptyStack()) {
        int v = peekStack()->content;
        pop();
        if (mark[v] == UNVISITED) {
            mark[v] = VISITED;
            int* w = LISTgetAllNeighborsOfVertex(v);
            int n = LISTgetNumberOfNeighborsOfVertex(v);
            for (int i = n - 1; i >= 0; i--)
                push(w[i]);
            free(w);
            printf("%d ", v);
        }
    }
}

void dfsRec(int v, int * mark) {
    int* w = LISTgetAllNeighborsOfVertex(v);
    int n = LISTgetNumberOfNeighborsOfVertex(v);
    if (w != NULL) {
        for (int i = 0; i < n; i++) {
            if (mark[w[i]] == UNVISITED) {
                printf("%d ", w[i]);
                mark[w[i]] = VISITED;
                dfsRec(w[i], mark);
            }
        }
    }
}

void dfsRecurs(int v) {
    int* mark = (int*)malloc(nrOfVerteces*sizeof(int));
    for (int i = 0; i < nrOfVerteces; i++)
        mark[i] = UNVISITED;
    printf("%d ", v);
    mark[v] = VISITED;
    dfsRec(v, mark);
}