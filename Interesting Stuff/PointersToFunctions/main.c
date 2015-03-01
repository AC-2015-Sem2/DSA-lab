#include "list.h"

int main()
{
    initList();
    (*listObj->addFirst)((void*)5);
    (*listObj->addFirst)((void*)4);
    (*listObj->addFirst)((void*)3);
    (*listObj->addFirst)((void*)2);
    (*listObj->addFirst)((void*)1);

    setPrintFunctionToV1();
    (*listObj->printList)();

    setPrintFunctionToV2();
    (*listObj->printList)();
    return 0;
}
