#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    struct node *left;
    struct node *right;
    char *data;
} NodeT;
typedef struct NodeL
{
    char *data;
    struct NodeL* next;
    struct NodeL* prev;
} NodeL;

NodeL *head, *tail;
NodeT *root;
void addLast(char *data)
{
    NodeL *p=(NodeL*)malloc(sizeof(NodeL));
    p->data=data;

    if(head==NULL)
    {
        p->prev=NULL;
        p->next=NULL;
        head=p;
        tail=head;
    }
    else
    {
        tail->next=p;
        p->prev=tail;
        p->next=NULL;
        tail=p;
    }
}


NodeT *createBinTree()
{
    char *data=(char*)malloc(sizeof(char)*20);
    scanf("%s",data);
    if(strcmp(data,"*")==0)
        return NULL;
    else
    {
        NodeT *p=(NodeT*)malloc(sizeof(NodeT));
        p->data=data;
        p->left=createBinTree();
        p->right=createBinTree();
        return p;
    }
}

void delTree(NodeT *root)
{
    if(root==NULL)
        return;

    delTree(root->left);
    delTree(root->right);
    free(root);
}
void traverseList()
{
    NodeL *aux=head;
    while(aux != NULL)
    {
        printf("%s ",aux->data);
        aux=aux->next;
    }
    printf("\n");
}
NodeT *getTreefromList(NodeL **head)
{
    if(strcmp((*head)->data,"*")==0)
    {
        *head=(*head)->next;
        return NULL;
    }
    else
    {
        NodeT *p=(NodeT*)malloc(sizeof(NodeT));
        p->data=(*head)->data;
        *head=(*head)->next;
        free((*head)->prev);
        p->left=getTreefromList(head);
        p->right=getTreefromList(head);
        return p;
    }
}
NodeL *getListfromTree(NodeT *root)
{
    if(root==NULL)
    {
        addLast("*");
    }
    else
    {
        addLast(root->data);
        getListfromTree(root->left);
        getListfromTree(root->right);
    }
    return head;
}

void prettyPrint(NodeT *root,int level)
{
    if(root==NULL)
    {
        level--; //! reached leaf, must decrement recur
        return;
    }
    level++; //! otherwise increment it
    prettyPrint(root->right,level); //! keep going right in the tree
    int j=0;

    //! print spaces for the appropriate recurrence level
    for(j=0; j<level-1; j++)
    {
        printf("     ");
    }
    //! then print value
    printf ( "%s " ,root->data );
    //! print  a new line
    printf("\n");

    prettyPrint(root->left,level); //! keep going left in the tree

}

int main()
{
    root=createBinTree();
    head=getListfromTree(root);
    printf("List to Tree: ");
    traverseList();
    printf("\n");
    delTree(root);
    root=NULL;
    root=getTreefromList(&head);
    printf("Tree to List: \n");
    prettyPrint(root,0);

    return 0;
}
