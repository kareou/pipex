#include "pipex.h"

void free_array(char **a)
{
    int i;

    while (a[i])
    {
        free(a[i]);
        i++;
    }
    free(a);
    a[i] = NULL;
}