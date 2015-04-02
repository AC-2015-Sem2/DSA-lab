#include "mainheader.h"

int main()
{
    FILE* In = NULL;
    FILE* Out = NULL;
    openFiles(&In, &Out);

    DLL* List = getListFromFile(In);
    DLLRewind(&List);
    DLLPrint(List);

    BinTree* Root = createBinTree(&List);
    prettyPrint(Out, Root, 0);

    closeFiles(&In, &Out);
    return 0;
}
