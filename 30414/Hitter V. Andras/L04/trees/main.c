#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include"def.h"
#include"Treefunctions.h"
#include"Listfunctions.h"
#include"conversions.h"

int main()
{

    NodeT* root=createBinTree();
    //preorder(root);
    //createStaticBinTree();

    //! toggle whether or not you want to read and print an integer element or a string into the nodes
    //! ps: the static tree is built with integers

    // getContent = &getStringContent;
    //getContent = &getIntegerContent;

    // printElement = &printStringElement;
    // printElement = &printIntegerElement;

    //NodeT * root = createBinTree();
    //NodeT * root = createStaticBinTree();

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

    TreeToList(root);
    printf("The list from the tree:\n");
    printAll(head);
    root=ListToTree();printf("\n");
    printf("The tree made from LIST: \n");
    prettyPrint(root,0);



    return 0;
}
