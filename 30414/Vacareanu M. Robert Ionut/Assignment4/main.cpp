#include "header.h"
#include "functions.cpp"

using namespace std;



int main()
{
    NodeT* root = NULL;
    root=insertNode(root , 10);
    root=insertNode(root , 15);
    root=insertNode(root , 17);
    root=insertNode(root , 11);
    root=insertNode(root , 110);
    root=insertNode(root , 151);
    root=insertNode(root , 17);
    prettyPrint(root, 0);
    return 0;
}
