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
        void * cont = getContent(content);
        p = ( NodeT *) malloc( sizeof( NodeT ) ) ;
        p->content = cont;
        p->left = createBinTree(f) ;
        p->right = createBinTree(f) ;
    }
    return p;
}


void preorder(NodeT * root)
{
    if ( root != NULL )
    {
        printElement(root);
        preorder( root->left) ;
        preorder( root->right) ;
    }
}

void inorder(NodeT * root)
{
    if ( root != NULL )
    {
        inorder( root->left) ;
        printElement(root);
        inorder( root->right ) ;
    }
}

void postorder(NodeT * root)
{
    if ( root != NULL )
    {
        postorder( root->left ) ;
        postorder( root->right ) ;
        printElement(root);
    }
}

void prettyPrint(NodeT *root,int recLevel) // root, index, length, reccurence level
{
    if(root==NULL)
    {
        recLevel--; // reached leaf, must decrement recurence level
        return;
    }
    recLevel++; // otherwise increment it
    prettyPrint(root->right,recLevel); // keep going right in the tree
    int j=0;

    // print spaces for the appropriate recurence level
    for(j=0; j<recLevel-1; j++)
    {
        printf("     ");
    }
    // then print value
    printElement(root);

    // print  a new line
    printf("\n");

    prettyPrint(root->left,recLevel); // keep going left in the tree
}

int maxDepth(NodeT * root)
{

    if(root == NULL)
    {
        return 0;
    }
    else
    {
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        if(leftDepth>rightDepth)
        {
            return leftDepth + 1;
        }
        else
        {
            return rightDepth + 1;
        }
    }
}

int hasPathSum(NodeT *root, int sum)
{

    if(root == NULL)
    {
        if(sum==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        int subSum = sum-(int)root->content;
        return (hasPathSum(root->left, subSum) || hasPathSum(root->right,subSum));
    }

}

int size(NodeT *root)
{

    if(root==NULL)
    {
        return 0;
    }
    else
    {
        return size(root->left)+size(root->right)+1;
    }

}

void printPaths(NodeT *root, int *path, int pathLength)
{

    if(root==NULL)
    {
        return;
    }
    path[pathLength] = (int)root->content;
    pathLength++;
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

void mirror(NodeT *root)
{
    if(root == NULL)
    {
        return;
    }
    else
    {
        NodeT *aux = root->left;
        root->left = root->right;
        root->right= aux;

        mirror(root->left);
        mirror(root->right);
    }
}

void doubleTree(NodeT *root)
{
    if(root == NULL)
    {
        return;
    }
    doubleTree(root->left);
    doubleTree(root->right);

    NodeT *oldLeft = root->left;
    root->left = createNode(root->content);
    root->left->left = oldLeft;
}


//! BST

NodeT * insert(NodeT * root, int content)
{
    if(root == NULL)
    {
        return createNode((void*)content);
    }
    else
    {
        if(content <= (int)root->content)
        {
            root->left = insert(root->left, content);
        }
        else
        {
            root->right = insert(root->right, content);
        }

        return root;
    }
}

int lookup(NodeT * root, int content)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        if (content == (int)root->content)
        {
            return 1;
        }
        if(content < (int)root->content)
        {
            return lookup(root->left, content);
        }
        else
        {
            return lookup(root->right, content);
        }
    }
}

int isBSTUtil(NodeT * root, int min, int max)
{
    if (root==NULL)
        return 1;

    if ((int)root->content<min || (int)root->content>max)
        return 0;

    return (
            isBSTUtil(root->left, min, (int) root->content)
                    &&
            isBSTUtil( root->right,(int) root->content+1, max)
            );

}


int sameTree(NodeT * a , NodeT * b){

    if(a==NULL && b == NULL){
        return 1;
    }

    else if(a!= NULL && b!= NULL){
        return ((int)a->content == (int)b->content && sameTree(a->left,b->left) && sameTree(a->right, b->right));
    }
    else {
        return 0;
    }

}

int isBST(NodeT * root)
{
    return (isBSTUtil(root, INT_MIN, INT_MAX));
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

void printStringElement(NodeT * node)
{
    printf ( "%s " ,(char*) node->content );
}

void printIntegerElement(NodeT * node)
{
    printf ( "%d " ,(int) node->content );
}

void * getStringContent(char * content)
{
    return content;
}

void * getIntegerContent(char * content)
{
    return (void*)atoi(content);
}


