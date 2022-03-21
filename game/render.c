/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:38:18 by fsinestr          #+#    #+#             */
/*   Updated: 2022/03/21 19:49:47 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	render(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	draw_empty(game);
	draw_collectibles(game, game->coll.lst_cl);
	draw_exit(game);
	draw_mob(game);
	draw_walls(game);
	if (game->player.state == ALIVE)
		put_moves_count(game->mlx, game->win, &game->move);
	else if (game->player.state == DEAD)
		mlx_string_put(game->mlx, game->win, 32, 15, 0x00FF0000, "game over");
	else if (game->player.state == WIN)
		mlx_string_put(game->mlx, game->win, 32, 15, 0x0000FF00, "win");
	return (1);
}
