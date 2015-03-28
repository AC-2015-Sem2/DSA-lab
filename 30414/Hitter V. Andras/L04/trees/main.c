#include<string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct nodel
{
    struct node *next;
    struct node *prev;
    char data;
}NodeL;
NodeL *head=NULL,*tail=NULL;

typedef struct nodet
{
    struct node* left;
    struct node* right;
    int data;
}NodeT;


//
//int maxDepth(NodeT* root)
//{
//    if (root==NULL)
//        return 0;
//    else
//    {
//        int left=maxDepth(root->left)+1;
//        int right=maxDepth(root->right)+1;
//        if(left>right) return left;
//        else return right;
//    }
//}
//
//void reverse(NodeT *p)
//{
//    if(p->next==NULL)
//    {
//        head=p;
//        return;
//    }
//    else
//    {
//        reverse(p->next);
//        NodeT* q=p->next;
//        q->next=p;
//        p->next=NULL;
//    }
//}

void AddLast(char *x)
{
    if (head==NULL)
    {
        head=(NodeL *)malloc(sizeof(NodeL));
        head->next=NULL;
        head->prev=NULL;
        head->data=x;
        tail=head;
    }
    else
    {
        NodeL *a=(NodeL *)malloc(sizeof(NodeL));
        a->data=x;
        a->next=NULL;
        a->prev=tail;
        tail->next=a;
        tail=a;
    }
}

NodeT* createNode(int d)
{
    NodeT *p;
    p=(NodeT*)malloc(sizeof(NodeT));
    p->left=NULL;
    p->right=NULL;
    p->data=d;
    return p;
}

NodeT* createBinTree()
{
    NodeT* p;
    char* data=(char*)malloc(sizeof(char)*100);
    scanf("%s",data);
    if(strcmp(data,"*")==0)
    {
        return NULL;
    }
    else
    {
        p=createNode(atoi(data));
        p->left=createBinTree();
        p->right=createBinTree();
    }
    return p;
}

void preorder(NodeT *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void TreeToList(NodeT *root)
{
    if(root==NULL)
    {
        AddLast('*');
    }
    else
    {
        AddLast(root->data);
        TreeToList(root->left);
        TreeToList(root->right);
    }

}

NodeT* ListToTree()
{
    NodeT *a=NULL;
    if (head!=NULL)
    {
        int i=head->data;
        if(i==42)
        {
            head=head->next;
        }
        else
        {
            a=createNode(head->data);
            head=head->next;
            a->left=ListToTree();
            a->right=ListToTree();

        }


    }
    return a;
}
void printAll(NodeL *head)
{
    NodeL *aux;
    {
    aux=head;
    while (aux!=NULL)
    {
        int i=aux->data;
        if(i!=42)
        printf("%d ",aux->data);
        else
            printf("%c ",aux->data);
        aux=aux->next;
    }
    printf("\n");}
}

void inorder(NodeT* root)
{
    if(root!=NULL)
    {
       inorder(root->left);
       printf("%d ",root->data);
       preorder(root->right);
    }
}

void postorder(NodeT* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}

//NodeT* createStaticBinTree()// !static tree!
//{
//    NodeT *root;
//    root=createNode(5);
//    root->left=createNode(6);
//    root->right=createNode(7);
//    root->left->left=createNode(1);
//    root->left->right=createNode(2);
//    root->right->right=createNode(3);
//    return root;
//}

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
    printf("%d",root->data);

    //! print  a new line
    printf("\n");

    prettyPrint(root->left,recLevel); //! keep going left in the tree
}

int main()
{

    NodeT* root=createBinTree();
    //preorder(root);
    //createStaticBinTree();

    //! toggle whether or not you want to read and print an integer element or a string into the nodes
    //! ps: the static tree is built with integers

    // getContent = &getStringContent;
    //getContent = &getIntegerContent;

        // printElement = &printStringElement;
   // printElement = &printIntegerElement;

    //NodeT * root = createBinTree();
    //NodeT * root = createStaticBinTree();

    printf("\n--------- START PREORDER ------------\n\n");
    preorder(root);
    printf("\n\n--------- END PREORDER ------------\n\n");

    printf("\n--------- START INORDER ------------\n\n");
    inorder(root);
    printf("\n\n--------- END INORDER ------------\n\n");

    printf("\n--------- START POSTORDER ------------\n\n");
    postorder(root);
    printf("\n\n--------- END POSTORDER ------------\n\n");

    printf("\n--------- START PRETTY PRINT ------------\n\n");
    prettyPrint(root,0);
    printf("\n\n--------- END PRETTY PRINT ------------\n\n");

TreeToList(root);
printf("The list from the tree:\n");
printAll(head);
root=ListToTree();
printf("The tree made from LIST \n");
prettyPrint(root,0);



    return 0;
}
