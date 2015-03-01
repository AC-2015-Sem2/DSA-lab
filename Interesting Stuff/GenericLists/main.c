#include "list_h.h"

int main()
{
    // added (void*) just to get rid of warnings
    addFirst((void*)5);
    addFirst((void*)4);
    addFirst((void*)3);
    addFirst((void*)2);
    addFirst((void*)1);
    addFirst((void*)'a');

    printList();

    return 0;
}
