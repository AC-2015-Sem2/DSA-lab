#include"header.h"

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
    int lefth,righth;
    if(root==NULL)
        return 0;
    if(root->left==NULL)
        lefth=0;
    else
        lefth=1+root->left->height;
    if(root->right==NULL)
        righth=0;
    else
        righth=1+root->right->height;
    return(lefth-righth);
}

NodeT* insert(NodeT* T, int value)  //! inserts a node
{
    if(T==NULL) return createNode(value);
    else if(value > T->data)
    {
        T->right=insert(T->right,value);
        if ( Balance( T ) == -2 )
        {
            if ( value > T->right->data )
                T=RR( T );
            else
                T=RL( T );
        }
    }
    else if(value < T->data)
    {
        T->left=insert(T->left,value);
        if( Balance( T ) == 2 )
        {
            if(value < T->left->data)
                T=LL(T);
            else
                T=LR(T);
        }
    }
    T->height=heigh(T);
    return T;
}


NodeT * Delete(NodeT *T,int x)
{
    NodeT *p;

    if(T==NULL)
    {
        return NULL;
    }
    else

        if(x > T->data)                // insert in right subtree
        {
            T->right=Delete(T->right,x);
            if(Balance(T)==2)
                if(Balance(T->left)>=0)
                    T=LL(T);
                else
                    T=LR(T);
        }
        else if(x<T->data)
        {
            T->left=Delete(T->left,x);
            if(Balance(T)==-2)//Rebalance during windup
                if(Balance(T->right)<=0)
                    T=RR(T);
                else
                    T=RL(T);
        }
        else
        {
            //data to be deleted is found
            if(T->right !=NULL)
            {
                //delete its inorder succesor
                p=T->right;
                while(p->left != NULL)
                    p=p->left;

                T->data=p->data;
                T->right=Delete(T->right,p->data);
                if(Balance(T)==2)//Rebalance during windup
                    if(Balance(T->left)>=0)
                        T=LL(T);
                    else
                        T=LR(T);
            }
            else
                return(T->left);

        }
    T->height=heigh(T);
    return(T);
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

