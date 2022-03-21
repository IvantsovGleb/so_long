/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:38:05 by fsinestr          #+#    #+#             */
/*   Updated: 2022/03/21 17:52:45 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static t_bool	define_code(t_game *game, int x, int y, t_tile_code code)
{
	if (code == EMP)
		return (add_pos(&game->empty.lst_emp, x, y));
	else if (code == WLL)
		return (add_pos(&game->wall.lst_wll, x, y));
	else if (code == COLL)
		return (add_collectible(&game->coll, x, y, &game->empty));
	else if (code == EXT)
	{
		game->exit.pos.x = x * TILE_SIZE;
		game->exit.pos.y = y * TILE_SIZE;
		game->exit.opened = FALSE;
		return (add_pos(&game->empty.lst_emp, x, y));
	}
	else if (code == PLR)
		return (add_player(&game->player, x, y, &game->empty));
	else if (code == NPC)
		return (add_pos(&game->npc.lst_npc, x, y)
			&& add_pos(&game->empty.lst_emp, x, y));
	return (TRUE);
}

static void	set_gamevars(t_game *game, char **map)
{
	int	y;
	int	x;

	game->empty.lst_emp = (void *) 0;
	game->wall.lst_wll = (void *) 0;
	game->coll.lst_cl = (void *) 0;
	game->npc.lst_npc = (void *) 0;
	game->coll.collects = 0;
	game->move.moved = FALSE;
	game->move.moves = 0;
	game->move.s_moves = (void *) 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			define_code(game, x, y, (t_tile_code)map[y][x]);
			x++;
		}
		y++;
	}
	game->win_sz.x = x * TILE_SIZE;
	game->win_sz.y = y * TILE_SIZE;
}

static void	open_images(t_game *game)
{
	open_wall_images(game->mlx, &game->wall);
	open_ece(game->mlx, &game->empty, &game->coll, &game->exit);
	open_plr_images(game->mlx, &game->player);
	open_npc_images(game->mlx, &game->npc);
}

t_bool	game_init(t_game *game, int argc, char *argv[])
{
	if (!extension(argc, argv))
		return (FALSE);
	game->chr_map = read_map(argv[1]);
	if (game->chr_map && map_valid(game->chr_map))
	{
		set_gamevars(game, game->chr_map);
	}
	else
	{
		mem_free(game->chr_map);
		return (FALSE);
	}
	game->mlx = mlx_init();
	game->win = mlx_new_window(
			game->mlx, game->win_sz.x, game->win_sz.y, "so_long");
	open_images(game);
	return (TRUE);
}
