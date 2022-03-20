#include "../so_long.h"

void     open_wall_images(t_game *game)
{
    game->wall.box = mlx_xpm_file_to_image(game->mlx, "sprites/box(64x92).xpm",
                                                &game->wall.img_sz.x, &game->wall.img_sz.y);
    game->wall.wall_top = mlx_xpm_file_to_image(game->mlx, "sprites/wall_top(64x64).xpm",
                                               &game->wall.img_sz.x, &game->wall.img_sz.y);
    game->wall.wall_mid = mlx_xpm_file_to_image(game->mlx, "sprites/wall_mid(64x64).xpm",
                                                     &game->wall.img_sz.x, &game->wall.img_sz.y);
    game->wall.up_corner_left = mlx_xpm_file_to_image(game->mlx, "sprites/corner_up_left(64x64).xpm",
                                                       &game->wall.img_sz.x, &game->wall.img_sz.y);
    game->wall.up_corner_right = mlx_xpm_file_to_image(game->mlx, "sprites/corner_up_right(64x64).xpm",
                                                       &game->wall.img_sz.x, &game->wall.img_sz.y);
    game->wall.down_corner_left = mlx_xpm_file_to_image(game->mlx,"sprites/corner_down_left(64x64).xpm",
                                                        &game->wall.img_sz.x, &game->wall.img_sz.y);
    game->wall.down_corner_right = mlx_xpm_file_to_image(game->mlx,"sprites/corner_down_right(64x64).xpm",
                                                        &game->wall.img_sz.x, &game->wall.img_sz.y);
    game->wall.down_left = mlx_xpm_file_to_image(game->mlx, "sprites/wall_down_left(64x64).xpm",
                                                       &game->wall.img_sz.x, &game->wall.img_sz.y);
    game->wall.down_right = mlx_xpm_file_to_image(game->mlx, "sprites/wall_down_right(64x64).xpm",
                                                        &game->wall.img_sz.x, &game->wall.img_sz.y);
    game->wall.left_side = mlx_xpm_file_to_image(game->mlx, "sprites/left_side(64x64).xpm",
                                                   &game->wall.img_sz.x, &game->wall.img_sz.y);
    game->wall.right_side = mlx_xpm_file_to_image(game->mlx, "sprites/right_side(64x64).xpm",
                                                    &game->wall.img_sz.x, &game->wall.img_sz.y);
}

void     open_ece(void *mlx, t_empty *empty, t_collectable *coll, t_exit *exit)
{
    empty->ground = mlx_xpm_file_to_image(mlx, "sprites/ground.xpm",
                                                  &empty->img_sz.x, &empty->img_sz.y);
    coll->gem_0 = mlx_xpm_file_to_image(mlx, "sprites/gem_0.xpm",
                                            &coll->img_sz.x, &coll->img_sz.y);
    coll->gem_1 = mlx_xpm_file_to_image(mlx, "sprites/gem_1.xpm",
                                            &coll->img_sz.x, &coll->img_sz.y);
    coll->gem_2 = mlx_xpm_file_to_image(mlx, "sprites/gem_2.xpm",
                                            &coll->img_sz.x, &coll->img_sz.y);
    coll->gem_3 = mlx_xpm_file_to_image(mlx, "sprites/gem_3.xpm",
                                            &coll->img_sz.x, &coll->img_sz.y);
    coll->gem_4 = mlx_xpm_file_to_image(mlx, "sprites/gem_4.xpm",
                                            &coll->img_sz.x, &coll->img_sz.y);
    coll->curr_img = coll->gem_0;
    coll->anim_frames = 10;
    exit->ladder = mlx_xpm_file_to_image(mlx, "sprites/ladder.xpm",
                                             &exit->img_sz.x, &exit->img_sz.y);
}

void    open_plr_images(void *mlx, t_player *plr)
{
    plr->idle_0 = mlx_xpm_file_to_image(mlx, "sprites/knight_0.xpm",
                                           &plr->img_sz.x, &plr->img_sz.y);
    plr->idle_1 = mlx_xpm_file_to_image(mlx, "sprites/knight_1.xpm",
                                           &plr->img_sz.x, &plr->img_sz.y);
    plr->idle_2 = mlx_xpm_file_to_image(mlx, "sprites/knight_2.xpm",
                                           &plr->img_sz.x, &plr->img_sz.y);
    plr->idle_3 = mlx_xpm_file_to_image(mlx, "sprites/knight_3.xpm",
                                           &plr->img_sz.x, &plr->img_sz.y);
    plr->curr_img = plr->idle_0;
    plr->anim_frames = 10;
    plr->dead_0 = mlx_xpm_file_to_image(mlx, "sprites/skelet_0.xpm",
                                           &plr->img_sz.x, &plr->img_sz.y);
    plr->dead_1 = mlx_xpm_file_to_image(mlx, "sprites/skelet_1.xpm",
                                           &plr->img_sz.x, &plr->img_sz.y);
    plr->dead_2 = mlx_xpm_file_to_image(mlx, "sprites/skelet_2.xpm",
                                           &plr->img_sz.x, &plr->img_sz.y);
    plr->dead_3 = mlx_xpm_file_to_image(mlx, "sprites/skelet_3.xpm",
                                           &plr->img_sz.x, &plr->img_sz.y);
}

void    open_npc_images(void *mlx, t_npc *npc)
{
    npc->idle_0 = mlx_xpm_file_to_image(mlx, "sprites/swampy_0.xpm",
                                           &npc->img_sz.x, &npc->img_sz.y);
    npc->idle_1 = mlx_xpm_file_to_image(mlx, "sprites/swampy_1.xpm",
                                           &npc->img_sz.x, &npc->img_sz.y);
    npc->idle_2 = mlx_xpm_file_to_image(mlx, "sprites/swampy_2.xpm",
                                           &npc->img_sz.x, &npc->img_sz.y);
    npc->idle_3 = mlx_xpm_file_to_image(mlx, "sprites/swampy_3.xpm",
                                           &npc->img_sz.x, &npc->img_sz.y);
    npc->curr_img = npc->idle_0;
    npc->anim_frames = 10;
}