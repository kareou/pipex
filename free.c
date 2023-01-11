#include "pipex.h"

void free_array(char **a, int i, int stop)
{
    while (i <= stop)
    {
        free(a[i]);
        i++;
    }
    free(a);
}