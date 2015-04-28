#include "graphRepresentation.h"
#include "graphTraversals.h"
#include "graphAlgorithms.h"

int main()
{
    NodeT **fromMatrixtoList(int **adjMatrix)
    {
        int i, j;

        NodeT **adjList;
        NodeT *aux;

        adjList = (NodeT**)calloc(nrOfVerteces, sizeof(NodeT*));

        for (i=0; i<nrOfVerteces; i++)
        {
            adjList[i]=(NodeT*)calloc(nrOfVerteces, sizeof(NodeT));
            adjList[i]->content=i;
            aux=adjList[i];
            for (j=0; j<nrOfVerteces; j++)
            {
                if (adjMatrix[i][j] == VISITED)
                {
                    aux->next = createNode(j);
                    aux=aux->next;
                }
            }
        }
        return(adjList);}

        int **fromListtoMatrix(NodeT **adjlist) //from adjacency List to adjacenc Matrix
        {
            int i;
            NodeT *aux;
            int **matrix;

            matrix = (int **)calloc(nrOfVerteces, sizeof(int*));
            for (i=0; i<nrOfVerteces; i++)
            {
                matrix[i]=(int *)calloc(nrOfVerteces, sizeof(int));
            }
            aux = (NodeT *)calloc(1, sizeof(NodeT));

            for (i=0; i<nrOfVerteces; i++)
            {
                aux=adjlist[i];
                aux=aux->next;
                while (aux != NULL)
                {
                    matrix[i][aux->content] = 1;
                    aux= aux->next;
                }
            }
            return(matrix);
        }
        void printAdjList(NodeT **adjList)

        {
               int i;
               NodeT *aux;
               aux = (NodeT *)calloc(1,sizeof(NodeT));
               for (i=0; i<nrOfVerteces; i++)
                  {
                      printf("Node %d has the the following adjacent nodes : ", i);
                      aux=adjList[i];
                      aux=aux->next;
                      while (aux != NULL)
                         {
                              printf("%d ", aux->content);
                              aux=aux->next;

                }
                       printf("\n");
            }
        }

        FILE * f = fopen("matrix.txt","r");
        NodeT **adjacencyList;
       int **adjacencyMatrix;


        readFromAdjMatrix(f);
        printAdjMatrix();
        bfs(0);
        dfs(0);
        dfsRecurs(0);
        prim(0);
        kruskal();
        dijkstra(0);
        adjacencyList = fromMatrixtoList(adjMatrix);
   printf("The adjacency List is : \n");
     printAdjList(adjacencyList);
  adjacencyMatrix=fromListtoMatrix(adjacencyList);
  adjMatrix=adjacencyMatrix;


        return 0;
    }
