#include "tree.h"

NodeT *createNode(void *content)
{
    NodeT* newNode = (NodeT*)malloc(sizeof(NodeT));
    newNode->content = content;
    newNode->left = NULL;
    newNode->right= NULL;
    return newNode;
}

NodeT * createBinTree(FILE * f)
{
    NodeT *p;
    char *content = (char*)malloc(sizeof(char)*MAX_SIZE_OF_CONTENT);
    fscanf(f, "%s" ,content );
    if ( strcmp(content,"*")==0 )
        return NULL;
    else
    {
        void * cont = (void*) atoi(content);
        p = ( NodeT *) malloc( sizeof( NodeT ) ) ;
        p->content = cont;
        p->left = createBinTree(f) ;
        p->right = createBinTree(f) ;
    }
    return p;
}

void postorder(NodeT * root)
{
    if ( root != NULL )
    {
        postorder( root->left ) ;
        postorder( root->right ) ;
        printf("%d ",(int)root->content);
    }
}

int size(NodeT *root)
{
    return (root == NULL) ? 0 : size(root->left)+size(root->right)+1;
}

int search(NodeT * root, int content)
{
    if(root == NULL)
        return 0;
    else
    {
        if (content == (int)root->content)
            return 1;
        return (int)root->content > content ? search(root->left, content):search(root->right, content);
    }
}

void mirror(NodeT *root)
{
    if(root == NULL)
        return;
    else
    {
        NodeT *aux = root->left;
        root->left = root->right;
        root->right= aux;

        mirror(root->left);
        mirror(root->right);
    }
}

void printArray(int *array, int length)
{
    int i=0;
    for(i=0; i<length; i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}

void printPaths(NodeT *root, int *path, int pathLength)
{
    if(root==NULL)
        return;
    path[pathLength++] = (int)root->content;
    if(root->left == NULL && root->right == NULL)
    {
        printArray(path,pathLength);
    }
    else
    {
        printPaths(root->left, path, pathLength);
        printPaths(root->right, path, pathLength);
    }
}


