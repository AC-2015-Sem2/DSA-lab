#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nod
{
    char data[3];
    struct nod *left;
    struct nod *right;
} NodeT;
typedef struct node
{
    char data[3];
    struct node *next;
    struct node *previous;
}NodeL;
NodeL *head,*tail;
NodeT* CreateNode(char data[3])
{
    NodeT*p=(NodeT*)malloc(sizeof(NodeT));
    strcpy(p->data,data);
    p->left=NULL;
    p->right=NULL;
    return p;
}
void addlast(char code[3])
{
    NodeL* p=(NodeL*)malloc(sizeof(NodeL));
    strcpy(p->data,code);
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
NodeT* getTreeFromList()
{
    NodeT *p;
    char content[3];
    strcpy(content,head->data);
    head=head->next;
      if(strcmp(content,"+")==0||strcmp(content,"-")==0 || strcmp(content,"*")==0 ||strcmp(content,"/")==0)
        {
        p=CreateNode(content);
        p->left=getTreeFromList();
        p->right=getTreeFromList();
    }
    else
        p=CreateNode(content);
    return p;
}
void printElement (NodeT *root)
{
    printf("%s ",root->data);
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
int main()
{
    FILE *f;
    f=fopen("input.dat","r");
    if(f==NULL)
    {
        perror("we can not open the file!");
        return -100;
    }
    char c[3];
    while(fscanf(f,"%s ",c)==1)
        addlast(c);
    NodeT *root = getTreeFromList();
    prettyPrint(root,0);
    return 0;
}
