#include "../so_long.h"

void    draw_collectibles(t_game *game, t_list *lst_cl)
{
    t_list *p_lst;

    update_coll_animation(&game->coll);
    p_lst = lst_cl;
    while (p_lst)
    {
        if (!((t_cl *)p_lst->content)->collected)
            mlx_put_image_to_window(game->mlx, game->win, game->coll.curr_img,
                                    ((t_cl *)p_lst->content)->pos.x + 15, ((t_cl *)p_lst->content)->pos.y + 15);
        p_lst = p_lst->next;
    }
}

void    draw_exit(t_game *game)
{
    update_exit_animation(&game->exit);
    mlx_put_image_to_window(game->mlx, game->win, game->exit.curr_img,
                            game->exit.pos.x , game->exit.pos.y);
}

void    draw_player(t_game *game)
{
    update_player_animation(&game->player);
    if (game->player.visible)
        mlx_put_image_to_window(game->mlx, game->win, game->player.curr_img,
                                game->player.coords.x, game->player.coords.y - 15);
}