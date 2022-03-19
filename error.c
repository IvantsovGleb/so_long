#include "so_long.h"

int error(char *message)
{
    write(2, "Error\n", 6);
    write(2, message, ft_strlen(message));
    return (0);
}

void    *nll_error(char *message)
{
    write(2, "Error\n", 6);
    write(2, message, ft_strlen(message));
    return ((void *) 0);
}