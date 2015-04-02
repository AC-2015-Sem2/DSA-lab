#include "tree.h"

NodeT *  createBinTree(FILE* in)  // Read from input.txt
{
    NodeT *p;
    char *content = (char*)malloc(sizeof(char)*MAX_SIZE_OF_CONTENT);

    fscanf(in, "%s " ,content );
    float aux;
    if ( sscanf(content,"%f", &aux) == 1 )  // if reached a child (number)
    {
        char * cont = content;
        p = ( NodeT *) malloc( sizeof( NodeT ) ) ;
        p->str = cont;
        p->left = NULL;
        p->right = NULL;
    }

    else  // is at a node (operator)
    {
        char * cont = content;
        p = ( NodeT *) malloc( sizeof( NodeT ) ) ;
        p->str = cont;
        p->left = createBinTree(in) ;
        p->right = createBinTree(in) ;
    }
    return p;
}

void printStringElement(NodeT * node)
{
    printf ( "%s " ,(char*) node->str );
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
    printStringElement(root);

    //! print  a new line
    printf("\n");

    prettyPrint(root->left,recLevel); //! keep going left in the tree
}


float calc (NodeT* root)
{
    float aux;
    if (sscanf(root->str,"%f",&aux)==1)
        return aux;
    else
    {
        char c;
        sscanf(root->str,"%c",&c);
        if (c=='*')
        {
            return calc(root->left) * calc(root->right);
        }
        else if (c=='/')
        {
            return calc(root->left) / calc(root->right);
        }
        else if (c=='+')
        {
            return calc(root->left) + calc(root->right);
        }
        else if (c=='-')
        {
            return calc(root->left) - calc(root->right);
        }
    }
    // I'm getting a warning here, for reaching end of non-void function, however a value is always returned, unless input is wrong
}
