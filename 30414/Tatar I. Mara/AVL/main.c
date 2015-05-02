#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node
{   int key;
    struct node *left;
    struct node *right;
    int height;
} NodeT;

int height(NodeT *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b)? a : b;
}

NodeT* newNode(int key)
{
    NodeT* nodNou = (NodeT*)malloc(sizeof(NodeT));
    nodNou->key   = key;
    nodNou->left   = NULL;
    nodNou->right  = NULL;
    nodNou->height = 1;
    return(nodNou);
}
// function to right rotate subtree rooted with y
// See the diagram given above.
NodeT*rightRotate(NodeT *y)
{
    NodeT *x = y->left;
    NodeT *T2 = x->right;


    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    return x;
}

//  function to left rotate subtree rooted with x
// See the diagram given above.
NodeT *leftRotate(NodeT *x)
{
    NodeT *y = x->right;
    NodeT *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    return y;
}

int getBalance(NodeT *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

NodeT* insert(NodeT* node, int key)
{
    /* 1.  Perform the normal BST rotation */
    if (node == NULL)
        return(newNode(key));

    if (key < node->key)
        node->left  = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    /* 2. Update height of this ancestor node */
    node->height = max(height(node->left), height(node->right)) + 1;

    /* 3. Get the balance factor of this ancestor node to check whether
       this node became unbalanced */
    int balance = getBalance(node);


    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void preOrder(NodeT *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main()
{
  NodeT *root = NULL;

  root = insert(root, 25);
  root = insert(root, 27);
  root = insert(root, 30);
  root = insert(root, 45);
  root = insert(root, 12);
  root = insert(root, 22);


  printf("Pre order traversal of the constructed AVL tree is \n");
  preOrder(root);

  return 0;
}
