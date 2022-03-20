#include "../so_long.h"

static void     end_game(t_game *game)
{
    mlx_destroy_window(game->mlx, game->win);

    mem_free(game->chr_map);

    ft_lstclear(&game->empty.lst_emp, free);
    mlx_destroy_image(game->mlx, game->empty.empty_img);

    ft_lstclear(&game->wall.lst_wll, free);
    mlx_destroy_image(game->mlx, game->wall.box);

    ft_lstclear(&game->coll.lst_cl, free);
    mlx_destroy_image(game->mlx, game->coll.curr_img);

    exit(0);
}

int     key_pressed(int keycode, t_game *game)
{
    t_bool  moved;

    if (keycode == W)
        moved = move_player(UP, game);
    else if (keycode == A)
        moved = move_player(LEFT, game);
    else if (keycode == S)
        moved = move_player(DOWN, game);
    else if (keycode == D)
        moved = move_player(RIGHT, game);
    else if (keycode == ESC)
        end_game(game);
    if (moved)
        game->moves++;
    printf("moves=%d\n", game->moves);
    return (0);
}
