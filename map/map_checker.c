/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:35:30 by fsinestr          #+#    #+#             */
/*   Updated: 2022/03/21 19:57:16 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_bool	extension(int argc, char *argv[])
{
	if (argc == 1)
		return (error("no args\n"));
	if (argc >= 3)
		return (error("more than 1 argument passed\n"));
	if (ft_strcmp(ft_strrchr(argv[1], '.'), ".ber") != 0)
		return (error("wrong file extension, requires "".ber""\n"));
	return (TRUE);
}

static t_bool	uniq_char(char ch, struct s_map_info *info)
{
	if (ch == '0' || ch == '1' || ch == 'C'
		|| ch == 'E' || ch == 'P' || ch == 'S')
	{
		if (ch == 'E')
		{
			info->count_e += 1;
			info->is_e = TRUE;
		}
		else if (ch == 'C')
			info->is_c = TRUE;
		else if (ch == 'P')
		{
			info->count_p += 1;
			info->is_p = TRUE;
		}
		return (TRUE);
	}
	return (FALSE);
}

static void	check(char **map, struct s_map_info *info)
{
	int	i;
	int	j;

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

static void	init_map_info(char **map, struct s_map_info *info)
{
	info->is_e = FALSE;
	info->count_e = 0;
	info->is_c = FALSE;
	info->is_p = FALSE;
	info->count_p = 0;
	info->rectangular = TRUE;
	info->uniq_ch = TRUE;
	info->walls = TRUE;
	info->map_sz.x = ft_strlen(map[0]);
	info->map_sz.y = count_rows(map);
}

t_bool	map_valid(char **map)
{
	struct s_map_info	info;

	init_map_info(map, &info);
	check(map, &info);
	if (!info.rectangular)
		return (error("map is not rectangular\n"));
	if (!info.walls)
		return (error("map is not closed/surrounded by walls\n"));
	if (!info.uniq_ch)
	{
		error("map is not composed of '0', '1', 'C', 'P' ('S' opt.) chars\n");
		return (0);
	}
	if (!(info.is_e && info.is_c && info.is_p))
	{
		error("map must contain at least 1 'E', 1 'C' and 1 'P' position\n");
		return (0);
	}
	if (info.count_p > 1 || info.count_e > 1)
		return (error("more than one 'P', 'E' on the map\n"));
	return (TRUE);
}
