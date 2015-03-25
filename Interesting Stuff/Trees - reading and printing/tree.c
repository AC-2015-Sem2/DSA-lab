#include "tree.h"

NodeT *createNode(void *content)
{
    NodeT* newNode = (NodeT*)malloc(sizeof(NodeT));
    newNode->content = content;
    newNode->left = NULL;
    newNode->right= NULL;
    return newNode;
}

NodeT * createBinTree()
{
    NodeT *p;
    char *content = (char*)malloc(sizeof(char)*MAX_SIZE_OF_CONTENT);

    scanf( "%s" ,content );
    if ( strcmp(content,"*")==0 )
        return NULL;
    else
    {
        void * cont = getContent(content);
        p = ( NodeT *) malloc( sizeof( NodeT ) ) ;
        p->content = cont;
        p->left = createBinTree() ;
        p->right = createBinTree() ;
    }
    return p;
}

NodeT * createStaticBinTree()
{
    NodeT * root = createNode((void*)1);
    NodeT * left1 = root->left = createNode((void*)2);
    NodeT * right1= root->right = createNode((void*)5);
    left1->left = createNode((void*)3);
    left1->right= createNode((void*)4);
    right1->left = createNode((void*)6);
    right1->right = createNode((void*)7);

    return root;
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
        printf("     ");
    }
    //! then print value
    printElement(root);

    //! print  a new line
    printf("\n");

    prettyPrint(root->left,recLevel); //! keep going left in the tree
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


