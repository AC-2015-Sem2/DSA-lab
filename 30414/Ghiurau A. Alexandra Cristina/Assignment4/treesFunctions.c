#include "functions.h"

NodeT *createNode(int data)
{
    NodeT *root = (NodeT*)malloc(sizeof(NodeT));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    root->height = 1;
    return root;
}

NodeT *createBinTree()
{
    NodeT *root = (NodeT*)malloc(sizeof(NodeT));

    char *data = (char*)malloc(sizeof(char)*100);
    scanf("%s", data);
    if(strcmp(data,"*")==0)
    {
        return 0;
    }
    else
    {
        root = createNode(atoi(data));
        root->left = createBinTree();
        root->right = createBinTree();
        root->height=max(height(root->left),height(root->right))+1;
    }
    return root;
}

NodeT *insert(NodeT *node, int data)
{
    /* 1.  Perform the normal BST rotation */
    if(node == NULL)
        return(createNode(data));

    if(data < node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);

    /* 2. Update height of this ancestor node */
    node->height = max(height(node->left), height(node->right)) + 1;

    /* 3. Get the balance factor of this ancestor node to check whether
       this node became unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then there are 4 cases

    if(balance == -2)
    {
        //Left Left Case
        if(node->right->data < data)
            leftRotation(&node);
        // Right Left Case
        if(node->right->data > data)
            rightLeftRotation(&node);
    }
    else
    {
        if(balance == 2)
        {
            // Right Right Case
            if(node->left->data > data)
                rightRotation(&node);
            // Left Right Case
            if(node->left->data < data)
                leftRightRotation(&node);
        }
    }
    /* return the (unchanged) node pointer */
    return node;
}
