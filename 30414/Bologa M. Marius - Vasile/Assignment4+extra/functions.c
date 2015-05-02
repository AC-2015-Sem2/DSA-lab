#include "functions.h"
struct node* createNode(int data)
{
    struct node* curr = (struct node*)malloc(sizeof(struct node));
    curr->data  = data;
    curr->left  = NULL;
    curr->right = NULL;
    curr->height = 1;
    return(curr);
}

int findHeight(struct node *root)
{
    if (root == NULL)
        return 0;
    else
        return root->height;
}
int maxi(int a, int b)
{
    return (a > b)? a : b;
}

struct node *rightRotate(struct node *root)
{
    struct node *nod1 = root->left;
    struct node *nod2 = nod1->right;
    nod1->right = root;
    root->left = nod2;
    root->height = maxi(findHeight(root->left), findHeight(root->right))+1;
    nod1->height = maxi(findHeight(nod1->left), findHeight(nod1->right))+1;
    return nod1;
}

struct node *leftRotate(struct node *nod)
{
    struct node *root = nod->right;
    struct node *nod1 = root->left;
    root->left = nod;
    nod->right = nod1;
    nod->height = maxi(findHeight(nod->left), findHeight(nod->right))+1;
    root->height = maxi(findHeight(root->left), findHeight(root->right))+1;
    return root;
}

int getBalance(struct node *root)
{
    if (root == NULL)
        return 0;
    return findHeight(root->left) - findHeight(root->right);
}

struct node* insertNode(struct node* node, int data)
{
    if (node == NULL)
        return(createNode(data));
    else if (data < node->data)
        node->left  = insertNode(node->left, data);
    else
        node->right = insertNode(node->right, data);
    node->height = maxi(findHeight(node->left), findHeight(node->right)) + 1;
    int balance = getBalance(node);
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);
    if (balance > 1 && data > node->left->data)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void prettyPrint(struct node *root,int nivel)
{
    if(root==NULL)
    {
        nivel--;
        return;
    }
    nivel++;
    prettyPrint(root->right,nivel);
    int j=0;
    for(j=0; j<nivel-1; j++)
    {
        printf("     ");
    }
    printf("%d", root->data);
    printf("\n");
    prettyPrint(root->left,nivel);
}
struct node* deleteNode(struct node* root, int data)
{
    if (root == NULL)
        return root;
    else if ( data < root->data )
        root->left = deleteNode(root->left, data);
    else if( data > root->data )
        root->right = deleteNode(root->right, data);
    else
    {
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct node *curr = root->left ? root->left : root->right;
            if(curr == NULL)
            {
                curr = root;
                root = NULL;
            }
            else
                *root = *curr;
            free(curr);
        }
        else
        {
            struct node* curr = miniNod(root->right);
            root->data = curr->data;
            root->right = deleteNode(root->right, curr->data);
        }
    }
    if (root == NULL)
        return root;
    root->height = maxi(findHeight(root->left), findHeight(root->right)) + 1;
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
struct node * miniNod(struct node* node)
{
    struct node* current = node;

    while (current->left != NULL)
        current = current->left;

    return current;
}
