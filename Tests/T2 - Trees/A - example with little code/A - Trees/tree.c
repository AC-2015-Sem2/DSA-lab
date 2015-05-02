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

void inorder(NodeT * root)
{
    if ( root != NULL )
    {
        inorder( root->left) ;
        printf("%d ",(int)root->content);
        inorder( root->right ) ;
    }
}

int maxDepth(NodeT * root)
{
    if(root == NULL)
        return 0;
    else
    {
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return leftDepth>rightDepth ? leftDepth+1 : rightDepth+1;
    }
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

int hasPathSum(NodeT *root, int sum)
{
    if(root == NULL)
        return sum == 0 ? 1 : 0;
    else
        return (hasPathSum(root->left, sum-(int)root->content) || hasPathSum(root->right,sum-(int)root->content));
}

void doubleTree(NodeT *root)
{
    if(root == NULL)
        return;

    doubleTree(root->left);
    doubleTree(root->right);

    NodeT *oldLeft = root->left;
    root->left = createNode(root->content);
    root->left->left = oldLeft;
}
