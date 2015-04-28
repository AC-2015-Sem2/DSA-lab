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
}

int getNumberOfNeighborsOfVertex(int v)
{
    int t=0;
    int j=0;
for (j=0;j<nrOfVerteces;j++)
    if (adjMatrix[v][j]==1) t++;
return t;
}

int * getAllNeighborsOfVertex(int v)
{
    int i=0;
    int t=0;
    int *aux=(int *)malloc(getNumberOfNeighborsOfVertex(v)*sizeof(int));
for (i=0;i<nrOfVerteces;i++)
if (adjMatrix[v][i]==1)  {
aux[t]=i;
t++;
}
return aux;
}

//! traversals

void bfs(int searchNode)
{
int* visited=(int*)malloc(nrOfVerteces*sizeof(int));
int i;
int v;
int n;
int w;
for (i=0;i<nrOfVerteces;i++)
    visited[i]=UNVISITED;
visited[searchNode]=VISITED;
enqueue(searchNode);
printf("%d ",searchNode);
while (!isEmptyQueue())
    {
    v=peekQueue()->content;
    dequeue();
    int* aux=(int*) malloc(getNumberOfNeighborsOfVertex(v)*sizeof(int));
    aux=getAllNeighborsOfVertex(v);
    n=getNumberOfNeighborsOfVertex(v);
    for (w=0;w<n;w++)
        {
        if (visited[aux[w]]==UNVISITED){
            visited[aux[w]]=VISITED;
            enqueue(aux[w]);
            printf(" %d",aux[w]);
            }
        }
    }
}


void dfs(int searchNode)
{
    int i;
    int v;
    int w;
    //int *aux;

int *visited=(int*)malloc(nrOfVerteces*sizeof(int));
for (i=0;i<nrOfVerteces;i++)
    visited[i]=UNVISITED;
push(searchNode);
//visited[searchNode]=VISITED;
while (! isEmptyStack()){
    v=peekStack()->content;
    pop();
    int *aux=(int*) malloc(getNumberOfNeighborsOfVertex(v)*sizeof(int));
    aux=getAllNeighborsOfVertex(v);
    if (visited[v]==UNVISITED){
            visited[v]=VISITED;
            for (w=getNumberOfNeighborsOfVertex(v)-1;w>=0;w--)
            if (visited[aux[w]]==UNVISITED)
            push(aux[w]);
    printf(" %d",v);
    }
}
}

void dfsRec(int v, int * mark)
{

}

void dfsRecurs(int v){

}
