#include "../so_long.h"

static t_bool   add_empty(t_empty *empty, int x, int y)
{
    t_point    *emp_pos;

    emp_pos = malloc(sizeof(t_point));
    if (!emp_pos)
        return (FALSE);
    emp_pos->x = x * TILE_SIZE;
    emp_pos->y = y * TILE_SIZE;
    ft_lstadd_back(&empty->lst_emp, ft_lstnew((void *)emp_pos));
    return (TRUE);
}

static t_bool   add_wall(t_wall *wall, int x, int y, t_point win_sz)
{
    t_point    *wll_pos;

    wll_pos = malloc(sizeof(t_point));
    if (!wll_pos)
        return (FALSE);
    wll_pos->x = x * TILE_SIZE;
    wll_pos->y = y * TILE_SIZE;
    ft_lstadd_back(&wall->lst_wll, ft_lstnew((void *)wll_pos));
    return (TRUE);
}

static t_bool   add_collectible(t_collectable *coll, int x, int y)
{
    t_cl    *p_cl;

    p_cl = malloc(sizeof(t_cl));
    if (!p_cl)
        return (FALSE);
    p_cl->pos.x = x * TILE_SIZE;
    p_cl->pos.y = y * TILE_SIZE;
    p_cl->collected = FALSE;
    ft_lstadd_back(&coll->lst_cl, ft_lstnew((void *)p_cl));
    coll->collects++;
    return (TRUE);
}

static void     init_mob(t_mob *mob, int x, int y)
{
    mob->old_coords.x = x * TILE_SIZE;
    mob->old_coords.y = y * TILE_SIZE;
    mob->coords.x = mob->old_coords.x;
    mob->coords.y = mob->old_coords.y;
}

t_bool   define_code(t_game *game, int x, int y, t_tile_code code)
{
    if (code == EMP)
        return (add_empty(&game->empty, x, y));
    else if (code == WLL)
        return (add_wall(&game->wall, x, y, game->win_sz));
    else if (code == COLL)
        return (add_empty(&game->empty, x, y) && add_collectible(&game->coll, x, y));
    else if (code == EXT)
    {
        game->exit.pos.x = x * TILE_SIZE;
        game->exit.pos.y = y * TILE_SIZE;
        game->exit.opened = FALSE;
        return (add_empty(&game->empty, x, y));
    }
    else if (code == PLR)
    {
        game->player.type = KNIGHT;
        game->player.visible = TRUE;
        init_mob(&game->player, x, y);
        return (add_empty(&game->empty, x, y));
    }
    return (TRUE);
}
