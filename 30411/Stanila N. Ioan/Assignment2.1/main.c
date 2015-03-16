#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sentinel.h"

void pseudo_cmd();

int main()
{
    pseudo_cmd();
    return 0;
}

void pseudo_cmd() {
    FILE* f;
    f = fopen("input.dat", "r");
    FILE* g;
    g = fopen("output.dat", "w");

    SENT t;
    sCreate(&t);

    char com[15];
    char subcom[15];
    int x = 0;

    while (!feof(f)) {
        fscanf(f, " %[^\n]s", com);
        sscanf(com, "%s %d", subcom, &x);

        if (!strcmp(subcom, "AF"))
            sAdd_first(&t, x);
        else if (!strcmp(subcom, "AL"))
            sAdd_last(&t, x);
        else if (!strcmp(subcom, "DF"))
            sDel_first(&t);
        else if (!strcmp(subcom, "DL"))
            sDel_last(&t);
        else if (!strcmp(subcom, "DOOM_THE_LIST"))
            sDoom_the_list(&t);
        else if (!strcmp(subcom, "DE"))
            sDel_x(&t, x);
        else if (!strcmp(subcom, "PRINT_ALL"))
            sPrint_all(t, g);
        else if (!strcmp(subcom, "PRINT_F"))
            sPrint_first_n(t, x, g);
        else if (!strcmp(subcom, "PRINT_L"))
            sPrint_last_n(t, x, g);

    }
    sDoom_the_list(&t);
}
