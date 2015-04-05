#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node
{
    int data;
    int height;
    struct node *left,*right;
}NodeT;

NodeT* create_node(int data)
{
    NodeT *p=(NodeT*)malloc(sizeof(NodeT));
    p->data=data;
    p->height=1;
    p->left=p->right=NULL;
    return p;
}
int height (NodeT *root)
{
    if(root==NULL)
        return 0;
    return root->height;
}
int Balance_factor(NodeT *root)
{
    if(root==NULL)
        return 0;
    else
        return height(root->left)-height(root->right);
}
int max (int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

NodeT* create_tree(FILE *a)
{
    NodeT *p;
    char *content=(char*)malloc(sizeof(char)*10);
    if(fscanf(a,"%s ",content)==1)
    {
        if(strcmp(content,"*")==0)
            return NULL;
        else
        {
            p=create_node(atoi(content));
            p->left=create_tree(a);
            p->right=create_tree(a);
        }
    }
    return p;
}
void preorder(NodeT *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
NodeT* right_rotate(NodeT *root)
{
    NodeT *p=root->left;
    NodeT *q=p->right;
    p->right=root;
    root->left=q;
    root->height=max(height(root->left),height(root->right))+1;
    p->height=max(height(p->left),height(p->right))+1;
    return p;
}
NodeT* left_rotate(NodeT *root)
{
    NodeT *p=root->right;
    NodeT *q=p->left;
    p->left=root;
    root->right=q;
    root->height=max(height(root->left),height(root->right))+1;
    p->height=max(height(p->left),height(p->right))+1;
    return p;
}
/*NodeT* Left_rotation(NodeT *root)
{
    NodeT *p=root;
    root=root->right;
    root->left=p;
    p->right=NULL;

    return root;
}
NodeT* Right_Rotation(NodeT *root)
{
    NodeT *p=root;
    root=root->left;
    root->right=p;
    p->left=NULL;
    return root;
}
NodeT* double_left(NodeT *root)
{
    NodeT *p=Right_Rotation(root->right);
    root->right=p;
    root=Left_rotation(root);
    return root;
}
NodeT* double_right(NodeT *root)
{
    NodeT *p=Left_rotation(root->left);
    root->left=p;
    root=Right_Rotation(root);
    return root;
}
*/
void prettyPrint(NodeT *root,int recLevel)
{
    if(root==NULL)
    {
       recLevel--;
        return;
   }
    recLevel++;
    prettyPrint(root->right,recLevel);
    int j=0;
    for(j=0; j<recLevel-1; j++)
    {
        printf("           ");
    }
    printf("%.0d",root->data);
    printf("\n");
    prettyPrint(root->left,recLevel);
}
NodeT* insert(NodeT *root,int data)
{
    if(root==NULL)
        return create_node(data);
    else
    {
        if(root->data>data)
            root->left=insert(root->left,data);
        else
            root->right=insert(root->right,data);
    }
    root->height=max(height(root->left),height(root->right))+1;
    int balance_fact=Balance_factor(root);
    if(balance_fact>1&&data<root->left->data)
        return right_rotate(root);
    if(balance_fact<-1&&data>root->right->data)
        return left_rotate(root);
    if(balance_fact>1&&data>root->left->data)
    {
        root->left=left_rotate(root->left);
        return right_rotate(root);
    }
    if(balance_fact<-1&&data<root->right->data)
    {
        root->right=right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

int main()
{   FILE *in=fopen("input.dat","r");

    NodeT *root=create_tree(in);

    prettyPrint(root,0);
    return 0;
}
