/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:10:25 by fsinestr          #+#    #+#             */
/*   Updated: 2022/03/21 18:10:40 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t n)
{
	char	*copy;
	size_t	slen;
	size_t	i;

	if (!str)
		return (NULL);
	slen = 0;
	while (slen < n && str[slen])
		slen++;
	copy = (char *)malloc(slen + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < slen)
	{
		*((char *) copy + i) = *((char *) str + i);
		i++;
	}
	copy[slen] = '\0';
	return (copy);
}
