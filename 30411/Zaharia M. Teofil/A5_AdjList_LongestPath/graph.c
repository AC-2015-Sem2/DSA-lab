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
    int i, n = 0;
    for (i = 0; i < nrOfVerteces; i++) {
        if (adjMatrix[v][i]) {
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
    for (i = 0; i < nrOfVerteces; i++) {
        if (adjMatrix[v][i]) {
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

    printf("\nBFS on adjLists:\n");
    printf("%d ", startNode);

    enqueue(startNode);

    while (!isEmptyQueue()) {
        first = peekQueue()->content;
        dequeue();

        visited[first] = 1;

        for (i = 0; i < adjListLengths[first]; i++) {
            kNode = adjLists[first][i];
            if (!visited[kNode]) {
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

    printf("\nDFS on adjLists:\n");
    while (!isEmptyStack()) {
        first = peekStack()->content;
        pop();


        for (i = adjListLengths[first]-1; i >=0; i--) {
            kNode = adjLists[first][i];
            if (!visited[kNode]) {
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
    for (i = 0; i < adjListLengths[v]; i++) {
        kNode = adjLists[v][i];
        if (!mark[kNode]) {
            mark[kNode] = 1;
            dfsRec(kNode, mark);
        }
    }
}

void dfsRecurs(int v) {
    int* mark  = (int*) calloc (nrOfVerteces, sizeof(int));

    printf("DFS_REC on adjLists:\n");
    mark[v] = 1;
    dfsRec(v, mark);
    printf("\n");
    free(mark);
}

void createAdjLists (int** adjMatrix) {
    adjListLengths = (int*) malloc(nrOfVerteces * sizeof(int));
    adjLists = (int**) malloc (nrOfVerteces * sizeof(int*));

    int i;
    for (i = 0; i < nrOfVerteces; i++) {
        adjListLengths[i] = getNumberOfNeighborsOfVertex(i);
        adjLists[i] = getAllNeighborsOfVertex(i);
    }
}

void printAdjLists() {
    int i, j;

    printf("Adjacency Lists representation:\n\n");
    for (i = 0; i < nrOfVerteces; i++) {
        printf("%c: ", i+65); //current node
        for (j = 0; j < adjListLengths[i]; j++) {
            printf("%c ", adjLists[i][j] + 65);
        }
        printf("\n");
    }
    printf("\n");
}

int** createAdjMatrixFromLists(int** adjLists, int* adjListLengths) {
    int** newAdjMatr = (int**) malloc (nrOfVerteces * sizeof(int*));

    int i, j;
    for (i = 0; i < nrOfVerteces; i++) {
        newAdjMatr[i] = (int*) calloc (nrOfVerteces, sizeof(int));
        // create as unvisited

        for (j = 0; j < adjListLengths[i]; j++) {
            newAdjMatr[i][adjLists[i][j]] = 1;
            // mark as visited the ones in the
            // corresponding adjList
        }
    }

    return newAdjMatr;
}


// Longest simple path problem
char* longestSimplePathFrom(int startNode, int* len) {
    int* mark  = (int*) calloc (nrOfVerteces, sizeof(int));
    char* c = (char*) malloc (2 * (nrOfVerteces + 1) * sizeof(char));
    c[0] = '\0';

    mark[startNode] = 1;
    int maxLen = dfsRecLen(startNode, mark, &c);
    *len = maxLen;
    free(mark);

    append(&c, startNode); // append first node to path
    return c;
}

void append(char** dest, int src) {
    char toAppend[3];
    toAppend[0] = ' ';
    toAppend[1] = (char)(src + 65);
    toAppend[2] = '\0';

    strcat(*dest, toAppend);
}

int dfsRecLen(int v, int* mark, char** c) {
    int i, kNode, terminalNode = 1, maxLen = 0, len;
    int markedLast;

    for (i = 0; i < adjListLengths[v]; i++) {
        kNode = adjLists[v][i];
        if (!mark[kNode]) {
            mark[kNode] = 1;
            terminalNode = 0;

            len = dfsRecLen(kNode, mark, c) + 1;

            // find the farthest "child"
            // from the start node
            if (len > maxLen) {
                maxLen = len;
                markedLast = kNode;
            }
        }
    }

    if (terminalNode) {
        return 1;
    } else {
        append(c, markedLast);
        return maxLen;
    }
}

char* longestSimplePath() {
    int i, len = 0, maxLen = 0;
    char *longestPath, *path;

    for (i = 0; i < nrOfVerteces; i++) {
        path = longestSimplePathFrom(i, &len);
        if (len > maxLen) {
            maxLen = len;
            longestPath = path;
        }
    }

    return longestPath;
}
