/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:35:30 by fsinestr          #+#    #+#             */
/*   Updated: 2022/03/21 13:37:05 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_bool   extension(int argc, char *argv[])
{
    if (argc == 1)
        return (error("no args\n"));
    if (argc >= 3)
        return (error("more than 1 argument passed\n"));
    if (ft_strcmp(ft_strrchr(argv[1], '.'), ".ber") != 0)
        return (error("wrong file extension, requires "".ber""\n"));
    return (TRUE);
}

static t_bool   uniq_char(char ch, struct s_map_info *info)
{
    if (ch == '0' || ch == '1' || ch == 'C'
        || ch == 'E' || ch == 'P' || ch == 'S')
    {
        if (ch == 'E')
        {
            info->count_E += 1;
            info->is_E = TRUE;
        }
        else if (ch == 'C')
            info->is_C = TRUE;
        else if (ch == 'P')
        {
            info->count_P += 1;
            info->is_P = TRUE;
        }
        return (TRUE);
    }
    return (FALSE);
}

static void     check(char **map, struct s_map_info *info)
{
    int     i;
    int     j;

    i = 0;
    while (map[i])
    {
        j = 0;
        if ((size_t)info->map_sz.x != ft_strlen(map[i]))
            info->rectangular = FALSE;
        while (map[i][j])
        {
            if ((i == 0 || i == (info->map_sz.y - 1)) && (map[i][j] != '1'))
                info->walls = FALSE;
            if (!uniq_char(map[i][j], info))
                info->uniq_ch = FALSE;
            j++;
        }
        if ((map[i][0] == map[i][j - 1]) != 1)
            info->walls = FALSE;
        i++;
    }
}

static void init_map_info(char **map, struct s_map_info *info)
{
    info->is_E = FALSE;
    info->count_E = 0;
    info->is_C = FALSE;
    info->is_P = FALSE;
    info->count_P = 0;
    info->rectangular = TRUE;
    info->uniq_ch = TRUE;
    info->walls = TRUE;
    info->map_sz.x = ft_strlen(map[0]);
    info->map_sz.y = count_rows(map);
}

t_bool  map_valid(char **map)
{
    struct s_map_info   info;

    init_map_info(map, &info);
    check(map, &info);
    if (!info.rectangular)
        return (error("map is not rectangular\n"));
    if (!info.walls)
        return (error("map is not closed/surrounded by walls\n"));
    if (!info.uniq_ch)
        return (error("map is not composed of '0', '1', 'E', 'C', 'P' ('S' optional) characters\n"));
    if (!(info.is_E && info.is_C && info.is_P))
        return (error("map must contain at least 1 exit, 1 collectible, and 1 starting position\n"));
    if (info.count_P > 1 || info.count_E > 1)
        return (error("more than one 'P', 'E' on the map\n"));
    return (TRUE);
}
