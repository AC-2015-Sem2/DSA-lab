#include "queue.h"
#include "stack.h"
#include "graph.h"
NodeT* addLast(NodeT *head,int code)
{
    if (head==NULL)
    {
        head=(struct node*)malloc(sizeof(struct node*));
        head->content=code;
        head->next=NULL;
    }
    else
    {
        NodeT *aux=head;
        while (aux->next!=NULL)
            aux=aux->next;
        struct node *p=(struct node*)malloc(sizeof(struct node*));
        p->content=code;
        p->next=NULL;
        aux->next=p;
    }
    return head;
}

NodeT **createAdjList()
{
    int i,j,k;
    NodeT **adjArray;
    adjArray=(NodeT**)malloc(sizeof(NodeT)*nrOfVerteces);
    for(i=0; i<nrOfVerteces; i++)
        adjArray[i] = 0;
    for(j=0; j<nrOfVerteces; j++)
        for(k=0; k<nrOfVerteces; k++)
            if(adjMatrix[j][k] == 1)
                adjArray[j]=addLast(adjArray[j],k);
    return adjArray;
}
void printAdjList(NodeT *adjList[nrOfVerteces])
{
    int j;
    for(j=0; j<nrOfVerteces; j++)
    {
        printf("%d ",j);
        NodeT *node=adjList[j];
        while (node!=NULL)
        {
            printf("%d ",node->content);
            node=node->next;
        }
        printf("\n");
    }
}
void clearmatrix()
{
    int i,j;
    for (i=0; i<nrOfVerteces; i++)
        for (j=0; j<nrOfVerteces; j++)
            adjMatrix[i][j]=0;

}
void createAdjmatrix(NodeT *adjList[nrOfVerteces])
{
    int j;
    for(j=0; j<nrOfVerteces; j++)
    {
        NodeT *node=adjList[j];
        while (node!=NULL)
        {

            adjMatrix[j][node->content]=1;
            node=node->next;
        }
    }
}
int getNumberOfNeighborsOfVertexList(int v,NodeT *adjList[nrOfVerteces])
{
    int ct=0;
    NodeT *node=adjList[v];
    while (node!=NULL)
    {
        ct++;
        node=node->next;
    }
    return ct;
}
int *getAllNeighborsOfVertexList(int v,NodeT *adjList[nrOfVerteces])
{
    int *a=(int*)malloc(sizeof(int)*nrOfVerteces);
    int ct=0;
    NodeT *node=adjList[v];
    while (node!=NULL)
    {
        a[ct]=node->content;
        ct++;
        node=node->next;
    }
    return a;
}
void bfsList(int searchNode,NodeT *adjList[nrOfVerteces])
{
    int mark[nrOfVerteces];
    int i;
    for (i=0; i<nrOfVerteces; i++)
        mark[i]=0;
    mark[searchNode]=1;
    printf("%d ",searchNode);
    enqueue(searchNode);
    while (!isEmptyQueue())
    {
        int v=peekQueue()->content;
        dequeue();
        int ct=getNumberOfNeighborsOfVertexList(v,adjList);
        int *a=getAllNeighborsOfVertexList(v,adjList);
        for (i=0; i<ct; i++)
            if (mark[a[i]]==0)
            {
                mark[a[i]]=1;
                enqueue(a[i]);
                printf("%d ",a[i]);
            }
    }
}
void dfsList(int searchNode,NodeT *adjList[nrOfVerteces])
{
    printf("\n");
    int mark[100];
    int i;
    for (i=0; i<100; i++)
        mark[i]=0;
    push(searchNode);
    while (!isEmptyStack())
    {
        int v=peekStack()->content;
        pop();
        if (mark[v]==0)
        {
            mark[v]=1;
            int ct=getNumberOfNeighborsOfVertexList(v,adjList);
            int *a=getAllNeighborsOfVertexList(v,adjList);
            for (i=ct-1; i>=0; i--)
            {
                if (mark[a[i]]!=1)
                {
                    push(a[i]);
                }
            }
            printf("%d ",v);
        }
    }
}
int main()
{
    FILE * f = fopen("matrix.txt","r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    bfs(0);
    dfs(0);
    dfsRecurs(0);
    printf("\n");
    NodeT **adjList;
    adjList=createAdjList();
    printAdjList(adjList);
    clearmatrix();
    createAdjmatrix(adjList);
    printAdjMatrix();
    printf("\n");
    bfsList(0,adjList);
    dfsList(0,adjList);
    return 0;
}
