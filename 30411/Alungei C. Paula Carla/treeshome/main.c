#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node
{
    struct node* right, *left;
    int data;
} NodeT;

typedef struct list
{
    struct list* previous, *next;
    int data;
} NodeL;

NodeT* createnode(int q)
{
    NodeT* p= (NodeT*)malloc(sizeof(NodeT));
    p->data=q ;
    p->left= NULL;
    p-> right= NULL;
    return p;
}

NodeT * createbintree()
{
    NodeT *p;
    char *content= (char*)malloc(20*sizeof(char));
    scanf("%s", content);
    if (strcmp(content, "*")==0) return NULL;
    else
    {
        NodeT* p= createnode(atoi(content));
        p->left= createbintree();
        p->right= createbintree();
        return p;
    }

}
NodeL *head, *tail;
void addlast(int code)
{
    NodeL* p=(NodeL*)malloc(sizeof(NodeL));
    p->data=code;
    if(head==NULL)
    {
        head=p;
        tail=p;
        p->next=NULL;
    }
    else if(tail!=NULL)
    {
        p->next=NULL;
        tail->next=p;
        tail=p;

    }
}

void getListFromTree(NodeT* root)
{
    if(root!=NULL)
    {
        addlast(root->data);
        getListFromTree(root->left);
        getListFromTree(root->right);
    }
    else
    {
        addlast('*');

    }
}

void printlist()
{
    NodeL* now=head;
    while(now!=NULL)
    {
        {
            printf("%d ",now->data );
            now=now->next;
        }
        printf("\n");
    }
}

NodeT* getTreeFromList()
{
    NodeT *p;
    int content;
    content=head->data;
    head=head->next;
    if(content==-1)
        return NULL;
    else
    {
        p=createnode(content);
        p->left=getTreeFromList();
        p->right=getTreeFromList();
    }
    return p;
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
    printElement(root);

    //! print  a new line
    printf("\n");

    prettyPrint(root->left,recLevel); //! keep going left in the tree
}

void printElement (NodeT *root)
{
    printf("%d",root->data);
}

int main()
{
    NodeT *root=createbintree();
    getListFromTree(root);
    printlist();
    root = getTreeFromList();
    prettyPrint(root,0);
    return 0;
}
