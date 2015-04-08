#include <stdio.h>
#include <stdlib.h>

#define setHeight(node) (node->height = 1 + max(node->left->height, node->right->height))
//I tried doing this inside a function but I just couldn't get it to work properly.


typedef struct nodeT{
    int data;
    int height;
    struct nodeT *left;
    struct nodeT *right;
}nodeT;

nodeT *root, *NIL; //NIL is an "empty" node that we use instead of NULL in order to have the height of "null" children equal to 0

int max(int a, int b)
{
    return ( (a > b) ? a : b);
}

nodeT* allocNode()
{
    return (nodeT*)malloc(sizeof(nodeT));
}

nodeT* createNode(int data)
{
    nodeT* newNode = allocNode();

    newNode->data = data;
    newNode->height = 1;
    newNode->left = NIL;
    newNode->right = NIL;

    return newNode;
}

void initTree()
{
    root = NIL = allocNode();
    NIL->data = 0;
    NIL->height = 0;
    NIL->left = NULL;
    NIL->right = NULL;
}

nodeT* rotateLeft(nodeT* node)
{

    /*
    The digits are not the data stored in the nodes, they're names(id's, etc).

        1                  2
       /                    \
      2          =>          1
       \                    /
        3                  3

    */
    nodeT* newNode = node->left;

    node->left = newNode->right;
    newNode->right = node;

    setHeight(node);
    setHeight(newNode);

    return newNode;
}

nodeT* rotateRight(nodeT* node)
{

    /*
    The digits are not the data stored in the nodes, they're names(id's, etc).

      1                  2
       \                /
        2      =>      1
       /                \
      3                  3

    */
    nodeT* newNode = node->right;

    node->right = newNode->left;
    newNode->left = node;

    setHeight(node);
    setHeight(newNode);

    return newNode;
}

nodeT* balanceNode(nodeT *node)
{
    setHeight(node);

    int balanceFactor = node->left->height - node->right->height;

    if(balanceFactor > 1)
    {
        //Left subtree is larger than the right one

        if(node->left->right->height > node->left->left->height)
            node->left = rotateRight(node->left);
        node = rotateLeft(node);

        /*
        The digits are not the data stored in the nodes, they're names(id's, etc).
        (In the case where there needs to be another rotation of the subtree(the if condition))
            1              1            5
           / \            / \          / \
          3   2          5   2        3   1
         / \     =>     / \     =>   /   / \
        4   5          3   6        4   6   2
             \        /
              6      4

        (hopefully I didn't get this wrong, all this rotating is making my head spin)
        */

    }
    else if(balanceFactor < -1)
    {
        //Right subtree is larger than the left one

        if(node->right->left->height > node->right->right->height)
            node->right = rotateLeft(node->right);
        node = rotateRight(node);

        /*
        The digits are not the data stored in the nodes, they're names(id's, etc).

            1            1                5
           / \          / \              / \
          2   3        2   5            1   3
             / \  =>      / \    =>    / \   \
            5   4        6   3        2   6   4
           /                  \
          6                    4

        */
    }

    return node;
}

nodeT* insert(nodeT *root, int data)
{
    if(root == NIL)
    {
        root = createNode(data);
        return root;
    }
    if(data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return balanceNode(root);

}

void prettyPrint(nodeT *root,int recLevel)
{
    if(root==NULL)
    {
        recLevel--;
        return;
    }
    recLevel++;
    prettyPrint(root->right,recLevel);
    int j=0;

    for(j=0; j<recLevel-1; j++)
    {
        printf("   ");
    }

    if(root->data != 0)
        printf("%d", root->data);

    printf("\n");
    prettyPrint(root->left,recLevel);
}

int main()
{
    initTree();

    FILE *f = fopen("input.dat", "r");
    int aux;

    while(fscanf(f, "%d", &aux) > 0)
        root = insert(root, aux);

    prettyPrint(root, 0);

    return 0;
}
