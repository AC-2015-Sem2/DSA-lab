#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node1
{
    char *c;
    struct node1 *prev,*next;
}NodeL;
NodeL *head,*tail;

typedef struct node
{
    char *c;
    struct node *left, *right;
}NodeT;

NodeT* create_tree_node(char *a)
{
    NodeT *p=(NodeT*)malloc(sizeof(NodeT));
    p->c=a;
    p->left=p->right=NULL;
    return p;
}
NodeL* create_list_node (char *x)
{
    NodeL *p=(NodeL*)malloc(sizeof(NodeL));
    p->c=x;
    p->next=p->prev=NULL;
    return p;
}
void AddLast(char *data)
{
    NodeL *p=create_list_node(data);
    if(head==NULL)
    {
        head=p;
        tail=head;
    }
    else
    {
        tail->next=p;
        p->prev=tail;
        tail=p;
    }
}
NodeT* createBinTree()
{
    NodeT *p;
    char *content=(char*)malloc(sizeof(char)*10);
    scanf("%s",content);
    if(strcmp(content,"*")==0)
        return NULL;
    else
    {
        p=(NodeT*)malloc(sizeof(NodeT));
        p->c=content;
        p->left=createBinTree();
        p->right=createBinTree();
    }
    return p;
}
NodeL* getListFromTree(NodeT *root)
{
    if(root==NULL)
        AddLast("*");
    else
    {
        AddLast(root->c);
        getListFromTree(root->left);
        getListFromTree(root->right);
    }
    return head;
}
void transverseList(NodeL *firstFList)
{
    NodeL *aux=firstFList;
    while(aux->next!=NULL)
    {
        printf("%s ",aux->c);
        aux=aux->next;
    }
}
NodeT* getTreeFromList(NodeL **firstFList)
{
    if(strcmp((*firstFList)->c,"*")==0)
    {
        *firstFList=(*firstFList)->next;
        return NULL;
    }
    else
    {
        NodeT *p=(NodeT*)malloc(sizeof(NodeT));
        p->c=(*firstFList)->c;
        *firstFList=(*firstFList)->next;
        free((*firstFList)->prev);
        p->left=getTreeFromList(firstFList);
        p->right=getTreeFromList(firstFList);
        return p;
    }

}
void deleteTree(NodeT *root)
{
    if(root==NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}
void prettyPrint(NodeT *root,int recLevel) //! root, index, length, reccurence level
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
    //printElement(root);

    //! print  a new line
    printf("\n");

    prettyPrint(root->left,recLevel); //! keep going left in the tree
}

int main()
{
        NodeT *root=createBinTree();
        NodeL *firstFromList =getListFromTree(root);
        transverseList(firstFromList);
        root=NULL;
        root=getTreeFromList(&firstFromList);
        prettyPrint(root,0);
        return 0;
}
