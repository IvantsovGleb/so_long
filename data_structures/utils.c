/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:38:40 by fsinestr          #+#    #+#             */
/*   Updated: 2022/03/21 14:16:22 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stretchy_string.h"

char	*reallocation(char **d, int old_n, int new_n)
{
	char	*new_d;

	new_d = (void *) 0;
	if (!*d)
	{
		new_d = ft_calloc(new_n, sizeof(char));
		if (!new_d)
			return ((void *) 0);
	}
	else if (new_n > old_n)
	{
		new_d = ft_calloc(new_n, sizeof(char));
		if (!new_d)
			return ((void *) 0);
		ft_memcpy(new_d, *d, old_n);
		free(*d);
	}
	return (new_d);
}

void	mem_free(char **data)
{
	char	**d;

	if (data == ((void *) 0))
		return ;
	d = data;
	while (*d)
	{
		free(*d);
		d++;
	}
	free(data);
}
