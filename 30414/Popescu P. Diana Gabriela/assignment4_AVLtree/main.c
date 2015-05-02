#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nod1
{
    int data;
    int height;
    struct nod1 *left, *right;
} NodeT;

NodeT* createNodeT(int data)
{
    NodeT* nnew=(NodeT*)malloc(sizeof(NodeT));
    nnew->data=data;
    nnew->left=NULL;
    nnew->right=NULL;
    nnew->height=1;
    return nnew;
}

int maxx(int a, int b)
{
    return (a>b)? a:b;
}

int height(NodeT* root)
{
    if(root==NULL)
        return 0;
    return root->height;
}

int balanceFactor(NodeT* root)
{
    if(root==NULL)
        return 0;
    return (height(root->left)-height(root->right));
}

int searchNode(NodeT* root, int value)
{
    if(root==NULL)
        return 0;
    else if(root->data==value)
        return 1;
  else
  {
      if(root->data < value)
        return searchNode(root->right, value);
      else
        return searchNode(root->left, value);
  }
}

NodeT* minNode(NodeT* root)
{
    while(root->left!=NULL)
        root=root->left;
    return root;
}

NodeT* createBinaryTree(FILE* f)
{
    NodeT* p;
    char* data=(char*)malloc(sizeof(char)*100);
    fscanf(f, "%s", data);
    if(strcmp(data, "*")==0)
        return NULL;
    else
    {
        p=createNodeT(atoi(data));
        p->left=createBinaryTree(f);
        p->right=createBinaryTree(f);
        p->height=maxx(height(p->left), height(p->right))+1;
    }
    return p;
}
//print function:
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
        printf("     ");
    }

    printf("%d", root->data);


    printf("\n");

    prettyPrint(root->left,recLevel);

}
//insert & rotation functions:
void leftRotation(NodeT** root)
{
    NodeT* aux=(*root)->right;
    (*root)->right=aux->left;
    aux->left=(*root);
    (*root)->height=maxx(height((*root)->left), height((*root)->right))+1;
    aux->height=maxx(height(aux->right), (*root)->height)+1;
    (*root)=aux;
}

void rightRotation(NodeT** root)
{
    NodeT* aux=(*root)->left;
    (*root)->left=aux->right;
    aux->right=(*root);
    (*root)->height=maxx(height((*root)->left), height((*root)->right))+1;
    aux->height=maxx(height(aux->right), (*root)->height)+1;
    (*root)=aux;
}

void LeftRight(NodeT** root)
{
    leftRotation(& ((*root)->left));
    rightRotation(root);
}

void RightLeft(NodeT** root)
{
    rightRotation(& ((*root)->right));
    leftRotation(root);
}

NodeT* insertNodeAVLtree(NodeT* root, int data)
{
    if(root==NULL)
        return createNodeT(data);
    else
    {
        if(root->data < data)
            root->right=insertNodeAVLtree(root->right, data);
        else
            root->left=insertNodeAVLtree(root->left, data);
    }

    root->height=maxx(height(root->left), height(root->right))+1;
    int aux=balanceFactor(root);

    if(aux>1)
    {
        if(root->left->data > data)//RR
            rightRotation(&root);
        else//LR
            LeftRight(&root);
    }
    else if(aux<-1)
    {
        if(root->right->data < data)//LL
            leftRotation(&root);
        else//RL
            RightLeft(&root);
    }
    //else
    return root;
}

/*
//delete function:
NodeT* deleteNodeAVLtree(NodeT* root, int value)
{
    if(root==NULL)
        return root;
    else
    {
        if(root->data > value)
            root->left=deleteNodeAVLtree(root->left, value);
        else if(root->data < value)
            root->right=deleteNodeAVLtree(root->right, value);
        else //!
        {
            if(root->left==NULL || root->right==NULL)
            {
                NodeT* aux;
                if(root->left!=NULL)
                    aux=root->left;
                else
                    aux=root->right;

                if(aux==NULL)
                {
                    aux=root;
                    //root==NULL;
                }
                else
                    *root=*aux;
                free(aux);
            }
            else
            {
                NodeT* aux=minNode(root->right);
                root->data=aux->data;
                root->right=deleteNodeAVLtree(root->right, aux->data);
            }
        }

    if(root==NULL)
        return root;

    root->height=maxx(height(root->left), height(root->right))+1;
    int auxx=balanceFactor(root);

    if(auxx>1)
    {
        if(root->left!=NULL)//RR
            rightRotation(&root);
        else//LR
            LeftRight(&root);
    }
    else if(auxx<-1)
    {
        if(root->right!=NULL)//LL
            leftRotation(&root);
        else//RL
            RightLeft(&root);

    }
    return root;
}
*/
int main()
{
    NodeT* root=NULL;

    FILE* f=fopen("input.txt", "r");
    if(f==0)
        printf("err");

    root=createBinaryTree(f);
    printf("Initial tree:\n");
    prettyPrint(root, 0);
    printf("\n\n\n");

    int vvalue;
    for(vvalue=1; vvalue<=100; vvalue++)
        if(searchNode(root, vvalue)==0)//this line is only for making sure that a value is not inserted 2 times
            root=insertNodeAVLtree(root, vvalue);

    prettyPrint(root, 0);

    fclose(f);
    return 0;
}
