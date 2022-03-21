/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:38:20 by fsinestr          #+#    #+#             */
/*   Updated: 2022/03/21 17:51:35 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	error(char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	return (0);
}

void	reset_pos(enum e_movement_dir dir, t_player *plr)
{
	if (dir == UP)
		plr->coords.y = plr->old_coords.y;
	else if (dir == LEFT)
		plr->coords.x = plr->old_coords.x;
	else if (dir == DOWN)
		plr->coords.y = plr->old_coords.y;
	else if (dir == RIGHT)
		plr->coords.x = plr->old_coords.x;
}

void	put_moves_count(void *mlx, void *win, t_move *move)
{
	static int	old_count;

	if (move->moves == 0)
	{
		move->s_moves = ft_itoa(move->moves);
		old_count = 0;
	}
	else if (move->moves > old_count)
	{
		free(move->s_moves);
		move->s_moves = ft_itoa(move->moves);
	}
	mlx_string_put(mlx, win, 32, 15, 0x00FFFFFF, move->s_moves);
}
