#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "graph.h"
#include "stack.h"
#include "queue.h"
#include "list.h"
//! representation

int getNumberOfNeighborsOfVertexList(int v)
{
    int count=0;
  NodeT *aux;
  aux=adjList[v];
  while (aux!=NULL)
    {
         count++;
         aux=aux->next;
    }
  return count;
}

int * getAllNeighborsOfVertexList(int v)
{
  int *array=(int*)malloc(sizeof(int)*nrOfVerteces);
  int count=0;
  NodeT *aux;
  aux=adjList[v];
    while (aux!=NULL)
      {
          array[count]=aux->content;
          count++;
          aux=aux->next;      }
     return array;
}

//! traversals

void bfsList(int searchNode)
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
    int nrOfNeighbours=getNumberOfNeighborsOfVertexList(v);
    int *neighbours=getAllNeighborsOfVertexList(v);
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

void dfsList(int searchNode)
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
            int *neighbours=getAllNeighborsOfVertexList(v);
            int nrOfNeighbours=getNumberOfNeighborsOfVertexList(v);
            for(i=nrOfNeighbours-1;i>=0;i--)
            {
                push(neighbours[i]);
            }
            printf("%d ",v);
        }
    }
}

void dfsRecList(int v, int * mark)
{
   mark[v]=VISITED;
   int nrOfNeighbours=getNumberOfNeighborsOfVertexList(v);
   int *neighbours=getAllNeighborsOfVertexList(v);
   printf("%d ",v);
   int i;
   for (i=0;i<nrOfNeighbours;i++)
   {
       int w=neighbours[i];
       if (mark[w]==UNVISITED)
          dfsRecList(w,mark);
   }
}

void dfsRecursList(int v)
{
    int *mark=(int*)malloc(sizeof(int)*nrOfVerteces);
    int i;
    for (i=0;i<nrOfVerteces;i++)
    {
        mark[i]=UNVISITED;
    }
    dfsRecList(v,mark);
}
