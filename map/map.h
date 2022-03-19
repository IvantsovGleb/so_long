#ifndef MAP_H
# define MAP_H

# include "../so_long.h"
# include "../data_structures/stretchy_string.h"

struct s_map_info
{
    t_bool  is_E;
    int     count_E;
    t_bool  is_C;
    t_bool  is_P;
    int     count_P;
    t_bool  rectangular;
    t_bool  uniq_ch;
    t_bool  walls;
    t_point map_sz;
};

/* tmp */
void    print_map(char  **map);
/*      */

int     count_lines(const char *path);
int     count_rows(char **map);

char    **read_map(const char *path);
t_bool  extension(int argc, char *argv[]);
t_bool  map_valid(char **map);

#endif
