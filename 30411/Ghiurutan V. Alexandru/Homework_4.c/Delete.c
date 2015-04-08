#include "Delete.h"
NodeT *deleteNode(NodeT *root,int x)
{
    NodeT *q,*w,*r;
    if(root!=NULL)
    {
        if(root->key<x)
        {
            root->right=deleteNode(root->right,x);
        }
        else if(root->key>x)
        {
            root->left=deleteNode(root->left,x);
        }
        else
        {
            q=root;
            if(q->right==NULL)
            {
                root=q->left;
            }
            else if(q->left==NULL)
            {
                root=q->right;
            }
            else
            {
                w=q->left;
                r=q;
                if(w->right!=NULL)
                {
                    r=w;
                    w=w->right;
                }
                root->key=w->key;
                q=w;
                r->right=w->left;
                r=root->left;
                w=w->left;
                if (r!=NULL)
                {
                    while ((r!=w)&&(r!=NULL))
                    {
                        r =balancing(r);
                        r=r->right;
                    }
                }
                else
                {
                    root->key=w->key;
                    root->left=w->left;
                    q=w;
                }
            }
            free(q);
        }
    }
    if (root!=NULL)
    {
        calculEchilibru(root);
        root = balancing(root);
    }
    return root;
}

