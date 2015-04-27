# include "insdelHeader.h"

NodeT *createNode(int data)
{
    NodeT *p=(NodeT*) malloc (sizeof(NodeT));
    p->data=data;
    p->right = NULL;
    p->left = NULL;
    p->height=1;
    return p;
}


int maxim(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int compHeight(NodeT *root)
{
    if(root == NULL)
        return 0;
    else
        return root->height;
}

NodeT *insertNode(NodeT *root, int value)
{
    if(root == NULL)
    {
        NodeT *p=createNode(value);
        return p;
    }
    else
    {
        if(value > root->data)
            root -> right = insertNode(root->right, value);
        else
            root -> left = insertNode(root->left, value);

        root->height = maxim(compHeight(root->left), compHeight(root->right)) +1;

        return Balance(root);
    }
}

void prettyPrint(NodeT *root,int recLevel) //! root, index, length, reccurence level
{
    if(root==NULL)
    {
        recLevel--; //! reached leaf, must decrement recurence level
        return;
    }
    recLevel++; //! otherwise increment it
    prettyPrint(root->right,recLevel); //! keep going right in the tree
    int j=0;

    //! print spaces for the appropriate recurence level
    for(j=0; j<recLevel-1; j++)
    {
        printf("  ");
    }

    //! then print value
    printf("%d", root->data);

    //! print a new line
    printf("\n");
    prettyPrint(root->left,recLevel); //! keep going left in the tree
}

NodeT *leftRotation(NodeT *root)
{
    NodeT *adr, *rightNode = root->right;
    adr = rightNode->left;
    rightNode -> left = root;
    root->right = adr;
    root = rightNode;
    return root;
}

NodeT *rightRotation(NodeT *root)
{
    NodeT *adr, *leftNode = root->left;
    adr = leftNode->right;
    leftNode->right = root;
    root->left = adr;
    root = leftNode;
    return root;
}

int getBalance(NodeT *root)
{
    if(root!=NULL && (root->right != NULL || root->left!=NULL))
    {
        if(root->right == NULL)
            return 0-root->left->height;
        else
            if(root->left == NULL)
                return root->right->height;
            else
                return root->right->height - root->left->height;
    }
    else
        return 0;
}

NodeT *findMin(NodeT *root)
{
    while(root->left != NULL)
        root = root->left;
    return root;
}

NodeT *deleteNode(NodeT *root, int value)
{
    NodeT *minNode;
    if(root == NULL)
        return NULL;
    else
        if(root->data > value)
            root->left = deleteNode(root->left, value);
        else
            if(root->data < value)
               root->right = deleteNode(root->right, value);
            else // found the node that I want to delete
            {
                if(root->left == NULL)
                {
                        minNode = root;
                        root = root->right;
                        free(minNode);
                }
                else
                    if(root->right == NULL)
                    {
                        minNode = root;
                        root = root->left;
                        free(minNode);
                    }
                    else
                    {
                        minNode = findMin(root->right);
                        root->data=minNode->data;
                        root->right = deleteNode(root->right, minNode->data);
                    }
            }
    return Balance(root);
}

int getHeights(NodeT *root) //computes all the heights of the nodes from the tree that has been rotated;
{
    if(root == NULL)
        return 0;
    else
    {
        root->height=maxim(getHeights(root->left), getHeights(root->right))+1;
        return root->height;
    }
}

NodeT *Balance(NodeT *root)
{
        int balance = getBalance(root);

        if(balance == -2)
        {
            balance = getBalance(root->left);
            if(balance >=1)
            {
                root -> left = leftRotation(root->left);
                root = rightRotation(root);
            }
            else
                root = rightRotation(root);
        }
        else
        {
            if(balance == 2)
            {
                balance = getBalance(root);
                if(balance <= -1)
                {
                    root -> right = rightRotation(root->right);
                    root = leftRotation(root);
                }
                else
                    root = leftRotation(root);
            }
        }

    getHeights(root);

    return root;
}
