#include "../so_long.h"

int     render(t_game *game)
{
    mlx_clear_window(game->mlx, game->win);
    draw_empty(game);
    draw_exit(game);
    draw_collectibles(game, game->coll.lst_cl);
    draw_player(game);
    draw_walls(game);
    return (1);
}
