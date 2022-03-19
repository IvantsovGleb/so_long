#include "../so_long.h"

t_bool   define_code(t_game *game, int x, int y, t_tile_code code);

static void    set_gamevars(t_game *game, char **map)
{
    int y;
    int x;

    game->empty.lst_emp = (void *) 0;
    game->wall.lst_wll = (void *) 0;
    game->coll.lst_cl = (void *) 0;
    game->coll.collects = 0;
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

static void    open_images(t_game  *game)
{
    open_empty_images(game);
    open_wall_images(game);
    open_collectible_images(game);
    open_exit_images(game);
    open_player_images(game);
}

t_bool  game_init(t_game *game, int argc, char *argv[])
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
    game->win = mlx_new_window(game->mlx , game->win_sz.x, game->win_sz.y, "so_long");
    open_images(game);
    return (TRUE);
}
