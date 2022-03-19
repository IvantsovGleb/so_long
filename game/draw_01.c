#include "../so_long.h"

void    draw_empty(t_game *game)
{
    int x;
    int y;
    t_list  *p_emp;

    p_emp = game->empty.lst_emp;
    while (p_emp)
    {
        x = ((t_point *)p_emp->content)->x;
        y = ((t_point *)p_emp->content)->y;
        mlx_put_image_to_window(game->mlx, game->win, game->empty.empty_img, x, y);
        if (y == game->win_sz.y - 2 * TILE_SIZE)
            mlx_put_image_to_window(game->mlx, game->win, game->wall.wall_top, x, y);
        p_emp = p_emp->next;
    }
}

static t_bool   draw_corners(t_game *game, int x, int y)
{
    if (y == 0 && x == 0)
    {
        mlx_put_image_to_window(game->mlx, game->win, game->wall.up_corner_left, x, y);
    }
    else if (y == 0 && x == game->win_sz.x - TILE_SIZE)
    {
        mlx_put_image_to_window(game->mlx, game->win, game->wall.up_corner_right, x, y);
    }
    else if (y == game->win_sz.y - TILE_SIZE && x == 0)
    {
        mlx_put_image_to_window(game->mlx, game->win, game->wall.down_left, x, y);
    }
    else if (y == game->win_sz.y - TILE_SIZE && x == game->win_sz.x - TILE_SIZE)
    {
        mlx_put_image_to_window(game->mlx, game->win, game->wall.down_right, x, y);
    }
    else
        return (FALSE);
    return (TRUE);
}

static t_bool   draw_sides(t_game *game, int x, int y)
{
    if (y == 0 || y == game->win_sz.y - TILE_SIZE)
    {
        mlx_put_image_to_window(game->mlx, game->win, game->wall.wall_mid, x, y);
    }
    else if (x == 0)
    {
        mlx_put_image_to_window(game->mlx, game->win, game->empty.empty_img, x, y);
        if (y == game->win_sz.y - 2 * TILE_SIZE)
            mlx_put_image_to_window(game->mlx, game->win, game->wall.down_corner_left, x, y);
        mlx_put_image_to_window(game->mlx, game->win, game->wall.left_side, x, y);
    }
    else if (x == game->win_sz.x - TILE_SIZE)
    {
        mlx_put_image_to_window(game->mlx, game->win, game->empty.empty_img, x, y);
        if (y == game->win_sz.y - 2 * TILE_SIZE)
            mlx_put_image_to_window(game->mlx, game->win, game->wall.down_corner_right, x, y);
        mlx_put_image_to_window(game->mlx, game->win, game->wall.right_side, x, y);
    }
    else
        return (FALSE);
    return (TRUE);
}

void    draw_walls(t_game *game)
{
    int x;
    int y;
    t_list  *p_wll;

    p_wll = game->wall.lst_wll;
    while (p_wll)
    {
        x = ((t_point *)p_wll->content)->x;
        y = ((t_point *)p_wll->content)->y;
        if (draw_corners(game, x, y))
            ;
        else if (draw_sides(game, x, y))
            ;
        else
        {
            mlx_put_image_to_window(game->mlx, game->win, game->empty.empty_img, x, y);
            mlx_put_image_to_window(game->mlx, game->win, game->wall.box, x, y - 28);
        }
        p_wll = p_wll->next;
    }
}
