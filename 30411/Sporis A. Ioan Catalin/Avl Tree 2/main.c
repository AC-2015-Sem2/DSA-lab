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
int height(NodeT *root)
{
    int lh,rh;
    if(root==NULL)
        return 0;
    if(root->left==NULL)
        lh=0;
    else
        lh=1+root->left->height;
    if(root->right==NULL)
        rh=0;
    else
        rh=1+root->right->height;
    if(lh>rh)
        return lh;
    return rh;
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

NodeT* deletion(NodeT *root, int data)
{
    NodeT *p;
    if(root==NULL)
        return NULL;
    else
        if(data>root->data)
        {
            root->right=deletion(root->right,data);
            if(Balance_factor(root)==2)
            {
                if(Balance_factor(root->left)>=0)
                {
                    right_rotate(root);
                }
                else
                {
                    root->left=left_rotate(root->left);
                    root=right_rotate(root);
                    return root;
                }
            }


        }
        else
            if(data<root->data)
            {
                root->left=deletion(root->left,data);
                if(Balance_factor(root)==-2)
                {
                    if(Balance_factor(root->right)<=0)
                        root=left_rotate(root);
                    else
                    {
                        root->right=right_rotate(root->right);
                        root=left_rotate(root);
                        return root;
                    }
                }
                else
                    if(root->right!=NULL)
                    {

                        p=root->right;
                        while(root->left!=NULL)
                            p=p->left;
                        root->data=p->data;
                        root->right=deletion(root->right,p->data);
                        if(Balance_factor(root)==2)
                        {
                            if(Balance_factor(root->left)>=0)
                                root=right_rotate(root);
                            else
                            {
                                root->left=left_rotate(root->left);
                                root=right_rotate(root);
                                return root;
                            }
                        }
                    }
            }
            root->height=height(root);
            return root;
}
int main()
{   FILE *in=fopen("input.dat","r");

    NodeT *root=create_tree(in);
    insert(root,16);
    //root=deletion(root,2);
    prettyPrint(root,0);
    return 0;
}
