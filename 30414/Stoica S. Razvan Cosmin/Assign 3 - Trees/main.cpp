#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nod
{
    char data;
    struct nod* left;
    struct nod* right;

}NodeT,NodeTT;

typedef struct List
{
    char data;
    struct List* next;
    struct List* prev;
}NodeL;

NodeL *head,*tail;

NodeT * createNode(char data)
{
    struct nod *node=(struct nod *)malloc(sizeof(struct nod));
    node->data=data;
    node->left=NULL;
    node->right=NULL;
    return node;
}

NodeT *createBinTree()
{
    NodeT *root;
    root=createNode('1');
    root->left=createNode('2');
    root->right=createNode('5');
    root->left->left=createNode('3');
    root->left->left->left=createNode('*');
    root->left->left->right=createNode('*');
    root->left->right=createNode('4');
    root->left->right->left=createNode('*');
    root->left->right->right=createNode('*');
    root->right->left=createNode('6');
    root->right->left->left=createNode('*');
    root->right->left->right=createNode('*');
    root->right->right=createNode('7');
    root->right->right->left=createNode('*');
    root->right->right->right=createNode('*');
    return root;
}

NodeL *getListFromTree(NodeT *root)
{
    if(root!=NULL)
    {
        NodeL *tempx=(NodeL *)malloc(sizeof(NodeL));
        NodeL *tempx2;
        tempx->data=root->data;
        tempx->next=NULL;
        if(head==NULL)
            {
            head=tempx;
            }
        else
        {
        tempx2 = head;
        while(tempx2->next!=NULL)
            {
            tempx2=tempx2->next;
            }
        tempx2->next=tempx;
        tempx2->prev=tempx;
        }
        getListFromTree(root->left);
        getListFromTree(root->right);
    }
    return head;
}

void traverseList(NodeL *firstFromList)
{
    NodeL* temp=firstFromList;
    while(temp!=NULL)
        {
        printf("%c ",temp->data);
        temp=temp->next;
        }
    printf("\n");
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
    printf("%c \n\n", root->data);
    prettyPrint(root->left,level);
}

NodeTT* getTreeFromList(NodeL** head)
{
    NodeTT* nodee;
    char c=(*head)->data;
    *head=(*head)->next;
    if(c=='*')
        return NULL;
    else
    {
        nodee=createNode(c);
        nodee->left=getTreeFromList(head);
        nodee->right=getTreeFromList(head);
    }
    return nodee;
}

int main()
{
    NodeT *root=createBinTree();
    NodeL *firstFromList=getListFromTree(root);
    traverseList(firstFromList);
    root=getTreeFromList(&firstFromList);
    printf("\n\n");
    prettyPrint(root,0);
    return 0;
}
