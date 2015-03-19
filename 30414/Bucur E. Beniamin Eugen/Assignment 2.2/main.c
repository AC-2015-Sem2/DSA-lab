#include "header.h"

int main()
{
    FILE        *in;
    FILE        *out;
    unsigned    nrs;
    unsigned    nrd;
    node1       *aux;

    in = fopen ("input.dat", "r");
    out = fopen ("output.dat", "w");
    tail1 = NULL;
    while (fscanf(in, "%u", &nrs))
        ft_AL(nrs);
    while (fscanf(in, "%*s %u %u", &nrd, &nrs) != EOF)
        ft_enq (nrd, nrs);
    aux = head1;
    while (aux != NULL)
    {
        nrd = ft_compute(aux->time);
        fprintf(out, "After %u seconds: %u\n", aux->time, nrd);
        aux = aux->next;
    }
    return 0;
}
