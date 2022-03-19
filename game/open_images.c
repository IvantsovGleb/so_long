#include "../so_long.h"

 void     open_empty_images(t_game *game)
{
    game->empty.empty_img = mlx_xpm_file_to_image(game->mlx, "sprites/floor(64x64).xpm",
                                                  &game->empty.img_sz.x, &game->empty.img_sz.y);
}

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

void     open_collectible_images(t_game *game)
{
    game->coll.gem0 = mlx_xpm_file_to_image(game->mlx, "sprites/gem0.xpm",
                                                  &game->coll.img_sz.x, &game->coll.img_sz.y);
    game->coll.gem1 = mlx_xpm_file_to_image(game->mlx, "sprites/gem1.xpm",
                                              &game->coll.img_sz.x, &game->coll.img_sz.y);
    game->coll.gem2 = mlx_xpm_file_to_image(game->mlx, "sprites/gem2.xpm",
                                              &game->coll.img_sz.x, &game->coll.img_sz.y);
    game->coll.gem3 = mlx_xpm_file_to_image(game->mlx, "sprites/gem3.xpm",
                                              &game->coll.img_sz.x, &game->coll.img_sz.y);
    game->coll.gem4 = mlx_xpm_file_to_image(game->mlx, "sprites/gem4.xpm",
                                              &game->coll.img_sz.x, &game->coll.img_sz.y);
    game->coll.curr_img = game->coll.gem0;
    game->coll.anim_frames = 10;
}

void     open_exit_images(t_game *game)
{
    game->exit.idle0 = mlx_xpm_file_to_image(game->mlx, "sprites/portal_idle_0.xpm",
                                            &game->exit.img_sz.x, &game->exit.img_sz.y);
    game->exit.idle1 = mlx_xpm_file_to_image(game->mlx, "sprites/portal_idle_1.xpm",
                                            &game->exit.img_sz.x, &game->exit.img_sz.y);
    game->exit.idle2 = mlx_xpm_file_to_image(game->mlx, "sprites/portal_idle_2.xpm",
                                            &game->exit.img_sz.x, &game->exit.img_sz.y);
    game->exit.idle3 = mlx_xpm_file_to_image(game->mlx, "sprites/portal_idle_3.xpm",
                                            &game->exit.img_sz.x, &game->exit.img_sz.y);
    game->exit.idle4 = mlx_xpm_file_to_image(game->mlx, "sprites/portal_idle_4.xpm",
                                            &game->exit.img_sz.x, &game->exit.img_sz.y);
    game->exit.idle5 = mlx_xpm_file_to_image(game->mlx, "sprites/portal_idle_5.xpm",
                                             &game->exit.img_sz.x, &game->exit.img_sz.y);
    game->exit.idle6 = mlx_xpm_file_to_image(game->mlx, "sprites/portal_idle_6.xpm",
                                             &game->exit.img_sz.x, &game->exit.img_sz.y);
    game->exit.curr_img = game->exit.idle0;
    game->exit.anim_frames = 4;
}

void    open_player_images(t_game *game)
{
    t_mob   *plr;

    plr = &game->player;
    plr->idle_img0 = mlx_xpm_file_to_image(game->mlx, "sprites/plr_idle0(64x64).xpm",
                                           &plr->img_sz.x, &plr->img_sz.y);
    plr->idle_img1 = mlx_xpm_file_to_image(game->mlx, "sprites/plr_idle1(64x64).xpm",
                                           &plr->img_sz.x, &plr->img_sz.y);
    plr->idle_img2 = mlx_xpm_file_to_image(game->mlx, "sprites/plr_idle2(64x64).xpm",
                                           &plr->img_sz.x, &plr->img_sz.y);
    plr->idle_img3 = mlx_xpm_file_to_image(game->mlx, "sprites/plr_idle3(64x64).xpm",
                                           &plr->img_sz.x, &plr->img_sz.y);
    game->player.curr_img = game->player.idle_img0;
    game->player.anim_frames = 10;
}
