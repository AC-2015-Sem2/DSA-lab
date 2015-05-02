#include "queue.h"
#include "stack.h"
#include "graph.h"

int main()
{
    /*    atunci cand completati matricea de adiacenta pentru a verifica,
     in loc de 0 pe diagonala principala trebuie sa pus 1
      */
    FILE * f = fopen("matrix.txt","r");
    readFromAdjMatrix(f);
    printAdjMatrix();
    printf("The path between 0 and 2 is: ");
    int s;
    s=dfs(0,2);
    printf("\nThe path between 3 and 6 is: ");
    s=dfs(3,6);
    printf("\nThe path between 7 and 4 is: ");
    s=dfs(7,4);
    printf("\nThe path between 5 and 7 is: ");
    s=dfs(5,7);
    return 0;
}
