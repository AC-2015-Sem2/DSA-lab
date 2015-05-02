#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int key;
    unsigned char height;
    struct  node* left;
    struct node* right;

} nodeT;


unsigned char height(nodeT* root)
{
    if(root==NULL) return 0;
    else return root->height;
}

int bfactor(nodeT* root)
{
    return height(root->right)-height(root->left);
}

void fixheight(nodeT* root)
{
    unsigned char hl = height(root->left);
    unsigned char hr = height(root->right);

    if(hl>hr) root->height=hl+1;
    else root->height=hr+1;
}

nodeT* rotateright(nodeT* y)
{
    nodeT* x = y->left;
    y->left = x->right;
    x->right = y;
    fixheight(y);
    fixheight(x);
    return x;
}

nodeT* rotateleft(nodeT* y)
{
    nodeT* x = y->right;
    y->right = x->left;
    x->left = y;
    fixheight(y);
    fixheight(x);
    return x;
}

nodeT* balance(nodeT* p) // balancing the p node
{
    fixheight(p);
    if( bfactor(p)==2 )
    {
        if( bfactor(p->right) < 0 )
            p->right = rotateright(p->right);
        return rotateleft(p);
    }
    if( bfactor(p)==-2 )
    {
        if( bfactor(p->left) > 0  )
            p->left = rotateleft(p->left);
        return rotateright(p);
    }
    return p; // balancing is not required
}

nodeT* newNode(int key)
{
    struct node* p = (nodeT*)malloc(sizeof(nodeT));
    p->key   = key;
    p->left   = NULL;
    p->right  = NULL;
    p->height = 1;  // new node is initially added at leaf
    return(p);
}

nodeT* insert(nodeT* root, int k) // insert k key in a tree with root root
{
    if( root==NULL ) return newNode(k);
    if( k < root->key )
        root->left = insert(root->left,k);
    else
        root->right = insert(root->right,k);
    return balance(root);
}

nodeT* findmin(nodeT* p) // find a node with minimal key in a p tree
{
    if(p->left == NULL) return p;
    else return findmin(p->left);


}

nodeT* removemin(nodeT* p) // deleting a node with minimal key from a p tree
{
    if( p->left==0 )
        return p->right;
    p->left = removemin(p->left);
    return balance(p);
}

nodeT* removeKey(nodeT* p, int k) // deleting k key from p tree
{
    if( !p ) return 0;
    if( k < p->key )
        p->left = removeKey(p->left,k);
    else if( k > p->key )
        p->right = removeKey(p->right,k);
    else //  k == p->key
    {
        nodeT* x = p->left;
        nodeT* y = p->right;
        free(p);
        if( y==NULL ) return x;
        nodeT* min = findmin(y);
        min->right = removemin(y);
        min->left = x;
        return balance(min);
    }
    return balance(p);
}
FILE *out;
void prettyPrint(struct node *root,int level)
{
    if(root==NULL)
    {
        level--; //! reached leaf, must decrement recurence level
        return;
    }
    level++; //! otherwise increment it
    prettyPrint(root->right,level); //! keep going right in the tree
    int j=0;

    //! print spaces for the appropriate recurence level
    for(j=0; j<level-1; j++)
    {
        fprintf(out, "     ");
    }
    //! then print value
    //printElement(root);
    fprintf (out, "%d " ,root->key );
    //! print  a new line
    fprintf(out,"\n");

    prettyPrint(root->left,level); //! keep going left in the tree
    //fclose(file);
}

int main()
{
    nodeT *root=NULL;

    FILE *a=fopen("for_insert.txt","r");
    FILE *b=fopen("for_delete.txt","r");
    out=fopen("output_after_insert_delete.txt","w");



    if(a==NULL) perror("something wrong with the insert file");
    if(b==NULL) perror("something wrong with the delete file");
    if(out==NULL) perror("something wrong with the output_insert file");

    int n;
    fprintf(out,"These keys will be inserted in AVL: ");

    while(fscanf(a,"%d ",&n)==1)
    {

        fprintf(out,"%d ",n);

        root=insert(root, n);

    }

    fprintf(out,"\n");
    fprintf(out,"\n");
    prettyPrint(root,0);
    fprintf(out,"\n");
    fprintf(out,"These keys will be deleteted from AVL: ");
    while(fscanf(b,"%d ",&n)==1)
    {

        fprintf(out,"%d ",n);

        root=removeKey(root, n);

    }


    fprintf(out,"\n");
    fprintf(out,"\n");
    prettyPrint(root,0);
    fclose(a);
    fclose(b);
    fclose(out);

    return 0;

}
