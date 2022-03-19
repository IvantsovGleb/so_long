/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:36:45 by fsinestr          #+#    #+#             */
/*   Updated: 2021/10/26 17:03:37 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	const char	*p;
	long		sign;
	long		base;

	p = nptr;
	sign = 1;
	base = 0;
	while (ft_isspace((unsigned char)*p))
		p++;
	if (*p == '+' || *p == '-')
		sign = 1 - 2 * (*p++ == '-');
	while (ft_isdigit((unsigned char)*p))
		base = base * 10 + (*p++ - '0');
	return ((int)(sign * base));
}
