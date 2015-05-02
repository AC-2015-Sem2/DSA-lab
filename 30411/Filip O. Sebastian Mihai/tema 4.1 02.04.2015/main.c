#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node* left;
    struct node* right;
    int data;
} NodeT;
NodeT* root;
NodeT* createNode(int data)
{
    NodeT* root=(NodeT*)malloc(sizeof(NodeT));
    root->data=data;
    root->left=NULL;
    root->right=NULL;
    return root;
}
int highleft(NodeT*root)
{
    int c=0;
    while(root!=NULL)
    {
        root=root->left;
        c++;
    }
    return c;
}
int highright(NodeT*root)
{
    int c=0;
    while(root!=NULL)
    {
        root=root->right;
        c++;
    }
    return c;
}
NodeT* insert(NodeT* root, int cont)
{
    int c;
    if(root==NULL)
    {
        return createNode(cont);
    }
    else
    {
        if(root->data>cont)
        {
            if(highleft(root)==highright(root))
            {
                root->left=insert(root->left,cont);
            }
            else if(highleft(root)==(highright(root)-1))
            {
                root->left=insert(root->left,cont);
            }
            else
            {
                c=1;
            }

        }
         else
        {
            if(highleft(root)==highright(root))
            {
               root->right=insert(root->right,cont);
            }
            else if(highleft(root)==(highright(root)+1))
            {
                root->right=insert(root->right,cont);
            }
            else
            {
                c=1;
            }

        }

        return root;
    }
}
void printElement(NodeT*  root)
{
    printf("%d",root->data);
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
int main()
{

    root=createNode(10);
    insert(root,4);
    insert(root,15);
    insert(root,1);
    insert(root,20);
    insert(root,17);
    insert(root,5);
    insert(root,6);
    insert(root,7);
    int i=0;
    prettyPrint(root,i);
    printf("%d",highleft(root));
    printf("\n%d",highright(root));
    return 0;
}
