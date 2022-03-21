/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:38:00 by fsinestr          #+#    #+#             */
/*   Updated: 2022/03/21 19:48:32 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_pressed(int keycode, t_game *game)
{
	if (keycode == W && game->player.state == ALIVE)
		game->move.moved = move_player(UP, game);
	else if (keycode == A && game->player.state == ALIVE)
		game->move.moved = move_player(LEFT, game);
	else if (keycode == S && game->player.state == ALIVE)
		game->move.moved = move_player(DOWN, game);
	else if (keycode == D && game->player.state == ALIVE)
		game->move.moved = move_player(RIGHT, game);
	else if (keycode == ESC)
		end_game(game);
	if (game->move.moved)
	{
		game->move.moves++;
		game->move.moved = FALSE;
	}
	return (0);
}
