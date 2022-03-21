/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stretchy_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:38:34 by fsinestr          #+#    #+#             */
/*   Updated: 2022/03/21 14:13:47 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stretchy_string.h"

static void	t_string_grow(t_string *s, int by)
{
	char	*new_d;

	if (s->i + by > s->n)
	{
		new_d = reallocation(&(s->d), s->n, s->n + by);
		if (!new_d)
			exit(-1);
		s->d = new_d;
		s->n += by;
	}
}

void	t_string_init(void *s)
{
	t_string	*tmp_s;

	tmp_s = (t_string *)s;
	tmp_s->d = (void *) 0;
	tmp_s->n = 0;
	tmp_s->i = 0;
	t_string_grow(tmp_s, 100);
}

void	t_string_copy(void *dst, const void *src)
{
	t_string			*tmp_dst;
	const t_string		*tmp_src;

	tmp_dst = (t_string *)dst;
	tmp_src = (t_string *)src;
	tmp_dst->n = tmp_src->n;
	tmp_dst->i = tmp_src->i;
	if (tmp_src->d)
		tmp_dst->d = ft_strdup(tmp_src->d);
	else
		tmp_dst->d = (void *) 0;
}

void	t_string_destructor(void *s)
{
	t_string	*tmp_s;

	tmp_s = (t_string *)s;
	free(tmp_s->d);
	tmp_s->d = (void *) 0;
	tmp_s->n = 0;
	tmp_s->i = 0;
}

void	t_string_push_back(t_string *s, char ch)
{
	t_string_grow(s, 1);
	s->d[s->i++] = ch;
}
