#include "map.h"

/* print map */
void    print_map(char **map)
{
    int i = 0;
    int j;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            printf("%c", map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}
/*          */

int  count_lines(const char *path)
{
    char    ch;
    int count;
    int fd;
    int r;

    fd = open(path, O_RDONLY);
    if (!fd)
        return (-1);
    count = 1;
    while (TRUE)
    {
        r = read(fd, &ch, 1);
        if (r < 0)
            return (-1);
        if (r == 0)
            break ;
        if (ch == '\n')
            count++;
    }
    close(fd);
    return (count);
}

int count_rows(char **map)
{
    int i;

    i = 0;
    while (map[i++])
        ;
    return (i);
}
