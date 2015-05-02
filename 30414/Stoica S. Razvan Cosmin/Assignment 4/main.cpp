#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct nod
{
    int data;
    struct nod *left;
    struct nod *right;
    int height;
}NodeT;

NodeT* createNode(int data)
{
    NodeT* NewNode=(NodeT*)malloc(sizeof(NodeT));
    NewNode->data=data;
    NewNode->left=NULL;
    NewNode->right=NULL;
    NewNode->height=1;
    return NewNode;
}

int NodeHeight(NodeT *Node)
{
    if(Node==NULL) return 0;
    return Node->height+1;
}

int BalanceFactor(NodeT *Node)
{
    if(Node==NULL) return 0;
    return NodeHeight(Node->left)-NodeHeight(Node->right);
}

int Max(int a, int b)
{
    if(a>b) return a;
    else return b;
}

NodeT *LeftRotation(NodeT *temp)
{
    int l,r,l1,r1;
    NodeT *temp2=temp->right;
    NodeT *temp3=temp2->left;
    temp2->left=temp;
    temp->right=temp3;
    l=NodeHeight(temp->left);
    r=NodeHeight(temp->right);
    temp->height=Max(l,r);
    l1=NodeHeight(temp2->left);
    r1=NodeHeight(temp2->right);
    temp2->height=Max(l1,r1);
    return temp2;
}

NodeT *RightRotation(NodeT *temp2)
{
    int l,r,l1,r1;
    NodeT *temp=temp2->left;
    NodeT *temp3=temp->right;
    temp->right=temp2;
    temp2->left=temp3;
    l=NodeHeight(temp2->left);
    r=NodeHeight(temp2->right);
    temp2->height=Max(l,r);
    l1=NodeHeight(temp->left);
    r1=NodeHeight(temp->right);
    temp->height=Max(l1,r1);
    return temp;
}

NodeT* Insert(NodeT* Node, int data)
{
    int b,r,l;
    if(Node==NULL) return createNode(data);
    if(data<Node->data) Node->left=Insert(Node->left,data);
    else Node->right=Insert(Node->right, data);
    l=NodeHeight(Node->left);
    r=NodeHeight(Node->right);
    Node->height=Max(l,r);
    b=BalanceFactor(Node);
    if(b<-1 && data>Node->right->data) return LeftRotation(Node);
    if(b>1 && data<Node->left->data) return RightRotation(Node);
    if(b<-1 && data<Node->right->data)
        {
        Node->right=RightRotation(Node->right);
        return LeftRotation(Node);
        }
    if(b>1 && data>Node->left->data)
        {
        Node->left=LeftRotation(Node->left);
        return RightRotation(Node);
        }
    return Node;
}

void prettyPrint(NodeT *root,int level)
{
    if(root==NULL) return;
    level++;
    prettyPrint(root->right,level);
    for(int i=0; i<level; i++)
        {
        printf("\t");
        }
    printf("%d \n\n", root->data);
    prettyPrint(root->left,level);
}

int main()
{
    FILE *p;
    NodeT *root=NULL;
    p=fopen("input.txt","r");
    int data;
    while(!feof(p))
    {
        fscanf(p,"%d",&data);
        root=Insert(root,data);
    }
    printf("\n");
    prettyPrint(root,0);
    return 0;
}
