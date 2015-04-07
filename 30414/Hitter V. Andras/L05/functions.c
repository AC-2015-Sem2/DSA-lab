#include"header.h"

int maximum(int a,int b)
{
    if(a>b) return a;
    else return b;
}
int heigh(NodeT *T)
{
    int Lheight,Rheight;
    if(T==NULL)
        return (0);
    if(T->left==NULL)
        Lheight=0;
    else
        Lheight=1+T->left->height;
    if(T->right==NULL)
        Rheight=0;
    else
        Rheight=1+T->right->height;
    if(Lheight>Rheight)
        return(Lheight);
    return(Rheight);

}

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

void preorder(NodeT *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

NodeT* createNode(int d)
{
    NodeT *p;
    p=(NodeT*)malloc(sizeof(NodeT));
    p->left=NULL;
    p->right=NULL;
    p->data=d;
    p->height=1;
    return p;
}

//NodeT* createBinTree(FILE *f)
//{
//    NodeT* p;
//    char* data=(char*)malloc(sizeof(char)*100);
//    fscanf(f,"%s",data);
//    if(strcmp(data,"*")==0)
//    {
//        return NULL;
//    }
//    else
//    {
//        p=createNode(atoi(data));
//        p->left=createBinTree(f);
//        p->right=createBinTree(f);
//    }
//    return p;
//}

int search(NodeT* root, int value) //! if found returns 1;
{
    if (root==NULL) return 0;
    else if(root->data==value) return 1;
    else if(root->data<value) return search(root->right,value);
    else return search(root->left, value);
}

NodeT *rotateright(NodeT *x)
{
    NodeT *y;
    y=x->left;
    x->left=y->right;
    y->right=x;
    x->height=heigh(x);
    y->height=heigh(y);
    return(y);
}

NodeT * rotateleft(NodeT *x)
{
    NodeT *y;
    y=x->right;
    x->right=y->left;
    y->left=x;
    x->height=heigh(x);
    y->height=heigh(y);
    return(y);
}

NodeT *RR(NodeT *T)
{
    T=rotateleft(T);
    printf("\nRotateleft(RR):\n");
    prettyPrint(T,0);
    return(T);
}

NodeT *LL(NodeT *T)
{
    T=rotateright(T);
    printf("\nRotateright( LL ):\n");
    prettyPrint(T,0);
    return(T);
}

NodeT *LR(NodeT *T)
{
    T->left=rotateleft(T->left);
    printf("\nRotateright( LR ):\n");
    prettyPrint(T,0);
    return(T);
}

NodeT *RL(NodeT *T)
{
    T->right=rotateright(T->right);
    printf("\nRotateright( RL ):\n");
    prettyPrint(T,0);
    return(T);
}

int Balance(NodeT *root)
{
    //int lefth,righth;
    if(root==NULL)
        return 0;
//    if(root->left==NULL)
//        lefth=0;
//    else
//        lefth=1+root->left->height;
//    if(root->right==NULL)
//        righth=0;
//    else
    return(heigh(root->left)-heigh(root->right));
}

NodeT* insert(NodeT *root,int data)
{
    if(root==NULL) return (createNode(data));
    if(data< root->data) root->left=insert(root->left,data);
    else root->right=insert(root->right,data);
    root->height=maximum(heigh(root->left),heigh(root->right))+1;
    int balan=Balance(root);

    if (balan>1 && data<root->left->data) return rotateright(root);

    if (balan<-1 && data>root->right->data) return rotateleft(root);

    if (balan>1 && data>root->left->data)
    {
        root->left=rotateleft(root->left);
        return(rotateright(root));
    }

    if (balan<-1 && data<root->right->data)
    {
        root->right=rotateright(root->right);
        return(rotateleft(root));
    }
    return root;


}
//the left most node
NodeT *leftmost(NodeT *root)
{
    NodeT *a=root;

    while (a->left!=NULL)
        a=a->left;

    return a;
}

NodeT* deletion(NodeT* root, int data)
{
    if (root==NULL)
        return root;
    if (data<root->data)
        root->left=deletion(root->left,data);
    else if( data>root->data )
        root->right=deletion(root->right,data);
    else
    {
        if((root->left==NULL)||(root->right == NULL))
        {
            NodeT *a;
            if(root->left!=NULL)
                a=root->left;
            else
                a=root->right;

            if(a==NULL)
            {
                a=root;
                root=NULL;
            }
            else
                *root = *a;
            free(a);
        }
        else
        {
            NodeT *a=leftmost(root->right);
            root->data=a->data;
            root->right=deletion(root->right,a->data);
        }
    }

    if (root==NULL)
        return root;
    root->height=maximum(heigh(root->left),heigh(root->right))+1;
    int balance=Balance(root);

    // Left Left case
    if (balance>1 && Balance(root->left)>=0)
        return rotateright(root);
    // Right Right
    if (balance<-1 && Balance(root->right) <= 0)
        return rotateleft(root);
    // Left Right
    if (balance>1 && Balance(root->left)<0)
    {
        root->left=rotateleft(root->left);
        return rotateright(root);
    }
    // Right Left
    if (balance<-1 && Balance(root->right) > 0)
    {
        root->right = rotateright(root->right);
        return rotateleft(root);
    }

    return root;
}

int isBSTUtil(NodeT *root,int min,int max)
{
    if(root==NULL) return 1;
    else if((root->data>max) || (root->data<min)) return 0;
    else return (isBSTUtil(root->left,min,root->data) && isBSTUtil(root->right,root->data,max));
}

int isBST(NodeT *root)
{
    return isBSTUtil(root,INT_MIN,INT_MAX);
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

