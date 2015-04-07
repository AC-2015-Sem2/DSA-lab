#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node
{
    struct node *left;
    struct node *right;
    int data;
} NodeT;
NodeT* createNode(int d)
{
    NodeT *newnode;
    newnode=(NodeT*)malloc(sizeof(NodeT));
    newnode->data=d;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
NodeT *CreateBinTree(FILE *f)
{
    NodeT *p;
    char *return_val;
    return_val=(char*)malloc(sizeof(char));
    fscanf(f,"%s",return_val);
    if (strcmp(return_val,"*")==0)
        return NULL;
    else
    {
        p=createNode(atoi(return_val));
        p->left=CreateBinTree(f);
        p->right=CreateBinTree(f);
    }
    return p;
}
void prettyPrint(NodeT *root,int level)
{
    if(root==NULL)
    {
        level=level-1;
        return ;
    }
    level=level+1;
    prettyPrint(root->right,level);
    int j=0;

    for(j=0; j<level-1; j++)
    {
        printf("  ");
    }
    printf("%d", root->data);
    printf("\n");
    prettyPrint(root->left,level);
}
void swap(NodeT*root)
{NodeT*aux;
    aux=root->left;
    root->left=root->right;
    root->right=aux;
    return;
}
void mirror(NodeT* root)
{
    if ((root->left==NULL)&&(root->right==NULL))
      return;
    else
    {
        mirror(root->left);
        mirror(root->right);
        swap(root);

    }
}
int main()
{
    FILE *f=fopen("input.txt","r");
    NodeT *root=CreateBinTree(f);
    mirror(root);
    prettyPrint(root,0);

    fclose(f);
    return 0;
}
