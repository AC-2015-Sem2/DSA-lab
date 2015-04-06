#include "header.h"
#include "functions.cpp"


using namespace std;



int main()
{
    NodeT* root = NULL;
    root=insertNode(root, 5);
    root=insertNode(root, 7);
    root=insertNode(root, 10);
    root=insertNode(root, 8);
    root=insertNode(root, 3);
    root=insertNode(root, 1);
    root=insertNode(root, 6);
    root=insertNode(root, 4);
    prettyPrint(root, 0);
    printf("\n\n\n\n\n");
    root=deleteNode(root, 5);
    prettyPrint(root, 0);

    return 0;
}
