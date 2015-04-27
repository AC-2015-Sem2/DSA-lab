#include "queue.h"
#include "stack.h"
#include "graph.h"
#include "list.h"
int **AdjMatrix1;
void AddLast (NodeT** head, int x)
{
    if (*head==NULL)
    {
        *head = (NodeT*)malloc(sizeof(NodeT));
        (*head)->content = x;
        (*head)->next = NULL;
    }
    else
    {
        NodeT* last = *head;
        while (last->next!=NULL)
        {
            last = last->next;
        }
        NodeT* node = (NodeT*)malloc(sizeof(NodeT));
        node->content = x;
        node->next = NULL;
        last->next = node;
    }
}

NodeT **createAdjList(void)
{
    int i,j,k;
    NodeT **adjArray;
    adjArray=(NodeT**)malloc(sizeof(NodeT)*nrOfVerteces);
    for(i=0; i<nrOfVerteces; i++)
            adjArray[i] = 0;
    for(j=0; j<nrOfVerteces; j++)
            for(k=0; k<nrOfVerteces; k++)
                    if(adjMatrix[j][k] == 1)
                        AddLast(&adjArray[j],k);
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
void returnAdjMatrix()
{
    int i,j;
    AdjMatrix1=(int**)malloc(nrOfVerteces*sizeof(int*));
    for (i=0; i<nrOfVerteces; i++)
    {
        *(AdjMatrix1+i)=(int*)malloc(nrOfVerteces*sizeof(int));
    }

    for (i=0; i<nrOfVerteces; i++)
        for (j=0; j<nrOfVerteces; j++)
            AdjMatrix1[i][j]=0;
    for(j=0; j<nrOfVerteces; j++)
    {
        NodeT *node=adjList[j];
        while (node!=NULL)
        {

            AdjMatrix1[j][node->content]=1;
            node=node->next;
        }
    }
}
void printAdjMatrix1()
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
            printf("%3d ",AdjMatrix1[i][j]);
        printf("\n");
    }
}
int main()
{
    FILE * f = fopen("matrix.txt","r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    adjList=createAdjList();
    printAdjList(adjList);
    bfsList(0);
    printf("\n");
    dfsList(0);
    printf("\n");
    dfsRecursList(0);
    returnAdjMatrix();
    printAdjMatrix1();
    return 0;
}
