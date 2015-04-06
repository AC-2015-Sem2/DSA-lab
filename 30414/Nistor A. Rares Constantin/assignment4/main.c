#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

FILE *input, *output;

typedef struct nod
{
    struct nod *left, *right;
    char data;
}NODET;

NODET *root;

NODET* createNODE(int d)
{
    NODET *p;
    p=(NODET*)malloc(sizeof(NODET));
    p->data=d;
    p->left=NULL;
    p->right=NULL;
    return p;
}

void prettyPrint(NODET *root,int recLevel)
{
    if(root==NULL)
    {
        recLevel--;
        return;
    }
    recLevel++;
    prettyPrint(root->right,recLevel);
    int i=0;
    for(i=0; i<recLevel-1; i++)
        fprintf(output,"  ");

    fprintf(output,"%d", root->data);
    fprintf(output,"\n");
    prettyPrint(root->left,recLevel);
}

 NODET* rotateright(NODET* root)
{
    NODET *node;
    node=root->right;
    root->right=node->left;
    node->left=root;
    return node;

}

NODET* rotateleft(NODET* root)
{
    NODET *node;
    node=root->left;
    root->left=node->right;
    node->right=root;
    return node;
}

int height(NODET *root)
{
    if(root==NULL)
        return 0;
    else
        {
            if(height(root->left)>height(root->right))
                return height(root->left)+1;
            else
                return height(root->right)+1;
        }
}

NODET* switchr(NODET *root)
{
     if(height(root->right)-height(root->left)>1)
            {
                if(height(root->right->left)>height(root->right->right))
                    root->right=rotateleft(root->right);
                root=rotateright(root);
            }

    else
        if(height(root->left)-height(root->right)>1)
            {
                if(height(root->left->right)>height(root->left->left))
                    root->left=rotateright(root->left);
                root=rotateleft(root);
            }
      return root;
}

NODET* insert(NODET* root,int value)
{
    if(root==NULL)
        return createNODE(value);
    else
    {
        if(root->data<value)
            root->right=insert(root->right,value);
        else
            root->left=insert(root->left,value);
        return switchr(root);
    }
}

int main()
{
    int a;
    input=fopen("input.dat","r");
    output=fopen("output.dat","w");
    while(fscanf(input,"%d",&a)>0)
            root=insert(root,a);
    prettyPrint(root,0);
    return 0;
}
