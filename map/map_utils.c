/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:35:34 by fsinestr          #+#    #+#             */
/*   Updated: 2022/03/21 16:35:44 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	count_lines(const char *path)
{
	char	ch;
	int		count;
	int		fd;
	int		r;

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

int	count_rows(char **map)
{
	int	i;

	i = 0;
	while (map[i++])
		;
	return (i);
}
