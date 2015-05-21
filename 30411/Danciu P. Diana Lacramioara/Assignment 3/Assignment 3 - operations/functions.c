#include "header.h"

TreeT *createNodeTree(char *data)
{
    TreeT *p;

    p = (TreeT *)malloc(sizeof(TreeT));
    p->data = data;
    p->left = p->right = NULL;
    return(p);
}

TreeT *createBinTree(FILE *f)
{
    char *content;
    TreeT *p;

    content = (char*)malloc(sizeof(char)*50);
    fscanf(f, "%s ", content);
    if (strstr("+-*/",content) == NULL)   //Here why I cannot use strcmp ?
    {
        p=createNodeTree(content);
    }
    else
    {
        p=(TreeT*)malloc(sizeof(TreeT));
        p->data = content;
        p->left=createBinTree(f);
        p->right=createBinTree(f);
    }
    return (p);
}
void prettyPrint(TreeT *root,int recLevel) //! root, index, length, reccurence level
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
    printf("%s ", root->data);

    //! print  a new line
    printf("\n");

    prettyPrint(root->left,recLevel); //! keep going left in the tree
}
