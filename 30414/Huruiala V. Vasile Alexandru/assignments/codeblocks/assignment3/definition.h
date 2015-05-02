typedef struct st_DLL DLL;
struct st_DLL
{
    DLL* next;
    DLL* prev;

    void* data;
};

typedef struct st_BinTree BinTree;
struct st_BinTree
{
    BinTree* left;
    BinTree* right;

    void* data;
};


