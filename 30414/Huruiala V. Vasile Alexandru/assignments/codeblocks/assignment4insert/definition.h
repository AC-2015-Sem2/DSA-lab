typedef struct st_BTree BTree;
struct st_BTree
{
    BTree* left;
    BTree* right;
    //Max depth of subtrees
    int Lweight;
    int Rweight;

    void* data;
};
