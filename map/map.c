/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:35:37 by fsinestr          #+#    #+#             */
/*   Updated: 2022/03/21 13:36:48 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static char     **alloc_rows(int m)
{
    char    **map_rows;

    if (m <= 0)
        return ((void *) 0);
    map_rows = malloc((m + 1) * sizeof(char *));
    if (!map_rows)
        return ((void *) 0);
    map_rows[m] = (void *) 0;
    return (map_rows);
}

static int  my_read(int fd, char **dst)
{
    t_string    str;
    char    ch;
    int     r;

    t_string_init(&str);
    while (TRUE)
    {
        r = read(fd, &ch, 1);
        if (r < 0)
        {
            t_string_destructor(&str);
            return (-1);
        }
        if (r == 0 || ch == '\n')
        {
            *dst = ft_strdup(str.d);
            break ;
        }
        else
            t_string_push_back(&str, ch);
    }
    t_string_destructor(&str);
    return (1);
}

char     **read_map(const char *path)
{
    char    **map;
    int     fd;
    int     i;
    int     m;

    m = count_lines(path);
    map = alloc_rows(m);
    if (!map)
        return ((void *) 0);
    fd = open(path, O_RDONLY);
    i = 0;
    while (i < m)
    {
        if (my_read(fd, &map[i]) < 0)
        {
            while (i > 0)
                free(map[--i]);
            free(map);
            return ((void *) 0);
        }
        i++;
    }
    close(fd);
    return (map);
}
