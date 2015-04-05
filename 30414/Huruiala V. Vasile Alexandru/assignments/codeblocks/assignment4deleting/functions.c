#include "definition.h"

BTree* createBTreeNode(void* data)
{
    BTree* New = (BTree*)malloc(sizeof(BTree));
    New->data = malloc(sizeof(int));
    *(int*)New->data = *(int*)data;
    New->left = NULL;
    New->right = NULL;

    New->Lweight = 0;
    New->Rweight = 0;

    return New;
}

//Insets an element to its place
//such that it remains a binary search tree
BTree* BSTInsert(BTree* root, void* data)
{
    if(root == NULL)
        return createBTreeNode(data);
    else if(*(int*)root->data < *(int*)data)
        root->right = BSTInsert(root->right, data);
        else
        root->left = BSTInsert(root->left, data);

    return root;
}

int maxDepth(BTree* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        int left = maxDepth(root->left) + 1;
        int right = maxDepth(root->right) + 1;
        if(left > right)
            return left;
        else
            return right;
    }
}

//This will get the maximum depths of its subtrees
void getWeight(BTree* root)
{
    if(root != NULL)
    {
        root->Lweight = maxDepth(root->left);
        root->Rweight = maxDepth(root->right);
        getWeight(root->left);
        getWeight(root->right);
    }
}

BTree* BSTRotate(BTree* root)
{
    if(root == NULL)
    {
        return NULL;
    }
    else
    {
        int diff = root->Lweight - root->Rweight;
        if(diff > 1)
        //>1 means the imbalance is on the left
        {
            int zig_type = root->left->Lweight - root->left->Rweight;

            if(zig_type > 0)
            //zig-zig
            {
                //single rotation
                //store the current root
                BTree* aux = root;
                //the left child becomes the root
                root = root->left;
                //the right child of the new root becomes the left child of the old root
                aux->left = root->right;
                //the old root becomes the right child of the new root
                root->right = aux;

                return root;
            }
            else if(zig_type < 0)
            //zig-zag
            {
                //double rotation
                //1: turn to zig-zig
                //store the left child of the root(to swap it with its right child)
                BTree* aux = root->left;
                //the right child of the left child becomes the new left child of the root(1st step of the swap)
                root->left = root->left->right;
                //child transfer
                aux->right = root->left->left;
                //the child becomes the parent(to finalize the swap)
                root->left->left = aux;
                //it is a zig-zig now
                //store the current root
                aux = root;
                //the left child becomes the root
                root = root->left;
                //the right child of the new root becomes the left child of the old root
                aux->left = root->right;
                //the old root becomes the right child of the new root
                root->right = aux;

                return root;
            }

        }
        else if(diff < -1)
        //<-1 the imbalance is on the right
        {
            int zig_type = root->right->Lweight - root->right->Rweight;

            if(zig_type < 0)
            //zig-zig
            {
                //single rotation
                //store the current root
                BTree* aux = root;
                //the right child becomes the root
                root = root->right;
                //the left child of the new root becomes the right child of the old root
                aux->right = root->left;
                //the old root becomes the left child of the new root
                root->left = aux;

                return root;
            }
            else if(zig_type > 0)
            //zig-zag
            {
                //double rotation
                //1: turn to zig-zig
                //store the right child of the root(to swap it with its right child)
                BTree* aux = root->right;
                //the left child of the right child becomes the new left child of the root(1st step of the swap)
                root->right = root->right->left;
                //child transfer
                aux->left = root->right->right;
                //the child becomes the parent(to finalize the swap)
                root->right->right = aux;
                //it is a zig-zig now
                //store the current root
                aux = root;
                //the right child becomes the root
                root = root->right;
                //the left child of the new root becomes the right child of the old root
                aux->right = root->left;
                //the old root becomes the left child of the new root
                root->left = aux;

                return root;
            }
        }
        else
        {
            return root;
        }
    }
    return root;
}

//Recursive part of the function below
int isBSTUtil(BTree* root, int Min, int Max)
{
    if(root == NULL)
        return 1;
    else if((*(int*)root->data > Max)||(*(int*)root->data < Min))
        return 0;
    else
        return isBSTUtil(root->left, Min, *(int*)root->data) & isBSTUtil(root->right, *(int*)root->data, Max);
}

//True if it is a balanced binary search tree
int isBST(BTree* root)
{
    return isBSTUtil(root ,INT_MIN, INT_MAX);
}

BTree* BSTBalance(BTree* root)
{
    if(root == NULL)
    {
        return NULL;
    }
    else
    {
        BTree* aux = root;
        aux = BSTRotate(root);
        if(aux == root)
        //This means no changes occurred(rotate always changes the root if the tree is imbalanced)
        //So if a rotation took place make no more operations
        //because the root will have been altered
        {
            aux->left = BSTBalance(aux->left);
            aux->right = BSTBalance(aux->right);
        }
        return aux;
    }
}

void AVLInsert(BTree** root, void* data)
{
    //step 1: add it
    *root = BSTInsert(*root, data);
    //step 2: get feedback
    getWeight(*root);
    //step 3: if it is imba nerf it
    *root = BSTBalance(*root);
}

BTree* createAVLFromFile(FILE* I)
{
    BTree* root = NULL;
    char* data = (char*)malloc(sizeof(char)*MAX_NR_LENGTH);
    while(fscanf(I, "%s", data) != -1)
    {
        int datap = atoi(data);
        AVLInsert(&root, (void*)&datap);

    }
    return root;
}

void BSTDestroy(BTree** node)
{
    (*node)->left = NULL;
    (*node)->right = NULL;
    (*node)->Lweight = 0;
    (*node)->Rweight = 0;
    free((*node)->data);
    (*node)->data = NULL;
    free(*node);
    *node = NULL;
}

/** Searches for the data key in the tree
 * if it finds one it deletes it and re-links the tree accordingly:
 * -if it is a leaf it just disconnects its parent from it
 * -if it is an internal node with 1 child it gives it to its predecessor
 * -if it has 2 children it searches for the nearest numerical successor(on the right)
 * or numerical predecessor(on the left), either of them
 * taking the place of the node and taking their children
 * and reestablishes the links(since the pred or succ got removed from there as well)
 */

void AVLDelete(BTree** root, void* data_key)
{
    if(*root == NULL)
        return;
    //Search for the node
    BTree* dnode = *root;
    //We need to keep track of the previous node at all times
    //so we can reconnect the tree after the removal of the node
    BTree* prev = NULL;
    while((dnode != NULL) && (*(int*)dnode->data != *(int*)data_key))
    {
        prev = dnode;
        if(*(int*)dnode->data > *(int*)data_key)
            dnode = dnode->left;
        else
            dnode = dnode->right;

    }
    if(dnode == NULL)
        return;
    else
    //Node found, now delete it
    {
        if(dnode->left == NULL && dnode->right == NULL)
        //Case 1: it is a leaf
        {
            if(prev != NULL)
            {
                //Remove the link to th node depending on the case
                if(prev->left == dnode)
                    prev->left = NULL;
                else if(prev->right == dnode)
                    prev->right = NULL;
            }
            else
            {
                *root = NULL;
            }
        }
        else if(dnode->left != NULL && dnode->right == NULL)
        //Case 2.1: the node has a left child
        {
            if(prev != NULL)
            {
                //Transfer the dnode's child to the previous node
                if(prev->left == dnode)
                    prev->left = dnode->left;
                else if(prev->right == dnode)
                    prev->right = dnode->left;
            }
            else
            {
                *root = (*root)->left;
            }
        }
        else if(dnode->left == NULL && dnode->right != NULL)
        //Case 2.2: the node has a right child
        {
            if(prev != NULL)
            {
                //Transfer the dnode's child to the previous node
                if(prev->left == dnode)
                    prev->left = dnode->right;
                else if(prev->right == dnode)
                    prev->right = dnode->right;
            }
            else
            {
                *root = (*root)->right;
            }
        }
        else
        //Case 3: the node has 2 children
        {
            if(prev == NULL)
            //dnode == *root
            //since it is the root, it does't really matter if it searches a lower or higher number
            {
                //Find the numerical successor of the dnode to replace it
                //and to take the children
                BTree* replacement = (*root)->left;
                BTree* prev_repl = *root;
                while(replacement->right != NULL)
                {
                    prev_repl = replacement;
                    replacement = replacement->right;
                }
                if(prev_repl == dnode)
                {
                    replacement->right = (*root)->right;
                    *root = replacement;
                }
                else
                {
                    prev_repl->right = replacement->left;
                    replacement->left = (*root)->left;
                    replacement->right = (*root)->right;
                    *root = replacement;
                }
            }
            else if(prev->left == dnode)
            {
                //Find the numerical successor of the dnode to replace it
                //and to take the children
                BTree* replacement = dnode->left;
                BTree* prev_repl = dnode;
                while(replacement->right != NULL)
                {
                    prev_repl = replacement;
                    replacement = replacement->right;
                }
                if(prev_repl == dnode)
                {
                    replacement->right = dnode->right;
                    prev->left = replacement;
                }
                else
                {
                    prev_repl->right = replacement->left;
                    replacement->left = dnode->left;
                    replacement->right = dnode->right;
                    prev->left = replacement;
                }
            }
            else if(prev->right == dnode)

            {
                //Find the numerical predecessor of the dnode to replace it
                //and to take the children
                BTree* replacement = dnode->right;
                BTree* prev_repl = dnode;
                while(replacement->left != NULL)
                {
                    prev_repl = replacement;
                    replacement = replacement->left;
                }
                if(prev_repl == dnode)
                {
                    replacement->left = dnode->left;
                    prev->right = replacement;
                }
                else
                {
                    prev_repl->left = replacement->right;
                    replacement->right = dnode->right;
                    replacement->left = dnode->left;
                    prev->right = replacement;
                }
            }
        }
        //Destroy the now isolated node
        BSTDestroy(&dnode);
    }
    //After deletion re-balance it
    getWeight(*root);
    *root = BSTBalance(*root);
}

void deleteAVLFromFile(FILE* I, BTree** root)
{
    char* data = (char*)malloc(sizeof(char)*MAX_NR_LENGTH);
    while(fscanf(I, "%s", data) != -1)
    {
        int datap = atoi(data);
        AVLDelete(root, (void*)&datap);
    }
}
