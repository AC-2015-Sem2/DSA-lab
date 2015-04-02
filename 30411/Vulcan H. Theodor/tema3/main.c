#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodeT
{
    int code;
    struct node *left,*right;

}TreeNode;

TreeNode *root;

typedef struct node
{
    int code;
    struct node *next;

}NodeL;

NodeL *head,*tail;

void addLast(int code)
{
    if (head==NULL)
    {
        head=(struct node*)malloc(sizeof(struct node*));
        head->code=code;
        head->next=NULL;
    }
    else
    {
        if (tail==NULL)
        {
            struct node *p=(struct node*)malloc(sizeof(struct node*));
            p->code=code;
            p->next=NULL;
            tail=p;
            head->next=tail;
        }
        else
        {
            struct node *p=(struct node*)malloc(sizeof(struct node*));
            p->code=code;
            p->next=NULL;
            tail->next=p;
            tail=p;
        }
    }
}



TreeNode *createNode(int code)
{
    TreeNode *p=(TreeNode*)malloc(sizeof(TreeNode));
    p->code=code;
    p->left=p->right=NULL;
    return p;
}

TreeNode* createBinTree()
{
    TreeNode *p;
    char *content=(char*)malloc(sizeof(char)*20);
    scanf("%s", content);
    if (strcmp(content,"*")==0)
        return NULL;
    else
    {
        p=createNode(atoi(content));
    }
    p->left=createBinTree();
    p->right=createBinTree();

return p;
}

void printElement(TreeNode * node)
{
    printf ( "%d " ,(int) node->code );
}

void prettyPrint(TreeNode *root,int recLevel) //! root, index, length, reccurence level
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

void getlistfromtree(TreeNode *root)
{

    if (root==NULL)
    {
        addLast(-1);
    }
    else
    {
        addLast(root->code);
        getlistfromtree(root->left);
        getlistfromtree(root->right);
    }

}


TreeNode *gettreefromlist()
{

    TreeNode *p;
    int content;
    content=head->code;
    head=head->next;
    if (content==-1)
        return NULL;
    else
    {
        p=createNode(content);
        p->left=gettreefromlist();
        p->right=gettreefromlist();
    }
    return p;
}

void printlist()
{
    struct node *p=head;
    while (p!=NULL)
    {
        printf("%d ",p->code);
        p=p->next;
    }
    printf("\n");
}

int main()
{
    TreeNode *root=createBinTree();
    getlistfromtree(root);
    root=gettreefromlist(head);
    prettyPrint(root,0);
    printlist();

    return 0;
}
