#include "AVL_Tree.h"

NodeT * createBinTree()
{
    NodeT *p;
    char *content = (char*)malloc(sizeof(char)*MAX_SIZE_OF_CONTENT);

    scanf( "%s" ,content );
    if ( strcmp(content,"*")==0 )
        return NULL;
    else
    {
        void * cont = getContent(content);
        p = ( NodeT *) malloc( sizeof( NodeT ) ) ;
        p->content = cont;
        p->left = createBinTree() ;
        p->right = createBinTree() ;
    }
    return p;
}

NodeT * createStaticBinTree()
{
    NodeT * root = createNode((void*)1);
    NodeT * left1 = root->left = createNode((void*)2);
    NodeT * right1= root->right = createNode((void*)5);
    left1->left = createNode((void*)3);
    left1->right= createNode((void*)4);
    right1->left = createNode((void*)6);
    right1->right = createNode((void*)7);

    return root;
}

void preorder(NodeT * root)
{
    if ( root != NULL )
    {
        printElement(root);
        preorder( root->left) ;
        preorder( root->right) ;
    }
}

void inorder(NodeT * root)
{
    if ( root != NULL )
    {
        inorder( root->left) ;
        printElement(root);
        inorder( root->right ) ;
    }
}

void postorder(NodeT * root)
{
    if ( root != NULL )
    {
        postorder( root->left ) ;
        postorder( root->right ) ;
        printElement(root);
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
        printf("     ");
    }
    //! then print value
    printElement(root);

    //! print  a new line
    printf("\n");

    prettyPrint(root->left,recLevel); //! keep going left in the tree
}

// AVL tree functions
void updateHeight(NodeT* root) {
    int hl = getHeight(root->left);
    int hr = getHeight(root->right);

    // root->height = max + 1
    if (hl > hr) {
        root->height = hl;
    } else {
        root->height = hr;
    }
    root->height++;
}

int balance(NodeT* root) {
    return getHeight(root->left) - getHeight(root->right);
}

int childCount(NodeT* root) {
    if (!root) {
        return -1;
    } else {
        int children = 0;

        if (root->left)
            children++;
        if (root->right)
            children++;

        return children;
    }
}

NodeT* minNode(NodeT* root) {
    NodeT* k = root;
    while (k->left) {
        // there are smaller nodes
        k = k->left;
    }
    return k;
}

NodeT* rotL(NodeT* root) {
    NodeT* rightChild = root->right;
    root->right = rightChild->left;
    rightChild->left = root;

    updateHeight(root);
    updateHeight(rightChild);
    return rightChild;
}

NodeT* rotR(NodeT* root) {
    NodeT* leftChild = root->left;
    root->left = leftChild->right;
    leftChild->right = root;

    updateHeight(root);
    updateHeight(leftChild);
    return leftChild;
}

NodeT* rotLR(NodeT* root) {
    root->left = rotL(root->left);
    return rotR(root);
}

NodeT* rotRL(NodeT* root) {
    root->right = rotR(root->right);
    return rotL(root);
}


NodeT* insertIn(NodeT* root, NodeT* newNode) {
    printf("el: ");
    printElement(newNode);

    if (!root) {
        printf("NULL\n\n");
        root = newNode;
    } else if (cmpContents(newNode, root) < 0) {
        // add left
        printf("left\n");
        root->left = insertIn(root->left, newNode);

        if (balance(root) == 2) {
            if (cmpContents(newNode, root->left) < 0) {
                root = rotR(root);
            } else {
                root = rotRL(root);
            }
        }
    } else if (cmpContents(newNode, root) > 0) {
        // add right
        printf("right\n");
        root->right = insertIn(root->right, newNode);

        if (balance(root) == -2) {
            if (cmpContents(newNode, root->right) > 0) {
                root = rotL(root);
            } else {
                root = rotLR(root);
            }
        }
    }

    updateHeight(root);
    return root;
}

NodeT* remFrom(NodeT* root, NodeT* toDel) {
    if (!root) {
        root = NULL;
    }

    if (cmpContents(toDel, root) < 0) {
        // toDel < root
        root->left = remFrom(root->left, toDel);
    }
    else if (cmpContents(toDel, root) > 0) {
        // toDel > root
        root->right = remFrom(root->right, toDel);
    } else {
        // toDel == root
        int childNo = childCount(root);
        if (childNo < 2) {
            // less than 2 children
            if (!childNo) {
                free(root);
                root = NULL;
            } else {
                // 1 child case
                // root becomes the non-empty child
                NodeT* temp;
                if (root->left) {
                    temp = root->left;
                    free(root);
                    root = temp;
                } else {
                    temp = root->right;
                    free(root);
                    root = temp;
                }
            }
        } else {
            // 2 children
            // root has to have the bst prop:
            // left < root < right
            // need the smallest node, larger than left
            //  = the farthest on the left of root->right

            // mistake, need to reconnect accordingly
            // or just copy the value to the root
            NodeT* temp = minNode(root->right);
            root->content = temp->content;
            free(temp);
            temp = NULL;
        }
    }

    // Check if we haven't reached a leaf
    if(root) {
        updateHeight(root);

        int bal = balance(root);

        if (bal > 1 && balance(root->left) > -1) {
            root = rotR(root);
        }

        if (bal > 1 && balance(root->left) < 0) {
            root = rotLR(root);
        }

        if (bal < -1 && balance(root->right) < 1) {
            root = rotL(root);
        }

        if (bal < -1 && balance(root->right) > 0) {
            root = rotRL(root);
        }
    }

    return root;
}
