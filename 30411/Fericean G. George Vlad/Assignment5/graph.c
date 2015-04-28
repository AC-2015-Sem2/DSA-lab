#include "graph.h"
#include "queue.h"
#include "matrix.h"
#include "stack.h"

int getNumberOfNeighborsOfVertex(int v, NodeT** adjList)
{
    int n=0;
    NodeT* aux=adjList[v]->next;
    while(aux!=NULL)
    {
        n++;
        aux=aux->next;
    }
    return n;
}

int *getAllNeighborsOfVertex(int v, NodeT** adjList)
{
    int n=getNumberOfNeighborsOfVertex(v, adjList);
    int* a=(int*)malloc(n*sizeof(int));
    int i=0;
    NodeT* aux=adjList[v]->next;
    while(aux!=NULL)
    {
        a[i]=aux->data;
        i++;
        aux=aux->next;
    }
    return a;
}

void bfs(NodeT** adjList, int searchNode)
{
    int *Visited, *neighbors;
    NodeT *V;
    int i,nr,w;

    Visited = (int *)calloc(nrOfVerteces, sizeof(int));
    Visited[searchNode]=1;
    printf("%c, ", searchNode+65);
    enqueue(searchNode);
    while (!isEmptyQueue())
    {
        V=peekQueue();
        dequeue();
        neighbors=getAllNeighborsOfVertex(V->data, adjList);
        nr=getNumberOfNeighborsOfVertex(V->data, adjList);
        for (i=0; i<nr; i++)
        {
            w=neighbors[i];
            if (Visited[w]==0)
            {
                enqueue(w);
                Visited[w]=1;
                printf("%c, ",w+65);
            }
        }
    }
}

void dfs(NodeT** adjList, int searchNode)
{
    int *Visited, *neighbors;
    //NodeT *V;
    int i,nr,w, v;

    Visited = (int *)calloc(nrOfVerteces, sizeof(int));
    push(searchNode);
    while(!isEmptyStack())
    {
        v=peekStack()->data;
        pop();
        if(Visited[v]==0)
        {
            Visited[v]=1;
            neighbors=getAllNeighborsOfVertex(v, adjList);
            nr=getNumberOfNeighborsOfVertex(v, adjList);
            for(i=0; i<nr; i++)
            {
                w=neighbors[i];
                if(Visited[w]==0)
                    push(w);
            }
            printf("%c, ", v+65);
        }

    }
}

void dfsRec(int v, int * mark, NodeT** adjList)
{
    //int* Visited = (int *)calloc(nrOfVerteces, sizeof(int));
    mark[v]=1;
    int nr=getNumberOfNeighborsOfVertex(v, adjList);
    int *neighbors=getAllNeighborsOfVertex(v, adjList);
    printf("%c, ", v+65);
    int i;
    for(i=0; i<nr; i++)
        {
            int w=neighbors[i];
            if(mark[w]==0)
                dfsRec(w, mark, adjList);
        }

}

void dfsRecurs(int v, NodeT** adjList)
{
    int* mark = (int *)calloc(nrOfVerteces, sizeof(int));
    dfsRec(v, mark, adjList);
}
