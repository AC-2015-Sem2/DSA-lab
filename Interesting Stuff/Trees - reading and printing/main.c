#include "tree.h"

int main()
{
    //! toggle whether or not you want to read and print an integer element or a string into the nodes
    //! ps: the static tree is built with integers

    // getContent = &getStringContent;
    getContent = &getIntegerContent;

        // printElement = &printStringElement;
    printElement = &printIntegerElement;

    // NodeT * root = createBinTree();
    NodeT * root = createStaticBinTree();

    printf("\n--------- START PREORDER ------------\n\n");
    preorder(root);
    printf("\n\n--------- END PREORDER ------------\n\n");

    printf("\n--------- START INORDER ------------\n\n");
    inorder(root);
    printf("\n\n--------- END INORDER ------------\n\n");

    printf("\n--------- START POSTORDER ------------\n\n");
    postorder(root);
    printf("\n\n--------- END POSTORDER ------------\n\n");

    printf("\n--------- START PRETTY PRINT ------------\n\n");
    prettyPrint(root,0);
    printf("\n\n--------- END PRETTY PRINT ------------\n\n");

    return 0;
}
