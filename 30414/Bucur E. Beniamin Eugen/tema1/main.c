#include "liste.h"
#include "functii.c"

int main()
{
    FILE    *in;
    char    instr[15];
    int     x;

    in = fopen ("input.dat", "r");
    while (fscanf(in, "%s %d", instr, &x) != EOF)
    {
        if (strcmp(instr, "AF") == 0)
            ft_AF(x);
        if (strcmp(instr, "AL") == 0)
            ft_AL(x);
        if (strcmp(instr, "DF") == 0)
            ft_DF();
        if (strcmp(instr, "DL") == 0)
            ft_DL();
        if (strcmp(instr, "DOOM_THE_LIST") == 0)
            ft_DOOM_THE_LIST();
        if (strcmp(instr, "DE") == 0)
            ft_DE(x);
        if (strcmp(instr, "PRINT_ALL") == 0)
            ft_PRINT_ALL();
        if (strcmp(instr, "PRINT_F") == 0)
            ft_PRINT_F(x);
        if (strcmp(instr, "PRINT_L") == 0)
            ft_PRINT_L(x);
        print_list();
        printf ("\n");
    }
    return 0;
}
