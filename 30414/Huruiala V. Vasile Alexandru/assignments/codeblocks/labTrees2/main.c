#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct st_NodeT NodeT;
struct st_NodeT
{
    NodeT* left;
    NodeT* right;

    int data;
};

NodeT* createNodeT(int data)
{
    NodeT* New = (NodeT*)malloc(sizeof(NodeT));
    New->data = data;
    New->left = NULL;
    New->right = NULL;

    return New;
}

int search(NodeT* root, int value)
{
    if(root == NULL)
        return 0;
    else if(root->data == value)
        return 1;
    else if(root->data < value)
        return search(root->right, value);
    else
        return search(root->left, value);
}

NodeT* insert(NodeT* root, int value)
{
    if(root == NULL)
    {
        return createNodeT(value);
    }
    else if(root->data < value)
        root->right = insert(root->right, value);
    else
        root->left = insert(root->left, value);
    return root;
}

void inorderPrint(NodeT* root)
{
    if(root != NULL)
    {
        inorderPrint(root->left);
        printf("%d ", root->data);
        inorderPrint(root->right);
    }
}

int isBSTUtil(NodeT* root, int Min, int Max)
{
    if(root == NULL)
        return 1;
    else if((root->data > Max)||(root->data < Min))
        return 0;
    else
        return isBSTUtil(root->left, Min, root->data) & isBSTUtil(root->right, root->data, Max);
}

int isBST(NodeT* root)
{
    return isBSTUtil(root ,INT_MIN, INT_MAX);
}

int main()
{
    NodeT* root1 = createNodeT(5);
    root1->left = createNodeT(2);
    root1->left->left = createNodeT(1);
    root1->right = createNodeT(9);
    root1->right->left = createNodeT(8);
    root1->right->right = createNodeT(11);

    /**
    int val;
    scanf("%d", &val);
    printf("%d\n", search(root1, val));
    inorderPrint(root1);
    printf("\n");
    **/

    insert(root1, 7);
    inorderPrint(root1);
    printf("\n");

    printf("Is BST: %d", isBST(root1));

    return 0;
}
