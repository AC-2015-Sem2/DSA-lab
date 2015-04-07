# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct nod
{
    struct nod *left, *right;
    char *data;
}NodeT;

typedef struct nod1
{
    struct nod1 *next, *prev;
    char *elem;
}NodeL;

NodeT *newNode(char *c)
{
    NodeT *p=(NodeT*) malloc (sizeof(NodeT));
    p->data=c;
    return p;
}

NodeT *create(FILE *in)
{
    char *aux=(char*) malloc (sizeof(char)*10);
    fscanf(in, "%c", aux);
    NodeT *p;

    if(strcmp(aux, "*") == 0)
    {
        return NULL;
    }
    else
    {
        p=newNode(aux);
        p->left=create(in);
        p->right=create(in);
    }
    return p;
}

void preorder(NodeT *root)
{
    if(root!=NULL)
    {
        printf("%s ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void addNode(NodeL **head, char *data)
{
    NodeL *myNode = (NodeL*) malloc (sizeof(NodeL));
    myNode->elem = data;

    if(*head == NULL)
    {
        myNode->prev = NULL;
        myNode->next = NULL;
        *head = myNode;
    }
    else
    {
        myNode->prev = *head;
        myNode->next=NULL;
        myNode->elem=data;
        *head=myNode;
    }
}

void constructList(NodeT *root, NodeL **head)
{
    if(root!=NULL)
    {
        addNode(head, root->data);
        constructList(root->left, head);
        constructList(root->right, head);
    }
    else
        addNode(head, "*");
}

NodeL *getList(NodeT *root)
{
    NodeL *head = NULL;
    constructList(root, &head);

    while(head->prev!=NULL)
    {
        head->prev->next=head;
        head=head->prev;
    }
    return head;
}

void traverseList(NodeL *head)
{
    while(head!=NULL)
    {
        printf("%s ", head->elem);
        head=head->next;
    }
    printf("\n");
}

NodeT *getFromList(NodeL **pointer)
{
    NodeT *p;
    NodeL *first=*pointer;
    *pointer=first->next;
    if(first == NULL || strcmp(first->elem, "*") == 0)
    {
        return NULL;
    }
    else
    {
        p=newNode(first->elem);
        p->left=getFromList(pointer);
        p->right=getFromList(pointer);
        return p;
    }
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
        printf("  ");
    }

    //! then print value
    printf("%s", root->data);

    //! print a new line
    printf("\n");
    prettyPrint(root->left,recLevel); //! keep going left in the tree
}

NodeT *createBinaryTree()
{
    FILE *in;
    in=fopen("sad.txt", "r");

    NodeT *root=create(in);

    return root;

}

int main()
{
    NodeT *root = createBinaryTree();
    NodeL *first = getList(root);
    traverseList(first);
    root=getFromList(&first);
    prettyPrint(root, 0);

    return 0;
}
