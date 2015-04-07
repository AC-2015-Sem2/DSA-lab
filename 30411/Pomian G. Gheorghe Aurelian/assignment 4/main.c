#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



typedef struct NodeT{
    int data;
    struct NodeT* left;
    struct NodeT* right;
    } NodeT;

NodeT* createNode(int data)
{
    NodeT* root=(NodeT*)malloc(sizeof(NodeT));
    root->data=data;
    root->left=NULL;
    root->right=NULL;
    return root;
}

NodeT* balancing(NodeT* root);


NodeT* insert(NodeT* root, int cont)
{
    if(root==NULL)
    {
        return createNode(cont);
    }
    else
    {
        if(root->data>cont)
        {
            root->left=insert(root->left,cont);
        }
        else
        {
            root->right=insert(root->right,cont);
        }
        return root;
    }
}


int length(NodeT* node)
{
    int max;
    if(node==NULL)
        return 0;
    else
        {
            if((node->right!=NULL) && (node->left!=NULL))
            {
                if(length(node->right)>length(node->left))
                    max=length(node->right);
                else
                    max=length(node->left);
                return max+1;
            }
            else
            {
                if((node->right!=NULL) || (node->left!=NULL)){
                    if(node->right==NULL)
                        return 1+length(node->left);
                    else
                        return 1+length(node->right);
                }
            }
        }
    return 0;
}

NodeT* balancing(NodeT* root)
{
    NodeT* newroot;
    if(length(root->left)>length(root->right))
    {
        newroot=root->left;
        root->left=newroot->right;
        newroot->right=root;
    }
    else
    {
        newroot=root->right;
        root->right=newroot->left;
        newroot->left=root;
    }
    return newroot;
}

int isBSTUtil(NodeT* root, int min, int max)
{
    if(root == NULL)
        return 1;
    else
        if((root->data < max)||(root->data > min))
        {
            return isBSTUtil(root->right,root->data,max)&&isBSTUtil(root->left,min,root->data);
        }
        else return 0;
}

int isBST(NodeT* root)
{
    return isBSTUtil(root,INT_MIN,INT_MAX);
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
    NodeT* root;
    root=NULL;
    root=insert(root,5);
    root=insert(root,-7);
    root=insert(root,-9);
    root=insert(root,-11);
    root=insert(root,-13);
    root=insert(root,-15);
    prettyPrint(root,0);
    int len,i;
    len=abs(length(root->right)+length(root->left));
    len=len/2;
    for(i=1;i<=len;i++){
        root=balancing(root);
    }
    prettyPrint(root,0);

    return 0;
}
