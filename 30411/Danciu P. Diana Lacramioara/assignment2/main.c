#include "header.h"

int main(void)
{
    s = (Santinel *)malloc(sizeof(Santinel));
    s->head = NULL;
    s->tail = NULL;
    s->length = 0;

    FILE *fd;
    FILE *f;
    char comm[20];
    int code;

    f = fopen("output.txt", "w");
    if (f == NULL)
    {
        perror("Cannot create file!");
        return(-1);
    }
    fd = fopen("input.txt", "r");
    if (fd == NULL)
    {
        perror("Cannot open file!");
        return(-1);
    }
    while(fscanf(fd,"%s %d\n", comm, &code) > 0)
    {
        if (strcmp(comm, "AF") == 0)
        {
            AddNodeFirst(code);
        }
        else if (strcmp(comm, "AL") == 0)
        {
            AddNodeLast(code);
        }
        else if (strcmp(comm, "DF") == 0)
        {
            RemoveFirst();
        }
        else if (strcmp(comm, "DL") == 0)
        {
            RemoveLast();
        }
        else if (strcmp(comm, "DOOM_THE_LIST") == 0)
        {
            DeleteList();
        }
        else if (strcmp(comm, "DE") == 0)
        {
            RemoveNodeX(code);
        }
        else if (strcmp(comm, "PRINT_ALL") == 0)
        {
            PrintList(f);
            fprintf(f, " \n");
        }
        else if (strcmp(comm, "PRINT_F") == 0)
         {
             PrintListFront(f, code);
             fprintf(f, " \n");
         }
         else if (strcmp(comm, "PRINT_L") == 0)
         {
             PrintListLast(f, code);
             fprintf(f, " \n");
         }
    }
    fclose(fd);
    fclose(f);
    return(0);
}
