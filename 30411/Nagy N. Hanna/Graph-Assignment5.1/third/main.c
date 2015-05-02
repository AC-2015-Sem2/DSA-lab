#include <stdio.h>
#include <stdlib.h>
#include "representation.h"
#include "list.h"
#include "graphAlgorithms.h"


int main()
{
    FILE *pf=fopen("matrix.txt", "r");
    if(pf==NULL)
    { perror("Something went wrong with the opening the file");
      return -1;
    }

    FILE *gg=fopen("adjList.txt","w");
    if(gg==NULL) perror("Something went wrong ");

    readFromAdjMatrix(pf);

    printf("\nThe given Matrix: \n");
    printMatrix(adjMatrix);

    nodeT** adjList=getListfromMatrix(adjMatrix);
    fprintf(gg,"Adjacency List: \n");
    printList(gg,adjList);


    printf("\nThe Matrix obtained from the list : \n");
    int** MatrixfromList=getMatrixfromList(adjList);
    printMatrix(MatrixfromList);


    printf("\n");
    //Traversals
    printf("\nBFS is: ");
    bfs(adjList, 0);
    printf("\nDFS is: ");

    dfs(adjList, 0);
    printf("\nDFS (Recursive): ");

    dfsRecurs(adjList,0);

    fclose(pf);
    return 0;
}
