typedef struct node
{
    struct node *left, *right;
    int data;
    int height;
} nodeT;
nodeT* createNode(int data);
nodeT* createBinTree(FILE *f);
void prettyPrint(nodeT *root,int recLevel);
void inorder(nodeT* root);
nodeT* insertNode(nodeT* node, int data);
