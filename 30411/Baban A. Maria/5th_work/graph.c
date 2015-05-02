#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void printAdjMatrix(int** adjMatrix)
{
    int i,j;

    printf("\nmatrix\n");
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
    int i, n = 0;
    for (i = 0; i < nrOfVerteces; i++)
    {
        if (adjMatrix[v][i])
        {
            n++;
        }
    }
    return n;
}

int * getAllNeighborsOfVertex(int v)
{
    int n  = getNumberOfNeighborsOfVertex(v);
    int* nbs = (int*) malloc (n * sizeof(int));

    int i, it = 0;
    for (i = 0; i < nrOfVerteces; i++)
    {
        if (adjMatrix[v][i])
        {
            nbs[it++] = i;
        }
    }

    return nbs;
}

//! traversals

void bfs(int startNode)
{
    int i, first, kNode;
    int* visited = (int*) calloc(nrOfVerteces, sizeof(int));

    printf("\nbfs on adjList\n");
    printf("%d ", startNode);

    enqueue(startNode);

    while (!isEmptyQueue())
    {
        first = peekQueue()->content;
        dequeue();

        visited[first] = 1;

        for (i = 0; i < adjListlength[first]; i++)
        {
            kNode = adjList[first][i];
            if (!visited[kNode])
            {
                visited[kNode] = 1;
                enqueue(kNode);
                printf("%d ", kNode);
            }
        }
    }

    printf("\n");
    free(visited);
}

void dfs(int startNode)
{
    int i, first, kNode;
    int* visited = (int*) calloc(nrOfVerteces, sizeof(int));


    push(startNode);
    visited[startNode] = 1;

    printf("\ndfs on adjList\n");
    while (!isEmptyStack())
    {
        first = peekStack()->content;
        pop();


        for (i = adjListlength[first]-1; i >=0; i--)
        {
            kNode = adjList[first][i];
            if (!visited[kNode])
            {
                visited[kNode] = 1;
                push(kNode);
            }
        }
        printf("%d ", first);
    }
    printf("\n");
    free(visited);
}

void dfsRec(int v, int * mark)
{
    int i, kNode;
    printf("%d ", v);
    for (i = 0; i < adjListlength[v]; i++)
    {
        kNode = adjList[v][i];
        if (!mark[kNode])
        {
            mark[kNode] = 1;
            dfsRec(kNode, mark);
        }
    }
}

void dfsRecurs(int v)
{
    int* mark  = (int*) calloc (nrOfVerteces, sizeof(int));

    printf("\ndfsRecurs on adjList\n");
    mark[v] = 1;
    dfsRec(v, mark);
    printf("\n");
    free(mark);
}

void createAdjList(int** adjMatrix)
{
    adjListlength = (int*) malloc(nrOfVerteces * sizeof(int));
    adjList = (int**) malloc (nrOfVerteces * sizeof(int*));

    int i;
    for (i = 0; i < nrOfVerteces; i++)
    {
        adjListlength[i] = getNumberOfNeighborsOfVertex(i);
        adjList[i] = getAllNeighborsOfVertex(i);
    }
}

void printAdjList()
{
    int i, j;

    printf("\nadjList\n");
    for (i = 0; i < nrOfVerteces; i++)
    {
        printf("%c: ", i+65);
        for (j = 0; j < adjListlength[i]; j++)
        {
            printf("%c ", adjList[i][j] + 65);
        }
        printf("\n");
    }
    printf("\n");
}

int** list2matrix(int** adjList, int* adjListlength)
{
    int** newAdjMatr = (int**) malloc (nrOfVerteces * sizeof(int*));

    int i, j;
    for (i = 0; i < nrOfVerteces; i++)
    {
        newAdjMatr[i] = (int*) calloc (nrOfVerteces, sizeof(int));
        for (j = 0; j < adjListlength[i]; j++)
        {
            newAdjMatr[i][adjList[i][j]] = 1;
        }
    }
    return newAdjMatr;
}

void add(char** dest, int src)
{
    char toAdd[3];
    toAdd[0] = ' ';
    toAdd[1] = (char)(src + 65);
    toAdd[2] = '\0';

    strcat(*dest, toAdd);
}

int dfsRecLen(int v, int* mark, char** c)
{
    int i, kNode, terminalNode = 1, maxLen = 0, len;
    int markedLast;

    for (i = 0; i < adjListlength[v]; i++)
    {
        kNode = adjList[v][i];
        if (!mark[kNode])
        {
            mark[kNode] = 1;
            terminalNode = 0;

            len = dfsRecLen(kNode, mark, c) + 1;
            if (len > maxLen)
            {
                maxLen = len;
                markedLast = kNode;
            }
        }
    }

    if (terminalNode)
    {
        return 1;
    }
    else
    {
        add(c, markedLast);
        return maxLen;
    }
}

