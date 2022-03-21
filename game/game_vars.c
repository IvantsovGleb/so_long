/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:38:07 by fsinestr          #+#    #+#             */
/*   Updated: 2022/03/21 15:14:37 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_bool	add_pos(t_list **lst_pos, int x, int y)
{
	t_point	*pos;

	pos = malloc(sizeof(t_point));
	if (!pos)
		return (FALSE);
	pos->x = x * TILE_SIZE;
	pos->y = y * TILE_SIZE;
	ft_lstadd_back(lst_pos, ft_lstnew((void *)pos));
	return (TRUE);
}

t_bool	add_collectible(t_collectable *coll, int x, int y, t_empty *empty)
{
	t_cl	*p_cl;

	p_cl = malloc(sizeof(t_cl));
	if (!p_cl)
		return (FALSE);
	p_cl->pos.x = x * TILE_SIZE;
	p_cl->pos.y = y * TILE_SIZE;
	p_cl->collected = FALSE;
	ft_lstadd_back(&coll->lst_cl, ft_lstnew((void *)p_cl));
	coll->collects++;
	return (add_pos(&empty->lst_emp, x, y));
}

t_bool	add_player(t_player *plr, int x, int y, t_empty *empty)
{
	plr->visible = TRUE;
	plr->state = ALIVE;
	plr->old_coords.x = x * TILE_SIZE;
	plr->old_coords.y = y * TILE_SIZE;
	plr->coords.x = plr->old_coords.x;
	plr->coords.y = plr->old_coords.y;
	return (add_pos(&empty->lst_emp, x, y));
}
