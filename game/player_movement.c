#include "../so_long.h"

static void        reset_pos(enum e_movement_dir dir, t_mob *plr)
{
    if (dir == UP)
        plr->coords.y = plr->old_coords.y;
    else if (dir == LEFT)
        plr->coords.x = plr->old_coords.x;
    else if (dir == DOWN)
        plr->coords.y = plr->old_coords.y;
    else if (dir == RIGHT)
        plr->coords.x = plr->old_coords.x;
}

static t_bool      check_collision(t_mob *plr, t_list *lst_wall, t_collectable *cl, t_exit exit)
{
    t_list *p_lst;

    if (plr->coords.x == exit.pos.x && plr->coords.y == exit.pos.y
        && cl->collects == 0)
        plr->visible = FALSE;
    p_lst = (t_list *)cl->lst_cl;
    while (p_lst)
    {
        if (((t_cl *)p_lst->content)->pos.x == plr->coords.x
            && ((t_cl *)p_lst->content)->pos.y == plr->coords.y)
        {
            --cl->collects;
            ((t_cl *) p_lst->content)->collected = TRUE;
        }
        p_lst = p_lst->next;
    }
    p_lst = lst_wall;
    while (p_lst)
    {
        if (((t_point *)p_lst->content)->x == plr->coords.x
                && ((t_point *)p_lst->content)->y == plr->coords.y)
            return (FALSE);
            p_lst = p_lst->next;
    }
    return (TRUE);
}

void    move_player(enum e_movement_dir dir, t_game *game)
{
    t_mob *plr;

    plr = &game->player;
    if (dir == UP)
    {
        plr->old_coords.y = plr->coords.y;
        plr->coords.y -= TILE_SIZE;
    }
    else if (dir == LEFT)
    {
        plr->old_coords.x = plr->coords.x;
        plr->coords.x -= TILE_SIZE;
    }
    else if (dir == DOWN)
    {
        plr->old_coords.y = plr->coords.y;
        plr->coords.y += TILE_SIZE;
    }
    else if (dir == RIGHT)
    {
        plr->old_coords.x = plr->coords.x;
        plr->coords.x += TILE_SIZE;
    }
    if (!check_collision(plr, game->wall.lst_wll, &game->coll, game->exit))
        reset_pos(dir, plr);
}
