#include<stdio.h>
#include<stdlib.h>
struct node* left_left_rotation();
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
int find_height(struct node *node)
{
    int height=0;
    if (node !=NULL)
    {
        int left_height= find_height(node ->left);
        int right_height= find_height(node -> right);
        int max=(left_height > right_height) ? left_height : right_height;
        height = 1+ max;
    }
    return height;
}

int get_diff(struct node *node)
{
    int left_height=find_height(node -> left);
    int right_height=find_height(node -> right);
    int b_factor= left_height - right_height;
    return b_factor;
}
struct node* right_right_rotation(struct node *parent)
{
    struct node *node1;
    node1=parent ->right;
    parent->right = node1 -> left;
    node1 -> left= parent;
    return node1;
}
struct node* right_left_rotation(struct node *parent)
{
    struct node *node1;
    node1=parent -> right;
    parent->right = left_left_rotation(node1);
    return right_right_rotation(parent);
}
struct node* left_left_rotation(struct node *parent)
{
    struct node *node1;
    node1 = parent -> left;
    parent -> left = node1 -> right;
    node1 -> right = parent;
    return node1;
}
struct node* left_right_rotation(struct node *parent)
{
    struct node *node1;
    node1= parent -> left;
    parent-> left = right_right_rotation(node1);
    return left_left_rotation(parent);
}
struct node* balancing(struct node *node)
{
    int b_f= get_diff(node);
    if (b_f >1)
    {
        if (get_diff(node->left) >0)
            node=left_left_rotation(node);
        else
            node=left_right_rotation(node);
    }
    else if(b_f < -1)
    {
        if(get_diff(node ->right) >0)
            node=right_left_rotation(node);
        else
            node=right_right_rotation(node);
    }
    return node;
}


struct node* insert(struct node *root,int val)
{
    if (root==NULL)
    {
        root = (struct node*) malloc(sizeof(struct node));
        root -> data = val;
        root -> left = NULL;
        root -> right = NULL;
        return root;
    }
    else if (val < root->data)
    {
        root->left = insert(root->left, val);
        root=balancing(root);
    }
    else if (val > root->data)
    {
        root->right = insert(root->right, val);
        root=balancing(root);
    }
    return root;
}
void printElement (struct node *root)
{
    printf("%d",root->data);
}
void preOrder(struct node *root, struct node *k)
{
    if(root != NULL)
    {
        while (root!=k)
            printf("%d ", root->data);
        preOrder(root->left,k);
        preOrder(root->right,k);
    }
    return root;
}
void prettyPrint(struct node *root,int recLevel) //! root, index, length, reccurence level
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
struct node *deletion(struct node *root, int data)
{

    struct node *remove_node;
    if (root == NULL)
    {
        return root;
    }

    if ( data < root->data)
    {
        root->left = deletion(root->left, data);

    }
    else if ( data > root->data)
    {
        root->right = deletion(root->right,data);

    }
    else            //! now we found the node that we want to delete
    {

        if ((root->left == NULL) && (root->right != NULL))
        {
            remove_node = root->right;
            *root = *remove_node;
            free(remove_node);

        }
        else if ((root->right == NULL)  && (root->left != NULL))
        {
            remove_node = root->left;
            *root = *remove_node;
            free(remove_node);

        }
        else if ((root->right == NULL)  && (root->left == NULL))
        {
            remove_node = root;
            root = NULL;

        }
        else
        {

            //! remove_node=preOrder(0,root);   here I have the successor function, hopefully done right
            root->data = remove_node->data;
            root->right = deletion(root->right, remove_node->data);
        }
    }

    if (root == NULL)
    {
        return root;
//lr
        if (balancing(root) == 2)
        {
            if (get_diff(root->left) == -1)
            {
                root->left =left_right_rotation(root);
//ll
            }
            else if (get_diff(root->left) == 1)
            {
                left_left_rotation(root);
            }
        }
//rr
        if (get_diff(root) == -2)
        {
            if (get_diff(root->right) == -1)
            {
                right_right_rotation(root);
            }


            //rl
            else if (get_diff(root->right) == 1)
            {
                root->right = right_left_rotation(root);

            }
        }
    }

    return root;
}
int main()
{
    struct node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 14);
    root = insert(root, 90);
    root = deletion(root, 1);
    root = deletion(root, 12);
    root = deletion(root, 14);
    printf("Pre order traversal of the constructed AVL tree is \n");
    prettyPrint(root,0);

    return 0;
}
