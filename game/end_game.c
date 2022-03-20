#include "../so_long.h"

static void     free_empty_exit(void *mlx, t_empty *empty, t_exit *exit)
{
    ft_lstclear(&empty->lst_emp, free);
    mlx_destroy_image(mlx, empty->ground);
    mlx_destroy_image(mlx, exit->ladder);
}

static void     free_wall(void *mlx, t_wall *wall)
{
    ft_lstclear(&wall->lst_wll, free);
    mlx_destroy_image(mlx, wall->box);
    mlx_destroy_image(mlx, wall->wall_top);
    mlx_destroy_image(mlx, wall->wall_mid);
    mlx_destroy_image(mlx, wall->up_corner_left);
    mlx_destroy_image(mlx, wall->up_corner_right);
    mlx_destroy_image(mlx, wall->left_side);
    mlx_destroy_image(mlx, wall->right_side);
    mlx_destroy_image(mlx, wall->down_corner_left);
    mlx_destroy_image(mlx, wall->down_corner_right);
    mlx_destroy_image(mlx, wall->down_left);
    mlx_destroy_image(mlx, wall->down_right);
}

static void     free_coll(void *mlx, t_collectable *coll)
{
    ft_lstclear(&coll->lst_cl, free);
    mlx_destroy_image(mlx, coll->gem_0);
    mlx_destroy_image(mlx, coll->gem_1);
    mlx_destroy_image(mlx, coll->gem_2);
    mlx_destroy_image(mlx, coll->gem_3);
    mlx_destroy_image(mlx, coll->gem_4);
}

static void     free_plr_npc(void *mlx, t_player *plr, t_npc *npc)
{
    mlx_destroy_image(mlx, plr->idle_0);
    mlx_destroy_image(mlx, plr->idle_1);
    mlx_destroy_image(mlx, plr->idle_2);
    mlx_destroy_image(mlx, plr->idle_3);
    mlx_destroy_image(mlx, plr->dead_0);
    mlx_destroy_image(mlx, plr->dead_1);
    mlx_destroy_image(mlx, plr->dead_2);
    mlx_destroy_image(mlx, plr->dead_3);
    ft_lstclear(&npc->lst_npc, free);
    mlx_destroy_image(mlx, npc->idle_0);
    mlx_destroy_image(mlx, npc->idle_1);
    mlx_destroy_image(mlx, npc->idle_2);
    mlx_destroy_image(mlx, npc->idle_3);
}

void     end_game(t_game *game)
{
    mlx_destroy_window(game->mlx, game->win);
    mem_free(game->chr_map);
    free(game->move.s_moves);
    free_empty_exit(game->mlx, &game->empty, &game->exit);
    free_wall(game->mlx, &game->wall);
    free_coll(game->mlx, &game->coll);
    free_plr_npc(game->mlx, &game->player, &game->npc);
    exit(0);
}