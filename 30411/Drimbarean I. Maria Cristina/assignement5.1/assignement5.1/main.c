#include "queue.h"
#include "stack.h"
#include "graph.h"
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

NodeT *createAdjList(void)
{
    int i,j,k;
    NodeT *adjArray[nrOfVerteces];
    for(i=0; i<=nrOfVerteces; i++)
            adjArray[i] = NULL;
    for(j=0; j<=nrOfVerteces; j++)
            for(k=0; k<=nrOfVerteces; k++)
                    if(adjMatrix[j][k] == 1)
                    AddLast(&adjArray[j],k);
    return adjArray[0];
}
void printAdjList(NodeT *adjList[nrOfVerteces])
{
  int j;
  for(j=0; j<=nrOfVerteces; j++)
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
int main()
{
    FILE * f = fopen("matrix.txt","r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    NodeT *adjList[nrOfVerteces];
    adjList[0]=createAdjList();
    printAdjList(adjList);
    return 0;
}
