#include "definingStructure.h"
#include <stdlib.h>
//the head is set to point to the second element of the list
void deleteFirst()
{
    if (head!=NULL)
        head=head->next;
}
