#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef  struct node
{
    int data;
    struct node*left,*right;
    int height;
}Node ;


int maxim(int a,int b)
{
    return (a>b)? a:b ;
}


int height(Node*Nod)
{
  if (Nod==NULL) return 0;
  return (Nod->height);
}


Node*createNode(int data)
{
    Node*newnode=(Node*)malloc(sizeof(Node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->height=1;
    return (newnode);
}


void preorder(Node*root)
{
    if (root!=NULL)
    {
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}


int balanced(Node*Nod)
{
   if (Nod==NULL) return 0;
   return height(Nod->left)- height(Nod->right);
}


Node*rotateRight(Node*x)
{
    Node*y=x->left;
    Node*T2=y->right;
    y->right=x;
    x->left=T2;
    x->height=maxim(height(x->left),height(x->right))+1;
    y->height=maxim(height(y->left),height(y->right))+1;
    return y;

}


Node*rotateLeft(Node*y)
{
  Node*x=y->right;
  Node*T2=x->left;
  x->left=y;
  y->right=T2;
    y->height=maxim(height(y->left),height(y->right));
    x->height=maxim(height(x->left),height(x->right));
    return x;
}

Node*insert(Node*node,int data)
{
   if(node==NULL) return (createNode(data));
   if(data< node->data) node->left=insert(node->left,data);
      else node->right=insert(node->right,data);
   node->height=maxim(height(node->left),height(node->right))+1;
   int balan=balanced(node);

   if (balan>1 && data<node->left->data) return rotateRight(node);

   if (balan<-1 && data>node->right->data) return rotateLeft(node);

   if (balan>1 && data>node->left->data)
       {
           node->left=rotateLeft(node->left);
        return(rotateRight(node));
       }

    if (balan<-1 && data<node->right->data)
    {
      node->right=rotateRight(node->right);
      return(rotateLeft(node));
    }
    return node;


}

void prettyPrint(Node*root,int reclevel)
{
    if (root==NULL)
    {
        reclevel--;
        return;
    }
    reclevel++;
    prettyPrint(root->right,reclevel);
    int j=0;
    for (j=0; j<reclevel-1; j++)
    {
        printf("  ");
    }
    printf("%d",root->data);
    printf("\n");
    prettyPrint(root->left,reclevel);
}

int main()
{
    Node *root = NULL;
   int i;
    for( i=0; i<10; i++)
        root = insert(root, i);
    printf("AVL \n");
    prettyPrint(root,0);

    return 0;
}
