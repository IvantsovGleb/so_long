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
    mlx_put_image_to_window(game->mlx, game->win, game->exit.ladder,
                            game->exit.pos.x , game->exit.pos.y);
    if (game->exit.pos.y == game->win_sz.y - 2 * TILE_SIZE)
    {
        mlx_put_image_to_window(game->mlx, game->win, game->wall.wall_top,
                                game->exit.pos.x , game->exit.pos.y);
    }
}

void    draw_mob(t_game *game)
{
    t_list  *p_lst;

    update_npc_animation(&game->npc);
    p_lst = game->npc.lst_npc;
    while (p_lst)
    {
        mlx_put_image_to_window(game->mlx, game->win, game->npc.curr_img,
                                ((t_point *)p_lst->content)->x + 15, ((t_point *)p_lst->content)->y + 15);
        p_lst = p_lst->next;
    }
    if (game->player.state == ALIVE && game->player.visible == TRUE)
    {
        update_plr_alive_animation(&game->player);
        mlx_put_image_to_window(game->mlx, game->win, game->player.curr_img,
                                game->player.coords.x + 13, game->player.coords.y - 15);
    }
    else if (game->player.visible == TRUE)
    {
        update_plr_dead_animation(&game->player);
        mlx_put_image_to_window(game->mlx, game->win, game->player.curr_img,
                                game->player.coords.x + 15, game->player.coords.y + 15);
    }
}
