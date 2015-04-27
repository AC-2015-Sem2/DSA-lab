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
  int i,count=0;
  for (i=0;i<nrOfVerteces;i++)
    if (adjMatrix[i][v]==1)
      count++;
  return count;
}

int * getAllNeighborsOfVertex(int v)
{
  int nrOfNeighbours=getNumberOfNeighborsOfVertex(v);
  int *array=(int*)malloc(sizeof(int)*nrOfNeighbours);
  int i,count=0;
  for (i=0;i<nrOfVerteces;i++)
    if (adjMatrix[i][v]==1)
      {
          array[count]=i;
          count++;
      }
     return array;
}

//! traversals

void bfs(int searchNode)
{
  int *mark=(int*)malloc(sizeof(int)*nrOfVerteces);
  int i;
    for (i=0;i<nrOfVerteces;i++)
    {
        mark[i]=UNVISITED;
    }
  mark[searchNode]=VISITED;
  enqueue(searchNode);
  printf("%d ",searchNode);
  while (!isEmptyQueue())
  {
    int v=peekQueue()->content;
    dequeue();
    int nrOfNeighbours=getNumberOfNeighborsOfVertex(v);
    int *neighbours=getAllNeighborsOfVertex(v);
    for (i=0;i<nrOfNeighbours;i++)
    {
        int w=neighbours[i];
        if (mark[w]==UNVISITED)
        {
            enqueue(w);
            mark[w]=VISITED;
            printf("%d ",w);
        }
    }
  }
}

void dfs(int searchNode)
{
  int *mark=(int*)malloc(sizeof(int)*nrOfVerteces);
  int i;
    for (i=0;i<nrOfVerteces;i++)
    {
        mark[i]=UNVISITED;
    }
    push(searchNode);
    while (!isEmptyStack())
    {
        int v=peekStack()->content;
        pop();
        if (mark[v]==UNVISITED)
        {
            mark[v]=VISITED;
            int *neighbours=getAllNeighborsOfVertex(v);
            int nrOfNeighbours=getNumberOfNeighborsOfVertex(v);
            for(i=nrOfNeighbours-1;i>=0;i--)
            {
                push(neighbours[i]);
            }
            printf("%d ",v);
        }
    }
}

void dfsRec(int v, int * mark)
{
   mark[v]=VISITED;
   int nrOfNeighbours=getNumberOfNeighborsOfVertex(v);
   int *neighbours=getAllNeighborsOfVertex(v);
   printf("%d ",v);
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
