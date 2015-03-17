#include "liste.h"

int main()
{
    FILE    *in;
    char    instr[15];
    int     x;

    in = fopen ("input.dat", "r");
    santinel = (ST*)malloc(sizeof(ST));
    santinel->head = NULL;
    santinel->tail = NULL;
    while (fscanf(in, "%s %d", instr, &x) != EOF)
    {
        if (!strcmp(instr, "AF"))
            ft_AF(x);
        if (!strcmp(instr, "AL"))
            ft_AL(x);
        if (!strcmp(instr, "DF"))
            ft_DF();
        if (!strcmp(instr, "DL"))
            ft_DL();
        if (!strcmp(instr, "DOOM_THE_LIST"))
            ft_DOOM_THE_LIST();
        if (!strcmp(instr, "DE"))
            ft_DE(x);
        if (!strcmp(instr, "PRINT_ALL"))
            ft_PRINT_ALL();
        if (!strcmp(instr, "PRINT_F"))
            ft_PRINT_F(x);
        if (!strcmp(instr, "PRINT_L"))
            ft_PRINT_L(x);
    }
    return 0;
}
