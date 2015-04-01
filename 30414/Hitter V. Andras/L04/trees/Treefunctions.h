#ifndef TREEFUNCTIONS_H_INCLUDED
#define TREEFUNCTIONS_H_INCLUDED

int maxDepth(NodeT* root)
{
    if (root==NULL)
        return 0;
    else
    {
        int left=maxDepth(root->left)+1;
        int right=maxDepth(root->right)+1;
        if(left>right) return left;
        else return right;
    }
}

void reverseT(NodeL *p)
{
    if(p->next==NULL)
    {
        head=p;
        return;
    }
    else
    {
        reverseT(p->next);
        NodeL* q=p->next;
        q->next=p;
        p->next=NULL;
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

NodeT* createStaticBinTree()// !static tree!
{
    NodeT *root;
    root=createNode(5);
    root->left=createNode(6);
    root->right=createNode(7);
    root->left->left=createNode(1);
    root->left->right=createNode(2);
    root->right->right=createNode(3);
    return root;
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
    printf("%d",root->data);

    //! print  a new line
    printf("\n");

    prettyPrint(root->left,recLevel); //! keep going left in the tree
}
#endif // TREEFUNCTIONS_H_INCLUDED
