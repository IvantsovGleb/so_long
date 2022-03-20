#include "../so_long.h"

static void     check_coll_collision(t_player *plr, t_collectable *coll)
{
    t_list  *p_lst;
    t_cl    *cl;

    p_lst = coll->lst_cl;
    while (p_lst)
    {
        cl = (t_cl *)p_lst->content;
        if (cl->pos.x == plr->coords.x && cl->pos.y == plr->coords.y)
        {
            cl->collected = TRUE;
            coll->collects -= 1;
        }
        p_lst = p_lst->next;
    }
}

static t_bool      check_wall_collision(t_player *plr, t_list *lst_wall)
{
    t_list  *p_lst;
    t_point *wll_pos;

    p_lst = lst_wall;
    while (p_lst)
    {
        wll_pos = (t_point *)p_lst->content;
        if (wll_pos->x == plr->coords.x && wll_pos->y == plr->coords.y)
            return (FALSE);
        p_lst = p_lst->next;
    }
    return (TRUE);
}

static t_bool      check_npc_collision(t_player *plr, t_list *lst_npc)
{
    t_list  *p_lst;
    t_point *npc_pos;

    p_lst = lst_npc;
    while (p_lst)
    {
        npc_pos = (t_point *)p_lst->content;
        if (npc_pos->x == plr->coords.x && npc_pos->y == plr->coords.y)
        {
            plr->state = DEAD;
            return (FALSE);
        }
        p_lst = p_lst->next;
    }
    return (TRUE);
}

static t_bool   check_collision(enum e_movement_dir dir, t_game *game)
{
    if (game->exit.pos.y == game->player.coords.y && game->exit.pos.x == game->player.coords.x
        && game->coll.collects <= 0)
    {
        game->player.state = WIN;
        game->player.visible = FALSE;
        return (FALSE);
    }
    check_coll_collision(&game->player, &game->coll);
    if (!(check_wall_collision(&game->player, game->wall.lst_wll)
            && check_npc_collision(&game->player, game->npc.lst_npc)))
    {
        reset_pos(dir, &game->player);
        return (FALSE);
    }
    return (TRUE);
}

t_bool      move_player(enum e_movement_dir dir, t_game *game)
{
    if (dir == UP && game->player.state == ALIVE)
    {
        game->player.old_coords.y = game->player.coords.y;
        game->player.coords.y -= TILE_SIZE;
    }
    else if (dir == LEFT && game->player.state == ALIVE)
    {
        game->player.old_coords.x = game->player.coords.x;
        game->player.coords.x -= TILE_SIZE;
    }
    else if (dir == DOWN && game->player.state == ALIVE)
    {
        game->player.old_coords.y = game->player.coords.y;
        game->player.coords.y += TILE_SIZE;
    }
    else if (dir == RIGHT && game->player.state == ALIVE)
    {
        game->player.old_coords.x = game->player.coords.x;
        game->player.coords.x += TILE_SIZE;
    }
    return (check_collision(dir, game));
}
