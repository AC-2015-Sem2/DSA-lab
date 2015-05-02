#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>


typedef struct node
{
    struct node*left;
    struct node*right;
    char data;
} nodeT;

typedef struct list
{
    char data;
    struct list*next;
    struct list*prev;
} nodeL;
nodeL *head, *tail;


void addLast(char x)
{
    if (head==NULL)
    {
        head=( nodeL*)malloc(sizeof( nodeL*));
        head->data=x;
        head->next=NULL;
    }
    else
    {
        if (tail==NULL)
        {
            nodeL *a=( nodeL*)malloc(sizeof( nodeL*));
            a->data=x;
            a->next=NULL;
            tail=a;
            head->next=tail;
        }
        else
        {
            nodeL *a=( nodeL*)malloc(sizeof( nodeL*));
            a->data=x;
            a->next=NULL;
            tail->next=a;
            tail=a;
        }
    }
}

nodeT*createNode(char d)
{
    nodeT*newnode=(nodeT*)malloc(sizeof(nodeT));
    newnode->data=d;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;

}

nodeT* createBinaryTree(FILE*f)
{
    nodeT* p;
    char* data=(char*)malloc(sizeof(char)*100);
    fscanf(f,"%c", data);
    if(strcpy(data, "*")==0)
        return NULL;
    else
    {
        p=createNode(atoi(data));
        p->left=createBinaryTree(f);
        p->right=createBinaryTree(f);
    }
    return p;
}


void preorder(nodeT* root)
{
    if(root!=NULL)
    {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}


void traverseList(nodeL*head)
{
    while(head!=NULL)
    {

        printf("%s",head->data);
        head=head->next;
    }
    printf("\n");
}


void printStringElement(nodeT * node)
{
    printf ( "%s " ,(char*) node->data );
}


nodeL *getListFromTree(nodeT* root)
{
    if (root==NULL) addLast('*');
    else
    {
        addLast(root->data);
        getListFromTree(root->left);
        getListFromTree(root->right);
    }
    return head;
}

nodeT*getTreeFromList()
{
nodeT*newnode=(nodeT*)malloc(sizeof(nodeT));
 char data=head->data;
head=head->next;
if (data="*") return 0;
else
{
    newnode=createNode(data);
    newnode->left=getTreeFromList();
    newnode->right=getTreeFromList();
}
return newnode;
}

void prettyPrint(nodeT *root,int recLevel) //! root, index, length, reccurence level
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
        printf(" ");
    }
//! then print value
    printStringElement(root);
//! print a new line
    printf("\n");
    prettyPrint(root->left,recLevel); //! keep going left in the tree
}


int main()
{
    FILE*f=fopen("Fisier.txt","r");
    nodeT*root=createBinaryTree(f);
    getListFromTree(root);
    traverseList(head);
    nodeT*rootfrom=getTreeFromList();
    prettyPrint(root,0);
    fclose(f);
    return 0;
}
