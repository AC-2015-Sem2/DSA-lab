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
    printf("\n");
}

int getNumberOfNeighborsOfVertex(int v)
{
    if(v<nrOfVerteces)
    {
        int nrOfNeighbors=0;
        int i;
        for(i=0; i< nrOfVerteces; i++)
        {
            if(adjMatrix[v][i]>0 && i!=v)
            {
                nrOfNeighbors++;
            }
        }
        return nrOfNeighbors;
    }
    else
    {
        return 0;
    }
}

int getNumberOfNeighborsOfVertex_List(int v)
{
    NodeT* aux;
    aux=adjList[v];
    if(v<nrOfVerteces)
    {
        int nrOfNeighbors=0;
        while (aux!=NULL)
        {
            nrOfNeighbors++;
            aux=aux->next;
        }

        return nrOfNeighbors;
    }
    else
    {
        return 0;
    }
}

int * getAllNeighborsOfVertex(int v)
{
    if(v<nrOfVerteces)
    {
        int nrOfNeighbors = getNumberOfNeighborsOfVertex(v);
        int * neighbors = (int*)malloc(sizeof(int) * nrOfNeighbors);
        int i,j=0;
        for(i=0; i<nrOfVerteces; i++)
        {
            if(adjMatrix[v][i]>0 && i!=v)
            {
                neighbors[j]=i;
                j++;
            }
        }
        return neighbors;
    }
    else
    {
        return NULL;
    }
}

int * getAllNeighborsOfVertex_List(int v)
{
    if (adjList[v]==NULL)
        return NULL;
    else
    {
        int n = getNumberOfNeighborsOfVertex_List(v);
        int * neighbors = (int*)malloc(sizeof(int) * n);
        int i=0;
        NodeT* aux = adjList[v];
        while (aux!=NULL)
        {
            neighbors[i]=aux->content;
            i++;
            aux=aux->next;
        }
        return neighbors;
    }
}

//! traversals

void bfs(int searchNode)
{
    printf("BFS started\n");
    int * mark = (int*)malloc(nrOfVerteces * sizeof(int));
    int i, v, w;

    for(i=0; i < nrOfVerteces; i++)
    {
        mark[i]=UNVISITED;
    }

    mark[searchNode] = VISITED;
    printf("%d ", searchNode);
    enqueue(searchNode);

    while(!isEmptyQueue())
    {
        v = peekQueue()->content;
        dequeue();
        int nrOfNeighbors = getNumberOfNeighborsOfVertex(v);
        int * neighbors = getAllNeighborsOfVertex(v);
        for(i=0; i<nrOfNeighbors; i++)
        {
            w = neighbors[i];
            if(mark[w] == UNVISITED)
            {
                printf("%d ", w);
                enqueue(w);
                mark[w] = VISITED;
            }
        }
    }
    printf("\nBFS ended\n\n");
}

void dfs(int searchNode)
{
    printf("DFS started\n");
    int * mark = (int*)malloc(nrOfVerteces * sizeof(int));
    int i, v;

    for(i=0; i < nrOfVerteces; i++)
    {
        mark[i]=UNVISITED;
    }

    push(searchNode);

    while(!isEmptyStack())
    {
        v = peekStack()->content;
        pop();

        if(mark[v] == UNVISITED)
        {
            mark[v] = VISITED;
            int nrOfNeighbors = getNumberOfNeighborsOfVertex(v);
            int * neighbors = getAllNeighborsOfVertex(v);
            for(i=nrOfNeighbors-1; i>=0; i--)
            {
                int w = neighbors[i];
                if(mark[w] == UNVISITED)
                {
                    push(w);
                }
            }
            printf("%d ",v);
        }

    }
    printf("\nDFS ended\n\n");
}

void dfsRec(int v, int * mark)
{
    int i;
    mark[v] = VISITED;
    int nrOfNeighbors = getNumberOfNeighborsOfVertex(v);
    int * neighbors = getAllNeighborsOfVertex(v);
    printf("%d ",v);
    for(i=0; i<nrOfNeighbors; i++)
    {
        int w = neighbors[i];
        if(mark[w]==UNVISITED)
        {
            dfsRec(w, mark);
        }
    }
}

void dfsRecurs(int v)
{
    printf("DFS recursive started\n");
    int * mark = (int*)malloc(nrOfVerteces * sizeof(int));
    int i;
    for(i=0; i<nrOfVerteces; i++)
    {
        mark[i]=0;
    }
    dfsRec(0,mark);
    printf("\nDFS recursive ended\n\n");
}

void  adjMatrix_list()
{
    printf("Transforming Matrix to List...\n");
    adjList=(NodeT**)malloc(nrOfVerteces*sizeof(NodeT*)); // Allocating vector with vertices

    int i,j;
    for (i=0;i<nrOfVerteces;i++)  // Initializing vector
    {
        for (j=0;j<nrOfVerteces;j++)  // Checking neighbors and adding them to the list
        {
            if (adjMatrix[i][j]==1)
                AL(&adjList[i],j);
        }
    }
}

void  adjList_Matrix()
{
    printf("Transforming List to Matrix...\n");

    int i,j,n;
    n = nrOfVerteces;
    NodeT* aux = (NodeT*) malloc(sizeof(NodeT*));

    adjMatrix=(int**)malloc(n*sizeof(int*));  // If it is not yet allocated...
    for (i=0; i<n; i++)
    {
        *(adjMatrix+i)=(int*)malloc(n*sizeof(int));
    }

    for (i=0; i<n; i++)  // DELETING adjMatrix  -- Just to make sure it works
    {
        aux=adjList[i];
        for (j=0; j<n; j++)
            adjMatrix[i][j]=0;
    }
    for (i=0; i<n; i++)
    {
        aux=adjList[i];
        while (aux!=NULL)
        {
            adjMatrix[i][aux->content]=1;
            aux=aux->next;
        }
    }
}

void  printAdjList()
{
    int i;
    NodeT* aux;
    printf("\nThe list is:\n");
    for (i=0; i<nrOfVerteces;i++)
    {
        printf("%c: ",65+i);
        aux=adjList[i];
        while (aux!=NULL)
        {
            printf("%c", 65+(aux->content));
            aux=aux->next;
            if (aux!=NULL)
                printf(", ");
            else
                printf(";    ");
        }
    }
    printf("\n\n");
}

void  bfsList(int searchNode)
{
    printf("BFSList started\n");
    int * mark = (int*)malloc(nrOfVerteces * sizeof(int));
    int i, v, w;

    for(i=0; i < nrOfVerteces; i++)
    {
        mark[i]=UNVISITED;
    }

    mark[searchNode] = VISITED;
    printf("%d ", searchNode);
    enqueue(searchNode);

    while(!isEmptyQueue())
    {
        v = peekQueue()->content;
        dequeue();
        int nrOfNeighbors = getNumberOfNeighborsOfVertex_List(v);
        int * neighbors = getAllNeighborsOfVertex_List(v);
        for(i=0; i<nrOfNeighbors; i++)
        {
            w = neighbors[i];
            if(mark[w] == UNVISITED)
            {
                printf("%d ", w);
                enqueue(w);
                mark[w] = VISITED;
            }
        }
    }
    printf("\nBFSList ended\n\n");
}

void  dfsList(int searchNode)
{
    printf("DFSList started\n");
    int * mark = (int*)malloc(nrOfVerteces * sizeof(int));
    int i, v;

    for(i=0; i < nrOfVerteces; i++)
    {
        mark[i]=UNVISITED;
    }

    push(searchNode);

    while(!isEmptyStack())
    {
        v = peekStack()->content;
        pop();

        if(mark[v] == UNVISITED)
        {
            mark[v] = VISITED;
            int nrOfNeighbors = getNumberOfNeighborsOfVertex_List(v);
            int * neighbors = getAllNeighborsOfVertex_List(v);
            for(i=nrOfNeighbors-1; i>=0; i--)
            {
                int w = neighbors[i];
                if(mark[w] == UNVISITED)
                {
                    push(w);
                }
            }
            printf("%d ",v);
        }

    }
    printf("\nDFSList ended\n\n");
}
