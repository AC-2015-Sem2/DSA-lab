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

void printNEWAdjMatrix()
{
    int i,j;

    printf("\nThe NEW matrix is:\n");
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
            printf("%3d ",adjMatrix2[i][j]);
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
            int nrOfNeighbors = getNumberOfNeighborsOfVertex1(v);
            int * neighbors = getAllNeighborsOfVertex1(v);
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

NodeT* MatrixToList(int** adjMatrix)
{
    int i,j;
    for(i=0; i<nrOfVerteces; i++)
    {
        printf("%d:",i);
        for(j=0; j<nrOfVerteces; j++)
        {
            if(adjMatrix[i][j]==1)
            {
                AddLast(j);
                printf("%d ",j);
            }
        }
        AddLast(-1);//! adding to the list -1 to mark the end of a line in the adjMatrix
        printf("\n");
    }
    return L;
}

int getNumberOfNeighborsOfVertex1(int v)
{
    int counter=0, serialofvertex=0;
    NodeT *aux=L;
    while(aux!=NULL)
    {
        if(serialofvertex==v) counter++;

        if(aux->content==-1)
        {
            serialofvertex++;aux=aux->next;
        }
        else
        {
            aux=aux->next;
        }
    }
return counter;
}

int getAllNeighborsOfVertex1(int v)
{
    int count=0, serialofvertex=0;
    int x=getNumberOfNeighborsOfVertex(v);
    int * neighbors = (int*)malloc(sizeof(int)*x);
    NodeT *aux=L;
    while(aux!=NULL)
    {
        if(serialofvertex==v) {neighbors[count]=aux->content;count++;}

        if(aux->content==-1)
        {
            serialofvertex++;aux=aux->next;
        }
        else
        {
            aux=aux->next;
        }
    }
return neighbors;
}

void ListToMatrix(NodeT *L,FILE *f)
{
    int n;
    f=fopen("matrix.txt","r");
    fscanf(f,"%d",&n);
    int i=0,j=0;
    NodeT* aux;
    aux=L;
    adjMatrix2=(int**)malloc(n*sizeof(int*));
    for (i=0; i<n; i++)
    {
        *(adjMatrix2+i)=(int*)malloc(n*sizeof(int));
    }

    for(i=0; i<n;i++)
    {
        for(j=0; j<n; j++)
        {
            adjMatrix2[i][j]=0;
        }
    }//! the new adjacency matrix is allocated and filled with 0

    if(L==NULL)
    {
        printf("NO LIST");
        return;
    }

    i=0;
    while(aux!=NULL)//!the next step is to put 1 in every row where we have adjacency
    {
        if(aux->content!=-1)
        {
            adjMatrix2[i][aux->content]=1;
            aux=aux->next;
        }
        else
        {
            i++;
            aux=aux->next;
        }
    }
}
