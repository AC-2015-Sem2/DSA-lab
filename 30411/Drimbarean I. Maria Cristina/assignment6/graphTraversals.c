#include "graphTraversals.h"
#include "graphRepresentation.h"

void bfs(int startNode)
{
    printf("BFS started\n");
  int *mark=(int*)malloc(sizeof(int)*nrOfVerteces);
  int i;
    for (i=0;i<nrOfVerteces;i++)
    {
        mark[i]=UNVISITED;
    }
  mark[startNode]=VISITED;
  enqueue(startNode);
  printf("%d ",startNode);
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
    printf("\nBFS ended\n\n");
}

void dfs(int startNode)
{
    printf("DFS started\n");
  int *mark=(int*)malloc(sizeof(int)*nrOfVerteces);
  int i;
    for (i=0;i<nrOfVerteces;i++)
    {
        mark[i]=UNVISITED;
    }
    push(startNode);
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
    printf("\nDFS ended\n\n");
}

void dfsRec(int v, int * visited)
{
   visited[v]=VISITED;
   int nrOfNeighbours=getNumberOfNeighborsOfVertex(v);
   int *neighbours=getAllNeighborsOfVertex(v);
   printf("%d ",v);
   int i;
   for (i=0;i<nrOfNeighbours;i++)
   {
       int w=neighbours[i];
       if (visited[w]==UNVISITED)
          dfsRec(w,visited);
   }
}

void dfsRecurs(int startNode)
{
    printf("DFS recursive started\n");
    int *mark=(int*)malloc(sizeof(int)*nrOfVerteces);
    int i;
    for (i=0;i<nrOfVerteces;i++)
    {
        mark[i]=UNVISITED;
    }
    dfsRec(startNode,mark);
    printf("\nDFS recursive ended\n\n");
}
