#include "header.h"
#include "functions.cpp"

using namespace std;



int main()
{
    NodeT* root = NULL;
    for(int i=0; i<50; i++){
        root=insertNode(root, i);
    }
    prettyPrint(root, 0);
    return 0;
}
