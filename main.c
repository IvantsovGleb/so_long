/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:34:40 by fsinestr          #+#    #+#             */
/*   Updated: 2022/03/21 13:37:05 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int     main(int argc, char **argv)
{
    t_game  game;
    if (!game_init(&game, argc, argv))
        return (0);

    printf("window size %d %d\n", game.win_sz.x, game.win_sz.y);
    printf("start pos (%d, %d)\n", game.player.coords.y, game.player.coords.x);

    mlx_hook(game.win, 2, 0, key_pressed, (void *)&game);
    mlx_loop_hook(game.mlx, render, (void *)&game);
    mlx_loop(game.mlx);
    return (0);
}
