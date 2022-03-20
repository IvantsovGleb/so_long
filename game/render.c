#include "../so_long.h"

int     render(t_game *game)
{
    mlx_clear_window(game->mlx, game->win);
    draw_empty(game);
    draw_collectibles(game, game->coll.lst_cl);
    draw_exit(game);
    draw_mob(game);
    draw_walls(game);
    put_moves_count(game->mlx, game->win, &game->move);
    return (1);
}
